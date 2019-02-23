#pragma once
// MESSAGE BEACON_POWER PACKING

#define MAVLINK_MSG_ID_BEACON_POWER 18

MAVPACKED(
typedef struct __mavlink_beacon_power_t {
 uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float frequency; /*<  The frequency of satellite signal (17.7GHz..22GHz).*/
 float power; /*<  The power of satellite signal dB.*/
 float LNB_voltage; /*<  The voltage of LNB(13.4V 18.2V 14.6V 19.4V 0v).*/
 uint8_t isLock; /*<  lock component(0:unlock 1:locked).*/
 uint8_t isValid; /*<  valid component(0:invalid 1:valid).*/
}) mavlink_beacon_power_t;

#define MAVLINK_MSG_ID_BEACON_POWER_LEN 22
#define MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN 22
#define MAVLINK_MSG_ID_18_LEN 22
#define MAVLINK_MSG_ID_18_MIN_LEN 22

#define MAVLINK_MSG_ID_BEACON_POWER_CRC 202
#define MAVLINK_MSG_ID_18_CRC 202



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BEACON_POWER { \
    18, \
    "BEACON_POWER", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_beacon_power_t, time_boot_ms) }, \
         { "frequency", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_beacon_power_t, frequency) }, \
         { "power", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_beacon_power_t, power) }, \
         { "LNB_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_beacon_power_t, LNB_voltage) }, \
         { "isLock", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_beacon_power_t, isLock) }, \
         { "isValid", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_beacon_power_t, isValid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BEACON_POWER { \
    "BEACON_POWER", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_beacon_power_t, time_boot_ms) }, \
         { "frequency", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_beacon_power_t, frequency) }, \
         { "power", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_beacon_power_t, power) }, \
         { "LNB_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_beacon_power_t, LNB_voltage) }, \
         { "isLock", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_beacon_power_t, isLock) }, \
         { "isValid", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_beacon_power_t, isValid) }, \
         } \
}
#endif

