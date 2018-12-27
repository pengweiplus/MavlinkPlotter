/***************************************************************************
**  This file is part of Serial Port Plotter                              **
**                                                                        **
**                                                                        **
**  Serial Port Plotter is a program for plotting integer data from       **
**  serial port using Qt and QCustomPlot                                  **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Borislav                                             **
**           Contact: b.kereziev@gmail.com                                **
**           Date: 29.12.14                                               **
****************************************************************************/

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

/******************************************************************************************************************/
/* Constructor */
/******************************************************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    connected(false), plotting(false),dataPointNumber(0), NUMBER_OF_POINTS(500),FREQ_OF_REFRESH(20),mavlinkThread(NULL)
{
    ui->setupUi(this);
    ui->plot->setBackground(QBrush(QColor(48,47,47)));                                    // Background for the plot area
    setupPlot();                                                                          // Setup plot area
    ui->plot->setNotAntialiasedElements(QCP::aeAll);                                      // used for higher performance (see QCustomPlot real time example)
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    ui->plot->xAxis->setTickLabelFont(font);
    ui->plot->yAxis->setTickLabelFont(font);
    ui->plot->legend->setFont(font);

    ui->plot->yAxis->setAutoTickStep(true);                                               // User can change tick step with a spin box
    ui->plot->yAxis->setTickStep(100);                                                    // Set initial tick step
    ui->plot->xAxis->setTickLabelColor(QColor(170,170,170));                              // Tick labels color
    ui->plot->yAxis->setTickLabelColor(QColor(170,170,170));                              // See QCustomPlot examples / styled demo
    ui->plot->xAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::NoPen));
    ui->plot->yAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::NoPen));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::NoPen));
    ui->plot->xAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->xAxis->setBasePen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setBasePen(QPen(QColor(170,170,170)));
    ui->plot->xAxis->setTickPen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setTickPen(QPen(QColor(170,170,170)));
    ui->plot->xAxis->setSubTickPen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setSubTickPen(QPen(QColor(170,170,170)));
    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->setInteraction(QCP::iRangeDrag, true);
    ui->plot->setInteraction(QCP::iRangeZoom, true);

    connect(ui->plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(onMouseMoveInPlot(QMouseEvent*)));
    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(replot()));

    //实例化帮助窗口类
    helpWindow = new HelpWindow(this);
    helpWindow->setWindowTitle("How to use this application");

    //实例化通信接口设置串口类
    setupWindow = new settingWindow(this);
    setupWindow->setWindowTitle("Comm Link Settings");
    connect(setupWindow,SIGNAL(sig_comm_connect()),this,SLOT(on_sig_comm_connect()));
    connect(setupWindow,SIGNAL(sig_comm_disconnect()),this,SLOT(on_sig_comm_disconnect()));

    //初始化mavlink工作线程
    mavlinkThread = new mavPraseThread();
    msgFilesType.insert(MAVLINK_TYPE_CHAR,"char");
    msgFilesType.insert(MAVLINK_TYPE_UINT8_T,"uint8_t");
    msgFilesType.insert(MAVLINK_TYPE_INT8_T,"int8_t");
    msgFilesType.insert(MAVLINK_TYPE_UINT16_T,"uint16_t");
    msgFilesType.insert(MAVLINK_TYPE_INT16_T,"int16_t");
    msgFilesType.insert(MAVLINK_TYPE_UINT32_T,"uint32_t");
    msgFilesType.insert(MAVLINK_TYPE_INT32_T,"int32_t");
    msgFilesType.insert(MAVLINK_TYPE_UINT64_T,"uint64_t");
    msgFilesType.insert(MAVLINK_TYPE_INT64_T,"int64_t");
    msgFilesType.insert(MAVLINK_TYPE_FLOAT,"float");
    msgFilesType.insert(MAVLINK_TYPE_DOUBLE,"double");

    //初始化树形列表
    initTree();
    connect(&treeviewTimer,SIGNAL(timeout()),this,SLOT(on_treeview_refresh()));
    connect(mavlinkThread,SIGNAL(sigNewMavlinkMsg(mavlink_message_t *)),this,SLOT(new_mavlink_msg(mavlink_message_t *)));
    connect(ui->cbox_axis_x_pointes,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(on_cbox_axis_x_pointes_changed(const QString &)));
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Destructor */
/******************************************************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/******************************************************************************************************************/


