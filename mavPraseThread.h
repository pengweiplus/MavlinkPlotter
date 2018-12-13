#ifndef MAVPRASETHREAD_H
#define MAVPRASETHREAD_H

#include <QObject>

#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QQueue>
#include <QDebug>
#include <QHash>
#include <QColor>

#include <QByteArray>
#include <QUdpSocket>
#include <QHostAddress>

#include "mavlink/fppa/mavlink.h"


//此结构体面向的对象是单个msg中的域,非单个msg!!!
//1.记录域的值(界面显示用到)
//2.记录在treeview中的行,列号(用于动态修改treeview中显示的值)
//3.记录该条曲线的颜色(界面显示用到)
//4.

typedef struct {
    double_t mean;            //平均值
    double_t variance;        //方差值
    double_t max;             //最大值
    double_t min;             //最小值

}msgAttribute_t;

typedef struct {
    const char *msgName;        //消息名称
    const char *fieldName;      //域名称
    double_t rtValue;           //实时数据
    msgAttribute_t attribute;   //属性域
    int dataType;               //数据类型
    int graphNum;               //graph
    int mulitNum;               //倍率
    int offsetNum;              //偏移
    bool checkd;                //是否显示到plot窗口
}disMavlinkMsg_t;

enum
{
    HW_SERIAL,
    HW_UDP,
};

class mavPraseThread : public QThread
{

    Q_OBJECT

protected:
    void run();

public:
    explicit mavPraseThread(QObject *parent = 0);

    bool setupHardIf(QSerialPortInfo *portInfo,int baudRate,QSerialPort::DataBits &dataBits,QSerialPort::Parity &parity,QSerialPort::StopBits &stopBits );
    bool setupHardIf(int port);

    bool closeHardIf();

    void packetReceived(mavlink_message_t &msg);
    bool handleMessage(mavlink_message_t &msg,QMap<QString,disMavlinkMsg_t>&msgHash);
    double get_mavlink_msg_info(mavlink_message_t *msg,const mavlink_message_info_t *msgInfo, uint32_t dataType,uint32_t i);


    /* mavlink */
    mavlink_message_t r_mav_msg;                    //消息帧[必要]
    mavlink_status_t r_mav_status;                  //解析器状态[必要]
    QMap<QString,disMavlinkMsg_t> disMavlinkMsg;   //消息域Hash表

signals:
    void sigNewMavlinkMsg(mavlink_message_t *msg);

private:
    //线程信息
    bool shouldExit;                                //线程退出标志

    //接口信息
    char nType;
    QSerialPort *serialPort;                        //serial

    QUdpSocket *mSocket;
    int udpListenPort;

};

#endif // MAVPRASETHREAD_H
