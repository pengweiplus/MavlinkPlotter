#include "turningWindows.h"
#include "ui_turningWindows.h"

turningWindows::turningWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::turningWindows)
{
    ui->setupUi(this);

    //实例化三轴模糊算法类
    fuzzyPidPolar = new algorithmFuzzyPid();
    fuzzyPidPitch = new algorithmFuzzyPid();
    fuzzyPidYaw = new algorithmFuzzyPid();

    //初始化模糊表空间
    setupFuzzyPidTabView(ROW,COL);

    //Slots
    connect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
    connect(ui->btn_fuzzy_pids_refresh_screen,SIGNAL(clicked()),this,SLOT(on_btn_fuzzy_pids_refresh_screen_clicked()));
    connect(ui->cbox_fuzzy_pids_axis_items,SIGNAL(currentIndexChanged(int)),this,SLOT(on_cbox_fuzzy_pids_axis_items_changed(int)));
    connect(ui->cbox_fuzzy_pids_ctrl_items,SIGNAL(currentIndexChanged(int)),this,SLOT(on_cbox_fuzzy_pids_ctrl_items_changed(int)));
    connect(ui->hs_fuzzy_pids_derror,SIGNAL(valueChanged(int)), this,SLOT(on_hs_fuzzy_pids_derror_changed(int)));
//    connect(ui->dsb_fuzzy_pids_derror,SIGNAL(valueChanged(double)), this,SLOT(on_dsb_fuzzy_pids_derror_changed(double)));

}

turningWindows::~turningWindows()
{
    delete ui;
}



//------Fuzzy Pids

///
/// \brief turningWindows::setupFuzzyPidTabview
/// 初始化模糊二维表格
/// \param fuzzy
/// \return
///
bool turningWindows::setupFuzzyPidTabView(int row,int col)
{
    row = row;

    //添加表头
    model = new QStandardItemModel();

    model->setColumnCount(col);

    QStringList labels = QObject::trUtf8("Error,NB,ZO,PB").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    labels = QObject::trUtf8("dError,NB,NM,NS,ZO,PS,PM,PB").simplified().split(",");
    model->setVerticalHeaderLabels(labels);

    //设置表格属性
    ui->tbv_fuzzy_pids_table->setModel(model);
    ui->tbv_fuzzy_pids_table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tbv_fuzzy_pids_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbv_fuzzy_pids_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    return true;
}

///
/// \brief turningWindows::setFuzzyPidTableView
/// 设置二维模糊表格值
/// \param tab
/// \return
///
bool turningWindows::setFuzzyPidTableView(struct algorithmFuzzyPid::fuzzyTable_t &tab,algorithmFuzzyPid::CTRL ctrl)
{
    //设置表格属性
    setupFuzzyPidTabView(tab.row,tab.col);

    //设置表格内容
    //添加ECdot、EECdot：
    for(int i = 0; i < tab.col; i++){

         for(int j = 0; j < tab.row; j++){

             //设置Edot(对应列表第一列)
             if(i==0){
                 int itemEdot = j+1;
                 //设置item数值
                 model->setItem(itemEdot,i,new QStandardItem( QString::number(tab.Edot[j],'f',1)));

                 //设置字符颜色
                 model->item(itemEdot,i)->setForeground(QBrush(QColor(255, 0, 0)));

                 //设置字符位置
                 model->item(itemEdot,i)->setTextAlignment(Qt::AlignCenter);
             }
             //设置ECdot（对应列表第一行）
             if(j==0){
                 int itemECdot = i+1;
                 //设置item数值
                 model->setItem(j,itemECdot,new QStandardItem( QString::number(tab.ECdot[i],'f',1)));

                 //设置字符颜色
                 model->item(j,itemECdot)->setForeground(QBrush(QColor(255, 0, 0)));

                 //设置字符位置
                 model->item(j,itemECdot)->setTextAlignment(Qt::AlignCenter);
             }
        }
    }

    /**************************设置模糊规则信息*****************************/
    for(int i = 0; i < tab.col; i++){
        //添加行信息：
         for(int j = 0; j < tab.row; j++){
             //设置模糊表

             //设置item数值
             if(algorithmFuzzyPid::CTRL_KP == ctrl) model->setItem(j+1,i+1,new QStandardItem( QString::number(tab.ptab[j][i],'f',1)));
             if(algorithmFuzzyPid::CTRL_KI == ctrl) model->setItem(j+1,i+1,new QStandardItem( QString::number(tab.itab[j][i],'f',1)));
             if(algorithmFuzzyPid::CTRL_KD == ctrl) model->setItem(j+1,i+1,new QStandardItem( QString::number(tab.dtab[j][i],'f',1)));

             //设置字符颜色
             model->item(j+1,i+1)->setForeground(QBrush(QColor(255, 255, 255)));

             //设置字符位置
             model->item(j+1,i+1)->setTextAlignment(Qt::AlignCenter);
        }
    }
    return true;
}