/******************************************************************************************************************/
/* The plot area */
/******************************************************************************************************************/
///
/// \brief MainWindow::setupPlot
///
void MainWindow::setupPlot()
{
    ui->plot->clearItems();                                         // Remove everything from the plot
    ui->plot->yAxis->setTickStep(10);                               // Set tick step according to user spin box
    ui->plot->yAxis->setRange(-200, 200);                           // Set lower and upper plot range
    ui->plot->xAxis->setRange(0, NUMBER_OF_POINTS);                 // Set x axis range for specified number of points
    ui->plot->setPlottingHints(QCP::phFastPolylines);               // Graph/Curve lines are drawn with a faster method.

}

///
/// \brief MainWindow::allocPlotGraph
/// \return
///
int MainWindow::allocPlotGraph()
{
    //
    mapPlotGraph.insert(ui->plot->graphCount(),Qt::red);
    ui->plot->addGraph();

    return ui->plot->graphCount() - 1;
}

QColor MainWindow::getPlotGraphColor(int num)
{
    return mapPlotGraph.find(num).value();
}

///
/// \brief MainWindow::replot
///
void MainWindow::replot()
{

    QMap<QString,disMavlinkMsg_t>::iterator j;

    //循环添加子节点
    for(j = mavlinkThread->disMavlinkMsg.begin(); j != mavlinkThread->disMavlinkMsg.end(); j++)
    {
        if(j.value().checkd == true){

            //获取当前消息绑定的graph
            QColor plotColor =  getPlotGraphColor(j.value().graphNum);

            //设置颜色、线宽
            QPen graphPen(plotColor);
            graphPen.setWidthF(1.5);

            //按照颜色绘制实时数据
            ui->plot->graph(j.value().graphNum)->setPen(QPen(graphPen));
            ui->plot->graph(j.value().graphNum)->addData(dataPointNumber, (j.value().rtValue  + j.value().offsetNum) * j.value().mulitNum );
            ui->plot->graph(j.value().graphNum)->removeDataBefore(dataPointNumber - NUMBER_OF_POINTS);
        }
    }

    dataPointNumber ++;

    ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);

    ui->plot->replot(QCustomPlot::rpQueued);

}

/******************************************************************************************************************/
/* Main window UI */
/******************************************************************************************************************/
///
/// \brief MainWindow::on_stopPlotButton_clicked
///
void MainWindow::on_stopPlotButton_clicked()
{
    if(plotting) {                                                                        // Stop plotting
        updateTimer.stop();                                                               // Stop updating plot timer
        plotting = false;
        ui->stopPlotButton->setText("Start Plot");
    } else {                                                                              // Start plotting
        updateTimer.start();                                                              // Start updating plot timer
        plotting = true;
        ui->stopPlotButton->setText("Stop Plot");
    }
}

///
/// \brief MainWindow::on_resetPlotButton_clicked
///
void MainWindow::on_resetPlotButton_clicked()
{
    ui->plot->yAxis->setRange(-1000, 1000);
    ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
    ui->plot->yAxis->setTickStep(100);
    ui->plot->replot(QCustomPlot::rpQueued);
}

///
/// \brief MainWindow::onMouseMoveInPlot
/// \param event
///
void MainWindow::onMouseMoveInPlot(QMouseEvent *event)
{
    int xx = ui->plot->xAxis->pixelToCoord(event->x());
    int yy = ui->plot->yAxis->pixelToCoord(event->y());
    QString coordinates("X: %1 Y: %2");
    coordinates = coordinates.arg(xx).arg(yy);
    ui->statusBar->showMessage(coordinates);
}

///
/// \brief MainWindow::on_actioncbox_axis_x_pointes_Changed
/// \param text
///
void MainWindow::on_cbox_axis_x_pointes_changed(const QString &text)
{
     QStringList list_time = text.split(' ');
     QString pointCnt = list_time.at(0);
     QString pointunit = list_time.at(1);

     if ((pointunit.compare("second") == 0) || (pointunit.compare("seconds") == 0)){
         NUMBER_OF_POINTS = pointCnt.toInt()*1000/FREQ_OF_REFRESH;
     }
     if ((pointunit.compare("minute") == 0) || (pointunit.compare("minutes") == 0)){
         NUMBER_OF_POINTS = pointCnt.toInt()*1000*60/FREQ_OF_REFRESH;
      }

     ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
     ui->plot->replot(QCustomPlot::rpQueued);
}

