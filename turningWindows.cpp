#include "turningWindows.h"
#include "ui_turningWindows.h"

turningWindows::turningWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::turningWindows)
{
    ui->setupUi(this);

    //setup data struct
    setupAlgorithmFuzzyPid(rx_polar);
    setupAlgorithmFuzzyPid(rx_pitch);
    setupAlgorithmFuzzyPid(rx_yaw);
    //获取basic pids
    getBasicPidsParams(rx_polar.params,rx_pitch.params,rx_yaw.params);

    //setup fuzzy TableView
    setupFuzzyPidTabView(7,3);

    setFuzzyTableAndReplotGraph();

    //Slots
    connect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
    connect(ui->btn_fuzzy_pids_refresh_screen,SIGNAL(clicked()),this,SLOT(on_btn_fuzzy_pids_refresh_screen_clicked()));
    connect(ui->cbox_fuzzy_pids_axis_items,SIGNAL(currentIndexChanged(int)),this,SLOT(on_cbox_fuzzy_pids_axis_items_changed(int)));
    connect(ui->cbox_fuzzy_pids_ctrl_items,SIGNAL(currentIndexChanged(int)),this,SLOT(on_cbox_fuzzy_pids_ctrl_items_changed(int)));

}

turningWindows::~turningWindows()
{
    delete ui;
}

///
/// \brief turningWindows::setupAlgorithmFuzzyPid
/// \param fuzzy
/// 初始化模糊PID算法数据结构
/// \return
///
bool turningWindows::setupAlgorithmFuzzyPid(struct algorithm_fuzzy_pid_t &fuzzy)
{

    //设置模糊二维表大小
    fuzzy.tab.col = 3;
    fuzzy.tab.row = 7;

    //设置偏差微分段
    float arrEdot[7] = {-EB,-EM,-ES,EO,ES,EM,EB};
    float arrECdot[3] = {-EEB,EEO,EEB};
    memcpy(fuzzy.tab.Edot,arrEdot,sizeof(arrEdot));
    memcpy(fuzzy.tab.ECdot,arrECdot,sizeof(arrECdot));

    //设置P表
    float arrptab[7][3] = { {NB ,NB ,NS},						/* 比例表 */
                            {NB ,NM ,NS},
                            {NM ,NM ,ZO},
                            {NS ,ZO ,PS},
                            {ZO ,PM ,PM},
                            {PS ,PM ,PB},
                            {PS ,PB ,PB} };
    memcpy(fuzzy.tab.ptab,arrptab,sizeof(arrptab));


    //设置I表
    float arritab[7][3] = { {3 ,4 ,3},};
    memcpy(fuzzy.tab.itab,arritab,sizeof(arritab));


    //设置D表
    float arrdtab[7][3] ={ {NB ,NM ,ZO},						/* 微分表 */
                           {NB ,NM ,ZO},
                           {NM ,NS ,ZO},
                           {NS ,ZO ,PS},
                           {ZO ,PS ,PM},
                           {ZO ,PM ,PB},
                           {ZO ,PM ,PB} };
    memcpy(fuzzy.tab.dtab,arrdtab,sizeof(arrdtab));

    return true;
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
    //添加表头
    model = new QStandardItemModel();

    model->setColumnCount(col);

    QStringList labels = QObject::trUtf8("Error,NB,ZO,PB").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    labels = QObject::trUtf8("dError,NB,NM,NS,ZO,PS,PM,PB").simplified().split(",");
    model->setVerticalHeaderLabels(labels);

    return true;
}

