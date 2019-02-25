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
/// \brief algorithmFuzzyPid::getFuzzyTable
/// 读取模糊表
/// \param tab
/// \return
///
bool algorithmFuzzyPid::getFuzzyTable(struct fuzzyTable_t &tab)
{
    if(&tab == NULL) return false;

    memcpy(&tab,&table,sizeof(struct fuzzyTable_t));
    return true;
}

///
/// \brief algorithmFuzzyPid::getFuzzyTable
/// \param tab
/// \param ctrl
/// \return
///
bool algorithmFuzzyPid::getFuzzyTable(struct fuzzyTable_t &tab,enum CTRL ctrl)
{

    if(&tab == NULL) return false;

    switch (ctrl) {
    case CTRL_KP:
        memcpy(&tab.ptab,&table.ptab,sizeof(table.ptab));
        break;
    case CTRL_KI:
         memcpy(&tab.itab,&table.itab,sizeof(table.itab));
        break;
    case CTRL_KD:
         memcpy(&tab.dtab,&table.dtab,sizeof(table.dtab));
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
/// \brief getFuzzy
/// \param fuzzyKp
/// \param fuzzyKi
/// \param fuzzyKd
/// \param error
/// \param delta_error
///
void algorithmFuzzyPid::getFuzzy(float &fuzzyKp,
              float &fuzzyKi,
              float &fuzzyKd,
              float error,
              float delta_error)
{

}
