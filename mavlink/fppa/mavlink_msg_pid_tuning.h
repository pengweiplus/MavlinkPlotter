#pragma once
// MESSAGE PID_TUNING PACKING

#define MAVLINK_MSG_ID_PID_TUNING 255

MAVPACKED(
typedef struct __mavlink_pid_tuning_t {
 uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float roll_desired; /*< [deg] Desired angle.*/
 float roll_achieved; /*< [deg] Achieved angle.*/
 float roll_FF; /*<  FF component.*/
 float roll_P; /*<  P component.*/
 float roll_I; /*<  I component.*/
 float roll_D; /*<  D component.*/
 float pitch_desired; /*< [deg] Desired angle.*/
 float pitch_achieved; /*< [deg] Achieved angle.*/
 float pitchl_FF; /*<  FF component.*/
 float pitch_P; /*<  P component.*/
 float pitch_I; /*<  I component.*/
 float pitch_D; /*<  D component.*/
 float yaw_desired; /*< [deg] Desired angle.*/
 float yaw_achieved; /*< [deg] Achieved angle.*/
 float yaw_FF; /*<  FF component.*/
 float yaw_P; /*<  P component.*/
 float yaw_I; /*<  I component.*/
 float yaw_D; /*<  D component.*/
}) mavlink_pid_tuning_t;

#define MAVLINK_MSG_ID_PID_TUNING_LEN 80
#define MAVLINK_MSG_ID_PID_TUNING_MIN_LEN 80
#define MAVLINK_MSG_ID_255_LEN 80
#define MAVLINK_MSG_ID_255_MIN_LEN 80

#define MAVLINK_MSG_ID_PID_TUNING_CRC 47
#define MAVLINK_MSG_ID_255_CRC 47



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PID_TUNING { \
    255, \
    "PID_TUNING", \
    19, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pid_tuning_t, time_boot_ms) }, \
         { "roll_desired", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_tuning_t, roll_desired) }, \
         { "roll_achieved", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_tuning_t, roll_achieved) }, \
         { "roll_FF", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pid_tuning_t, roll_FF) }, \
         { "roll_P", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pid_tuning_t, roll_P) }, \
         { "roll_I", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_pid_tuning_t, roll_I) }, \
         { "roll_D", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_pid_tuning_t, roll_D) }, \
         { "pitch_desired", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_pid_tuning_t, pitch_desired) }, \
         { "pitch_achieved", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_pid_tuning_t, pitch_achieved) }, \
         { "pitchl_FF", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_pid_tuning_t, pitchl_FF) }, \
         { "pitch_P", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_pid_tuning_t, pitch_P) }, \
         { "pitch_I", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_pid_tuning_t, pitch_I) }, \
         { "pitch_D", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_pid_tuning_t, pitch_D) }, \
         { "yaw_desired", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_pid_tuning_t, yaw_desired) }, \
         { "yaw_achieved", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_pid_tuning_t, yaw_achieved) }, \
         { "yaw_FF", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_pid_tuning_t, yaw_FF) }, \
         { "yaw_P", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_pid_tuning_t, yaw_P) }, \
         { "yaw_I", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_pid_tuning_t, yaw_I) }, \
         { "yaw_D", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_pid_tuning_t, yaw_D) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PID_TUNING { \
    "PID_TUNING", \
    19, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pid_tuning_t, time_boot_ms) }, \
         { "roll_desired", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_tuning_t, roll_desired) }, \
         { "roll_achieved", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_tuning_t, roll_achieved) }, \
         { "roll_FF", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pid_tuning_t, roll_FF) }, \
         { "roll_P", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pid_tuning_t, roll_P) }, \
         { "roll_I", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_pid_tuning_t, roll_I) }, \
         { "roll_D", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_pid_tuning_t, roll_D) }, \
         { "pitch_desired", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_pid_tuning_t, pitch_desired) }, \
         { "pitch_achieved", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_pid_tuning_t, pitch_achieved) }, \
         { "pitchl_FF", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_pid_tuning_t, pitchl_FF) }, \
         { "pitch_P", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_pid_tuning_t, pitch_P) }, \
         { "pitch_I", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_pid_tuning_t, pitch_I) }, \
         { "pitch_D", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_pid_tuning_t, pitch_D) }, \
         { "yaw_desired", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_pid_tuning_t, yaw_desired) }, \
         { "yaw_achieved", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_pid_tuning_t, yaw_achieved) }, \
         { "yaw_FF", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_pid_tuning_t, yaw_FF) }, \
         { "yaw_P", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_pid_tuning_t, yaw_P) }, \
         { "yaw_I", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_pid_tuning_t, yaw_I) }, \
         { "yaw_D", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_pid_tuning_t, yaw_D) }, \
         } \
}
#endif