///
/// \brief turningWindows::setFuzzyPidTable
/// 设置二维模糊表格值
/// \param fuzzy
/// \return
///
bool turningWindows::setFuzzyPidTable(struct algorithm_fuzzy_pid_t &fuzzy)
{

    //设置表格属性
    ui->tbv_fuzzy_pids_table->setModel(model);
    ui->tbv_fuzzy_pids_table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tbv_fuzzy_pids_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tbv_fuzzy_pids_table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //添加ECdot、EECdot：
    for(int i = 0; i < fuzzy.tab.col; i++){

         for(int j = 0; j < fuzzy.tab.row; j++){

             //设置Edot(对应列表第一列)
             if(i==0){
                 int itemEdot = j+1;
                 //设置item数值
                 model->setItem(itemEdot,i,new QStandardItem( QString::number(fuzzy.tab.Edot[j],'f',1)));

                 //设置字符颜色
                 model->item(itemEdot,i)->setForeground(QBrush(QColor(255, 0, 0)));

                 //设置字符位置
                 model->item(itemEdot,i)->setTextAlignment(Qt::AlignCenter);
             }
             //设置ECdot（对应列表第一行）
             if(j==0){
                 int itemECdot = i+1;
                 //设置item数值
                 model->setItem(j,itemECdot,new QStandardItem( QString::number(fuzzy.tab.ECdot[i],'f',1)));

                 //设置字符颜色
                 model->item(j,itemECdot)->setForeground(QBrush(QColor(255, 0, 0)));

                 //设置字符位置
                 model->item(j,itemECdot)->setTextAlignment(Qt::AlignCenter);
             }
        }
    }

    //设置模糊规则信息
    for(int i = 0; i < fuzzy.tab.col; i++){
        //添加行信息：
         for(int j = 0; j < fuzzy.tab.row; j++){
             //设置模糊表

             //设置item数值
             model->setItem(j+1,i+1,new QStandardItem( QString::number(fuzzy.tab.ptab[j][i],'f',1)));

             //设置字符颜色
             model->item(j+1,i+1)->setForeground(QBrush(QColor(255, 255, 255)));

             //设置字符位置
             model->item(j+1,i+1)->setTextAlignment(Qt::AlignCenter);
        }
    }
    return true;
}

///
/// \brief turningWindows::getFuzzyPidTable
/// 读取二维模糊表格值
/// \param fuzzy
/// \return
///
bool turningWindows::getFuzzyPidTable(struct algorithm_fuzzy_pid_t &fuzzy)
{
    //读取ECdot、EECdot：
    for(int i = 0; i < fuzzy.tab.col; i++){

         for(int j = 0; j < fuzzy.tab.row; j++){

             //读取Edot(对应列表第一列)
             if(i==0){
                 int itemEdot = j+1;
                 //读取item数值
                 fuzzy.tab.Edot[j] = model->item(itemEdot,i)->text().toFloat();
             }
             //读取ECdot（对应列表第一行）
             if(j==0){
                 int itemECdot = i+1;
                 //读取item数值
                 fuzzy.tab.ECdot[i] =  model->item(j,itemECdot)->text().toFloat();
             }
        }
    }

    //读取模糊规则信息
    for(int i = 0; i < fuzzy.tab.col; i++){

         for(int j = 0; j < fuzzy.tab.row; j++){
             //读取item数值
             fuzzy.tab.ptab[j][i] = model->item(j+1,i+1)->text().toFloat();
        }
    }
    return true;
}

//------Basic Pids

