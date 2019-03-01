#include "commSetting.h"
#include "ui_commSetting.h"

commSetting::commSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commSetting)
{
    ui->setupUi(this);
    ui->label_setup_status->setText(" ");
    setupSerialUI();        //设置串口窗口
    setupUdplUI();          //设置UDP窗口

    connect(ui->cbox_comm_link,SIGNAL(currentIndexChanged(int)),this,SLOT(cboxCommLinkChanged(int)));

}

commSetting::~commSetting()
{
    delete ui;
}


///
/// \brief commSetting::closeEvent
/// 窗口关闭前事件
/// \param event
///
void commSetting::closeEvent(QCloseEvent *event)
{
    ui->label_setup_status->setText(" ");
}


///
/// \brief commSetting::setupSerialUI
/// 初始化串口设置界面
/// \return
///
bool commSetting::setupSerialUI()
{

    int serialPorts = QSerialPortInfo::availablePorts().size();
    if(serialPorts == 0) {                                   // Check if there are any ports at all; if not, disable controls and return
        return false;
    }

    for(int i = 0; i < serialPorts; i++) {                    // List all available serial ports and populate ports combo box
        ui->cbox_serial_port->addItem(QSerialPortInfo::availablePorts().at(i).portName());
    }

    return true;
}

///
/// \brief commSetting::setupUdplUI
/// 初始化udp设置界面
/// \return
///
bool commSetting::setupUdplUI()
{

    return true;
}

///
/// \brief commSetting::setCommLinkInfo
/// \param res
///
void commSetting::setCommLinkInfo(bool res)
{
    if(res){
        //界面提示
        ui->label_setup_status->setText("Connected");
        ui->btn_comm_connect->setEnabled(false);
        ui->btn_comm_disconnect->setEnabled(true);
    }else{
        //界面提示
        ui->label_setup_status->setText("Disconnected");
        ui->btn_comm_connect->setEnabled(true);
        ui->btn_comm_disconnect->setEnabled(false);
    }
}

///
/// \brief commSetting::on_btn_comm_connect_released
/// 连接数据通道,启动工作线程
///  * 1.尝试连接通信端口(serial/udp)
///  *      1)若硬件连接成功,进入步骤2
///  *      2)若硬件连接失败:
///  *          (1)窗口提示失败原因
///
///  * 2.硬件连接成功
///  *      1)实例化对应端口工作进程
///  *      2)启动工作进程
///  *      3)互斥显示connect和disconnect
///

void commSetting::on_btn_comm_connect_released()
{

   //1.设置接口参数
    commlinkType = ui->cbox_comm_link->currentIndex();
    switch(commlinkType)
    {
        //serial
        case HW_SERIAL:
        {

            //串口参数设置
            portInfo = new QSerialPortInfo(ui->cbox_serial_port->currentText());
            baudRate = ui->cbox_serial_baud_rate->currentText().toInt();        // Get baud rate from combo box
            int dataBitsIndex = ui->cbox_serial_data_bits->currentIndex();          // Get index of data bits combo box
            int parityIndex = ui->cbox_serial_parity->currentIndex();               // Get index of parity combo box
            int stopBitsIndex = ui->cbox_serial_stop_bits->currentIndex();


            if(dataBitsIndex == 0) {                                            // Set data bits according to the selected index
                dataBits = QSerialPort::Data8;
            } else {
                dataBits = QSerialPort::Data7;
            }

            if(parityIndex == 0) {                                              // Set parity according to the selected index
                parity = QSerialPort::NoParity;
            } else if(parityIndex == 1) {
                parity = QSerialPort::OddParity;
            } else {
                parity = QSerialPort::EvenParity;
            }


            if(stopBitsIndex == 0) {                                            // Set stop bits according to the selected index
                stopBits = QSerialPort::OneStop;
            } else {
                stopBits = QSerialPort::TwoStop;
            }

        }break;

        //udp
        case HW_UDP:
        {
                udp_port = ui->ledit_udp_port->text().toInt();

        }break;

        default:
        {
            ;
        }
    }

    emit sig_comm_connect();
}

//void commSetting::on_btn_comm_connect_released()
//{

//    //实例化一个工作线程
//    mavlinkThread = new mavPraseThread();


//   //1.尝试连接硬件接口
//    switch(ui->cbox_comm_link->currentIndex())
//    {
//        //serial
//        case HW_SERIAL:
//        {

