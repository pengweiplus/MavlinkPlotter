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
    connected(false),
    plotting(false),
    logging(false),
    dataPointNumber(0),
    NUMBER_OF_POINTS(500),
    FREQ_OF_REFRESH(20),
    mavlinkThread(NULL)
{
    ui->setupUi(this);

    //初始化设置2D图形界面
    setupPlotGraphView();
    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(replot()));

    //初始化QRubberBand
    rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->plot);

    //鼠标事件
    connect(ui->plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress(QMouseEvent*)));
    connect(ui->plot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
    connect(ui->plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));

    //实例化通信接口设置类
    mCommSetting = new commSetting(this);
    mCommSetting->setWindowTitle("Comm Link Settings");
    connect(mCommSetting,SIGNAL(sig_comm_connect()),this,SLOT(commConnect()));
    connect(mCommSetting,SIGNAL(sig_comm_disconnect()),this,SLOT(commDisconnect()));

    //实例化调试窗口类
    mTurningWindows = new turningWindows(this);
    mTurningWindows->setWindowTitle("Turning Settings");

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
    setupTreeView();
    connect(&treeviewTimer,SIGNAL(timeout()),this,SLOT(treeviewRefresh()));
    connect(mavlinkThread,SIGNAL(sigNewMavlinkMsg(mavlink_message_t *)),this,SLOT(newMavlinkMsg(mavlink_message_t *)));
    connect(ui->cbox_axis_x_pointes,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(cboxAxisXPointesChanged(const QString &)));
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
//------custemplot 2D图

///
/// \brief MainWindow::setupPlotGraphView
/// 设置QCustemPlot界面属性
///
void MainWindow::setupPlotGraphView()
{
    //设置背景颜色
    ui->plot->setBackground(QBrush(QColor(48,47,47)));              // Background for the plot area

    //设置x-y轴参数
    ui->plot->clearItems();                                         // Remove everything from the plot
    ui->plot->yAxis->setTickStep(10);                               // Set tick step according to user spin box
    ui->plot->yAxis->setRange(-200, 200);                           // Set lower and upper plot range
    ui->plot->xAxis->setRange(0, NUMBER_OF_POINTS);                 // Set x axis range for specified number of points
    ui->plot->setPlottingHints(QCP::phFastPolylines);               // Graph/Curve lines are drawn with a faster method.

    //设置为高性能绘图模式
    ui->plot->setNotAntialiasedElements(QCP::aeAll);                // used for higher performance (see QCustomPlot real time example)

    //设置字体
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    ui->plot->xAxis->setTickLabelFont(font);
    ui->plot->yAxis->setTickLabelFont(font);
    ui->plot->legend->setFont(font);

    //设置刻度（自动大小、颜色）
    ui->plot->yAxis->setAutoTickStep(true);                                               // User can change tick step with a spin box
    ui->plot->yAxis->setTickStep(100);                                                    // Set initial tick step
    ui->plot->xAxis->setTickLabelColor(QColor(170,170,170));                              // Tick labels color
    ui->plot->yAxis->setTickLabelColor(QColor(170,170,170));                              // See QCustomPlot examples / styled demo

    //设置主、副网格属性（颜色、可见性）
    ui->plot->xAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::NoPen));
    ui->plot->yAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::NoPen));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::NoPen));
    ui->plot->xAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->grid()->setSubGridVisible(true);

    //设置x-y轴（颜色、箭头、鼠标拖拽、滚轮缩放）
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
}

///
/// \brief MainWindow::allocPlotGraph
/// 申请QCustemPlot图层编号
/// \return
///
int MainWindow::allocPlotGraph()
{
    //
    mapPlotGraph.insert(ui->plot->graphCount(),Qt::red);
    ui->plot->addGraph();

    return ui->plot->graphCount() - 1;
}

///
/// \brief MainWindow::getPlotGraphColor
/// 获取图层画笔颜色
/// \param num
/// \return
///
QColor MainWindow::getPlotGraphColor(int num)
{
    return mapPlotGraph.find(num).value();
}

///
/// \brief MainWindow::replot
/// 绘制2D图形界面
///
void MainWindow::replot()
{

    QMap<QString,disMavlinkMsg_t>::iterator j;

    QString f_msg_dield;

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

        //只有在建立连接的情况下，才能启动
        if(connected == true){
            updateTimer.start();                                                              // Start updating plot timer
            plotting = true;
            ui->stopPlotButton->setText("Stop Plot");
        }
    }
}
///
/// \brief on_saveDataLogButton_clicked
///
void MainWindow::on_saveDataLogButton_clicked()
{
    if(logging){
        logging = false;
        ui->saveDataLogButton->setText("Start Log");

        filePath.clear();

    }else{

        //get time
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy-MM-dd-hh-mm-ss");

        //选择路径
        QString filename = QFileDialog::getSaveFileName(this,tr("Save Log File"),current_date,tr("*.log"));
        if(!filename.isEmpty()){

            filePath = filename + ".log";
            QFile file(filePath);
            file.open( QIODevice::ReadWrite | QIODevice::Text );
            file.close();

            logging = true;
            ui->saveDataLogButton->setText("Stop Log");
        }
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
/// \brief MainWindow::on_actioncbox_axis_x_pointes_Changed
/// \param text
///
void MainWindow::cboxAxisXPointesChanged(const QString &text)
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
/// \brief MainWindow::setupTreeView
///
void MainWindow::setupTreeView()
{
    //QStandardItemModelei,负责组织数据,形成列表或者树,供其他视图类显示
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    model = new QStandardItemModel(ui->treeView);
    //设置水平栏
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Parameter")<<QStringLiteral("Unit")<<QStringLiteral("Value")<<QStringLiteral("Multi")<<QStringLiteral("Offset"));

    //关联项目属性改变的信号和槽
//    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(treeViewItemChanged(QStandardItem*)));
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
/// \brief MainWindow::treeviewRefresh
/// 定时刷新treeview表格
///
void MainWindow::treeviewRefresh()
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
                treeViewItemChanged(itemField,tt);
            }
        }
    }
}