///
/// \brief turningWindows::getBasicPidsParams
/// \param polar
/// \param pitch
/// \param yaw
///
void turningWindows::getBasicPidsParams(struct fuzzy_pid_params_t &polar,struct fuzzy_pid_params_t &pitch,struct fuzzy_pid_params_t &yaw)
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
void turningWindows::setBasicPidsParams(struct fuzzy_pid_params_t &polar,struct fuzzy_pid_params_t &pitch,struct fuzzy_pid_params_t &yaw)
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
/// \brief turningWindows::plotGraphSimulator
/// \param fuzzy
/// \param item
///
void turningWindows::plotGraphSimulator(struct algorithm_fuzzy_pid_t &fuzzy,int item)
{
    //Remove all Graph
    for(int i = ui->cpl_fuzzy_pids_graph->graphCount(); i >= 0;i--){
        ui->cpl_fuzzy_pids_graph->removeGraph(i);
    }

    ui->cpl_fuzzy_pids_graph->clearItems();                                                           // Remove everything from the plot
    ui->cpl_fuzzy_pids_graph->yAxis->setTickStep(10);                                                 // Set tick step according to user spin box
    ui->cpl_fuzzy_pids_graph->yAxis->setRange(fuzzy.tab.ECdot[0], fuzzy.tab.ECdot[fuzzy.tab.col-1]);  // Set lower and upper plot range
    ui->cpl_fuzzy_pids_graph->xAxis->setRange(fuzzy.tab.Edot[0], fuzzy.tab.Edot[fuzzy.tab.row-1]);    // Set x axis range for specified number of points
    ui->cpl_fuzzy_pids_graph->setPlottingHints(QCP::phFastPolylines);                                 // Graph/Curve lines are drawn with a faster method.
    ui->cpl_fuzzy_pids_graph->xAxis->setLabel("Error");
    ui->cpl_fuzzy_pids_graph->yAxis->setLabel("dError");

    float eecdot[3] = {EES,EEM,EEB};
    //按照颜色绘制实时数据
    for(float x = fuzzy.tab.Edot[0];x < fuzzy.tab.Edot[fuzzy.tab.row-1];x+=0.1){

        for(int i = 0; i<3 ;i++){
            //设定微分项
            float y1 = eecdot[i];

            //模糊计算
            fuzzy_out(fuzzy,x,y1);

            //设置颜色、线宽
            QPen graphPen(Qt::red);
            graphPen.setWidthF(1.5);
            graphPen.setStyle(Qt::SolidLine);
            if(i == 0){graphPen.setColor(Qt::red);}
            else if(i == 1){ graphPen.setColor(Qt::blue);}
            else { graphPen.setColor(Qt::green);}

            //增加图层
            ui->cpl_fuzzy_pids_graph->addGraph();

            //绘制x-y曲线
            ui->cpl_fuzzy_pids_graph->graph(i*2)->setPen(graphPen);

            if(item == 0) ui->cpl_fuzzy_pids_graph->graph(i*2)->addData(x,fuzzy.tab.kp);
            if(item == 1) ui->cpl_fuzzy_pids_graph->graph(i*2)->addData(x,fuzzy.tab.ki);
            if(item == 2) ui->cpl_fuzzy_pids_graph->graph(i*2)->addData(x,fuzzy.tab.kd);

            //设定微分项
            float y2 = -y1;

            //模糊计算
            fuzzy_out(fuzzy,x,y2);

            //增加图层
            ui->cpl_fuzzy_pids_graph->addGraph();

            //绘制x-y曲线
            graphPen.setStyle(Qt::DotLine);
            ui->cpl_fuzzy_pids_graph->graph(i*2+1)->setPen(graphPen);
            if(item == 0) ui->cpl_fuzzy_pids_graph->graph(i*2+1)->addData(x,-fuzzy.tab.kp);
            if(item == 1) ui->cpl_fuzzy_pids_graph->graph(i*2+1)->addData(x,-fuzzy.tab.ki);
            if(item == 2) ui->cpl_fuzzy_pids_graph->graph(i*2+1)->addData(x,-fuzzy.tab.kd);

            ui->cpl_fuzzy_pids_graph->replot(QCustomPlot::rpQueued);
        }
    }
}

///
/// \brief turningWindows::fuzzy_out
/// \param pid
/// \param error
/// \param delta_error
///
void turningWindows::fuzzy_out(struct algorithm_fuzzy_pid_t &pid,float error,float delta_error)
{
   unsigned char  i,j;
   float psum=0.0,isum=0.0,dsum=0.0;
   float l_BP[10]={0,0,0,0,0,0,0,0,0,0};
   float l_BD[10]={0,0,0,0,0,0,0,0,0,0};

   /* 确定偏差位置 */
   for(i=0; i<pid.tab.row; i++){

     if(error <= pid.tab.Edot[i]) break;

   }

   /*
    * 偏差位置分为两种情况(线性化处理偏差)
    * 1. 处于两头
    * 2. 处于中间
    */
   if(i==0)l_BP[0]=100;
   else if(i == pid.tab.row ) l_BP[pid.tab.row-1] = 100;
   else if(i > 0 && i<pid.tab.row){

     l_BP[i] 	= (float)100.0*(error-pid.tab.Edot[i-1])/(pid.tab.Edot[i]-pid.tab.Edot[i-1]);
     l_BP[i-1]	= (float)100.0*(pid.tab.Edot[i]-error)/(pid.tab.Edot[i]-pid.tab.Edot[i-1]);

   }

   /* 确定微分位置 */
   for(j=0;j<pid.tab.col;j++){

     if(delta_error<=pid.tab.ECdot[j])break;

   }

   /*
    * 微分位置分为两种情况(线性化处理偏差)
    * 1. 处于两头
    * 2. 处于中间
    */
   if(j==0)l_BD[0]=100;
   else if(j==pid.tab.col) l_BD[pid.tab.col-1]=100;
   else if(j>0 && j<pid.tab.col){

     l_BD[j]   = (float)100.0*(delta_error-pid.tab.ECdot[j-1])/(pid.tab.ECdot[j]-pid.tab.ECdot[j-1]);
     l_BD[j-1] = (float)100.0*(pid.tab.ECdot[j]-delta_error)/(pid.tab.ECdot[j]-pid.tab.ECdot[j-1]);

   }

   /*
    * 合成输出
    */
   for(i=0; i<pid.tab.row; i++){

     for(j=0; j<pid.tab.col; j++){

       psum+=(float)l_BP[i] * l_BD[j] * (pid.tab.ptab[i][j]);
       isum+=(float)l_BP[i] * l_BD[j] * (pid.tab.itab[i][j]);
       dsum+=(float)l_BP[i] * l_BD[j] * (pid.tab.dtab[i][j]);

     }
   }

   pid.tab.kp = pid.params.kp * (psum/1000000.0);
//	   pid.tab.ki = pid.params.ki * (isum/1000000.0);
   pid.tab.ki = pid.params.ki;
   pid.tab.kd = pid.params.kd * (dsum/1000000.0);
}

