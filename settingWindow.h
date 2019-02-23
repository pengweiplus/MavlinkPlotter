#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QDialog>

#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QQueue>

#include <QByteArray>
#include <QUdpSocket>
#include <QHostAddress>


#include "mavPraseThread.h"

namespace Ui {
class settingWindow;
}

class settingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit settingWindow(QWidget *parent = 0);
    ~settingWindow();

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

private:
    Ui::settingWindow *ui;
};

#endif // SETTINGWINDOW_H
