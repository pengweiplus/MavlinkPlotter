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

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QTreeView>
#include <QMap>
#include <QStandardItemModel>
#include <QColorDialog>

#include "commSetting/commSetting.h"
#include "turningSetting/turningWindows.h"


#define WAIT_START      1
#define IN_MESSAGE      2
#define UNDEFINED       3

//此结构体的意义
//1.记录域的值(界面显示用到)
//2.记录在treeview中的行,列号(用于动态修改treeview中显示的值)
//3.记录该条曲线的颜色(界面显示用到)
typedef struct {
    double_t value;
    uint32_t row;
    uint32_t col;
    bool     checkd;
}mavlinkFieldInfos_t;


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //图形控件相关事件
    void on_stopPlotButton_clicked();                              // 停止2D图形绘制
    void on_resetPlotButton_clicked();                             // 复位2D图形x-y的缩放
    void replot();                                                 // Slot for repainting the plot
    void cboxAxisXPointesChanged(const QString &text);

    //日志
    void on_saveDataLogButton_clicked();                           // 日志记录

    //目录点击事件
    void on_actionCommLinks_triggered();
    void on_actionTurning_triggered();

    //树型列表控件相关事件
    void newMavlinkMsg(mavlink_message_t *msg);
    void treeviewRefresh();
    void treeViewItemChanged(QStandardItem * item);

    //commlink windows
    void commConnect();
    void commDisconnect();

    //鼠标事件
    void mousePress(QMouseEvent* mevent);
    void mouseMove(QMouseEvent *mevent);
    void mouseRelease(QMouseEvent *mevent);

signals:
    void portOpenFail();                                                                  // Emitted when cannot open port
    void portOpenOK();                                                                    // Emitted when port is open
    void portClosed();                                                                    // Emitted when port is closed
    void newData(QStringList data);                                                       // Emitted when new data has arrived

private:
    Ui::MainWindow *ui;

    bool connected;                                                                       // Status connection variable
    bool plotting;                                                                        // Status plotting variable
    bool logging;
    QString filePath;
    int dataPointNumber;                                                                  // Keep track of data points
    QTimer updateTimer;                                                                   // Timer used for replotting the plot
    QTimer treeviewTimer;                                                                 // Timer used for replotting the treeview
    int NUMBER_OF_POINTS;                                                                 // Number of points plotted
    int FREQ_OF_REFRESH;                                                                  // Frequence of plotted [Unit:ms]
    QRubberBand *rubberBand;
    QPoint rubberOrigin;

    //Graph
    QMap<uint32_t,QColor> mapPlotGraph;                                                   // QCustomPlot Graph numbe map for color

    //windows
    commSetting *mCommSetting;                                                           // Setup windows
    turningWindows *mTurningWindows;                                                        // turningWindows

    //mavlink
    mavPraseThread *mavlinkThread;
    QMap<uint32_t,QString> msgFilesType;                                                  // mavlink msg field data type
    QMap<uint32_t,mavlink_message_t> mapMavlinkMsg;                                       // mavlink msg
    void setupPlotGraphView();                                                            // Setup the QCustomPlot
    int  allocPlotGraph();                                                                // Alloc the QCustomPlot Graph numbe
    QColor getPlotGraphColor(int num);                                                    // Get the QCustomPlot Graph numbe
    void startRefreshTimer();                                                             // Start the QCustomPlot plot timer
    void stopRefreshTimer();                                                              // Start the QCustomPlot plot timer

    //treeview
    QStandardItemModel* model;                                                            // Treeview model
    void setupTreeView();                                                                 // Initialize treeview model
    bool addNodeItem(QStandardItemModel* model,
                     QStandardItem* nodeProject);                                         // Add the main-item
    int addNodeItem(QStandardItem* nodeProject,
                    QString& fieldName,
                    QString& fieldUnit,
                    QString& fieldValue);                                                 // Add the main-item and sub-items
    void treeViewItemChanged(QStandardItem * item,disMavlinkMsg_t *t);
};


#endif                                                                                    // MAINWINDOW_HPP
