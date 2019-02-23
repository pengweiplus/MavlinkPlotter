#pragma once
// MESSAGE MOTOR_STATUS PACKING

#define MAVLINK_MSG_ID_MOTOR_STATUS 11

MAVPACKED(
typedef struct __mavlink_motor_status_t {
 uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float RxL1; /*< [deg] Receive L1 Position(0..360)(deg)*/
 float RxL2; /*< [deg] Receive L2 Position(0..360)(deg)*/
 float RxL3; /*< [deg] Receive L3 Position(0..360)(deg)*/
 float TxL1; /*< [deg] Transmit L1 Position(0..360)(deg)*/
 float TxL2; /*< [deg] Transmit L2 Position(0..360)(deg)*/
 float TxL3; /*< [deg] Transmit L3 Position(0..360)(deg)*/
 uint8_t status; /*<   2bits per motor (0:xx 1:xx 2:xx 3:xx)*/
}) mavlink_motor_status_t;

#define MAVLINK_MSG_ID_MOTOR_STATUS_LEN 33
#define MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN 33
#define MAVLINK_MSG_ID_11_LEN 33
#define MAVLINK_MSG_ID_11_MIN_LEN 33

#define MAVLINK_MSG_ID_MOTOR_STATUS_CRC 47
#define MAVLINK_MSG_ID_11_CRC 47



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTOR_STATUS { \
    11, \
    "MOTOR_STATUS", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_status_t, time_boot_ms) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_motor_status_t, status) }, \
         { "RxL1", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_motor_status_t, RxL1) }, \
         { "RxL2", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_motor_status_t, RxL2) }, \
         { "RxL3", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motor_status_t, RxL3) }, \
         { "TxL1", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_motor_status_t, TxL1) }, \
         { "TxL2", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_motor_status_t, TxL2) }, \
         { "TxL3", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_motor_status_t, TxL3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTOR_STATUS { \
    "MOTOR_STATUS", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_status_t, time_boot_ms) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_motor_status_t, status) }, \
         { "RxL1", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_motor_status_t, RxL1) }, \
         { "RxL2", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_motor_status_t, RxL2) }, \
         { "RxL3", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motor_status_t, RxL3) }, \
         { "TxL1", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_motor_status_t, TxL1) }, \
         { "TxL2", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_motor_status_t, TxL2) }, \
         { "TxL3", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_motor_status_t, TxL3) }, \
         } \
}
#endif

