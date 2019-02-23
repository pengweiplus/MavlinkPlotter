#pragma once
// MESSAGE RAW_IMU PACKING

#define MAVLINK_MSG_ID_RAW_IMU 15

MAVPACKED(
typedef struct __mavlink_raw_imu_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.*/
 float xacc; /*<  X acceleration (raw)*/
 float yacc; /*<  Y acceleration (raw)*/
 float zacc; /*<  Z acceleration (raw)*/
 float xgyro; /*<  Angular speed around X axis (raw)*/
 float ygyro; /*<  Angular speed around Y axis (raw)*/
 float zgyro; /*<  Angular speed around Z axis (raw)*/
 float xmag; /*<  X Magnetic field (raw)*/
 float ymag; /*<  Y Magnetic field (raw)*/
 float zmag; /*<  Z Magnetic field (raw)*/
 float x_delta_v; /*<  X delta vel (raw)*/
 float y_delta_v; /*<  Y delta vel (raw)*/
 float z_delta_v; /*<  Z delta vel (raw)*/
 float x_angle; /*<  X delta angle (raw)*/
 float y_angle; /*<  Y delta angle (raw)*/
 float z_angle; /*<  Z delta angle (raw)*/
}) mavlink_raw_imu_t;

#define MAVLINK_MSG_ID_RAW_IMU_LEN 68
#define MAVLINK_MSG_ID_RAW_IMU_MIN_LEN 68
#define MAVLINK_MSG_ID_15_LEN 68
#define MAVLINK_MSG_ID_15_MIN_LEN 68

#define MAVLINK_MSG_ID_RAW_IMU_CRC 161
#define MAVLINK_MSG_ID_15_CRC 161



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RAW_IMU { \
    15, \
    "RAW_IMU", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_imu_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_raw_imu_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_raw_imu_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_raw_imu_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_raw_imu_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_raw_imu_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_raw_imu_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_raw_imu_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_raw_imu_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_raw_imu_t, zmag) }, \
         { "x_delta_v", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_raw_imu_t, x_delta_v) }, \
         { "y_delta_v", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_raw_imu_t, y_delta_v) }, \
         { "z_delta_v", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_raw_imu_t, z_delta_v) }, \
         { "x_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_raw_imu_t, x_angle) }, \
         { "y_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_raw_imu_t, y_angle) }, \
         { "z_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_raw_imu_t, z_angle) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RAW_IMU { \
    "RAW_IMU", \
    16, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_imu_t, time_usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_raw_imu_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_raw_imu_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_raw_imu_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_raw_imu_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_raw_imu_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_raw_imu_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_raw_imu_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_raw_imu_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_raw_imu_t, zmag) }, \
         { "x_delta_v", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_raw_imu_t, x_delta_v) }, \
         { "y_delta_v", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_raw_imu_t, y_delta_v) }, \
         { "z_delta_v", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_raw_imu_t, z_delta_v) }, \
         { "x_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_raw_imu_t, x_angle) }, \
         { "y_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_raw_imu_t, y_angle) }, \
         { "z_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_raw_imu_t, z_angle) }, \
         } \
}
#endif

