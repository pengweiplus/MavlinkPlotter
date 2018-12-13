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
    commConfig.cpp

HEADERS  += mainwindow.hpp \
                qcustomplot.h \
    helpwindow.hpp \
    settingWindow.h \
    mavPraseThread.h \
    mavlink/fppa/fppa.h \
    mavlink/fppa/fppa.hpp \
    mavlink/fppa/gtestsuite.hpp \
    mavlink/fppa/mavlink.h \
    mavlink/fppa/mavlink_msg_ahrs.h \
    mavlink/fppa/mavlink_msg_ahrs.hpp \
    mavlink/fppa/mavlink_msg_ahrs2.h \
    mavlink/fppa/mavlink_msg_ahrs2.hpp \
    mavlink/fppa/mavlink_msg_ahrs3.h \
    mavlink/fppa/mavlink_msg_ahrs3.hpp \
    mavlink/fppa/mavlink_msg_attitude.h \
    mavlink/fppa/mavlink_msg_attitude.hpp \
    mavlink/fppa/mavlink_msg_attitude_quaternion.h \
    mavlink/fppa/mavlink_msg_attitude_quaternion.hpp \
    mavlink/fppa/mavlink_msg_attitude_target.h \
    mavlink/fppa/mavlink_msg_attitude_target.hpp \
    mavlink/fppa/mavlink_msg_beacon_power.h \
    mavlink/fppa/mavlink_msg_beacon_power.hpp \
    mavlink/fppa/mavlink_msg_command_long.h \
    mavlink/fppa/mavlink_msg_command_long.hpp \
    mavlink/fppa/mavlink_msg_gps_raw_int.h \
    mavlink/fppa/mavlink_msg_gps_raw_int.hpp \
    mavlink/fppa/mavlink_msg_heartbeat.h \
    mavlink/fppa/mavlink_msg_heartbeat.hpp \
    mavlink/fppa/mavlink_msg_humiture.h \
    mavlink/fppa/mavlink_msg_humiture.hpp \
    mavlink/fppa/mavlink_msg_local_position_ned.h \
    mavlink/fppa/mavlink_msg_local_position_ned.hpp \
    mavlink/fppa/mavlink_msg_manual_setpoint.h \
    mavlink/fppa/mavlink_msg_manual_setpoint.hpp \
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
    commConfig.h


FORMS    += mainwindow.ui \
    helpwindow.ui \
    settingWindow.ui

RC_FILE = myapp.rc

RESOURCES += \
    appresources.qrc


