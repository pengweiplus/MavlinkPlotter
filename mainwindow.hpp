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

#include "helpwindow.hpp"
#include "settingWindow.h"
#include "turningWindows.h"


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
    void on_stopPlotButton_clicked();                                                     // Starts and stops plotting
    void on_resetPlotButton_clicked();                                                    // Resets plot to initial zoom and coordinates
    void on_saveDataLogButton_clicked();                                                  // start log data

    void onMouseMoveInPlot(QMouseEvent *event);                                           // Displays coordinates of mouse pointer when clicked in plot in status bar
    void replot();                                                                        // Slot for repainting the plot

    void on_actionAntenna_triggered();
    void on_actionHow_to_use_triggered();
    void on_actionCommLinks_triggered();
    void on_actionTurning_triggered();
    void on_cbox_axis_x_pointes_changed(const QString &text);
    void new_mavlink_msg(mavlink_message_t *msg);
    void on_treeview_refresh();
    void treeItemChanged(QStandardItem * item);

    //commlink windows
    void on_sig_comm_connect();
    void on_sig_comm_disconnect();


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

    //Graph
    QMap<uint32_t,QColor> mapPlotGraph;                                                   // QCustomPlot Graph numbe map for color

    //windows
    HelpWindow *helpWindow;                                                               // Help windows
    settingWindow *setupWindow;                                                           // Setup windows
    turningWindows *turningWindow;                                                        // turningWindows

    //mavlink
    mavPraseThread *mavlinkThread;
    QMap<uint32_t,QString> msgFilesType;                                                  // mavlink msg field data type
    QMap<uint32_t,mavlink_message_t> mapMavlinkMsg;                                       // mavlink msg
    void setupPlot();                                                                     // Setup the QCustomPlot
    int  allocPlotGraph();                                                                // Alloc the QCustomPlot Graph numbe
    QColor getPlotGraphColor(int num);                                                    // Get the QCustomPlot Graph numbe
    void startRefreshTimer();                                                             // Start the QCustomPlot plot timer
    void stopRefreshTimer();                                                              // Start the QCustomPlot plot timer

    //treeview
    QStandardItemModel* model;                                                            // Treeview model
    void initTree();                                                                      // Initialize treeview model
    bool addNodeItem(QStandardItemModel* model,QStandardItem* nodeProject);               // Add the main-item
    int addNodeItem(QStandardItem* nodeProject,QString& fieldName,QString& fieldUnit, QString& fieldValue);// Add the main-item and sub-items
    void treeItemChanged(QStandardItem * item,disMavlinkMsg_t *t);
};


#endif                                                                                    // MAINWINDOW_HPP