///
/// \brief turningWindows::setFuzzyTableAndReplotGraph
///
void turningWindows::setFuzzyTableAndReplotGraph()
{
    switch (ui->cbox_fuzzy_pids_ctrl_items->currentIndex()) {
    case 0://rx polar
        //update table
        setFuzzyPidTable(rx_polar);

        //update Graph
        plotGraphSimulator(rx_polar,ui->cbox_fuzzy_pids_ctrl_items->currentIndex());
        break;

    case 1://rx pitch
        //update table
        setFuzzyPidTable(rx_pitch);

        //update Graph
        plotGraphSimulator(rx_pitch,ui->cbox_fuzzy_pids_ctrl_items->currentIndex());
        break;

    case 2://rx yaw
        //update table
        setFuzzyPidTable(rx_yaw);

        //update Graph
        plotGraphSimulator(rx_yaw,ui->cbox_fuzzy_pids_ctrl_items->currentIndex());
        break;

    default:
        break;
    }
}

//-------slots

///
/// \brief turningWindows::on_tbv_fuzzy_pids_table_changed
///
void turningWindows::on_tbv_fuzzy_pids_table_changed()
{
    switch (ui->cbox_fuzzy_pids_ctrl_items->currentIndex()) {
    case 0://rx polar
        //update table
        getFuzzyPidTable(rx_polar);

        //update Graph
        plotGraphSimulator(rx_polar,ui->cbox_fuzzy_pids_ctrl_items->currentIndex());
        break;

    case 1://rx pitch
        //update table
        getFuzzyPidTable(rx_pitch);

        //update Graph
        plotGraphSimulator(rx_pitch,ui->cbox_fuzzy_pids_ctrl_items->currentIndex());
        break;

    case 2://rx yaw
        //update table
        getFuzzyPidTable(rx_yaw);

        //update Graph
        plotGraphSimulator(rx_yaw,ui->cbox_fuzzy_pids_ctrl_items->currentIndex());
        break;

    default:
        break;
    }
}

///
/// \brief turningWindows::on_btn_fuzzy_pids_refresh_screen_clicked
///
void turningWindows::on_btn_fuzzy_pids_refresh_screen_clicked()
{

}


///
/// \brief turningWindows::on_cbox_fuzzy_pids_axis_items_changed
///
void turningWindows::on_cbox_fuzzy_pids_axis_items_changed(int index)
{
    disconnect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
    setFuzzyTableAndReplotGraph();
    connect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
}

///
/// \brief turningWindows::on_cbox_fuzzy_pids_ctrl_items_changed
///
void turningWindows::on_cbox_fuzzy_pids_ctrl_items_changed(int index)
{
    disconnect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
    setFuzzyTableAndReplotGraph();
    connect(ui->tbv_fuzzy_pids_table->model(),SIGNAL(itemChanged(QStandardItem*)),this,SLOT(on_tbv_fuzzy_pids_table_changed()));
}
