#pragma once
// MESSAGE HUMITURE PACKING

#define MAVLINK_MSG_ID_HUMITURE 156

MAVPACKED(
typedef struct __mavlink_humiture_t {
 float TEMPRETURE; /*<  power component.*/
 float HUMIDITY; /*<  lock component.*/
}) mavlink_humiture_t;

#define MAVLINK_MSG_ID_HUMITURE_LEN 8
#define MAVLINK_MSG_ID_HUMITURE_MIN_LEN 8
#define MAVLINK_MSG_ID_156_LEN 8
#define MAVLINK_MSG_ID_156_MIN_LEN 8

#define MAVLINK_MSG_ID_HUMITURE_CRC 100
#define MAVLINK_MSG_ID_156_CRC 100



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HUMITURE { \
    156, \
    "HUMITURE", \
    2, \
    {  { "TEMPRETURE", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_humiture_t, TEMPRETURE) }, \
         { "HUMIDITY", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_humiture_t, HUMIDITY) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HUMITURE { \
    "HUMITURE", \
    2, \
    {  { "TEMPRETURE", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_humiture_t, TEMPRETURE) }, \
         { "HUMIDITY", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_humiture_t, HUMIDITY) }, \
         } \
}
#endif

/**
 * @brief Pack a humiture message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param TEMPRETURE  power component.
 * @param HUMIDITY  lock component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_humiture_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float TEMPRETURE, float HUMIDITY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HUMITURE_LEN];
    _mav_put_float(buf, 0, TEMPRETURE);
    _mav_put_float(buf, 4, HUMIDITY);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HUMITURE_LEN);
#else
    mavlink_humiture_t packet;
    packet.TEMPRETURE = TEMPRETURE;
    packet.HUMIDITY = HUMIDITY;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HUMITURE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HUMITURE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HUMITURE_MIN_LEN, MAVLINK_MSG_ID_HUMITURE_LEN, MAVLINK_MSG_ID_HUMITURE_CRC);
}

/**
 * @brief Pack a humiture message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param TEMPRETURE  power component.
 * @param HUMIDITY  lock component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_humiture_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float TEMPRETURE,float HUMIDITY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HUMITURE_LEN];
    _mav_put_float(buf, 0, TEMPRETURE);
    _mav_put_float(buf, 4, HUMIDITY);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HUMITURE_LEN);
#else
    mavlink_humiture_t packet;
    packet.TEMPRETURE = TEMPRETURE;
    packet.HUMIDITY = HUMIDITY;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HUMITURE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HUMITURE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HUMITURE_MIN_LEN, MAVLINK_MSG_ID_HUMITURE_LEN, MAVLINK_MSG_ID_HUMITURE_CRC);
}

/**
 * @brief Encode a humiture struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param humiture C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_humiture_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_humiture_t* humiture)
{
    return mavlink_msg_humiture_pack(system_id, component_id, msg, humiture->TEMPRETURE, humiture->HUMIDITY);
}

/**
 * @brief Encode a humiture struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param humiture C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_humiture_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_humiture_t* humiture)
{
    return mavlink_msg_humiture_pack_chan(system_id, component_id, chan, msg, humiture->TEMPRETURE, humiture->HUMIDITY);
}

/**
 * @brief Send a humiture message
 * @param chan MAVLink channel to send the message
 *
 * @param TEMPRETURE  power component.
 * @param HUMIDITY  lock component.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_humiture_send(mavlink_channel_t chan, float TEMPRETURE, float HUMIDITY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HUMITURE_LEN];
    _mav_put_float(buf, 0, TEMPRETURE);
    _mav_put_float(buf, 4, HUMIDITY);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUMITURE, buf, MAVLINK_MSG_ID_HUMITURE_MIN_LEN, MAVLINK_MSG_ID_HUMITURE_LEN, MAVLINK_MSG_ID_HUMITURE_CRC);
#else
    mavlink_humiture_t packet;
    packet.TEMPRETURE = TEMPRETURE;
    packet.HUMIDITY = HUMIDITY;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUMITURE, (const char *)&packet, MAVLINK_MSG_ID_HUMITURE_MIN_LEN, MAVLINK_MSG_ID_HUMITURE_LEN, MAVLINK_MSG_ID_HUMITURE_CRC);
#endif
}

/**
 * @brief Send a humiture message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_humiture_send_struct(mavlink_channel_t chan, const mavlink_humiture_t* humiture)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_humiture_send(chan, humiture->TEMPRETURE, humiture->HUMIDITY);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUMITURE, (const char *)humiture, MAVLINK_MSG_ID_HUMITURE_MIN_LEN, MAVLINK_MSG_ID_HUMITURE_LEN, MAVLINK_MSG_ID_HUMITURE_CRC);
#endif
}

#if MAVLINK_MSG_ID_HUMITURE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_humiture_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float TEMPRETURE, float HUMIDITY)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, TEMPRETURE);
    _mav_put_float(buf, 4, HUMIDITY);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUMITURE, buf, MAVLINK_MSG_ID_HUMITURE_MIN_LEN, MAVLINK_MSG_ID_HUMITURE_LEN, MAVLINK_MSG_ID_HUMITURE_CRC);
#else
    mavlink_humiture_t *packet = (mavlink_humiture_t *)msgbuf;
    packet->TEMPRETURE = TEMPRETURE;
    packet->HUMIDITY = HUMIDITY;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HUMITURE, (const char *)packet, MAVLINK_MSG_ID_HUMITURE_MIN_LEN, MAVLINK_MSG_ID_HUMITURE_LEN, MAVLINK_MSG_ID_HUMITURE_CRC);
#endif
}
#endif

#endif

// MESSAGE HUMITURE UNPACKING


/**
 * @brief Get field TEMPRETURE from humiture message
 *
 * @return  power component.
 */
static inline float mavlink_msg_humiture_get_TEMPRETURE(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field HUMIDITY from humiture message
 *
 * @return  lock component.
 */
static inline float mavlink_msg_humiture_get_HUMIDITY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a humiture message into a struct
 *
 * @param msg The message to decode
 * @param humiture C-struct to decode the message contents into
 */
static inline void mavlink_msg_humiture_decode(const mavlink_message_t* msg, mavlink_humiture_t* humiture)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    humiture->TEMPRETURE = mavlink_msg_humiture_get_TEMPRETURE(msg);
    humiture->HUMIDITY = mavlink_msg_humiture_get_HUMIDITY(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HUMITURE_LEN? msg->len : MAVLINK_MSG_ID_HUMITURE_LEN;
        memset(humiture, 0, MAVLINK_MSG_ID_HUMITURE_LEN);
    memcpy(humiture, _MAV_PAYLOAD(msg), len);
#endif
}