///
/// \brief turningWindows::getFuzzyPidTableView
/// 读取二维模糊表格值
/// \param tab
/// \return
///
bool turningWindows::getFuzzyPidTableView(struct algorithmFuzzyPid::fuzzyTable_t &tab,algorithmFuzzyPid::CTRL ctrl)
{
    //读取行、列
    tab.col = model->columnCount()-1;
    tab.row = model->rowCount()-1;

    //读取ECdot、EECdot：
    for(int i = 0; i < tab.col; i++){

         for(int j = 0; j < tab.row; j++){

             //读取Edot(对应列表第一列)
             if(i==0){
                 int itemEdot = j+1;
                 //读取item数值
                 tab.Edot[j] = model->item(itemEdot,i)->text().toFloat();
             }
             //读取ECdot（对应列表第一行）
             if(j==0){
                 int itemECdot = i+1;
                 //读取item数值
                 tab.ECdot[i] =  model->item(j,itemECdot)->text().toFloat();
             }
        }
    }

    //读取模糊规则信息
    for(int i = 0; i < tab.col; i++){

         for(int j = 0; j < tab.row; j++){
             //读取item数值
             if(algorithmFuzzyPid::CTRL_KP == ctrl)tab.ptab[j][i] = model->item(j+1,i+1)->text().toFloat();
             if(algorithmFuzzyPid::CTRL_KI == ctrl)tab.itab[j][i] = model->item(j+1,i+1)->text().toFloat();
             if(algorithmFuzzyPid::CTRL_KD == ctrl)tab.dtab[j][i] = model->item(j+1,i+1)->text().toFloat();
        }
    }
    return true;
}

///
/// \brief turningWindows::plotGraph
/// \param obj
/// \param derror
///
void turningWindows::plotGraph(algorithmFuzzyPid &obj,double derror)
{
    algorithmFuzzyPid::fuzzyTable_t tab;

    //获取模糊表数据
    obj.getFuzzyTableData(tab);

    //清除现有图层
    for(int i = ui->cpl_fuzzy_pids_graph->graphCount(); i >= 0;i--){
        ui->cpl_fuzzy_pids_graph->removeGraph(i);
    }

    ui->cpl_fuzzy_pids_graph->clearItems();                                         // Remove everything from the plot
    ui->cpl_fuzzy_pids_graph->yAxis->setTickStep(10);                               // Set tick step according to user spin box
    ui->cpl_fuzzy_pids_graph->yAxis->setRange(0, tab.ECdot[tab.col-1]);  // Set lower and upper plot range
    ui->cpl_fuzzy_pids_graph->xAxis->setRange(tab.Edot[0], tab.Edot[tab.row-1]);    // Set x axis range for specified number of points
    ui->cpl_fuzzy_pids_graph->setPlottingHints(QCP::phFastPolylines);               // Graph/Curve lines are drawn with a faster method.
    ui->cpl_fuzzy_pids_graph->xAxis->setLabel("Error");
    ui->cpl_fuzzy_pids_graph->yAxis->setLabel("Val");

    //增加图层
    ui->cpl_fuzzy_pids_graph->addGraph();
    ui->cpl_fuzzy_pids_graph->addGraph();
    ui->cpl_fuzzy_pids_graph->addGraph();

    //按照颜色绘制实时数据
    for(float x = tab.Edot[0];x < tab.Edot[tab.row-1];x+=0.1){

            //设定微分项
            float y1 = derror;

            //模糊计算
            obj.getFuzzy(obj,x,y1);
            obj.getFuzzyTableData(tab);


            /****************KP***************/
            //设置颜色、线宽
            QPen graphPen(Qt::red);
            graphPen.setWidthF(1.5);
            graphPen.setStyle(Qt::SolidLine);
            graphPen.setColor(Qt::red);

            //绘制x-y曲线
            ui->cpl_fuzzy_pids_graph->graph(0)->setPen(graphPen);
            ui->cpl_fuzzy_pids_graph->graph(0)->addData(x,tab.kp);
            ui->cpl_fuzzy_pids_graph->replot(QCustomPlot::rpQueued);

            /****************KP***************/
            //设置颜色、线宽
            QPen graphPen1(Qt::blue);
            graphPen.setWidthF(1.5);
            graphPen.setStyle(Qt::SolidLine);
            graphPen.setColor(Qt::red);

            //绘制x-y曲线
            ui->cpl_fuzzy_pids_graph->graph(1)->setPen(graphPen1);
            ui->cpl_fuzzy_pids_graph->graph(1)->addData(x,tab.ki);
            ui->cpl_fuzzy_pids_graph->replot(QCustomPlot::rpQueued);

            /****************KD***************/
            //设置颜色、线宽
            QPen graphPen2(Qt::green);
            graphPen.setWidthF(1.5);
            graphPen.setStyle(Qt::SolidLine);
            graphPen.setColor(Qt::red);

            //绘制x-y曲线
            ui->cpl_fuzzy_pids_graph->graph(2)->setPen(graphPen2);
            ui->cpl_fuzzy_pids_graph->graph(2)->addData(x,tab.kd);
            ui->cpl_fuzzy_pids_graph->replot(QCustomPlot::rpQueued);

    }
}


