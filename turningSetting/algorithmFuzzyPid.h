#ifndef ALGORITHMFUZZYPID_H
#define ALGORITHMFUZZYPID_H

#include <string.h>
/********默认模糊表参数*********/
#define ROW 7
#define COL 3

#define  EB   0.3
#define  EM   0.15
#define  ES   0.07
#define  EO   0.0
#define  EEB  3.0
#define  EEM  1.5
#define  EES  0.7
#define  EEO  0

#define  PB  100
#define  PM  75
#define  PS  55
#define  ZO  30
#define  NB  100
#define  NM  75
#define  NS  55

/********默认PID参数*********/
#define  KP  1.8
#define  KI  0.4
#define  KD  0.05
#define  KF  0.0
#define  F_CUT  0.0
#define  I_MAX  30.0
#define  I_DZ  1.0
#define  O_MAX  50.0

class algorithmFuzzyPid
{
public:
    algorithmFuzzyPid();

    enum CTRL{
        CTRL_KP = 0,
        CTRL_KI = 1,
        CTRL_KD = 2
    };

    enum AXIS{
        AXIS_POLAR = 0,
        AXIS_PITCH = 1,
        CTRL_YAW = 2
    };

    struct fuzzyTable_t
    {
        int row;								//模糊PID,偏差行
        int col;								//模糊PID,微分列
        float kp;                               //模糊比例系数
        float ki;                               //模糊积分系数
        float kd;                               //模糊微分系数
        float ptab[ROW][COL];					//模糊PID,比例权重控制表(行:偏差,列微分)
        float itab[ROW][COL];					//模糊PID,积分权重控制表(行:偏差,列微分)
        float dtab[ROW][COL];					//模糊PID,微分权重控制表(行:偏差,列微分)
        float Edot[ROW];						//模糊PID,偏差段
        float ECdot[COL];                       //模糊PID,微分段
    };

    struct fuzzyParams_t
    {
        //PID parameters
        float kp;                               //比例系数
        float ki;                               //积分系数
        float kd;                               //微分系数
        float kf;                               //前馈系数

        //filter parameters
        float fCut;								//一阶低通滤波器截止频率(Hz)

        //maximal integrator and output value
        float i_max;							//积分限制阀值
        float o_max;							//输出限制阀值

        //
        float i_threshold;						//积分分离阀值

    };

    bool setAllDefault();                               //设置默认数据
    bool setFuzzyTable(struct fuzzyTable_t &tab);       //设置模糊表数据
    bool setFuzzyTable(struct fuzzyTable_t &tab,        //设置模糊表数据
                       enum CTRL ctrl);
    bool getFuzzyTable(struct fuzzyTable_t &tab);       //读取模糊表格
    bool getFuzzyTable(struct fuzzyTable_t &tab,        //读取模糊表格
                       enum CTRL ctrl);
    bool setParams(struct fuzzyParams_t &para);         //设置默认数据
    bool getParams(struct fuzzyParams_t &para);         //读取默认数据
    void getFuzzy(float &fuzzyKp,                       //执行模糊化算法
                  float &fuzzyKi,
                  float &fuzzyKd,
                  float error,
                  float delta_error);
private:
    fuzzyTable_t table;
    fuzzyParams_t params;
};

#endif // ALGORITHMFUZZYPID_H
