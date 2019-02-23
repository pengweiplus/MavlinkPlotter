#ifndef IO_MANAGER_H
#define IO_MANAGER_H

#include <QObject>
#include <QByteArray>

#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QUdpSocket>
#include <QHostAddress>

class io_manager
{
public:
    io_manager();

    bool setupIf(QSerialPortInfo &portInfo,\
                 QSerialPort::BaudRate baud= QSerialPort::Baud115200,\
                 QSerialPort::DataBits dataBits =QSerialPort::Data8,\
                 QSerialPort::Parity parity=QSerialPort::NoParity,\
                 QSerialPort::StopBits stopBits = QSerialPort::OneStop);
    bool setupIf(int udpPort=14550);
    bool closeIf();
    int readBytes(char* buffer,uint32_t len=1024);
    int writeBytes(char* buffer,uint32_t len);

    enum interfaceType_e{
        SERIAL,
        UDP_SOCKET,
        TCP_SOCKET,
    };

private:
    /* interface type */
    enum interfaceType_e nType;

    /* interface */
    //Serial Port

    QSerialPort *serialPort;

    //UDP Socket
    QUdpSocket *mSocket;
    int udpListenPort;

    int readBytesFromSerial(char* buffer,uint32_t len=1024);
    int writeBytesToSerial(char* buffer,uint32_t len);
    int readBytesFromUdpSocket(char* buffer,uint32_t len=1024);
    int writeBytesToUdpSocket(char* buffer,uint32_t len);

};

#endif // IO_MANAGER_H