//------Basic Pids

///
/// \brief turningWindows::getBasicPidsParams
/// \param polar
/// \param pitch
/// \param yaw
///
void turningWindows::getBasicPidsParams(struct algorithmFuzzyPid::fuzzyParams_t &polar,
                                        struct algorithmFuzzyPid::fuzzyParams_t &pitch,
                                        struct algorithmFuzzyPid::fuzzyParams_t &yaw)
{
    //polar
    polar.kp = ui->dsb_basic_pids_polar_kp->value();
    polar.ki = ui->dsb_basic_pids_polar_ki->value();
    polar.kd = ui->dsb_basic_pids_polar_kd->value();
    polar.kf = 0;
    polar.i_max = ui->dsb_basic_pids_polar_i_max->value();
    polar.i_threshold = ui->dsb_basic_pids_polar_i_dz->value();
    polar.o_max = ui->dsb_basic_pids_polar_o_max->value();
    polar.fCut = ui->dsb_basic_pids_polar_lpf_fcut->value();

    //pitch
    pitch.kp = ui->dsb_basic_pids_pitch_kp->value();
    pitch.ki = ui->dsb_basic_pids_pitch_ki->value();
    pitch.kd = ui->dsb_basic_pids_pitch_kd->value();
    pitch.kf = 0;
    pitch.i_max = ui->dsb_basic_pids_pitch_i_max->value();
    pitch.i_threshold = ui->dsb_basic_pids_pitch_i_dz->value();
    pitch.o_max = ui->dsb_basic_pids_pitch_o_max->value();
    pitch.fCut = ui->dsb_basic_pids_pitch_lpf_fcut->value();

    //yaw
    yaw.kp = ui->dsb_basic_pids_yaw_kp->value();
    yaw.ki = ui->dsb_basic_pids_yaw_ki->value();
    yaw.kd = ui->dsb_basic_pids_yaw_kd->value();
    yaw.kf = 0;
    yaw.i_max = ui->dsb_basic_pids_yaw_i_max->value();
    yaw.i_threshold = ui->dsb_basic_pids_yaw_i_dz->value();
    yaw.o_max = ui->dsb_basic_pids_yaw_o_max->value();
    yaw.fCut = ui->dsb_basic_pids_yaw_lpf_fcut->value();
}

///
/// \brief turningWindows::setBasicPidsParams
/// \param polar 极化轴PID参数
/// \param pitch 俯仰轴PID参数
/// \param yaw   方位轴PID参数
///
void turningWindows::setBasicPidsParams(struct algorithmFuzzyPid::fuzzyParams_t &polar,
                                        struct algorithmFuzzyPid::fuzzyParams_t &pitch,
                                        struct algorithmFuzzyPid::fuzzyParams_t &yaw)
{
    //polar
    ui->dsb_basic_pids_polar_kp->setValue(polar.kp);
    ui->dsb_basic_pids_polar_ki->setValue(polar.ki);
    ui->dsb_basic_pids_polar_kd->setValue(polar.kd);
    ui->dsb_basic_pids_polar_i_max->setValue(polar.i_max);
    ui->dsb_basic_pids_polar_i_dz->setValue(polar.i_threshold);
    ui->dsb_basic_pids_polar_o_max->setValue(polar.o_max);
    ui->dsb_basic_pids_polar_lpf_fcut->setValue(polar.fCut);

