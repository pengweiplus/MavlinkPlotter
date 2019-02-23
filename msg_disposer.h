#ifndef MSG_DISPOSER_H
#define MSG_DISPOSER_H

#include <QObject>
#include <QDebug>
#include <QQueue>
#include <QHash>

#include "mavlink/fppa/mavlink.h"

class msg_disposer: public QObject
{
    Q_OBJECT

public:
    msg_disposer();

    typedef struct {
        const char *msgName;        //消息名称
        const char *fieldName;      //域名称
        double rtValue;             //实时数据
        int dataType;               //数据类型
    }mavlink_field_t;

    bool handle_stream(QMap<QString,mavlink_field_t>&map,char *buffer,uint32_t len);

signals:
    void sigNewMavlinkMsg(mavlink_message_t *msg);

private:
    bool handle_msg_frame(mavlink_message_t *msg,QMap<QString,mavlink_field_t>&map);
    double get_msg_info(mavlink_message_t *msg,const mavlink_message_info_t *msgInfo, uint32_t dataType,uint32_t i);

    /* mavlink */
    mavlink_message_t r_mav_msg;    //消息帧[必要]
    mavlink_status_t r_mav_status;  //解析器状态[必要]
    mavlink_field_t single_field;

};

#endif // MSG_DISPOSER_H