/**
 * @brief Pack a raw_imu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 * @param xacc  X acceleration (raw)
 * @param yacc  Y acceleration (raw)
 * @param zacc  Z acceleration (raw)
 * @param xgyro  Angular speed around X axis (raw)
 * @param ygyro  Angular speed around Y axis (raw)
 * @param zgyro  Angular speed around Z axis (raw)
 * @param xmag  X Magnetic field (raw)
 * @param ymag  Y Magnetic field (raw)
 * @param zmag  Z Magnetic field (raw)
 * @param x_delta_v  X delta vel (raw)
 * @param y_delta_v  Y delta vel (raw)
 * @param z_delta_v  Z delta vel (raw)
 * @param x_angle  X delta angle (raw)
 * @param y_angle  Y delta angle (raw)
 * @param z_angle  Z delta angle (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_imu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float x_delta_v, float y_delta_v, float z_delta_v, float x_angle, float y_angle, float z_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_IMU_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, xacc);
    _mav_put_float(buf, 12, yacc);
    _mav_put_float(buf, 16, zacc);
    _mav_put_float(buf, 20, xgyro);
    _mav_put_float(buf, 24, ygyro);
    _mav_put_float(buf, 28, zgyro);
    _mav_put_float(buf, 32, xmag);
    _mav_put_float(buf, 36, ymag);
    _mav_put_float(buf, 40, zmag);
    _mav_put_float(buf, 44, x_delta_v);
    _mav_put_float(buf, 48, y_delta_v);
    _mav_put_float(buf, 52, z_delta_v);
    _mav_put_float(buf, 56, x_angle);
    _mav_put_float(buf, 60, y_angle);
    _mav_put_float(buf, 64, z_angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RAW_IMU_LEN);
#else
    mavlink_raw_imu_t packet;
    packet.time_usec = time_usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;
    packet.x_delta_v = x_delta_v;
    packet.y_delta_v = y_delta_v;
    packet.z_delta_v = z_delta_v;
    packet.x_angle = x_angle;
    packet.y_angle = y_angle;
    packet.z_angle = z_angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RAW_IMU_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_IMU;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
}

/**
 * @brief Pack a raw_imu message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 * @param xacc  X acceleration (raw)
 * @param yacc  Y acceleration (raw)
 * @param zacc  Z acceleration (raw)
 * @param xgyro  Angular speed around X axis (raw)
 * @param ygyro  Angular speed around Y axis (raw)
 * @param zgyro  Angular speed around Z axis (raw)
 * @param xmag  X Magnetic field (raw)
 * @param ymag  Y Magnetic field (raw)
 * @param zmag  Z Magnetic field (raw)
 * @param x_delta_v  X delta vel (raw)
 * @param y_delta_v  Y delta vel (raw)
 * @param z_delta_v  Z delta vel (raw)
 * @param x_angle  X delta angle (raw)
 * @param y_angle  Y delta angle (raw)
 * @param z_angle  Z delta angle (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_imu_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float xacc,float yacc,float zacc,float xgyro,float ygyro,float zgyro,float xmag,float ymag,float zmag,float x_delta_v,float y_delta_v,float z_delta_v,float x_angle,float y_angle,float z_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_IMU_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, xacc);
    _mav_put_float(buf, 12, yacc);
    _mav_put_float(buf, 16, zacc);
    _mav_put_float(buf, 20, xgyro);
    _mav_put_float(buf, 24, ygyro);
    _mav_put_float(buf, 28, zgyro);
    _mav_put_float(buf, 32, xmag);
    _mav_put_float(buf, 36, ymag);
    _mav_put_float(buf, 40, zmag);
    _mav_put_float(buf, 44, x_delta_v);
    _mav_put_float(buf, 48, y_delta_v);
    _mav_put_float(buf, 52, z_delta_v);
    _mav_put_float(buf, 56, x_angle);
    _mav_put_float(buf, 60, y_angle);
    _mav_put_float(buf, 64, z_angle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RAW_IMU_LEN);
#else
    mavlink_raw_imu_t packet;
    packet.time_usec = time_usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;
    packet.x_delta_v = x_delta_v;
    packet.y_delta_v = y_delta_v;
    packet.z_delta_v = z_delta_v;
    packet.x_angle = x_angle;
    packet.y_angle = y_angle;
    packet.z_angle = z_angle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RAW_IMU_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_IMU;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
}

/**
 * @brief Encode a raw_imu struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param raw_imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_imu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_raw_imu_t* raw_imu)
{
    return mavlink_msg_raw_imu_pack(system_id, component_id, msg, raw_imu->time_usec, raw_imu->xacc, raw_imu->yacc, raw_imu->zacc, raw_imu->xgyro, raw_imu->ygyro, raw_imu->zgyro, raw_imu->xmag, raw_imu->ymag, raw_imu->zmag, raw_imu->x_delta_v, raw_imu->y_delta_v, raw_imu->z_delta_v, raw_imu->x_angle, raw_imu->y_angle, raw_imu->z_angle);
}

/**
 * @brief Encode a raw_imu struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param raw_imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_imu_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_raw_imu_t* raw_imu)
{
    return mavlink_msg_raw_imu_pack_chan(system_id, component_id, chan, msg, raw_imu->time_usec, raw_imu->xacc, raw_imu->yacc, raw_imu->zacc, raw_imu->xgyro, raw_imu->ygyro, raw_imu->zgyro, raw_imu->xmag, raw_imu->ymag, raw_imu->zmag, raw_imu->x_delta_v, raw_imu->y_delta_v, raw_imu->z_delta_v, raw_imu->x_angle, raw_imu->y_angle, raw_imu->z_angle);
}

/**
 * @brief Send a raw_imu message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 * @param xacc  X acceleration (raw)
 * @param yacc  Y acceleration (raw)
 * @param zacc  Z acceleration (raw)
 * @param xgyro  Angular speed around X axis (raw)
 * @param ygyro  Angular speed around Y axis (raw)
 * @param zgyro  Angular speed around Z axis (raw)
 * @param xmag  X Magnetic field (raw)
 * @param ymag  Y Magnetic field (raw)
 * @param zmag  Z Magnetic field (raw)
 * @param x_delta_v  X delta vel (raw)
 * @param y_delta_v  Y delta vel (raw)
 * @param z_delta_v  Z delta vel (raw)
 * @param x_angle  X delta angle (raw)
 * @param y_angle  Y delta angle (raw)
 * @param z_angle  Z delta angle (raw)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_raw_imu_send(mavlink_channel_t chan, uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float x_delta_v, float y_delta_v, float z_delta_v, float x_angle, float y_angle, float z_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_IMU_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, xacc);
    _mav_put_float(buf, 12, yacc);
    _mav_put_float(buf, 16, zacc);
    _mav_put_float(buf, 20, xgyro);
    _mav_put_float(buf, 24, ygyro);
    _mav_put_float(buf, 28, zgyro);
    _mav_put_float(buf, 32, xmag);
    _mav_put_float(buf, 36, ymag);
    _mav_put_float(buf, 40, zmag);
    _mav_put_float(buf, 44, x_delta_v);
    _mav_put_float(buf, 48, y_delta_v);
    _mav_put_float(buf, 52, z_delta_v);
    _mav_put_float(buf, 56, x_angle);
    _mav_put_float(buf, 60, y_angle);
    _mav_put_float(buf, 64, z_angle);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, buf, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
#else
    mavlink_raw_imu_t packet;
    packet.time_usec = time_usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;
    packet.x_delta_v = x_delta_v;
    packet.y_delta_v = y_delta_v;
    packet.z_delta_v = z_delta_v;
    packet.x_angle = x_angle;
    packet.y_angle = y_angle;
    packet.z_angle = z_angle;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, (const char *)&packet, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
#endif
}

/**
 * @brief Send a raw_imu message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_raw_imu_send_struct(mavlink_channel_t chan, const mavlink_raw_imu_t* raw_imu)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_raw_imu_send(chan, raw_imu->time_usec, raw_imu->xacc, raw_imu->yacc, raw_imu->zacc, raw_imu->xgyro, raw_imu->ygyro, raw_imu->zgyro, raw_imu->xmag, raw_imu->ymag, raw_imu->zmag, raw_imu->x_delta_v, raw_imu->y_delta_v, raw_imu->z_delta_v, raw_imu->x_angle, raw_imu->y_angle, raw_imu->z_angle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, (const char *)raw_imu, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
#endif
}

#if MAVLINK_MSG_ID_RAW_IMU_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_raw_imu_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xmag, float ymag, float zmag, float x_delta_v, float y_delta_v, float z_delta_v, float x_angle, float y_angle, float z_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, xacc);
    _mav_put_float(buf, 12, yacc);
    _mav_put_float(buf, 16, zacc);
    _mav_put_float(buf, 20, xgyro);
    _mav_put_float(buf, 24, ygyro);
    _mav_put_float(buf, 28, zgyro);
    _mav_put_float(buf, 32, xmag);
    _mav_put_float(buf, 36, ymag);
    _mav_put_float(buf, 40, zmag);
    _mav_put_float(buf, 44, x_delta_v);
    _mav_put_float(buf, 48, y_delta_v);
    _mav_put_float(buf, 52, z_delta_v);
    _mav_put_float(buf, 56, x_angle);
    _mav_put_float(buf, 60, y_angle);
    _mav_put_float(buf, 64, z_angle);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, buf, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
#else
    mavlink_raw_imu_t *packet = (mavlink_raw_imu_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->xacc = xacc;
    packet->yacc = yacc;
    packet->zacc = zacc;
    packet->xgyro = xgyro;
    packet->ygyro = ygyro;
    packet->zgyro = zgyro;
    packet->xmag = xmag;
    packet->ymag = ymag;
    packet->zmag = zmag;
    packet->x_delta_v = x_delta_v;
    packet->y_delta_v = y_delta_v;
    packet->z_delta_v = z_delta_v;
    packet->x_angle = x_angle;
    packet->y_angle = y_angle;
    packet->z_angle = z_angle;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, (const char *)packet, MAVLINK_MSG_ID_RAW_IMU_MIN_LEN, MAVLINK_MSG_ID_RAW_IMU_LEN, MAVLINK_MSG_ID_RAW_IMU_CRC);
#endif
}
#endif

#endif

// MESSAGE RAW_IMU UNPACKING


/**
 * @brief Get field time_usec from raw_imu message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 */