/**
 * @brief Pack a pid_tuning message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll_desired [deg] Desired angle.
 * @param roll_achieved [deg] Achieved angle.
 * @param roll_FF  FF component.
 * @param roll_P  P component.
 * @param roll_I  I component.
 * @param roll_D  D component.
 * @param pitch_desired [deg] Desired angle.
 * @param pitch_achieved [deg] Achieved angle.
 * @param pitchl_FF  FF component.
 * @param pitch_P  P component.
 * @param pitch_I  I component.
 * @param pitch_D  D component.
 * @param yaw_desired [deg] Desired angle.
 * @param yaw_achieved [deg] Achieved angle.
 * @param yaw_FF  FF component.
 * @param yaw_P  P component.
 * @param yaw_I  I component.
 * @param yaw_D  D component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_tuning_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, float roll_desired, float roll_achieved, float roll_FF, float roll_P, float roll_I, float roll_D, float pitch_desired, float pitch_achieved, float pitchl_FF, float pitch_P, float pitch_I, float pitch_D, float yaw_desired, float yaw_achieved, float yaw_FF, float yaw_P, float yaw_I, float yaw_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_TUNING_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll_desired);
    _mav_put_float(buf, 12, roll_achieved);
    _mav_put_float(buf, 16, roll_FF);
    _mav_put_float(buf, 20, roll_P);
    _mav_put_float(buf, 24, roll_I);
    _mav_put_float(buf, 28, roll_D);
    _mav_put_float(buf, 32, pitch_desired);
    _mav_put_float(buf, 36, pitch_achieved);
    _mav_put_float(buf, 40, pitchl_FF);
    _mav_put_float(buf, 44, pitch_P);
    _mav_put_float(buf, 48, pitch_I);
    _mav_put_float(buf, 52, pitch_D);
    _mav_put_float(buf, 56, yaw_desired);
    _mav_put_float(buf, 60, yaw_achieved);
    _mav_put_float(buf, 64, yaw_FF);
    _mav_put_float(buf, 68, yaw_P);
    _mav_put_float(buf, 72, yaw_I);
    _mav_put_float(buf, 76, yaw_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_TUNING_LEN);
#else
    mavlink_pid_tuning_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll_desired = roll_desired;
    packet.roll_achieved = roll_achieved;
    packet.roll_FF = roll_FF;
    packet.roll_P = roll_P;
    packet.roll_I = roll_I;
    packet.roll_D = roll_D;
    packet.pitch_desired = pitch_desired;
    packet.pitch_achieved = pitch_achieved;
    packet.pitchl_FF = pitchl_FF;
    packet.pitch_P = pitch_P;
    packet.pitch_I = pitch_I;
    packet.pitch_D = pitch_D;
    packet.yaw_desired = yaw_desired;
    packet.yaw_achieved = yaw_achieved;
    packet.yaw_FF = yaw_FF;
    packet.yaw_P = yaw_P;
    packet.yaw_I = yaw_I;
    packet.yaw_D = yaw_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_TUNING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_TUNING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_TUNING_MIN_LEN, MAVLINK_MSG_ID_PID_TUNING_LEN, MAVLINK_MSG_ID_PID_TUNING_CRC);
}

/**
 * @brief Pack a pid_tuning message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll_desired [deg] Desired angle.
 * @param roll_achieved [deg] Achieved angle.
 * @param roll_FF  FF component.
 * @param roll_P  P component.
 * @param roll_I  I component.
 * @param roll_D  D component.
 * @param pitch_desired [deg] Desired angle.
 * @param pitch_achieved [deg] Achieved angle.
 * @param pitchl_FF  FF component.
 * @param pitch_P  P component.
 * @param pitch_I  I component.
 * @param pitch_D  D component.
 * @param yaw_desired [deg] Desired angle.
 * @param yaw_achieved [deg] Achieved angle.
 * @param yaw_FF  FF component.
 * @param yaw_P  P component.
 * @param yaw_I  I component.
 * @param yaw_D  D component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_tuning_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,float roll_desired,float roll_achieved,float roll_FF,float roll_P,float roll_I,float roll_D,float pitch_desired,float pitch_achieved,float pitchl_FF,float pitch_P,float pitch_I,float pitch_D,float yaw_desired,float yaw_achieved,float yaw_FF,float yaw_P,float yaw_I,float yaw_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_TUNING_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll_desired);
    _mav_put_float(buf, 12, roll_achieved);
    _mav_put_float(buf, 16, roll_FF);
    _mav_put_float(buf, 20, roll_P);
    _mav_put_float(buf, 24, roll_I);
    _mav_put_float(buf, 28, roll_D);
    _mav_put_float(buf, 32, pitch_desired);
    _mav_put_float(buf, 36, pitch_achieved);
    _mav_put_float(buf, 40, pitchl_FF);
    _mav_put_float(buf, 44, pitch_P);
    _mav_put_float(buf, 48, pitch_I);
    _mav_put_float(buf, 52, pitch_D);
    _mav_put_float(buf, 56, yaw_desired);
    _mav_put_float(buf, 60, yaw_achieved);
    _mav_put_float(buf, 64, yaw_FF);
    _mav_put_float(buf, 68, yaw_P);
    _mav_put_float(buf, 72, yaw_I);
    _mav_put_float(buf, 76, yaw_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_TUNING_LEN);
#else
    mavlink_pid_tuning_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll_desired = roll_desired;
    packet.roll_achieved = roll_achieved;
    packet.roll_FF = roll_FF;
    packet.roll_P = roll_P;
    packet.roll_I = roll_I;
    packet.roll_D = roll_D;
    packet.pitch_desired = pitch_desired;
    packet.pitch_achieved = pitch_achieved;
    packet.pitchl_FF = pitchl_FF;
    packet.pitch_P = pitch_P;
    packet.pitch_I = pitch_I;
    packet.pitch_D = pitch_D;
    packet.yaw_desired = yaw_desired;
    packet.yaw_achieved = yaw_achieved;
    packet.yaw_FF = yaw_FF;
    packet.yaw_P = yaw_P;
    packet.yaw_I = yaw_I;
    packet.yaw_D = yaw_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_TUNING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_TUNING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_TUNING_MIN_LEN, MAVLINK_MSG_ID_PID_TUNING_LEN, MAVLINK_MSG_ID_PID_TUNING_CRC);
}

/**
 * @brief Encode a pid_tuning struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_tuning C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_tuning_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_tuning_t* pid_tuning)
{
    return mavlink_msg_pid_tuning_pack(system_id, component_id, msg, pid_tuning->time_boot_ms, pid_tuning->roll_desired, pid_tuning->roll_achieved, pid_tuning->roll_FF, pid_tuning->roll_P, pid_tuning->roll_I, pid_tuning->roll_D, pid_tuning->pitch_desired, pid_tuning->pitch_achieved, pid_tuning->pitchl_FF, pid_tuning->pitch_P, pid_tuning->pitch_I, pid_tuning->pitch_D, pid_tuning->yaw_desired, pid_tuning->yaw_achieved, pid_tuning->yaw_FF, pid_tuning->yaw_P, pid_tuning->yaw_I, pid_tuning->yaw_D);
}

/**
 * @brief Encode a pid_tuning struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_tuning C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_tuning_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pid_tuning_t* pid_tuning)
{
    return mavlink_msg_pid_tuning_pack_chan(system_id, component_id, chan, msg, pid_tuning->time_boot_ms, pid_tuning->roll_desired, pid_tuning->roll_achieved, pid_tuning->roll_FF, pid_tuning->roll_P, pid_tuning->roll_I, pid_tuning->roll_D, pid_tuning->pitch_desired, pid_tuning->pitch_achieved, pid_tuning->pitchl_FF, pid_tuning->pitch_P, pid_tuning->pitch_I, pid_tuning->pitch_D, pid_tuning->yaw_desired, pid_tuning->yaw_achieved, pid_tuning->yaw_FF, pid_tuning->yaw_P, pid_tuning->yaw_I, pid_tuning->yaw_D);
}

/**
 * @brief Send a pid_tuning message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll_desired [deg] Desired angle.
 * @param roll_achieved [deg] Achieved angle.
 * @param roll_FF  FF component.
 * @param roll_P  P component.
 * @param roll_I  I component.
 * @param roll_D  D component.
 * @param pitch_desired [deg] Desired angle.
 * @param pitch_achieved [deg] Achieved angle.
 * @param pitchl_FF  FF component.
 * @param pitch_P  P component.
 * @param pitch_I  I component.
 * @param pitch_D  D component.
 * @param yaw_desired [deg] Desired angle.
 * @param yaw_achieved [deg] Achieved angle.
 * @param yaw_FF  FF component.
 * @param yaw_P  P component.
 * @param yaw_I  I component.
 * @param yaw_D  D component.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pid_tuning_send(mavlink_channel_t chan, uint64_t time_boot_ms, float roll_desired, float roll_achieved, float roll_FF, float roll_P, float roll_I, float roll_D, float pitch_desired, float pitch_achieved, float pitchl_FF, float pitch_P, float pitch_I, float pitch_D, float yaw_desired, float yaw_achieved, float yaw_FF, float yaw_P, float yaw_I, float yaw_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_TUNING_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll_desired);
    _mav_put_float(buf, 12, roll_achieved);
    _mav_put_float(buf, 16, roll_FF);
    _mav_put_float(buf, 20, roll_P);
    _mav_put_float(buf, 24, roll_I);
    _mav_put_float(buf, 28, roll_D);
    _mav_put_float(buf, 32, pitch_desired);
    _mav_put_float(buf, 36, pitch_achieved);
    _mav_put_float(buf, 40, pitchl_FF);
    _mav_put_float(buf, 44, pitch_P);
    _mav_put_float(buf, 48, pitch_I);
    _mav_put_float(buf, 52, pitch_D);
    _mav_put_float(buf, 56, yaw_desired);
    _mav_put_float(buf, 60, yaw_achieved);
    _mav_put_float(buf, 64, yaw_FF);
    _mav_put_float(buf, 68, yaw_P);
    _mav_put_float(buf, 72, yaw_I);
    _mav_put_float(buf, 76, yaw_D);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNING, buf, MAVLINK_MSG_ID_PID_TUNING_MIN_LEN, MAVLINK_MSG_ID_PID_TUNING_LEN, MAVLINK_MSG_ID_PID_TUNING_CRC);
#else
    mavlink_pid_tuning_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll_desired = roll_desired;
    packet.roll_achieved = roll_achieved;
    packet.roll_FF = roll_FF;
    packet.roll_P = roll_P;
    packet.roll_I = roll_I;
    packet.roll_D = roll_D;
    packet.pitch_desired = pitch_desired;
    packet.pitch_achieved = pitch_achieved;
    packet.pitchl_FF = pitchl_FF;
    packet.pitch_P = pitch_P;
    packet.pitch_I = pitch_I;
    packet.pitch_D = pitch_D;
    packet.yaw_desired = yaw_desired;
    packet.yaw_achieved = yaw_achieved;
    packet.yaw_FF = yaw_FF;
    packet.yaw_P = yaw_P;
    packet.yaw_I = yaw_I;
    packet.yaw_D = yaw_D;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNING, (const char *)&packet, MAVLINK_MSG_ID_PID_TUNING_MIN_LEN, MAVLINK_MSG_ID_PID_TUNING_LEN, MAVLINK_MSG_ID_PID_TUNING_CRC);
#endif
}

/**
 * @brief Send a pid_tuning message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pid_tuning_send_struct(mavlink_channel_t chan, const mavlink_pid_tuning_t* pid_tuning)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pid_tuning_send(chan, pid_tuning->time_boot_ms, pid_tuning->roll_desired, pid_tuning->roll_achieved, pid_tuning->roll_FF, pid_tuning->roll_P, pid_tuning->roll_I, pid_tuning->roll_D, pid_tuning->pitch_desired, pid_tuning->pitch_achieved, pid_tuning->pitchl_FF, pid_tuning->pitch_P, pid_tuning->pitch_I, pid_tuning->pitch_D, pid_tuning->yaw_desired, pid_tuning->yaw_achieved, pid_tuning->yaw_FF, pid_tuning->yaw_P, pid_tuning->yaw_I, pid_tuning->yaw_D);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNING, (const char *)pid_tuning, MAVLINK_MSG_ID_PID_TUNING_MIN_LEN, MAVLINK_MSG_ID_PID_TUNING_LEN, MAVLINK_MSG_ID_PID_TUNING_CRC);
#endif
}

#if MAVLINK_MSG_ID_PID_TUNING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pid_tuning_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, float roll_desired, float roll_achieved, float roll_FF, float roll_P, float roll_I, float roll_D, float pitch_desired, float pitch_achieved, float pitchl_FF, float pitch_P, float pitch_I, float pitch_D, float yaw_desired, float yaw_achieved, float yaw_FF, float yaw_P, float yaw_I, float yaw_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll_desired);
    _mav_put_float(buf, 12, roll_achieved);
    _mav_put_float(buf, 16, roll_FF);
    _mav_put_float(buf, 20, roll_P);
    _mav_put_float(buf, 24, roll_I);
    _mav_put_float(buf, 28, roll_D);
    _mav_put_float(buf, 32, pitch_desired);
    _mav_put_float(buf, 36, pitch_achieved);
    _mav_put_float(buf, 40, pitchl_FF);
    _mav_put_float(buf, 44, pitch_P);
    _mav_put_float(buf, 48, pitch_I);
    _mav_put_float(buf, 52, pitch_D);
    _mav_put_float(buf, 56, yaw_desired);
    _mav_put_float(buf, 60, yaw_achieved);
    _mav_put_float(buf, 64, yaw_FF);
    _mav_put_float(buf, 68, yaw_P);
    _mav_put_float(buf, 72, yaw_I);
    _mav_put_float(buf, 76, yaw_D);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNING, buf, MAVLINK_MSG_ID_PID_TUNING_MIN_LEN, MAVLINK_MSG_ID_PID_TUNING_LEN, MAVLINK_MSG_ID_PID_TUNING_CRC);
#else
    mavlink_pid_tuning_t *packet = (mavlink_pid_tuning_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->roll_desired = roll_desired;
    packet->roll_achieved = roll_achieved;
    packet->roll_FF = roll_FF;
    packet->roll_P = roll_P;
    packet->roll_I = roll_I;
    packet->roll_D = roll_D;
    packet->pitch_desired = pitch_desired;
    packet->pitch_achieved = pitch_achieved;
    packet->pitchl_FF = pitchl_FF;
    packet->pitch_P = pitch_P;
    packet->pitch_I = pitch_I;
    packet->pitch_D = pitch_D;
    packet->yaw_desired = yaw_desired;
    packet->yaw_achieved = yaw_achieved;
    packet->yaw_FF = yaw_FF;
    packet->yaw_P = yaw_P;
    packet->yaw_I = yaw_I;
    packet->yaw_D = yaw_D;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_TUNING, (const char *)packet, MAVLINK_MSG_ID_PID_TUNING_MIN_LEN, MAVLINK_MSG_ID_PID_TUNING_LEN, MAVLINK_MSG_ID_PID_TUNING_CRC);
#endif
}
#endif

#endif

// MESSAGE PID_TUNING UNPACKING


/**
 * @brief Get field time_boot_ms from pid_tuning message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_pid_tuning_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field roll_desired from pid_tuning message
 *
 * @return [deg] Desired angle.
 */