/**
 * @brief Pack a beacon_power message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param frequency  The frequency of satellite signal (17.7GHz..22GHz).
 * @param power  The power of satellite signal dB.
 * @param LNB_voltage  The voltage of LNB(13.4V 18.2V 14.6V 19.4V 0v).
 * @param isLock  lock component(0:unlock 1:locked).
 * @param isValid  valid component(0:invalid 1:valid).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_beacon_power_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, float frequency, float power, float LNB_voltage, uint8_t isLock, uint8_t isValid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BEACON_POWER_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, frequency);
    _mav_put_float(buf, 12, power);
    _mav_put_float(buf, 16, LNB_voltage);
    _mav_put_uint8_t(buf, 20, isLock);
    _mav_put_uint8_t(buf, 21, isValid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BEACON_POWER_LEN);
#else
    mavlink_beacon_power_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.frequency = frequency;
    packet.power = power;
    packet.LNB_voltage = LNB_voltage;
    packet.isLock = isLock;
    packet.isValid = isValid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BEACON_POWER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BEACON_POWER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN, MAVLINK_MSG_ID_BEACON_POWER_LEN, MAVLINK_MSG_ID_BEACON_POWER_CRC);
}

/**
 * @brief Pack a beacon_power message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param frequency  The frequency of satellite signal (17.7GHz..22GHz).
 * @param power  The power of satellite signal dB.
 * @param LNB_voltage  The voltage of LNB(13.4V 18.2V 14.6V 19.4V 0v).
 * @param isLock  lock component(0:unlock 1:locked).
 * @param isValid  valid component(0:invalid 1:valid).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_beacon_power_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,float frequency,float power,float LNB_voltage,uint8_t isLock,uint8_t isValid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BEACON_POWER_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, frequency);
    _mav_put_float(buf, 12, power);
    _mav_put_float(buf, 16, LNB_voltage);
    _mav_put_uint8_t(buf, 20, isLock);
    _mav_put_uint8_t(buf, 21, isValid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BEACON_POWER_LEN);
#else
    mavlink_beacon_power_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.frequency = frequency;
    packet.power = power;
    packet.LNB_voltage = LNB_voltage;
    packet.isLock = isLock;
    packet.isValid = isValid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BEACON_POWER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BEACON_POWER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN, MAVLINK_MSG_ID_BEACON_POWER_LEN, MAVLINK_MSG_ID_BEACON_POWER_CRC);
}

/**
 * @brief Encode a beacon_power struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param beacon_power C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_beacon_power_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_beacon_power_t* beacon_power)
{
    return mavlink_msg_beacon_power_pack(system_id, component_id, msg, beacon_power->time_boot_ms, beacon_power->frequency, beacon_power->power, beacon_power->LNB_voltage, beacon_power->isLock, beacon_power->isValid);
}

/**
 * @brief Encode a beacon_power struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param beacon_power C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_beacon_power_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_beacon_power_t* beacon_power)
{
    return mavlink_msg_beacon_power_pack_chan(system_id, component_id, chan, msg, beacon_power->time_boot_ms, beacon_power->frequency, beacon_power->power, beacon_power->LNB_voltage, beacon_power->isLock, beacon_power->isValid);
}

/**
 * @brief Send a beacon_power message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param frequency  The frequency of satellite signal (17.7GHz..22GHz).
 * @param power  The power of satellite signal dB.
 * @param LNB_voltage  The voltage of LNB(13.4V 18.2V 14.6V 19.4V 0v).
 * @param isLock  lock component(0:unlock 1:locked).
 * @param isValid  valid component(0:invalid 1:valid).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_beacon_power_send(mavlink_channel_t chan, uint64_t time_boot_ms, float frequency, float power, float LNB_voltage, uint8_t isLock, uint8_t isValid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BEACON_POWER_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, frequency);
    _mav_put_float(buf, 12, power);
    _mav_put_float(buf, 16, LNB_voltage);
    _mav_put_uint8_t(buf, 20, isLock);
    _mav_put_uint8_t(buf, 21, isValid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POWER, buf, MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN, MAVLINK_MSG_ID_BEACON_POWER_LEN, MAVLINK_MSG_ID_BEACON_POWER_CRC);
#else
    mavlink_beacon_power_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.frequency = frequency;
    packet.power = power;
    packet.LNB_voltage = LNB_voltage;
    packet.isLock = isLock;
    packet.isValid = isValid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POWER, (const char *)&packet, MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN, MAVLINK_MSG_ID_BEACON_POWER_LEN, MAVLINK_MSG_ID_BEACON_POWER_CRC);
#endif
}

/**
 * @brief Send a beacon_power message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_beacon_power_send_struct(mavlink_channel_t chan, const mavlink_beacon_power_t* beacon_power)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_beacon_power_send(chan, beacon_power->time_boot_ms, beacon_power->frequency, beacon_power->power, beacon_power->LNB_voltage, beacon_power->isLock, beacon_power->isValid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POWER, (const char *)beacon_power, MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN, MAVLINK_MSG_ID_BEACON_POWER_LEN, MAVLINK_MSG_ID_BEACON_POWER_CRC);
#endif
}

#if MAVLINK_MSG_ID_BEACON_POWER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_beacon_power_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, float frequency, float power, float LNB_voltage, uint8_t isLock, uint8_t isValid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, frequency);
    _mav_put_float(buf, 12, power);
    _mav_put_float(buf, 16, LNB_voltage);
    _mav_put_uint8_t(buf, 20, isLock);
    _mav_put_uint8_t(buf, 21, isValid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POWER, buf, MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN, MAVLINK_MSG_ID_BEACON_POWER_LEN, MAVLINK_MSG_ID_BEACON_POWER_CRC);
#else
    mavlink_beacon_power_t *packet = (mavlink_beacon_power_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->frequency = frequency;
    packet->power = power;
    packet->LNB_voltage = LNB_voltage;
    packet->isLock = isLock;
    packet->isValid = isValid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POWER, (const char *)packet, MAVLINK_MSG_ID_BEACON_POWER_MIN_LEN, MAVLINK_MSG_ID_BEACON_POWER_LEN, MAVLINK_MSG_ID_BEACON_POWER_CRC);
#endif
}
#endif

#endif

// MESSAGE BEACON_POWER UNPACKING


/**
 * @brief Get field time_boot_ms from beacon_power message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_beacon_power_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field frequency from beacon_power message
 *
 * @return  The frequency of satellite signal (17.7GHz..22GHz).
 */
static inline float mavlink_msg_beacon_power_get_frequency(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field power from beacon_power message
 *
 * @return  The power of satellite signal dB.
 */
static inline float mavlink_msg_beacon_power_get_power(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field LNB_voltage from beacon_power message
 *
 * @return  The voltage of LNB(13.4V 18.2V 14.6V 19.4V 0v).
 */
static inline float mavlink_msg_beacon_power_get_LNB_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field isLock from beacon_power message
 *
 * @return  lock component(0:unlock 1:locked).
 */
static inline uint8_t mavlink_msg_beacon_power_get_isLock(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field isValid from beacon_power message
 *
 * @return  valid component(0:invalid 1:valid).
 */
static inline uint8_t mavlink_msg_beacon_power_get_isValid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Decode a beacon_power message into a struct
 *
 * @param msg The message to decode
 * @param beacon_power C-struct to decode the message contents into
 */
static inline void mavlink_msg_beacon_power_decode(const mavlink_message_t* msg, mavlink_beacon_power_t* beacon_power)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    beacon_power->time_boot_ms = mavlink_msg_beacon_power_get_time_boot_ms(msg);
    beacon_power->frequency = mavlink_msg_beacon_power_get_frequency(msg);
    beacon_power->power = mavlink_msg_beacon_power_get_power(msg);
    beacon_power->LNB_voltage = mavlink_msg_beacon_power_get_LNB_voltage(msg);
    beacon_power->isLock = mavlink_msg_beacon_power_get_isLock(msg);
    beacon_power->isValid = mavlink_msg_beacon_power_get_isValid(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BEACON_POWER_LEN? msg->len : MAVLINK_MSG_ID_BEACON_POWER_LEN;
        memset(beacon_power, 0, MAVLINK_MSG_ID_BEACON_POWER_LEN);
    memcpy(beacon_power, _MAV_PAYLOAD(msg), len);
#endif
}