///
/// \brief MainWindow::initTree
///
void MainWindow::initTree()
{
    //QStandardItemModelei,负责组织数据,形成列表或者树,供其他视图类显示
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    model = new QStandardItemModel(ui->treeView);
    //设置水平栏
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Parameter")<<QStringLiteral("Unit")<<QStringLiteral("Value")<<QStringLiteral("Multi")<<QStringLiteral("Offset"));

    //关联项目属性改变的信号和槽
//    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(treeItemChanged(QStandardItem*)));
    ui->treeView->setModel(model);
}




///
/// \brief 添加父节点
/// \param nodeProject,父节点
/// \param nodeName,节点名称
/// \return
///
bool MainWindow::addNodeItem(QStandardItemModel* model,
                             QStandardItem* nodeProject)
{
    //添加节点
    model->appendRow(nodeProject);
    model->setItem(model->indexFromItem(nodeProject).row(),0,nodeProject);

    return true;
}

///
/// \brief 添加子节点
/// \param nodeProject,父节点
/// \param fieldName,域名称
/// \param fieldUnit,域单位
/// \param fieldValue,域值
/// \return
///
int MainWindow::addNodeItem(QStandardItem* nodeProject,
                             QString& fieldName,
                             QString& fieldUnit,
                             QString& fieldValue )
{

    //添加节点名称
    QStandardItem* itemNode = new QStandardItem(fieldName);
    itemNode->setCheckable(true);
    itemNode->setEditable(false);
    nodeProject->appendRow(itemNode);

    //添加节点单位
    QStandardItem* itemUnit = new QStandardItem(fieldUnit);
    itemUnit->setEditable(false);
    nodeProject->setChild(itemNode->index().row(),1,itemUnit);

    //添加节点值
    QStandardItem* itemValue = new QStandardItem(fieldValue);
    itemValue->setEditable(false);
    nodeProject->setChild(itemNode->index().row(),2,itemValue);

    //添加倍率值
    QStandardItem* itemMulti = new QStandardItem("1.0");
    itemMulti->setEditable(true);
    nodeProject->setChild(itemNode->index().row(),3,itemMulti);

    //添加偏移值
    QStandardItem* itemOffset = new QStandardItem("0.0");
    itemOffset->setEditable(true);
    nodeProject->setChild(itemNode->index().row(),4,itemOffset);


    return itemNode->index().row();
}

///
/// \brief MainWindow::startRefreshTimer
///
void MainWindow::startRefreshTimer()
{
    if(connected)return;

    connected = true;                                                                     // Set flags
    plotting = true;

    treeviewTimer.start(100);
    updateTimer.start(FREQ_OF_REFRESH);                                                   // Slot is refreshed 20 times per second
}
///
/// \brief MainWindow::stopRefreshTimer
///
void MainWindow::stopRefreshTimer()
{
    if(!connected)return;

    connected = false;                                                                     // Set flags
    plotting = false;

    treeviewTimer.stop();
    updateTimer.stop();
}

///
/// \brief MainWindow::on_treeview_refresh
/// 定时刷新treeview表格
///
void MainWindow::on_treeview_refresh()
{
    static qint64 timestamp_last = 0;
    bool is_freq_1hz = false;

    //周期计算
    qint64 timestamp = QDateTime::currentDateTime().toMSecsSinceEpoch(); //毫秒级
    if((timestamp - timestamp_last)>1000){
        is_freq_1hz = true;
        timestamp_last = timestamp;
    }else{
        is_freq_1hz = false;
    }

    //treeview列表循环刷新实时数值
    //0:第一列,mavlink消息名称
    //1:第二列,mavlink域名称
    //2:第三列,mavlink域值
    //3:第四列,mavlink倍率值
    //4:第五列,mavlink偏移值

    for(int j = 0;j < model->rowCount(); j++){
        //获取当前msgitem
        QStandardItem *itemMsg = model->item(j,0);

        //只刷新消息的域值
        if(itemMsg->hasChildren()){

            for(int i = 0;i<itemMsg->rowCount();i++){

                QStandardItem *itemField = itemMsg->child(i,0);

                //获取实时数据
                QString msgName = itemMsg->text();
                QString fieldName = itemField->text();
                QString fullName = msgName + fieldName;
                disMavlinkMsg_t *tt = &(mavlinkThread->disMavlinkMsg.find(fullName).value());
                QString rtValue = QString::number(tt->rtValue);

                //刷新数据
                if(is_freq_1hz){
                    itemMsg->child(itemField->row(),2)->setText(rtValue);
                }

                //刷新倍率和偏移量到hash
                tt->mulitNum = itemMsg->child(itemField->row(),3)->text().toDouble();
                tt->offsetNum = itemMsg->child(itemField->row(),4)->text().toDouble();

                //刷新复选框
                treeItemChanged(itemField,tt);
            }
        }
    }
}