static inline uint64_t mavlink_msg_raw_imu_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xacc from raw_imu message
 *
 * @return  X acceleration (raw)
 */
static inline float mavlink_msg_raw_imu_get_xacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yacc from raw_imu message
 *
 * @return  Y acceleration (raw)
 */
static inline float mavlink_msg_raw_imu_get_yacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field zacc from raw_imu message
 *
 * @return  Z acceleration (raw)
 */
static inline float mavlink_msg_raw_imu_get_zacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field xgyro from raw_imu message
 *
 * @return  Angular speed around X axis (raw)
 */
static inline float mavlink_msg_raw_imu_get_xgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field ygyro from raw_imu message
 *
 * @return  Angular speed around Y axis (raw)
 */
static inline float mavlink_msg_raw_imu_get_ygyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field zgyro from raw_imu message
 *
 * @return  Angular speed around Z axis (raw)
 */
static inline float mavlink_msg_raw_imu_get_zgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field xmag from raw_imu message
 *
 * @return  X Magnetic field (raw)
 */
static inline float mavlink_msg_raw_imu_get_xmag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field ymag from raw_imu message
 *
 * @return  Y Magnetic field (raw)
 */
static inline float mavlink_msg_raw_imu_get_ymag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field zmag from raw_imu message
 *
 * @return  Z Magnetic field (raw)
 */