/**
 * @brief Pack a motor_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param status   2bits per motor (0:xx 1:xx 2:xx 3:xx)
 * @param RxL1 [deg] Receive L1 Position(0..360)(deg)
 * @param RxL2 [deg] Receive L2 Position(0..360)(deg)
 * @param RxL3 [deg] Receive L3 Position(0..360)(deg)
 * @param TxL1 [deg] Transmit L1 Position(0..360)(deg)
 * @param TxL2 [deg] Transmit L2 Position(0..360)(deg)
 * @param TxL3 [deg] Transmit L3 Position(0..360)(deg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, uint8_t status, float RxL1, float RxL2, float RxL3, float TxL1, float TxL2, float TxL3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, RxL1);
    _mav_put_float(buf, 12, RxL2);
    _mav_put_float(buf, 16, RxL3);
    _mav_put_float(buf, 20, TxL1);
    _mav_put_float(buf, 24, TxL2);
    _mav_put_float(buf, 28, TxL3);
    _mav_put_uint8_t(buf, 32, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_STATUS_LEN);
#else
    mavlink_motor_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.RxL1 = RxL1;
    packet.RxL2 = RxL2;
    packet.RxL3 = RxL3;
    packet.TxL1 = TxL1;
    packet.TxL2 = TxL2;
    packet.TxL3 = TxL3;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_CRC);
}

/**
 * @brief Pack a motor_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param status   2bits per motor (0:xx 1:xx 2:xx 3:xx)
 * @param RxL1 [deg] Receive L1 Position(0..360)(deg)
 * @param RxL2 [deg] Receive L2 Position(0..360)(deg)
 * @param RxL3 [deg] Receive L3 Position(0..360)(deg)
 * @param TxL1 [deg] Transmit L1 Position(0..360)(deg)
 * @param TxL2 [deg] Transmit L2 Position(0..360)(deg)
 * @param TxL3 [deg] Transmit L3 Position(0..360)(deg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,uint8_t status,float RxL1,float RxL2,float RxL3,float TxL1,float TxL2,float TxL3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, RxL1);
    _mav_put_float(buf, 12, RxL2);
    _mav_put_float(buf, 16, RxL3);
    _mav_put_float(buf, 20, TxL1);
    _mav_put_float(buf, 24, TxL2);
    _mav_put_float(buf, 28, TxL3);
    _mav_put_uint8_t(buf, 32, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_STATUS_LEN);
#else
    mavlink_motor_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.RxL1 = RxL1;
    packet.RxL2 = RxL2;
    packet.RxL3 = RxL3;
    packet.TxL1 = TxL1;
    packet.TxL2 = TxL2;
    packet.TxL3 = TxL3;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_CRC);
}

/**
 * @brief Encode a motor_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_status_t* motor_status)
{
    return mavlink_msg_motor_status_pack(system_id, component_id, msg, motor_status->time_boot_ms, motor_status->status, motor_status->RxL1, motor_status->RxL2, motor_status->RxL3, motor_status->TxL1, motor_status->TxL2, motor_status->TxL3);
}

/**
 * @brief Encode a motor_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_status_t* motor_status)
{
    return mavlink_msg_motor_status_pack_chan(system_id, component_id, chan, msg, motor_status->time_boot_ms, motor_status->status, motor_status->RxL1, motor_status->RxL2, motor_status->RxL3, motor_status->TxL1, motor_status->TxL2, motor_status->TxL3);
}

/**
 * @brief Send a motor_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param status   2bits per motor (0:xx 1:xx 2:xx 3:xx)
 * @param RxL1 [deg] Receive L1 Position(0..360)(deg)
 * @param RxL2 [deg] Receive L2 Position(0..360)(deg)
 * @param RxL3 [deg] Receive L3 Position(0..360)(deg)
 * @param TxL1 [deg] Transmit L1 Position(0..360)(deg)
 * @param TxL2 [deg] Transmit L2 Position(0..360)(deg)
 * @param TxL3 [deg] Transmit L3 Position(0..360)(deg)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_status_send(mavlink_channel_t chan, uint64_t time_boot_ms, uint8_t status, float RxL1, float RxL2, float RxL3, float TxL1, float TxL2, float TxL3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, RxL1);
    _mav_put_float(buf, 12, RxL2);
    _mav_put_float(buf, 16, RxL3);
    _mav_put_float(buf, 20, TxL1);
    _mav_put_float(buf, 24, TxL2);
    _mav_put_float(buf, 28, TxL3);
    _mav_put_uint8_t(buf, 32, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS, buf, MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_CRC);
#else
    mavlink_motor_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.RxL1 = RxL1;
    packet.RxL2 = RxL2;
    packet.RxL3 = RxL3;
    packet.TxL1 = TxL1;
    packet.TxL2 = TxL2;
    packet.TxL3 = TxL3;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_CRC);
#endif
}

/**
 * @brief Send a motor_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motor_status_send_struct(mavlink_channel_t chan, const mavlink_motor_status_t* motor_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motor_status_send(chan, motor_status->time_boot_ms, motor_status->status, motor_status->RxL1, motor_status->RxL2, motor_status->RxL3, motor_status->TxL1, motor_status->TxL2, motor_status->TxL3);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS, (const char *)motor_status, MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTOR_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, uint8_t status, float RxL1, float RxL2, float RxL3, float TxL1, float TxL2, float TxL3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, RxL1);
    _mav_put_float(buf, 12, RxL2);
    _mav_put_float(buf, 16, RxL3);
    _mav_put_float(buf, 20, TxL1);
    _mav_put_float(buf, 24, TxL2);
    _mav_put_float(buf, 28, TxL3);
    _mav_put_uint8_t(buf, 32, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS, buf, MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_CRC);
#else
    mavlink_motor_status_t *packet = (mavlink_motor_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->RxL1 = RxL1;
    packet->RxL2 = RxL2;
    packet->RxL3 = RxL3;
    packet->TxL1 = TxL1;
    packet->TxL2 = TxL2;
    packet->TxL3 = TxL3;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_STATUS, (const char *)packet, MAVLINK_MSG_ID_MOTOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_LEN, MAVLINK_MSG_ID_MOTOR_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTOR_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from motor_status message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_motor_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field status from motor_status message
 *
 * @return   2bits per motor (0:xx 1:xx 2:xx 3:xx)
 */
static inline uint8_t mavlink_msg_motor_status_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field RxL1 from motor_status message
 *
 * @return [deg] Receive L1 Position(0..360)(deg)
 */
static inline float mavlink_msg_motor_status_get_RxL1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field RxL2 from motor_status message
 *
 * @return [deg] Receive L2 Position(0..360)(deg)
 */
static inline float mavlink_msg_motor_status_get_RxL2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field RxL3 from motor_status message
 *
 * @return [deg] Receive L3 Position(0..360)(deg)
 */
static inline float mavlink_msg_motor_status_get_RxL3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field TxL1 from motor_status message
 *
 * @return [deg] Transmit L1 Position(0..360)(deg)
 */
static inline float mavlink_msg_motor_status_get_TxL1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field TxL2 from motor_status message
 *
 * @return [deg] Transmit L2 Position(0..360)(deg)
 */
static inline float mavlink_msg_motor_status_get_TxL2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field TxL3 from motor_status message
 *
 * @return [deg] Transmit L3 Position(0..360)(deg)
 */
static inline float mavlink_msg_motor_status_get_TxL3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a motor_status message into a struct
 *
 * @param msg The message to decode
 * @param motor_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_status_decode(const mavlink_message_t* msg, mavlink_motor_status_t* motor_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motor_status->time_boot_ms = mavlink_msg_motor_status_get_time_boot_ms(msg);
    motor_status->RxL1 = mavlink_msg_motor_status_get_RxL1(msg);
    motor_status->RxL2 = mavlink_msg_motor_status_get_RxL2(msg);
    motor_status->RxL3 = mavlink_msg_motor_status_get_RxL3(msg);
    motor_status->TxL1 = mavlink_msg_motor_status_get_TxL1(msg);
    motor_status->TxL2 = mavlink_msg_motor_status_get_TxL2(msg);
    motor_status->TxL3 = mavlink_msg_motor_status_get_TxL3(msg);
    motor_status->status = mavlink_msg_motor_status_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTOR_STATUS_LEN? msg->len : MAVLINK_MSG_ID_MOTOR_STATUS_LEN;
        memset(motor_status, 0, MAVLINK_MSG_ID_MOTOR_STATUS_LEN);
    memcpy(motor_status, _MAV_PAYLOAD(msg), len);
#endif
}