///
/// \brief MainWindow::newMavlinkMsg
/// \param msg
///
void MainWindow::newMavlinkMsg(mavlink_message_t *msg)
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
/// \brief MainWindow::treeViewItemChanged
/// \param item
///

#define RANDOM_COLOR 1

void MainWindow::treeViewItemChanged(QStandardItem * item)
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
/// \brief MainWindow::treeViewItemChanged
/// \param item
/// \param t
///
void MainWindow::treeViewItemChanged(QStandardItem * item,disMavlinkMsg_t *t)
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
/* settingWindows */
/******************************************************************************************************************/

///
/// \brief MainWindow::on_actionCommLinks_triggered
///
void MainWindow::on_actionCommLinks_triggered()
{
    mCommSetting->show();
}

///
/// \brief MainWindow::on_actionTurning_triggered
///
void MainWindow::on_actionTurning_triggered()
{
    mTurningWindows->show();
}

///
/// \brief MainWindow::commConnect
///
void MainWindow::commConnect()
{
    //实例化一个工作线程
    if(mavlinkThread == NULL){
        mavlinkThread = new mavPraseThread();
    }

   //1.尝试连接硬件接口
    switch(mCommSetting->commlinkType)
    {
        //serial
        case HW_SERIAL:
        {

            //1.1连接成功,启动数据处理线程
            if(mavlinkThread->setupHardIf(mCommSetting->portInfo,
                                          mCommSetting->baudRate,
                                          mCommSetting->dataBits,
                                          mCommSetting->parity,
                                          mCommSetting->stopBits) == true) {

                //启动工作线程
                mavlinkThread->start();

                //界面提示
                mCommSetting->setCommLinkInfo(true);

                //启动plot刷新和treeview刷新
                startRefreshTimer();
            }
            //1.2连接失败,窗口显示错误信息
            else {

                //删除工作线程
                delete mavlinkThread;
                mavlinkThread = NULL;

                //界面提示
                mCommSetting->setCommLinkInfo(false);
            }

        }break;

        //udp
        case HW_UDP:
        {
                //设置socket 参数
                bool ret = mavlinkThread->setupHardIf(mCommSetting->udp_port);
                if(ret){
                    //启动工作线程
                    mavlinkThread->start();

                    //界面提示
                    mCommSetting->setCommLinkInfo(true);

                    //启动plot刷新和treeview刷新
                    startRefreshTimer();
                }else{

                    // 删除工作线程
                    delete mavlinkThread;
                    mavlinkThread = NULL;

                    //界面提示
                    mCommSetting->setCommLinkInfo(false);
                }

        }break;

        default:
        {
            ;
        }
    }
}

///
/// \brief MainWindow::commDisconnect
///
void MainWindow::commDisconnect()
{
    //删除一个工作线程
    if(mavlinkThread == NULL){
        return;
    }

    //1.关闭serial端口
    switch(mCommSetting->commlinkType)
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
    mCommSetting->setCommLinkInfo(false);

    //4.关闭界面刷新
    stopRefreshTimer();
}


/******************************************************************************************************************/
/* mouse event */
/******************************************************************************************************************/
void MainWindow::mousePress(QMouseEvent* mevent)
{ 
    if(mevent->button() == Qt::RightButton && plotting == false && connected == true)
    {
        rubberOrigin = mevent->pos();
        rubberBand->setGeometry(QRect(rubberOrigin, QSize()));
        rubberBand->show();
    }
}

void MainWindow::mouseMove(QMouseEvent *mevent)
{
    if(rubberBand->isVisible() && plotting == false && connected == true)
            rubberBand->setGeometry(QRect(rubberOrigin, mevent->pos()).normalized());
}

void MainWindow::mouseRelease(QMouseEvent *mevent)
{

    Q_UNUSED(mevent);
    if (rubberBand->isVisible() && plotting == false && connected == true)
    {
        const QRect zoomRect = rubberBand->geometry();
        int xp1, yp1, xp2, yp2;
        zoomRect.getCoords(&xp1, &yp1, &xp2, &yp2);
        double x1 = ui->plot->xAxis->pixelToCoord(xp1);
        double x2 = ui->plot->xAxis->pixelToCoord(xp2);
        double y1 = ui->plot->yAxis->pixelToCoord(yp1);
        double y2 = ui->plot->yAxis->pixelToCoord(yp2);

        ui->plot->xAxis->setRange(x1, x2);
        ui->plot->yAxis->setRange(y1, y2);

        rubberBand->hide();
        ui->plot->replot();
    }

    if(mevent->button() == Qt::LeftButton){
        int xx = ui->plot->xAxis->pixelToCoord(mevent->x());
        int yy = ui->plot->yAxis->pixelToCoord(mevent->y());
        QString coordinates("X: %1 Y: %2");
        coordinates = coordinates.arg(xx).arg(yy);
        ui->statusBar->showMessage(coordinates);
    }
}