static inline float mavlink_msg_raw_imu_get_zmag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field x_delta_v from raw_imu message
 *
 * @return  X delta vel (raw)
 */
static inline float mavlink_msg_raw_imu_get_x_delta_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field y_delta_v from raw_imu message
 *
 * @return  Y delta vel (raw)
 */
static inline float mavlink_msg_raw_imu_get_y_delta_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field z_delta_v from raw_imu message
 *
 * @return  Z delta vel (raw)
 */
static inline float mavlink_msg_raw_imu_get_z_delta_v(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field x_angle from raw_imu message
 *
 * @return  X delta angle (raw)
 */
static inline float mavlink_msg_raw_imu_get_x_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field y_angle from raw_imu message
 *
 * @return  Y delta angle (raw)
 */
static inline float mavlink_msg_raw_imu_get_y_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field z_angle from raw_imu message
 *
 * @return  Z delta angle (raw)
 */
static inline float mavlink_msg_raw_imu_get_z_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Decode a raw_imu message into a struct
 *
 * @param msg The message to decode
 * @param raw_imu C-struct to decode the message contents into
 */
static inline void mavlink_msg_raw_imu_decode(const mavlink_message_t* msg, mavlink_raw_imu_t* raw_imu)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    raw_imu->time_usec = mavlink_msg_raw_imu_get_time_usec(msg);
    raw_imu->xacc = mavlink_msg_raw_imu_get_xacc(msg);
    raw_imu->yacc = mavlink_msg_raw_imu_get_yacc(msg);
    raw_imu->zacc = mavlink_msg_raw_imu_get_zacc(msg);
    raw_imu->xgyro = mavlink_msg_raw_imu_get_xgyro(msg);
    raw_imu->ygyro = mavlink_msg_raw_imu_get_ygyro(msg);
    raw_imu->zgyro = mavlink_msg_raw_imu_get_zgyro(msg);
    raw_imu->xmag = mavlink_msg_raw_imu_get_xmag(msg);
    raw_imu->ymag = mavlink_msg_raw_imu_get_ymag(msg);
    raw_imu->zmag = mavlink_msg_raw_imu_get_zmag(msg);
    raw_imu->x_delta_v = mavlink_msg_raw_imu_get_x_delta_v(msg);
    raw_imu->y_delta_v = mavlink_msg_raw_imu_get_y_delta_v(msg);
    raw_imu->z_delta_v = mavlink_msg_raw_imu_get_z_delta_v(msg);
    raw_imu->x_angle = mavlink_msg_raw_imu_get_x_angle(msg);
    raw_imu->y_angle = mavlink_msg_raw_imu_get_y_angle(msg);
    raw_imu->z_angle = mavlink_msg_raw_imu_get_z_angle(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RAW_IMU_LEN? msg->len : MAVLINK_MSG_ID_RAW_IMU_LEN;
        memset(raw_imu, 0, MAVLINK_MSG_ID_RAW_IMU_LEN);
    memcpy(raw_imu, _MAV_PAYLOAD(msg), len);
#endif
}
