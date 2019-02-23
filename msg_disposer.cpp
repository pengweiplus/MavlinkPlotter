#include "msg_disposer.h"

msg_disposer::msg_disposer()
{

}

///
/// \brief mavPraseThread::get_mavlink_msg_info
/// \param msg          mavlink消息
/// \param msgInfo      mavlink消息信息
/// \param dataType     数据类型
/// \param i
/// \return
///
double msg_disposer::get_msg_info(mavlink_message_t *msg,const mavlink_message_info_t *msgInfo, uint32_t dataType,uint32_t i)
{
    double value = 0;

    if(MAVLINK_TYPE_CHAR == dataType){
         value = _MAV_RETURN_char(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT8_T == dataType){
        value = _MAV_RETURN_uint8_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_INT8_T == dataType){
        value = _MAV_RETURN_int8_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT16_T == dataType){
        value = _MAV_RETURN_uint16_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_INT16_T == dataType){
        value = _MAV_RETURN_int16_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT32_T == dataType){
        value = _MAV_RETURN_uint32_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_INT32_T == dataType){
        value = _MAV_RETURN_int32_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_UINT64_T == dataType){
        value = _MAV_RETURN_uint64_t(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_DOUBLE == dataType){
        value = _MAV_RETURN_double(msg,msgInfo->fields[i].wire_offset);
    }else if(MAVLINK_TYPE_FLOAT == dataType){
        value = _MAV_RETURN_float(msg,msgInfo->fields[i].wire_offset);
    }else{
        ;
    }

    return value;
}



///
/// \brief msg_disposer::handle_msg_frame
/// \param msg
/// \param map
/// \return
///
bool msg_disposer::handle_msg_frame(mavlink_message_t *msg, QMap<QString, mavlink_field_t> &map)
{

    //提取消息信息
    const mavlink_message_info_t *msgInfo = mavlink_get_message_info(msg);

    //消息错误,退出
    if(NULL == msgInfo )return false;

    mavlink_field_t t;

    //读取消息名称
    t.msgName = msgInfo->name;
    QString msgName(t.msgName);

    //读取该条消息的所有域(依据名称,类型获取值)
    for(uint32_t i = 0; i < msgInfo->num_fields; i++){
        //名称
        t.fieldName = msgInfo->fields[i].name;
        QString fieldName(t.fieldName);

        //类型
        t.dataType  = msgInfo->fields[i].type;

        //获取值
        t.rtValue = get_msg_info(msg,msgInfo, t.dataType,i);

        //生成全名
        QString fullName = msgName + fieldName;

        //新数据,保存到Hash表
        map.insert(fullName,t);
    }

    return true;
}

///
/// \brief msg_disposer::handle_stream
/// \param map
/// \param buffer
/// \param len
/// \return
///
bool msg_disposer::handle_stream(QMap<QString,mavlink_field_t>&map,char *buffer,uint32_t len)
{
    bool ret = false;
    //这里处理需要优化,直接影响数据的实时性
    for(uint32_t count = 0; count < len ; count++){

        //每处理完一帧数据就针对整包有效数据进行处理
        if(mavlink_parse_char(MAVLINK_COMM_0,buffer[count],&r_mav_msg,&r_mav_status)){
            ret = handle_msg_frame(&r_mav_msg,map);
            emit sigNewMavlinkMsg(&r_mav_msg);
        }else{
            ret =false;
        }
    }

    return ret;
}
