#include "algorithmFuzzyPid.h"

algorithmFuzzyPid::algorithmFuzzyPid()
{
    setAllDefault();
}

///
/// \brief algorithmFuzzyPid::setAllDefault
/// 设置默认数据参数
/// \return
///
bool algorithmFuzzyPid::setAllDefault()
{
    /*********************************设置模糊表******************************/
    //设置模糊二维表大小
    table.col = COL;
    table.row = ROW;

    //设置偏差微分段
    float arrEdot[ROW] = {-EB,-EM,-ES,EO,ES,EM,EB};
    float arrECdot[COL] = {-EEB,EEO,EEB};
    memcpy(table.Edot,arrEdot,sizeof(arrEdot));
    memcpy(table.ECdot,arrECdot,sizeof(arrECdot));

    //设置P表
    float arrptab[ROW][COL] = { {NB ,NB ,NS},						/* 比例表 */
                            {NB ,NM ,NS},
                            {NM ,NM ,ZO},
                            {NS ,ZO ,PS},
                            {ZO ,PM ,PM},
                            {PS ,PM ,PB},
                            {PS ,PB ,PB} };
    memcpy(table.ptab,arrptab,sizeof(arrptab));


    //设置I表
    float arritab[ROW][COL] = { {NB ,NB ,NS},						/* 积分表 */
                                {NB ,NM ,NS},
                                {NM ,NM ,ZO},
                                {NS ,ZO ,PS},
                                {ZO ,PM ,PM},
                                {PS ,PM ,PB},
                                {PS ,PB ,PB} };
    memcpy(table.itab,arritab,sizeof(arritab));


    //设置D表
    float arrdtab[ROW][COL] ={ {NB ,NM ,ZO},						/* 微分表 */
                           {NB ,NM ,ZO},
                           {NM ,NS ,ZO},
                           {NS ,ZO ,PS},
                           {ZO ,PS ,PM},
                           {ZO ,PM ,PB},
                           {ZO ,PM ,PB} };
    memcpy(table.dtab,arrdtab,sizeof(arrdtab));

    /*********************************设置PID参数******************************/
    params.kp = KP;
    params.ki = KI;
    params.kd = KD;
    params.kf = KF;
    params.fCut = F_CUT;
    params.i_max = I_MAX;
    params.i_threshold = I_DZ;
    params.o_max = O_MAX;

    return true;
}

///
/// \brief algorithmFuzzyPid::setFuzzyTable
/// 设置模糊表
/// \param tab
/// \return
///
bool algorithmFuzzyPid::setFuzzyTable(struct fuzzyTable_t &tab)
{
    if(&tab == NULL) return false;

    memcpy(&table,&tab,sizeof(struct fuzzyTable_t));

    return true;
}

///
/// \brief algorithmFuzzyPid::setFuzzyTable
/// 设置模糊表
/// \param tab
/// \param ctrl
/// \return
///
bool algorithmFuzzyPid::setFuzzyTable(struct fuzzyTable_t &tab,enum CTRL ctrl)
{
    if(&tab == NULL) return false;

    switch (ctrl) {
    case CTRL_KP:
        memcpy(&table.ptab,&tab.ptab,sizeof(tab.ptab));
        break;
    case CTRL_KI:
         memcpy(&table.itab,&tab.itab,sizeof(tab.itab));
        break;
    case CTRL_KD:
         memcpy(&table.dtab,&tab.dtab,sizeof(tab.dtab));
        break;
    default:
        break;
    }

    return true;
}

///
/// \brief algorithmFuzzyPid::getFuzzyTableData
/// 读取模糊表
/// \param tab
/// \return
///
bool algorithmFuzzyPid::getFuzzyTableData(struct fuzzyTable_t &tab)
{
    if(&tab == NULL) return false;

    memcpy(&tab,&table,sizeof(struct fuzzyTable_t));
    return true;
}