    //pitch
    ui->dsb_basic_pids_pitch_kp->setValue(pitch.kp);
    ui->dsb_basic_pids_pitch_ki->setValue(pitch.ki);
    ui->dsb_basic_pids_pitch_kd->setValue(pitch.kd);
    ui->dsb_basic_pids_pitch_i_max->setValue(pitch.i_max);
    ui->dsb_basic_pids_pitch_i_dz->setValue(pitch.i_threshold);
    ui->dsb_basic_pids_pitch_o_max->setValue(pitch.o_max);
    ui->dsb_basic_pids_pitch_lpf_fcut->setValue(pitch.fCut);

    //yaw
    ui->dsb_basic_pids_yaw_kp->setValue(yaw.kp);
    ui->dsb_basic_pids_yaw_ki->setValue(yaw.ki);
    ui->dsb_basic_pids_yaw_kd->setValue(yaw.kd);
    ui->dsb_basic_pids_yaw_i_max->setValue(yaw.i_max);
    ui->dsb_basic_pids_yaw_i_dz->setValue(yaw.i_threshold);
    ui->dsb_basic_pids_yaw_o_max->setValue(yaw.o_max);
    ui->dsb_basic_pids_yaw_lpf_fcut->setValue(yaw.fCut);
}


//------Logic

///
/// \brief turningWindows::saveFuzzyDataAndReplotGraph
/// 1、保存界面模糊表格、参数到对应存储的数据结构中；
/// 2、重新绘制图形
///
void turningWindows::saveFuzzyDataAndReplotGraph()
{
    //获取当前选中的控制轴(Polar/Pitch/Yaw)
    int axis = ui->cbox_fuzzy_pids_axis_items->currentIndex();
    //获取当前选中的控制条目（KP/KI/KD）
    int ctrl = ui->cbox_fuzzy_pids_ctrl_items->currentIndex();
    //获取滑动条的微分值
    double derror = ui->dsb_fuzzy_pids_derror->value();

    //设置模糊表格&绘制图形
    algorithmFuzzyPid::fuzzyTable_t tab;
    algorithmFuzzyPid::fuzzyParams_t polar,pitch,yaw;

    //从pid参数界面中读取数据并保存到对应数据结构
    getBasicPidsParams(polar,pitch,yaw);
    fuzzyPidPolar->setParams(polar);
    fuzzyPidPitch->setParams(pitch);
    fuzzyPidYaw->setParams(yaw);

    //从表格中读取模糊表格数据并保存到对应数据结构
    getFuzzyPidTableView(tab,(algorithmFuzzyPid::CTRL)ctrl);

    switch (axis) {
        //rx polar
        case 0:{
            fuzzyPidPolar->setFuzzyTable(tab,(algorithmFuzzyPid::CTRL)ctrl);
            //重新绘制2D图形
            plotGraph(*fuzzyPidPolar,derror);

        }break;
        //rx pitch
        case 1:{
            fuzzyPidPitch->setFuzzyTable(tab,(algorithmFuzzyPid::CTRL)ctrl);
            //重新绘制2D图形
            plotGraph(*fuzzyPidPitch,derror);
        }break;
        //rx yaw
        case 2:{
            fuzzyPidYaw->setFuzzyTable(tab,(algorithmFuzzyPid::CTRL)ctrl);
            //重新绘制2D图形
            plotGraph(*fuzzyPidYaw,derror);
        }break;

        default:{}break;
    }
}

