#include "io_manager.h"

io_manager::io_manager():
    nType(UDP_SOCKET),
    serialPort(NULL),
    mSocket(NULL)

{

}

///
/// \brief io_manager::setupIf
/// \param portInfo
/// \param baud
/// \param dataBits
/// \param parity
/// \param stopBits
/// \return
///
bool io_manager::setupIf(QSerialPortInfo &portInfo,
                         QSerialPort::BaudRate baud,
                         QSerialPort::DataBits dataBits,
                         QSerialPort::Parity parity,
                         QSerialPort::StopBits stopBits)
{
    // Indicate the port type
    nType = SERIAL;

    //1.尝试连接硬件串口
    serialPort = new QSerialPort(portInfo, 0);                          // Use local instance of QSerialPort; does not crash

    //1.1连接成功,启动数据处理线程
    if(serialPort->open(QIODevice::ReadWrite) == true) {
        serialPort->setBaudRate(baud);
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
/// \brief io_manager::setupIf
/// \param udpPort
/// \return
///
bool io_manager::setupIf(int udpPort)
{
    nType = UDP_SOCKET; //udp

    mSocket = new  QUdpSocket();                            //udp socket
    if(mSocket->bind(QHostAddress::AnyIPv4,udpPort)){
        udpListenPort =  udpPort;

        return true;
    }else{

        return false;
    }

}

///
/// \brief io_manager::closeIf
/// \return
///
bool io_manager::closeIf()
{
    switch(nType){
    case SERIAL:
    {
        serialPort->close();
        return true;
    }break;

    case UDP_SOCKET:
    {
        mSocket->close();
        return true;
    }break;

    case TCP_SOCKET:
    {
        qDebug("Unsupported TCP port!!!");
        return false;
    }break;

    default:
    {
        qDebug("Unsupported hardware port!!!");
        return false;
    }break;
    }
}

///
/// \brief io_manager::readBytes
/// \param buffer
/// \param len
/// \return
///
int io_manager::readBytes(char *buffer, uint32_t len)
{
    switch(nType){
    case SERIAL:
    {
        return readBytesFromSerial(buffer,len);
    }break;

    case UDP_SOCKET:
    {
        return readBytesFromUdpSocket(buffer,len);
    }break;

    case TCP_SOCKET:
    {
        qDebug("Unsupport tcp read!!!");
        return 0;
    }break;

    default:
    {
        qDebug("Unsupported hardware port!!!");
        return 0;
    }break;
    }
}

///
/// \brief io_manager::writeBytes
/// \param buffer
/// \param len
/// \return
///
int io_manager::writeBytes(char *buffer, uint32_t len)
{
    switch(nType){
    case SERIAL:
    {
        qDebug("Unsupported hardware write!!!");
        return 0;
    }break;

    case UDP_SOCKET:
    {
        qDebug("Unsupported hardware write!!!");
        return 0;
    }break;

    case TCP_SOCKET:
    {
        qDebug("Unsupported hardware write!!!");
        return 0;
    }break;

    default:
    {
        qDebug("Unsupported hardware write!!!");
        return 0;
    }break;
    }
}

///
/// \brief io_manager::readBytesFromSerial
/// \param buffer
/// \param len
/// \return
///
int io_manager::readBytesFromSerial(char *buffer, uint32_t len)
{

    // blocks until new data is available for reading
    if (serialPort->waitForReadyRead()){
       return serialPort->read(buffer, len);;
    }

    return 0;
}

///
/// \brief io_manager::writeBytesToSerial
/// \param buffer
/// \param len
/// \return
///
int io_manager::writeBytesToSerial(char *buffer, uint32_t len)
{
    qDebug("Unsupported serial write!!!");
    return 0;
}

///
/// \brief io_manager::readBytesFromUdpSocket
/// \param buffer
/// \param len
/// \return
///
int io_manager::readBytesFromUdpSocket(char *buffer, uint32_t len)
{
    QByteArray array;

    //阻塞等待下一个数据到来
    mSocket->waitForReadyRead();

    //获取缓存数据大小
    int numRead = mSocket->bytesAvailable();

    //根据可读数据来设置空间大小
    array.resize(numRead);

    //读取数据
    mSocket->readDatagram(array.data(),array.size());

    //这里处理需要优化,直接影响数据的实时性
    for(int count = 0; count < numRead ; count++){

        buffer[count]=array.at(count);
    }

    return numRead;

}
