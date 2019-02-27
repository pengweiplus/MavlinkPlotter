#ifndef TURNINGWINDOWS_H
#define TURNINGWINDOWS_H

#include <QDialog>
#include <QStandardItemModel>
#include "algorithmFuzzyPid.h"

namespace Ui {
class turningWindows;
}

class turningWindows : public QDialog
{
    Q_OBJECT

public:
    explicit turningWindows(QWidget *parent = 0);
    ~turningWindows();

private slots:
    void on_tbv_fuzzy_pids_table_changed();
    void on_btn_fuzzy_pids_refresh_screen_clicked();
    void on_cbox_fuzzy_pids_axis_items_changed(int index);
    void on_cbox_fuzzy_pids_ctrl_items_changed(int index);
    void on_hs_fuzzy_pids_derror_changed(int val);
    void on_dsb_fuzzy_pids_derror_changed(double val);

private:
    Ui::turningWindows *ui;                 //UI界面
    QStandardItemModel *model;              //模糊表Item模型
    algorithmFuzzyPid *fuzzyPidPolar;       //极化轴模糊算法对象
    algorithmFuzzyPid *fuzzyPidPitch;       //俯仰轴模糊算法对象
    algorithmFuzzyPid *fuzzyPidYaw;         //范围轴模糊算法对象

    //Event


    //Fuzzy Pids
    bool setupFuzzyPidTabView(int row,int col);                                     //设置模糊表头
    bool setFuzzyPidTableView(struct algorithmFuzzyPid::fuzzyTable_t &tab,
                              algorithmFuzzyPid::CTRL ctrl);                        //设置模糊表
    bool getFuzzyPidTableView(struct algorithmFuzzyPid::fuzzyTable_t &tab,
                              algorithmFuzzyPid::CTRL ctrl);                        //读取模糊表
    void plotGraph(algorithmFuzzyPid &obj,
                   double derror);                                                  //绘制模糊图形

    //Basic Pids
    void getBasicPidsParams(struct algorithmFuzzyPid::fuzzyParams_t &polar,
                            struct algorithmFuzzyPid::fuzzyParams_t &pitch,
                            struct algorithmFuzzyPid::fuzzyParams_t &yaw);          //读取PID参数
    void setBasicPidsParams(struct algorithmFuzzyPid::fuzzyParams_t &polar,
                            struct algorithmFuzzyPid::fuzzyParams_t &pitch,
                            struct algorithmFuzzyPid::fuzzyParams_t &yaw);          //设置PID参数

    //Logic
    void saveFuzzyDataAndReplotGraph();     //保存界面数据到对应数据结构
    void loadFuzzyDataAndReplotGraph();     //载入数据结构中的数据到界面

};

#endif // TURNINGWINDOWS_H