///
/// \brief algorithmFuzzyPid::getFuzzyTableData
/// \param tab
/// \param ctrl
/// \return
///
bool algorithmFuzzyPid::getFuzzyTableData(struct fuzzyTable_t &tab,enum CTRL ctrl)
{

    if(&tab == NULL) return false;

    switch (ctrl) {
    case CTRL_KP:
        memcpy(tab.ptab,table.ptab,sizeof(table.ptab));
        break;
    case CTRL_KI:
         memcpy(tab.itab,table.itab,sizeof(table.ptab));
        break;
    case CTRL_KD:
         memcpy(tab.dtab,table.dtab,sizeof(table.ptab));
        break;
    default:
        break;
    }

    return true;
}

///
/// \brief algorithmFuzzyPid::setParams
/// 设置PID参数
/// \param para
/// \return
///
bool algorithmFuzzyPid::setParams(struct fuzzyParams_t &para)
{
    if(&para == NULL) return false;

    memcpy(&params,&para,sizeof(struct fuzzyParams_t));
    return true;
}

///
/// \brief algorithmFuzzyPid::getParams
/// 读取PID参数
/// \param para
/// \return
///
bool algorithmFuzzyPid::getParams(struct fuzzyParams_t &para)
{
    if(&para == NULL) return false;

    memcpy(&para,&params,sizeof(struct fuzzyParams_t));
    return true;
}

///
/// \brief algorithmFuzzyPid::getFuzzy
/// \param obj
/// \param error
/// \param delta_error
///
void algorithmFuzzyPid::getFuzzy(algorithmFuzzyPid &obj,
              float error,
              float delta_error)
{
    unsigned char  i,j;
    float psum=0.0,isum=0.0,dsum=0.0;
    float l_BP[10]={0,0,0,0,0,0,0,0,0,0};
    float l_BD[10]={0,0,0,0,0,0,0,0,0,0};

    /* 确定偏差位置 */
    for(i=0; i<obj.table.row; i++){

      if(error <= obj.table.Edot[i]) break;

    }

    /*
     * 偏差位置分为两种情况(线性化处理偏差)
     * 1. 处于两头
     * 2. 处于中间
     */
    if(i==0)l_BP[0]=100;
    else if(i == obj.table.row ) l_BP[obj.table.row-1] = 100;
    else if(i > 0 && i<obj.table.row){

      l_BP[i] 	= (float)100.0*(error-obj.table.Edot[i-1])/(obj.table.Edot[i]-obj.table.Edot[i-1]);
      l_BP[i-1]	= (float)100.0*(obj.table.Edot[i]-error)/(obj.table.Edot[i]-obj.table.Edot[i-1]);

    }

    /* 确定微分位置 */
    for(j=0;j<obj.table.col;j++){

      if(delta_error<=obj.table.ECdot[j])break;

    }

    /*
     * 微分位置分为两种情况(线性化处理偏差)
     * 1. 处于两头
     * 2. 处于中间
     */
    if(j==0)l_BD[0]=100;
    else if(j==obj.table.col) l_BD[obj.table.col-1]=100;
    else if(j>0 && j<obj.table.col){

      l_BD[j]   = (float)100.0*(delta_error-obj.table.ECdot[j-1])/(obj.table.ECdot[j]-obj.table.ECdot[j-1]);
      l_BD[j-1] = (float)100.0*(obj.table.ECdot[j]-delta_error)/(obj.table.ECdot[j]-obj.table.ECdot[j-1]);

    }

    /*
     * 合成输出
     */
    for(i=0; i<obj.table.row; i++){

      for(j=0; j<obj.table.col; j++){

        psum+=(float)l_BP[i] * l_BD[j] * (obj.table.ptab[i][j]);
        isum+=(float)l_BP[i] * l_BD[j] * (obj.table.itab[i][j]);
        dsum+=(float)l_BP[i] * l_BD[j] * (obj.table.dtab[i][j]);

      }
    }

    obj.table.kp = obj.params.kp * (psum/1000000.0);
 //	   obj.table.ki = obj.params.ki * (isum/1000000.0);
    obj.table.ki = obj.params.ki;
    obj.table.kd = obj.params.kd * (dsum/1000000.0);
}
