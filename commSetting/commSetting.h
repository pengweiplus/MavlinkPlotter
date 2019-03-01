#ifndef COMM_SETTING_H
#define COMM_SETTING_H

#include <QDialog>

#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QQueue>

#include <QByteArray>
#include <QUdpSocket>
#include <QHostAddress>


#include "mavPraseThread.h"

namespace Ui {
class commSetting;
}

class commSetting : public QDialog
{
    Q_OBJECT

public:
    explicit commSetting(QWidget *parent = 0);
    ~commSetting();

    bool setupSerialUI();
    bool setupUdplUI();
    void setCommLinkInfo(bool res);

    //端口模式
    int commlinkType;

    //串口设置参数
    QSerialPortInfo *portInfo;
    int baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;

    //udp设置参数
    int udp_port;

protected:
     void closeEvent(QCloseEvent *event);

signals:
    void sig_comm_newdata();
    void sig_comm_connect();
    void sig_comm_disconnect();

private slots:
    void on_btn_comm_connect_released();
    void on_btn_comm_disconnect_released();
    void cboxCommLinkChanged(int index);

private:
    Ui::commSetting *ui;
};

#endif // COMM_SETTING_H