///
/// \brief turningWindows::loadFuzzyDataAndReplotGraph
/// 1、对应存储的数据，设置到模糊表格、参数界面；
/// 2、重新绘制图形
///
void turningWindows::loadFuzzyDataAndReplotGraph()
{
    //获取当前选中的控制轴(Polar/Pitch/Yaw)
    int axis = ui->cbox_fuzzy_pids_axis_items->currentIndex();
    //获取当前选中的控制条目（KP/KI/KD）
    int ctrl = ui->cbox_fuzzy_pids_ctrl_items->currentIndex();
    //获取滑动条的微分值
    double derror = ui->dsb_fuzzy_pids_derror->value();

    //设置模糊表格&绘制图形
    algorithmFuzzyPid::fuzzyTable_t tab;
    algorithmFuzzyPid::fuzzyParams_t polar,pitch,yaw;

    //从pid数据结构中读取数据并写入到对应参数界面
    fuzzyPidPolar->getParams(polar);
    fuzzyPidPitch->getParams(pitch);
    fuzzyPidYaw->getParams(yaw);
    setBasicPidsParams(polar,pitch,yaw);

    //从表格数据结构中读取数据并保存到对应模糊表格界面
    switch (axis) {
        //rx polar
        case 0:{
            fuzzyPidPolar->getFuzzyTableData(tab);
            //重新绘制2D图形
            plotGraph(*fuzzyPidPolar,derror);

        }break;
        //rx pitch
        case 1:{
            fuzzyPidPitch->getFuzzyTableData(tab);
            //重新绘制2D图形
            plotGraph(*fuzzyPidPitch,derror);
        }break;
        //rx yaw
        case 2:{
            fuzzyPidYaw->getFuzzyTableData(tab);
            //重新绘制2D图形
            plotGraph(*fuzzyPidYaw,derror);
        }break;

        default:{}break;
    }
    setFuzzyPidTableView(tab,(algorithmFuzzyPid::CTRL)ctrl);
}

//-------pravate slots

///
/// \brief turningWindows::on_tbv_fuzzy_pids_table_changed
/// 槽函数：修改模糊表格
/// 1、保存修改后的值到对应数据结构
/// 2、重新绘制图形
///
void turningWindows::on_tbv_fuzzy_pids_table_changed()
{
    //保存参数到数据结构，并重新绘制图形
    saveFuzzyDataAndReplotGraph();
}

///
/// \brief turningWindows::on_btn_fuzzy_pids_refresh_screen_clicked
/// 槽函数：读取下位机数据
/// 1、将接收到的数据更新到对应数据结构中
/// 2、重新绘制图形
///
void turningWindows::on_btn_fuzzy_pids_refresh_screen_clicked()
{

}


///
/// \brief turningWindows::on_cbox_fuzzy_pids_axis_items_changed
/// 槽函数：控制轴更新
/// 1、从对应数据结构中读取出数据
/// 2、重新绘制图形
///
void turningWindows::on_cbox_fuzzy_pids_axis_items_changed(int index)
{
    index= index;
    disconnect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
    loadFuzzyDataAndReplotGraph();
    connect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
}

///
/// \brief turningWindows::on_cbox_fuzzy_pids_ctrl_items_changed
/// 槽函数：控制条目更新
/// 1、从对应数据结构中读取出数据
/// 2、重新绘制图形
///
void turningWindows::on_cbox_fuzzy_pids_ctrl_items_changed(int index)
{
    index = index;
    disconnect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
    loadFuzzyDataAndReplotGraph();
    connect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
}

///
/// \brief turningWindows::on_hs_fuzzy_pids_derror_changed
/// \param val
/// 槽函数：微分值手动更新
/// 1、从对应数据结构中读取出数据
/// 2、重新绘制图形
///
void turningWindows::on_hs_fuzzy_pids_derror_changed(int val)
{
    double derror = val/10.0;
    ui->dsb_fuzzy_pids_derror->setValue(derror);

    //获取当前选中的控制轴(Polar/Pitch/Yaw)
    int axis = ui->cbox_fuzzy_pids_axis_items->currentIndex();

    //重新绘制2D图形
    switch (axis) {
        //rx polar
        case 0:{plotGraph(*fuzzyPidPolar,derror);}break;
        //rx pitch
        case 1:{plotGraph(*fuzzyPidPitch,derror);}break;
        //rx yaw
        case 2:{plotGraph(*fuzzyPidYaw,derror);}break;

        default:{}break;
    }
}

///
/// \brief turningWindows::on_dsb_fuzzy_pids_derror_changed
/// \param val
///
void turningWindows::on_dsb_fuzzy_pids_derror_changed(double val)
{
    int tmp = val*10;

    ui->hs_fuzzy_pids_derror->setValue(tmp);

    //获取当前选中的控制轴(Polar/Pitch/Yaw)
    int axis = ui->cbox_fuzzy_pids_axis_items->currentIndex();

    //重新绘制2D图形
    switch (axis) {
        //rx polar
        case 0:{plotGraph(*fuzzyPidPolar,val);}break;
        //rx pitch
        case 1:{plotGraph(*fuzzyPidPitch,val);}break;
        //rx yaw
        case 2:{plotGraph(*fuzzyPidYaw,val);}break;

        default:{}break;
    }
}
