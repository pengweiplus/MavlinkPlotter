#-------------------------------------------------
#
# Project created by QtCreator 2014-12-22T14:53:33
#
#-------------------------------------------------

QT       += core gui network serialport
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MavlinkPlotter
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp \
    helpwindow.cpp \
    settingWindow.cpp \
    mavPraseThread.cpp \
    commConfig.cpp \
    io_manager.cpp \
    msg_disposer.cpp \
    msg_prase_thread.cpp \
    turningWindows.cpp

HEADERS  += mainwindow.hpp \
                qcustomplot.h \
    helpwindow.hpp \
    settingWindow.h \
    mavPraseThread.h \
    mavlink/checksum.h \
    mavlink/mavlink_conversions.h \
    mavlink/mavlink_get_info.h \
    mavlink/mavlink_helpers.h \
    mavlink/mavlink_sha256.h \
    mavlink/mavlink_types.h \
    mavlink/message.hpp \
    mavlink/msgmap.hpp \
    mavlink/protocol.h \
    commConfig.h \
    mavlink/checksum.h \
    mavlink/mavlink_conversions.h \
    mavlink/mavlink_get_info.h \
    mavlink/mavlink_helpers.h \
    mavlink/mavlink_sha256.h \
    mavlink/mavlink_types.h \
    mavlink/message.hpp \
    mavlink/msgmap.hpp \
    mavlink/protocol.h \
    mavlink/fppa/fppa.h \
    mavlink/fppa/fppa.hpp \
    mavlink/fppa/gtestsuite.hpp \
    mavlink/fppa/mavlink.h \
    mavlink/fppa/mavlink_msg_attitude_beam.h \
    mavlink/fppa/mavlink_msg_attitude_beam.hpp \
    mavlink/fppa/mavlink_msg_attitude_beam_target.h \
    mavlink/fppa/mavlink_msg_attitude_beam_target.hpp \
    mavlink/fppa/mavlink_msg_attitude_body.h \
    mavlink/fppa/mavlink_msg_attitude_body.hpp \
    mavlink/fppa/mavlink_msg_beacon_power.h \
    mavlink/fppa/mavlink_msg_beacon_power.hpp \
    mavlink/fppa/mavlink_msg_heartbeat.h \
    mavlink/fppa/mavlink_msg_heartbeat.hpp \
    mavlink/fppa/mavlink_msg_humiture.h \
    mavlink/fppa/mavlink_msg_humiture.hpp \
    mavlink/fppa/mavlink_msg_motor_status.h \
    mavlink/fppa/mavlink_msg_motor_status.hpp \
    mavlink/fppa/mavlink_msg_pid_tuning.h \
    mavlink/fppa/mavlink_msg_pid_tuning.hpp \
    mavlink/fppa/mavlink_msg_raw_imu.h \
    mavlink/fppa/mavlink_msg_raw_imu.hpp \
    mavlink/fppa/mavlink_msg_rtk_gps.h \
    mavlink/fppa/mavlink_msg_rtk_gps.hpp \
    mavlink/fppa/testsuite.h \
    mavlink/fppa/version.h \
    mavlink/checksum.h \
    mavlink/mavlink_conversions.h \
    mavlink/mavlink_get_info.h \
    mavlink/mavlink_helpers.h \
    mavlink/mavlink_sha256.h \
    mavlink/mavlink_types.h \
    mavlink/message.hpp \
    mavlink/msgmap.hpp \
    mavlink/protocol.h \
    io_manager.h \
    msg_disposer.h \
    msg_prase_thread.h \
    turningWindows.h


FORMS    += mainwindow.ui \
    helpwindow.ui \
    settingWindow.ui \
    turningWindows.ui

RC_FILE = myapp.rc

RESOURCES += \
    appresources.qrc