static inline float mavlink_msg_pid_tuning_get_roll_desired(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field roll_achieved from pid_tuning message
 *
 * @return [deg] Achieved angle.
 */
static inline float mavlink_msg_pid_tuning_get_roll_achieved(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field roll_FF from pid_tuning message
 *
 * @return  FF component.
 */
static inline float mavlink_msg_pid_tuning_get_roll_FF(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field roll_P from pid_tuning message
 *
 * @return  P component.
 */
static inline float mavlink_msg_pid_tuning_get_roll_P(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field roll_I from pid_tuning message
 *
 * @return  I component.
 */
static inline float mavlink_msg_pid_tuning_get_roll_I(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field roll_D from pid_tuning message
 *
 * @return  D component.
 */
static inline float mavlink_msg_pid_tuning_get_roll_D(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field pitch_desired from pid_tuning message
 *
 * @return [deg] Desired angle.
 */
static inline float mavlink_msg_pid_tuning_get_pitch_desired(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field pitch_achieved from pid_tuning message
 *
 * @return [deg] Achieved angle.
 */
static inline float mavlink_msg_pid_tuning_get_pitch_achieved(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field pitchl_FF from pid_tuning message
 *
 * @return  FF component.
 */
static inline float mavlink_msg_pid_tuning_get_pitchl_FF(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field pitch_P from pid_tuning message
 *
 * @return  P component.
 */
static inline float mavlink_msg_pid_tuning_get_pitch_P(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field pitch_I from pid_tuning message
 *
 * @return  I component.
 */
static inline float mavlink_msg_pid_tuning_get_pitch_I(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field pitch_D from pid_tuning message
 *
 * @return  D component.
 */
static inline float mavlink_msg_pid_tuning_get_pitch_D(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field yaw_desired from pid_tuning message
 *
 * @return [deg] Desired angle.
 */
static inline float mavlink_msg_pid_tuning_get_yaw_desired(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field yaw_achieved from pid_tuning message
 *
 * @return [deg] Achieved angle.
 */
static inline float mavlink_msg_pid_tuning_get_yaw_achieved(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field yaw_FF from pid_tuning message
 *
 * @return  FF component.
 */
static inline float mavlink_msg_pid_tuning_get_yaw_FF(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field yaw_P from pid_tuning message
 *
 * @return  P component.
 */
static inline float mavlink_msg_pid_tuning_get_yaw_P(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field yaw_I from pid_tuning message
 *
 * @return  I component.
 */
static inline float mavlink_msg_pid_tuning_get_yaw_I(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field yaw_D from pid_tuning message
 *
 * @return  D component.
 */
static inline float mavlink_msg_pid_tuning_get_yaw_D(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Decode a pid_tuning message into a struct
 *
 * @param msg The message to decode
 * @param pid_tuning C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_tuning_decode(const mavlink_message_t* msg, mavlink_pid_tuning_t* pid_tuning)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pid_tuning->time_boot_ms = mavlink_msg_pid_tuning_get_time_boot_ms(msg);
    pid_tuning->roll_desired = mavlink_msg_pid_tuning_get_roll_desired(msg);
    pid_tuning->roll_achieved = mavlink_msg_pid_tuning_get_roll_achieved(msg);
    pid_tuning->roll_FF = mavlink_msg_pid_tuning_get_roll_FF(msg);
    pid_tuning->roll_P = mavlink_msg_pid_tuning_get_roll_P(msg);
    pid_tuning->roll_I = mavlink_msg_pid_tuning_get_roll_I(msg);
    pid_tuning->roll_D = mavlink_msg_pid_tuning_get_roll_D(msg);
    pid_tuning->pitch_desired = mavlink_msg_pid_tuning_get_pitch_desired(msg);
    pid_tuning->pitch_achieved = mavlink_msg_pid_tuning_get_pitch_achieved(msg);
    pid_tuning->pitchl_FF = mavlink_msg_pid_tuning_get_pitchl_FF(msg);
    pid_tuning->pitch_P = mavlink_msg_pid_tuning_get_pitch_P(msg);
    pid_tuning->pitch_I = mavlink_msg_pid_tuning_get_pitch_I(msg);
    pid_tuning->pitch_D = mavlink_msg_pid_tuning_get_pitch_D(msg);
    pid_tuning->yaw_desired = mavlink_msg_pid_tuning_get_yaw_desired(msg);
    pid_tuning->yaw_achieved = mavlink_msg_pid_tuning_get_yaw_achieved(msg);
    pid_tuning->yaw_FF = mavlink_msg_pid_tuning_get_yaw_FF(msg);
    pid_tuning->yaw_P = mavlink_msg_pid_tuning_get_yaw_P(msg);
    pid_tuning->yaw_I = mavlink_msg_pid_tuning_get_yaw_I(msg);
    pid_tuning->yaw_D = mavlink_msg_pid_tuning_get_yaw_D(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PID_TUNING_LEN? msg->len : MAVLINK_MSG_ID_PID_TUNING_LEN;
        memset(pid_tuning, 0, MAVLINK_MSG_ID_PID_TUNING_LEN);
    memcpy(pid_tuning, _MAV_PAYLOAD(msg), len);
#endif
}
