#ifndef TURNINGWINDOWS_H
#define TURNINGWINDOWS_H

#include <QDialog>
#include <QStandardItemModel>

#define  EB   0.3
#define  EM   0.15
#define  ES   0.07
#define  EO   0.0
#define  EEB  3.0
#define  EEM  1.5
#define  EES  0.7
#define  EEO  0

namespace Ui {
class turningWindows;
}

class turningWindows : public QDialog
{
    Q_OBJECT

public:
    explicit turningWindows(QWidget *parent = 0);
    ~turningWindows();

    enum{
        PB = 100,
        PM = 75,
        PS = 55,
        ZO = 30,
        NB = 100,
        NM = 75,
        NS = 55,
    };

    struct fuzzy_pid_fuzzy_t
    {
        int row;								//模糊PID,偏差行
        int col;								//模糊PID,微分列
        float kp;                               //模糊比例系数
        float ki;                               //模糊积分系数
        float kd;                               //模糊微分系数
        float ptab[7][3];						//模糊PID,比例权重控制表(行:偏差,列微分)
        float itab[7][3];						//模糊PID,积分权重控制表(行:偏差,列微分)
        float dtab[7][3];						//模糊PID,微分权重控制表(行:偏差,列微分)
        float Edot[7];							//模糊PID,偏差段
        float ECdot[3];                         //模糊PID,微分段
    };

    struct fuzzy_pid_params_t
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

    struct algorithm_fuzzy_pid_t
    {

        //PID parameters
        struct fuzzy_pid_params_t params;		//需要保存到存储器的参数
        struct fuzzy_pid_fuzzy_t  tab;          //模糊表
    };


private slots:
    void on_tbv_fuzzy_pids_table_changed();
    void on_btn_fuzzy_pids_refresh_screen_clicked();
    void on_cbox_fuzzy_pids_axis_items_changed(int index);
    void on_cbox_fuzzy_pids_ctrl_items_changed(int index);

private:
    Ui::turningWindows *ui;                 //UI界面
    QStandardItemModel  *model;             //模糊表Item模型

    struct algorithm_fuzzy_pid_t rx_polar;
    struct algorithm_fuzzy_pid_t rx_pitch;
    struct algorithm_fuzzy_pid_t rx_yaw;

    //Event


    //Logic
    bool setupAlgorithmFuzzyPid(struct algorithm_fuzzy_pid_t &fuzzy);
    void plotGraphSimulator(struct algorithm_fuzzy_pid_t &fuzzy,int item);
    void fuzzy_out(struct algorithm_fuzzy_pid_t &pid,float error,float delta_error);
    void setFuzzyTableAndReplotGraph();

    //Fuzzy Pids
    bool setupFuzzyPidTabView(int row,int col);
    bool setFuzzyPidTable(struct algorithm_fuzzy_pid_t &fuzzy);
    bool getFuzzyPidTable(struct algorithm_fuzzy_pid_t &fuzzy);

    //Basic Pids
    void getBasicPidsParams(struct fuzzy_pid_params_t &polar,struct fuzzy_pid_params_t &pitch,struct fuzzy_pid_params_t &yaw);
    void setBasicPidsParams(struct fuzzy_pid_params_t &polar,struct fuzzy_pid_params_t &pitch,struct fuzzy_pid_params_t &yaw);

};

#endif // TURNINGWINDOWS_H