///
/// \brief MainWindow::new_mavlink_msg
/// \param msg
///
void MainWindow::new_mavlink_msg(mavlink_message_t *msg)
{
    const mavlink_message_info_t *msgInfo;
    //提取消息信息
    msgInfo = mavlink_get_message_info(msg);

    //消息错误,退出
    if(NULL == msgInfo )return;

    //判断当前信息是否已经加载
    if(mapMavlinkMsg.contains(msgInfo->msgid)){
        return;
    }else{

        //记录新消息
        mapMavlinkMsg.insert(msgInfo->msgid,*msg);

        //添加消息节点名称
        QString nodeName(msgInfo->name);

        QStandardItem* nodeRoot = new QStandardItem(QIcon(QStringLiteral(":/Icons/Icons/feed.png")),nodeName);

        addNodeItem(model,nodeRoot);

        //添加消息域信息
        for(uint32_t i = 0; i < msgInfo->num_fields; i++){
            //名称
            QString fieldName(msgInfo->fields[i].name);

            //类型
            uint32_t key = msgInfo->fields[i].type;
            QMap<uint32_t,QString>::iterator it = msgFilesType.find(key);
            QString fieldUnit = it.value();

            //值
            QString fieldValue;

            //添加
            addNodeItem(nodeRoot, fieldName,fieldUnit, fieldValue);
        }
    }
}


///
/// \brief MainWindow::treeItemChanged
/// \param item
///

#define RANDOM_COLOR 1

void MainWindow::treeItemChanged(QStandardItem * item)
{
    if(item == nullptr)
        return;

    //获取当前改变item信息
    QStandardItem * parentItem = item->parent();
    QString fullName = parentItem->text() + item->text();

    //修改hash
    disMavlinkMsg_t *t = &(mavlinkThread->disMavlinkMsg.find(fullName).value());

    if(Qt::Checked == item->checkState()){

       // 申请过图层后,不再分配新的图层
       if(t->graphNum == 0xFFFF){
           t->graphNum = allocPlotGraph();  //获取当前的图层编号
       }

       t->checkd = true;                //获取当前的选择状态

#ifdef SELECT_COLOR
       //创建对象
       QColorDialog dialog(Qt::red,this);

       //显示alpha选项
       dialog.setOption(QColorDialog::ShowAlphaChannel);

       //以模态方式运行对话框
       dialog.exec();

       QColor qc = dialog.selectedColor();
       if( qc != QColor::Invalid){

            mapPlotGraph.insert(t->graphNum,qc);
            item->parent()->child(item->row(),1)->setBackground(QBrush(qc));
       }
    }
#endif

#ifdef RANDOM_COLOR

       QColor c = QColor::fromHsl(qrand()%12*30,255,128);
       QColor qc(c.red(),c.green(),c.blue());
       mapPlotGraph.insert(t->graphNum,qc);
       item->parent()->child(item->row(),1)->setBackground(QBrush(qc));
    }

#endif

    if(Qt::Unchecked == item->checkState()){

        t->checkd = false;                //获取当前的选择状态

        QColor c = QColor(0x302F2F);

        item->parent()->child(item->row(),1)->setBackground(QBrush(c));
    }


}

