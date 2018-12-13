#include "mavPraseThread.h"

///
/// \brief mavPraseThread::mavPraseThread
/// \param parent
///
mavPraseThread::mavPraseThread(QObject *parent) :
    QThread(parent),shouldExit(false)
{

}

///
/// \brief mavPraseThread::setupHardIf
/// \param portInfo 串口号信息
/// \param baudRate 波特率
/// \param dataBits 数据位
/// \param parity   校验位
/// \param stopBits 停止位
/// \return
///
bool mavPraseThread::setupHardIf(QSerialPortInfo *portInfo,int baudRate,QSerialPort::DataBits &dataBits,QSerialPort::Parity &parity,QSerialPort::StopBits &stopBits )
{
    nType = HW_SERIAL;

    //1.尝试连接硬件串口
    serialPort = new QSerialPort(*portInfo, 0);                          // Use local instance of QSerialPort; does not crash

    //1.1连接成功,启动数据处理线程
    if(serialPort->open(QIODevice::ReadWrite) == true) {
        serialPort->setBaudRate(baudRate);
        serialPort->setParity(parity);
        serialPort->setDataBits(dataBits);
        serialPort->setStopBits(stopBits);

        return true;
    }
    //1.2连接失败,窗口显示错误信息
    else {
        return false;
    }
}


///
/// \brief mavPraseThread::setupHardIf
/// \param port UDP监听端口
/// \return
///
bool mavPraseThread::setupHardIf(int port)
{
    nType = HW_UDP; //udp

    //设置监听端口
    udpListenPort = port;

    //设置循环退出标志
    shouldExit = false;

    return true;
}


///
/// \brief mavPraseThread::closeHardIf
/// 关闭硬件资源并退出
/// \return
///
bool mavPraseThread::closeHardIf()
{
    shouldExit = true;

    return true;
}

///
/// \brief mavPraseThread::packetReceived
/// 解析一包mavlink数据
/// \param msg
///
void mavPraseThread::packetReceived(mavlink_message_t &msg)
{

    //如果正确解析出一包完整数据,发射信号
    if(handleMessage(msg,disMavlinkMsg) == true){

        emit sigNewMavlinkMsg(&msg);
    }
}

///
/// \brief mavPraseThread::run
/// 主工作线程循环
///
void mavPraseThread::run()
{
    int numRead = 0;
    char buffer[1024];

    //初始化端口信息
    //socket的对象必须在run中实例化,否则会提示跨进程使用!!!
    if(nType == HW_UDP)
    {
        mSocket = new  QUdpSocket();                            //udp socket
        mSocket->bind(QHostAddress::AnyIPv4,udpListenPort);
    }

    //主任务循环
    while (!shouldExit) {

        switch(nType)
        {
            //serial
            case HW_SERIAL:
            {
                numRead  = serialPort->read(buffer, 1024);

                //这里处理需要优化,直接影响数据的实时性
                for(int count = 0; count < numRead ; count++){

                    //每处理完一帧数据就针对整包有效数据进行处理
                    if(mavlink_parse_char(MAVLINK_COMM_0,buffer[count],&r_mav_msg,&r_mav_status)){
                        packetReceived(r_mav_msg);
                    }
                }

                //阻塞等待下一个数据到来
                if (numRead == 0 && !serialPort->waitForReadyRead())
                    break;

            }break;

            //udp
            case HW_UDP:
            {

                QByteArray array;

                //阻塞等待下一个数据到来
                mSocket->waitForReadyRead();

                //获取缓存数据大小
                numRead = mSocket->bytesAvailable();

                //根据可读数据来设置空间大小
                array.resize(numRead);

                //读取数据
                mSocket->readDatagram(array.data(),array.size());

                //这里处理需要优化,直接影响数据的实时性
                for(int count = 0; count < numRead ; count++){

                    //每处理完一帧数据就针对整包有效数据进行处理
                    if(mavlink_parse_char(MAVLINK_COMM_0,array.at(count),&r_mav_msg,&r_mav_status)){
                        packetReceived(r_mav_msg);
                    }
                }

            }break;

            default:
            {
                ;
            }break;
        }

    }

    //关闭硬件端口
    //socket的对象必须在run中关闭,否则会提示跨进程使用!!!
    if(nType == HW_UDP)
    {
        mSocket->close();
        delete mSocket;
    }

}


///
/// \brief 以消息域为单位的,将原始msg拆分处理,存入Hash表格
/// \param msg,原始消息
/// \return true,处理完成  false,处理失败
///
bool mavPraseThread::handleMessage(mavlink_message_t &msg,QMap<QString,disMavlinkMsg_t>&msgMap)
{

    //提取消息信息
    const mavlink_message_info_t *msgInfo = mavlink_get_message_info(&msg);

    //消息错误,退出
    if(NULL == msgInfo )return false;

    disMavlinkMsg_t t;

    //读取消息名称
    t.msgName = msgInfo->name;
    QString msgName(t.msgName);

    //读取该条消息的所有域(依据名称,类型获取值)
    for(uint32_t i = 0; i < msgInfo->num_fields; i++){
        //名称
        t.fieldName = msgInfo->fields[i].name;
        QString fieldName(t.fieldName);
        //类型
        t.dataType  = msgInfo->fields[i].type;

        //获取值
        t.rtValue = get_mavlink_msg_info(&msg,msgInfo, t.dataType,i);

        //生成全名
        QString fullName = msgName + fieldName;

        //保留当前check状态
        if(msgMap.contains(fullName)  == true){
            QMap<QString,disMavlinkMsg_t>::iterator r = msgMap.find(fullName);
            t.checkd = r.value().checkd;
            t.graphNum = r.value().graphNum;
            t.mulitNum = r.value().mulitNum;
            t.offsetNum = r.value().offsetNum;

            //旧数据,被替换掉
            memcpy(&msgMap.find(fullName).value(),&t,sizeof(t));
        }else{
            //新数据,保存到Hash表
            t.checkd = false;
            t.graphNum = 0xFFFF;
            t.mulitNum = 1.0;
            t.offsetNum = 0.0;

            msgMap.insert(fullName,t);
        }
    }

    return true;
}


///
/// \brief mavPraseThread::get_mavlink_msg_info
/// \param msg          mavlink消息
/// \param msgInfo      mavlink消息信息
/// \param dataType     数据类型
/// \param i
/// \return
///
double mavPraseThread::get_mavlink_msg_info(mavlink_message_t *msg,const mavlink_message_info_t *msgInfo, uint32_t dataType,uint32_t i)
{
    double value = 0;

    if(MAVLINK_TYPE_CHAR == dataType){
         value = _MAV_RETURN_char(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT8_T == dataType){
        value = _MAV_RETURN_uint8_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_INT8_T == dataType){
        value = _MAV_RETURN_int8_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT16_T == dataType){
        value = _MAV_RETURN_uint16_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_INT16_T == dataType){
        value = _MAV_RETURN_int16_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT32_T == dataType){
        value = _MAV_RETURN_uint32_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_INT32_T == dataType){
        value = _MAV_RETURN_int32_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT64_T == dataType){
        value = _MAV_RETURN_uint64_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_DOUBLE == dataType){
        value = _MAV_RETURN_double(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_FLOAT == dataType){
        value = _MAV_RETURN_float(msg,msgInfo->fields[i].wire_offset);
    }else{
        ;
    }

    return value;
}









