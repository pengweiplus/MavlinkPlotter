#pragma once
// MESSAGE ATTITUDE_BEAM_TARGET PACKING

#define MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET 13

MAVPACKED(
typedef struct __mavlink_attitude_beam_target_t {
 uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float q[4]; /*<  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float roll; /*< [deg] Beam roll rate(-90.0..90.0)(deg)*/
 float pitch; /*< [deg] Beam pitch rate(-90.0..90.0)(deg)*/
 float yaw; /*< [deg] Beam yaw rate(-180.0..180.0)(deg)*/
}) mavlink_attitude_beam_target_t;

#define MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN 36
#define MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN 36
#define MAVLINK_MSG_ID_13_LEN 36
#define MAVLINK_MSG_ID_13_MIN_LEN 36

#define MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC 11
#define MAVLINK_MSG_ID_13_CRC 11

#define MAVLINK_MSG_ATTITUDE_BEAM_TARGET_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATTITUDE_BEAM_TARGET { \
    13, \
    "ATTITUDE_BEAM_TARGET", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_attitude_beam_target_t, time_boot_ms) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_attitude_beam_target_t, q) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_attitude_beam_target_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_attitude_beam_target_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_attitude_beam_target_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATTITUDE_BEAM_TARGET { \
    "ATTITUDE_BEAM_TARGET", \
    5, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_attitude_beam_target_t, time_boot_ms) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_attitude_beam_target_t, q) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_attitude_beam_target_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_attitude_beam_target_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_attitude_beam_target_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a attitude_beam_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param roll [deg] Beam roll rate(-90.0..90.0)(deg)
 * @param pitch [deg] Beam pitch rate(-90.0..90.0)(deg)
 * @param yaw [deg] Beam yaw rate(-180.0..180.0)(deg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_beam_target_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, const float *q, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 24, roll);
    _mav_put_float(buf, 28, pitch);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN);
#else
    mavlink_attitude_beam_target_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC);
}

/**
 * @brief Pack a attitude_beam_target message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param roll [deg] Beam roll rate(-90.0..90.0)(deg)
 * @param pitch [deg] Beam pitch rate(-90.0..90.0)(deg)
 * @param yaw [deg] Beam yaw rate(-180.0..180.0)(deg)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_beam_target_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,const float *q,float roll,float pitch,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 24, roll);
    _mav_put_float(buf, 28, pitch);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN);
#else
    mavlink_attitude_beam_target_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC);
}

/**
 * @brief Encode a attitude_beam_target struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param attitude_beam_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_beam_target_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_attitude_beam_target_t* attitude_beam_target)
{
    return mavlink_msg_attitude_beam_target_pack(system_id, component_id, msg, attitude_beam_target->time_boot_ms, attitude_beam_target->q, attitude_beam_target->roll, attitude_beam_target->pitch, attitude_beam_target->yaw);
}

/**
 * @brief Encode a attitude_beam_target struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param attitude_beam_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_beam_target_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_attitude_beam_target_t* attitude_beam_target)
{
    return mavlink_msg_attitude_beam_target_pack_chan(system_id, component_id, chan, msg, attitude_beam_target->time_boot_ms, attitude_beam_target->q, attitude_beam_target->roll, attitude_beam_target->pitch, attitude_beam_target->yaw);
}

/**
 * @brief Send a attitude_beam_target message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param roll [deg] Beam roll rate(-90.0..90.0)(deg)
 * @param pitch [deg] Beam pitch rate(-90.0..90.0)(deg)
 * @param yaw [deg] Beam yaw rate(-180.0..180.0)(deg)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_attitude_beam_target_send(mavlink_channel_t chan, uint64_t time_boot_ms, const float *q, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 24, roll);
    _mav_put_float(buf, 28, pitch);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float_array(buf, 8, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET, buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC);
#else
    mavlink_attitude_beam_target_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET, (const char *)&packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC);
#endif
}

/**
 * @brief Send a attitude_beam_target message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_attitude_beam_target_send_struct(mavlink_channel_t chan, const mavlink_attitude_beam_target_t* attitude_beam_target)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_attitude_beam_target_send(chan, attitude_beam_target->time_boot_ms, attitude_beam_target->q, attitude_beam_target->roll, attitude_beam_target->pitch, attitude_beam_target->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET, (const char *)attitude_beam_target, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC);
#endif
}

#if MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_attitude_beam_target_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, const float *q, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 24, roll);
    _mav_put_float(buf, 28, pitch);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float_array(buf, 8, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET, buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC);
#else
    mavlink_attitude_beam_target_t *packet = (mavlink_attitude_beam_target_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    mav_array_memcpy(packet->q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET, (const char *)packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_CRC);
#endif
}
#endif

#endif

// MESSAGE ATTITUDE_BEAM_TARGET UNPACKING


/**
 * @brief Get field time_boot_ms from attitude_beam_target message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_attitude_beam_target_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field q from attitude_beam_target message
 *
 * @return  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 */
static inline uint16_t mavlink_msg_attitude_beam_target_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  8);
}

/**
 * @brief Get field roll from attitude_beam_target message
 *
 * @return [deg] Beam roll rate(-90.0..90.0)(deg)
 */
static inline float mavlink_msg_attitude_beam_target_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field pitch from attitude_beam_target message
 *
 * @return [deg] Beam pitch rate(-90.0..90.0)(deg)
 */
static inline float mavlink_msg_attitude_beam_target_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field yaw from attitude_beam_target message
 *
 * @return [deg] Beam yaw rate(-180.0..180.0)(deg)
 */
static inline float mavlink_msg_attitude_beam_target_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a attitude_beam_target message into a struct
 *
 * @param msg The message to decode
 * @param attitude_beam_target C-struct to decode the message contents into
 */
static inline void mavlink_msg_attitude_beam_target_decode(const mavlink_message_t* msg, mavlink_attitude_beam_target_t* attitude_beam_target)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    attitude_beam_target->time_boot_ms = mavlink_msg_attitude_beam_target_get_time_boot_ms(msg);
    mavlink_msg_attitude_beam_target_get_q(msg, attitude_beam_target->q);
    attitude_beam_target->roll = mavlink_msg_attitude_beam_target_get_roll(msg);
    attitude_beam_target->pitch = mavlink_msg_attitude_beam_target_get_pitch(msg);
    attitude_beam_target->yaw = mavlink_msg_attitude_beam_target_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN? msg->len : MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN;
        memset(attitude_beam_target, 0, MAVLINK_MSG_ID_ATTITUDE_BEAM_TARGET_LEN);
    memcpy(attitude_beam_target, _MAV_PAYLOAD(msg), len);
#endif
}