//            //串口参数设置
//            QSerialPortInfo *portInfo = new QSerialPortInfo(ui->cbox_serial_port->currentText());
//            int baudRate = ui->cbox_serial_baud_rate->currentText().toInt();        // Get baud rate from combo box
//            int dataBitsIndex = ui->cbox_serial_data_bits->currentIndex();          // Get index of data bits combo box
//            int parityIndex = ui->cbox_serial_parity->currentIndex();               // Get index of parity combo box
//            int stopBitsIndex = ui->cbox_serial_stop_bits->currentIndex();

//            QSerialPort::DataBits dataBits;
//            if(dataBitsIndex == 0) {                                            // Set data bits according to the selected index
//                dataBits = QSerialPort::Data8;
//            } else {
//                dataBits = QSerialPort::Data7;
//            }

//            QSerialPort::Parity parity;
//            if(parityIndex == 0) {                                              // Set parity according to the selected index
//                parity = QSerialPort::NoParity;
//            } else if(parityIndex == 1) {
//                parity = QSerialPort::OddParity;
//            } else {
//                parity = QSerialPort::EvenParity;
//            }

//            QSerialPort::StopBits stopBits;
//            if(stopBitsIndex == 0) {                                            // Set stop bits according to the selected index
//                stopBits = QSerialPort::OneStop;
//            } else {
//                stopBits = QSerialPort::TwoStop;
//            }

//            //1.1连接成功,启动数据处理线程
//            if(mavlinkThread->setupHardIf(portInfo,baudRate,dataBits,parity,stopBits) == true) {

//                //启动工作线程
//                mavlinkThread->start();

//                //界面提示
//                ui->label_setup_status->setText("Open successful!");
//                ui->btn_comm_connect->setEnabled(false);
//                ui->btn_comm_disconnect->setEnabled(true);
//            }
//            //1.2连接失败,窗口显示错误信息
//            else {

//                // 删除工作线程
//                delete mavlinkThread;

//                //界面提示
//                ui->label_setup_status->setText("Open fialed!");
//                ui->btn_comm_connect->setEnabled(true);
//                ui->btn_comm_disconnect->setEnabled(false);
//            }

//        }break;

//        //udp
//        case HW_UDP:
//        {
//            int udp_port = ui->ledit_udp_port->text().toInt();

//                //设置socket 参数
//                bool ret = mavlinkThread->setupHardIf(udp_port);
//                if(ret){
//                    //启动工作线程
//                    mavlinkThread->start();

//                    ui->label_setup_status->setText("Listen port successful!");
//                    ui->btn_comm_connect->setEnabled(false);
//                    ui->btn_comm_disconnect->setEnabled(true);
//                }else{

//                    // 删除工作线程
//                    delete mavlinkThread;

//                    ui->label_setup_status->setText("Listen port fialed!");
//                    ui->btn_comm_connect->setEnabled(true);
//                    ui->btn_comm_disconnect->setEnabled(false);
//                }


//        }break;

//        default:
//        {
//            ;
//        }
//    }
//}


///
/// \brief commSetting::on_btn_comm_disconnect_released
/// *  关闭数据通道,清空数据
/// * 1.关闭工作进程
/// *      1)如果关闭失败,窗口提示失败原因
/// *      2)关闭成功反实例化对应端口工作进程
/// *
/// * 2.关闭硬件端口(serial/udp)
/// *      1)若硬件连接失败:
/// *          (1)窗口提示失败原因
/// *      2)关闭成功互斥显示connect和disconnect
///
///
void commSetting::on_btn_comm_disconnect_released()
{
    emit sig_comm_disconnect();
}
//void commSetting::on_btn_comm_disconnect_released()
//{
//    switch(ui->cbox_comm_link->currentIndex())
//    {
//        //serial
//        case HW_SERIAL:
//        {
//            //1.关闭serial端口
//            mavlinkThread->closeHardIf();

//            //2.关闭工作线程
//            mavlinkThread->exit();

//            //3.界面显示
//            ui->label_setup_status->setText("Close successful!");
//            ui->btn_comm_connect->setEnabled(true);
//            ui->btn_comm_disconnect->setEnabled(false);

//        }break;

//        //udp
//        case HW_UDP:
//        {

//            //2.关闭工作线程
//            mavlinkThread->exit();

//            //3.界面显示
//            ui->label_setup_status->setText("Close successful!");
//            ui->btn_comm_connect->setEnabled(true);
//            ui->btn_comm_disconnect->setEnabled(false);

//        }break;

//        default:
//        {
//            ;
//        }
//    }
//}

///
/// \brief commSetting::cboxCommLinkChanged
/// \param index
///
void commSetting::cboxCommLinkChanged(int index)
{
    ui->tab_comm->setCurrentIndex(index);
}
