#pragma once
// MESSAGE ATTITUDE_BEAM PACKING

#define MAVLINK_MSG_ID_ATTITUDE_BEAM 14

MAVPACKED(
typedef struct __mavlink_attitude_beam_t {
 uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float roll; /*< [deg] Roll angle.(-90.0..90.0)(deg)*/
 float pitch; /*< [deg] Pitch angle.(-90.0..90.0)(deg)*/
 float yaw; /*< [deg] Yaw angle.(-180.0..180.0)(deg)*/
 float altitude; /*< [m] Altitude (MSL).*/
 float q[4]; /*<  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
}) mavlink_attitude_beam_t;

#define MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN 40
#define MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN 40
#define MAVLINK_MSG_ID_14_LEN 40
#define MAVLINK_MSG_ID_14_MIN_LEN 40

#define MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC 50
#define MAVLINK_MSG_ID_14_CRC 50

#define MAVLINK_MSG_ATTITUDE_BEAM_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATTITUDE_BEAM { \
    14, \
    "ATTITUDE_BEAM", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_attitude_beam_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_attitude_beam_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_attitude_beam_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_attitude_beam_t, yaw) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_attitude_beam_t, altitude) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_attitude_beam_t, q) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATTITUDE_BEAM { \
    "ATTITUDE_BEAM", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_attitude_beam_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_attitude_beam_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_attitude_beam_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_attitude_beam_t, yaw) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_attitude_beam_t, altitude) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_attitude_beam_t, q) }, \
         } \
}
#endif

/**
 * @brief Pack a attitude_beam message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll [deg] Roll angle.(-90.0..90.0)(deg)
 * @param pitch [deg] Pitch angle.(-90.0..90.0)(deg)
 * @param yaw [deg] Yaw angle.(-180.0..180.0)(deg)
 * @param altitude [m] Altitude (MSL).
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_beam_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, float roll, float pitch, float yaw, float altitude, const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, altitude);
    _mav_put_float_array(buf, 24, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN);
#else
    mavlink_attitude_beam_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.altitude = altitude;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATTITUDE_BEAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC);
}

/**
 * @brief Pack a attitude_beam message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll [deg] Roll angle.(-90.0..90.0)(deg)
 * @param pitch [deg] Pitch angle.(-90.0..90.0)(deg)
 * @param yaw [deg] Yaw angle.(-180.0..180.0)(deg)
 * @param altitude [m] Altitude (MSL).
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_beam_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,float roll,float pitch,float yaw,float altitude,const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, altitude);
    _mav_put_float_array(buf, 24, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN);
#else
    mavlink_attitude_beam_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.altitude = altitude;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATTITUDE_BEAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC);
}

/**
 * @brief Encode a attitude_beam struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param attitude_beam C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_beam_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_attitude_beam_t* attitude_beam)
{
    return mavlink_msg_attitude_beam_pack(system_id, component_id, msg, attitude_beam->time_boot_ms, attitude_beam->roll, attitude_beam->pitch, attitude_beam->yaw, attitude_beam->altitude, attitude_beam->q);
}

/**
 * @brief Encode a attitude_beam struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param attitude_beam C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_beam_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_attitude_beam_t* attitude_beam)
{
    return mavlink_msg_attitude_beam_pack_chan(system_id, component_id, chan, msg, attitude_beam->time_boot_ms, attitude_beam->roll, attitude_beam->pitch, attitude_beam->yaw, attitude_beam->altitude, attitude_beam->q);
}

/**
 * @brief Send a attitude_beam message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll [deg] Roll angle.(-90.0..90.0)(deg)
 * @param pitch [deg] Pitch angle.(-90.0..90.0)(deg)
 * @param yaw [deg] Yaw angle.(-180.0..180.0)(deg)
 * @param altitude [m] Altitude (MSL).
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_attitude_beam_send(mavlink_channel_t chan, uint64_t time_boot_ms, float roll, float pitch, float yaw, float altitude, const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, altitude);
    _mav_put_float_array(buf, 24, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM, buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC);
#else
    mavlink_attitude_beam_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.altitude = altitude;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM, (const char *)&packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC);
#endif
}

/**
 * @brief Send a attitude_beam message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_attitude_beam_send_struct(mavlink_channel_t chan, const mavlink_attitude_beam_t* attitude_beam)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_attitude_beam_send(chan, attitude_beam->time_boot_ms, attitude_beam->roll, attitude_beam->pitch, attitude_beam->yaw, attitude_beam->altitude, attitude_beam->q);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM, (const char *)attitude_beam, MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_attitude_beam_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, float roll, float pitch, float yaw, float altitude, const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, altitude);
    _mav_put_float_array(buf, 24, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM, buf, MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC);
#else
    mavlink_attitude_beam_t *packet = (mavlink_attitude_beam_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->altitude = altitude;
    mav_array_memcpy(packet->q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BEAM, (const char *)packet, MAVLINK_MSG_ID_ATTITUDE_BEAM_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN, MAVLINK_MSG_ID_ATTITUDE_BEAM_CRC);
#endif
}
#endif

#endif

// MESSAGE ATTITUDE_BEAM UNPACKING


/**
 * @brief Get field time_boot_ms from attitude_beam message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_attitude_beam_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field roll from attitude_beam message
 *
 * @return [deg] Roll angle.(-90.0..90.0)(deg)
 */
static inline float mavlink_msg_attitude_beam_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field pitch from attitude_beam message
 *
 * @return [deg] Pitch angle.(-90.0..90.0)(deg)
 */
static inline float mavlink_msg_attitude_beam_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw from attitude_beam message
 *
 * @return [deg] Yaw angle.(-180.0..180.0)(deg)
 */
static inline float mavlink_msg_attitude_beam_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field altitude from attitude_beam message
 *
 * @return [m] Altitude (MSL).
 */
static inline float mavlink_msg_attitude_beam_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field q from attitude_beam message
 *
 * @return  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 */
static inline uint16_t mavlink_msg_attitude_beam_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  24);
}

/**
 * @brief Decode a attitude_beam message into a struct
 *
 * @param msg The message to decode
 * @param attitude_beam C-struct to decode the message contents into
 */
static inline void mavlink_msg_attitude_beam_decode(const mavlink_message_t* msg, mavlink_attitude_beam_t* attitude_beam)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    attitude_beam->time_boot_ms = mavlink_msg_attitude_beam_get_time_boot_ms(msg);
    attitude_beam->roll = mavlink_msg_attitude_beam_get_roll(msg);
    attitude_beam->pitch = mavlink_msg_attitude_beam_get_pitch(msg);
    attitude_beam->yaw = mavlink_msg_attitude_beam_get_yaw(msg);
    attitude_beam->altitude = mavlink_msg_attitude_beam_get_altitude(msg);
    mavlink_msg_attitude_beam_get_q(msg, attitude_beam->q);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN? msg->len : MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN;
        memset(attitude_beam, 0, MAVLINK_MSG_ID_ATTITUDE_BEAM_LEN);
    memcpy(attitude_beam, _MAV_PAYLOAD(msg), len);
#endif
}