///
/// \brief MainWindow::treeItemChanged
/// \param item
/// \param t
///
void MainWindow::treeItemChanged(QStandardItem * item,disMavlinkMsg_t *t)
{

    if(item == nullptr)
        return;

    //获取当前改变item信息
    QStandardItem * parentItem = item->parent();

    //当前勾选状态和上一次不一致,触发勾选事件
    if(Qt::Checked == item->checkState() && t->checkd == false){

       //申请过图层后,不再分配新的图层
       if(t->graphNum == 0xFFFF){
           t->graphNum = allocPlotGraph();  //获取当前的图层编号
       }


       t->checkd = true;                //获取当前的选择状态

#ifdef SELECT_COLOR
       //创建对象
       QColorDialog dialog(Qt::red,this);

       //显示alpha选项
       dialog.setOption(QColorDialog::ShowAlphaChannel);

       //以模态方式运行对话框
       dialog.exec();

       QColor qc = dialog.selectedColor();
       if( qc != QColor::Invalid){

            mapPlotGraph.insert(t->graphNum,qc);
            item->parent()->child(item->row(),1)->setBackground(QBrush(qc));
       }
    }
#endif

#ifdef RANDOM_COLOR

       QColor c = QColor::fromHsl(qrand()%12*30,255,128);
       QColor qc(c.red(),c.green(),c.blue());
       mapPlotGraph.insert(t->graphNum,qc);
       parentItem->child(item->row(),1)->setBackground(QBrush(qc));
    }

#endif

    if(Qt::Unchecked == item->checkState() && t->checkd == true){

        t->checkd = false;                //获取当前的选择状态

        QColor c = QColor(0x302F2F);

        parentItem->child(item->row(),1)->setBackground(QBrush(c));
    }

}



/******************************************************************************************************************/
/* How to use window with instructions */
/******************************************************************************************************************/
///
/// \brief MainWindow::on_actionHow_to_use_triggered
///
void MainWindow::on_actionHow_to_use_triggered()
{
    helpWindow->show();
}


/******************************************************************************************************************/
/* settingWindows */
/******************************************************************************************************************/

///
/// \brief MainWindow::on_actionCommLinks_triggered
///
void MainWindow::on_actionCommLinks_triggered()
{
    setupWindow->show();
}

///
/// \brief MainWindow::on_sig_comm_connect
///
void MainWindow::on_sig_comm_connect()
{
    //实例化一个工作线程
    if(mavlinkThread == NULL){
        mavlinkThread = new mavPraseThread();
    }

   //1.尝试连接硬件接口
    switch(setupWindow->commlinkType)
    {
        //serial
        case HW_SERIAL:
        {

            //1.1连接成功,启动数据处理线程
            if(mavlinkThread->setupHardIf(setupWindow->portInfo,
                                          setupWindow->baudRate,
                                          setupWindow->dataBits,
                                          setupWindow->parity,
                                          setupWindow->stopBits) == true) {

                //启动工作线程
                mavlinkThread->start();

                //界面提示
                setupWindow->setCommLinkInfo(true);

                //启动plot刷新和treeview刷新
                startRefreshTimer();
            }
            //1.2连接失败,窗口显示错误信息
            else {

                //删除工作线程
                delete mavlinkThread;
                mavlinkThread = NULL;

                //界面提示
                setupWindow->setCommLinkInfo(false);
            }

        }break;

        //udp
        case HW_UDP:
        {
                //设置socket 参数
                bool ret = mavlinkThread->setupHardIf(setupWindow->udp_port);
                if(ret){
                    //启动工作线程
                    mavlinkThread->start();

                    //界面提示
                    setupWindow->setCommLinkInfo(true);

                    //启动plot刷新和treeview刷新
                    startRefreshTimer();
                }else{

                    // 删除工作线程
                    delete mavlinkThread;
                    mavlinkThread = NULL;

                    //界面提示
                    setupWindow->setCommLinkInfo(false);
                }

        }break;

        default:
        {
            ;
        }
    }
}

///
/// \brief MainWindow::on_sig_comm_disconnect
///
void MainWindow::on_sig_comm_disconnect()
{
    //删除一个工作线程
    if(mavlinkThread == NULL){
        return;
    }

    //1.关闭serial端口
    switch(setupWindow->commlinkType)
    {
        //serial
        case HW_SERIAL:
        {
            mavlinkThread->closeHardIf();
        }break;

        //udp
        case HW_UDP:
        {
            mavlinkThread->closeHardIf();
        }break;

        default:
        {
            ;
        }
    }

    //2.关闭工作线程
    mavlinkThread->exit();

    //3.界面显示
    setupWindow->setCommLinkInfo(false);

    //4.关闭界面刷新
    stopRefreshTimer();
}




