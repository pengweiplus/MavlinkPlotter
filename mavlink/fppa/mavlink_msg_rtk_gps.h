#pragma once
// MESSAGE RTK_GPS PACKING

#define MAVLINK_MSG_ID_RTK_GPS 154

MAVPACKED(
typedef struct __mavlink_rtk_gps_t {
 float longitude; /*<  longitude component.*/
 float latitude; /*<   component.*/
 float azimuth; /*<   component.*/
 float height; /*<  longitude component.*/
 float speed; /*<   component.*/
 float orientation; /*<   component.*/
 float com_precision; /*<  longitude component.*/
 float level_precision; /*<   component.*/
 float vertical_precision; /*<   component.*/
 char status; /*<  status component.*/
 char number; /*<   component.*/
 char year; /*<   component.*/
 char month; /*<   component.*/
 char day; /*<   component.*/
 char hour; /*<   component.*/
 char minute; /*<   component.*/
 char second; /*<   component.*/
}) mavlink_rtk_gps_t;

#define MAVLINK_MSG_ID_RTK_GPS_LEN 44
#define MAVLINK_MSG_ID_RTK_GPS_MIN_LEN 44
#define MAVLINK_MSG_ID_154_LEN 44
#define MAVLINK_MSG_ID_154_MIN_LEN 44

#define MAVLINK_MSG_ID_RTK_GPS_CRC 195
#define MAVLINK_MSG_ID_154_CRC 195



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RTK_GPS { \
    154, \
    "RTK_GPS", \
    17, \
    {  { "status", NULL, MAVLINK_TYPE_CHAR, 0, 36, offsetof(mavlink_rtk_gps_t, status) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rtk_gps_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rtk_gps_t, latitude) }, \
         { "azimuth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_rtk_gps_t, azimuth) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_rtk_gps_t, height) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_rtk_gps_t, speed) }, \
         { "orientation", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_rtk_gps_t, orientation) }, \
         { "com_precision", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_rtk_gps_t, com_precision) }, \
         { "level_precision", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_rtk_gps_t, level_precision) }, \
         { "vertical_precision", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_rtk_gps_t, vertical_precision) }, \
         { "number", NULL, MAVLINK_TYPE_CHAR, 0, 37, offsetof(mavlink_rtk_gps_t, number) }, \
         { "year", NULL, MAVLINK_TYPE_CHAR, 0, 38, offsetof(mavlink_rtk_gps_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_CHAR, 0, 39, offsetof(mavlink_rtk_gps_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_CHAR, 0, 40, offsetof(mavlink_rtk_gps_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_CHAR, 0, 41, offsetof(mavlink_rtk_gps_t, hour) }, \
         { "minute", NULL, MAVLINK_TYPE_CHAR, 0, 42, offsetof(mavlink_rtk_gps_t, minute) }, \
         { "second", NULL, MAVLINK_TYPE_CHAR, 0, 43, offsetof(mavlink_rtk_gps_t, second) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RTK_GPS { \
    "RTK_GPS", \
    17, \
    {  { "status", NULL, MAVLINK_TYPE_CHAR, 0, 36, offsetof(mavlink_rtk_gps_t, status) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rtk_gps_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rtk_gps_t, latitude) }, \
         { "azimuth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_rtk_gps_t, azimuth) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_rtk_gps_t, height) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_rtk_gps_t, speed) }, \
         { "orientation", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_rtk_gps_t, orientation) }, \
         { "com_precision", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_rtk_gps_t, com_precision) }, \
         { "level_precision", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_rtk_gps_t, level_precision) }, \
         { "vertical_precision", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_rtk_gps_t, vertical_precision) }, \
         { "number", NULL, MAVLINK_TYPE_CHAR, 0, 37, offsetof(mavlink_rtk_gps_t, number) }, \
         { "year", NULL, MAVLINK_TYPE_CHAR, 0, 38, offsetof(mavlink_rtk_gps_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_CHAR, 0, 39, offsetof(mavlink_rtk_gps_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_CHAR, 0, 40, offsetof(mavlink_rtk_gps_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_CHAR, 0, 41, offsetof(mavlink_rtk_gps_t, hour) }, \
         { "minute", NULL, MAVLINK_TYPE_CHAR, 0, 42, offsetof(mavlink_rtk_gps_t, minute) }, \
         { "second", NULL, MAVLINK_TYPE_CHAR, 0, 43, offsetof(mavlink_rtk_gps_t, second) }, \
         } \
}
#endif

/**
 * @brief Pack a rtk_gps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param status  status component.
 * @param longitude  longitude component.
 * @param latitude   component.
 * @param azimuth   component.
 * @param height  longitude component.
 * @param speed   component.
 * @param orientation   component.
 * @param com_precision  longitude component.
 * @param level_precision   component.
 * @param vertical_precision   component.
 * @param number   component.
 * @param year   component.
 * @param month   component.
 * @param day   component.
 * @param hour   component.
 * @param minute   component.
 * @param second   component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rtk_gps_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               char status, float longitude, float latitude, float azimuth, float height, float speed, float orientation, float com_precision, float level_precision, float vertical_precision, char number, char year, char month, char day, char hour, char minute, char second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTK_GPS_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, orientation);
    _mav_put_float(buf, 24, com_precision);
    _mav_put_float(buf, 28, level_precision);
    _mav_put_float(buf, 32, vertical_precision);
    _mav_put_char(buf, 36, status);
    _mav_put_char(buf, 37, number);
    _mav_put_char(buf, 38, year);
    _mav_put_char(buf, 39, month);
    _mav_put_char(buf, 40, day);
    _mav_put_char(buf, 41, hour);
    _mav_put_char(buf, 42, minute);
    _mav_put_char(buf, 43, second);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTK_GPS_LEN);
#else
    mavlink_rtk_gps_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.azimuth = azimuth;
    packet.height = height;
    packet.speed = speed;
    packet.orientation = orientation;
    packet.com_precision = com_precision;
    packet.level_precision = level_precision;
    packet.vertical_precision = vertical_precision;
    packet.status = status;
    packet.number = number;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.minute = minute;
    packet.second = second;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RTK_GPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RTK_GPS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
}

/**
 * @brief Pack a rtk_gps message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param status  status component.
 * @param longitude  longitude component.
 * @param latitude   component.
 * @param azimuth   component.
 * @param height  longitude component.
 * @param speed   component.
 * @param orientation   component.
 * @param com_precision  longitude component.
 * @param level_precision   component.
 * @param vertical_precision   component.
 * @param number   component.
 * @param year   component.
 * @param month   component.
 * @param day   component.
 * @param hour   component.
 * @param minute   component.
 * @param second   component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rtk_gps_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   char status,float longitude,float latitude,float azimuth,float height,float speed,float orientation,float com_precision,float level_precision,float vertical_precision,char number,char year,char month,char day,char hour,char minute,char second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTK_GPS_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, orientation);
    _mav_put_float(buf, 24, com_precision);
    _mav_put_float(buf, 28, level_precision);
    _mav_put_float(buf, 32, vertical_precision);
    _mav_put_char(buf, 36, status);
    _mav_put_char(buf, 37, number);
    _mav_put_char(buf, 38, year);
    _mav_put_char(buf, 39, month);
    _mav_put_char(buf, 40, day);
    _mav_put_char(buf, 41, hour);
    _mav_put_char(buf, 42, minute);
    _mav_put_char(buf, 43, second);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTK_GPS_LEN);
#else
    mavlink_rtk_gps_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.azimuth = azimuth;
    packet.height = height;
    packet.speed = speed;
    packet.orientation = orientation;
    packet.com_precision = com_precision;
    packet.level_precision = level_precision;
    packet.vertical_precision = vertical_precision;
    packet.status = status;
    packet.number = number;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.minute = minute;
    packet.second = second;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RTK_GPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RTK_GPS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
}

/**
 * @brief Encode a rtk_gps struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rtk_gps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rtk_gps_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rtk_gps_t* rtk_gps)
{
    return mavlink_msg_rtk_gps_pack(system_id, component_id, msg, rtk_gps->status, rtk_gps->longitude, rtk_gps->latitude, rtk_gps->azimuth, rtk_gps->height, rtk_gps->speed, rtk_gps->orientation, rtk_gps->com_precision, rtk_gps->level_precision, rtk_gps->vertical_precision, rtk_gps->number, rtk_gps->year, rtk_gps->month, rtk_gps->day, rtk_gps->hour, rtk_gps->minute, rtk_gps->second);
}

/**
 * @brief Encode a rtk_gps struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rtk_gps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rtk_gps_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rtk_gps_t* rtk_gps)
{
    return mavlink_msg_rtk_gps_pack_chan(system_id, component_id, chan, msg, rtk_gps->status, rtk_gps->longitude, rtk_gps->latitude, rtk_gps->azimuth, rtk_gps->height, rtk_gps->speed, rtk_gps->orientation, rtk_gps->com_precision, rtk_gps->level_precision, rtk_gps->vertical_precision, rtk_gps->number, rtk_gps->year, rtk_gps->month, rtk_gps->day, rtk_gps->hour, rtk_gps->minute, rtk_gps->second);
}

/**
 * @brief Send a rtk_gps message
 * @param chan MAVLink channel to send the message
 *
 * @param status  status component.
 * @param longitude  longitude component.
 * @param latitude   component.
 * @param azimuth   component.
 * @param height  longitude component.
 * @param speed   component.
 * @param orientation   component.
 * @param com_precision  longitude component.
 * @param level_precision   component.
 * @param vertical_precision   component.
 * @param number   component.
 * @param year   component.
 * @param month   component.
 * @param day   component.
 * @param hour   component.
 * @param minute   component.
 * @param second   component.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rtk_gps_send(mavlink_channel_t chan, char status, float longitude, float latitude, float azimuth, float height, float speed, float orientation, float com_precision, float level_precision, float vertical_precision, char number, char year, char month, char day, char hour, char minute, char second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTK_GPS_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, orientation);
    _mav_put_float(buf, 24, com_precision);
    _mav_put_float(buf, 28, level_precision);
    _mav_put_float(buf, 32, vertical_precision);
    _mav_put_char(buf, 36, status);
    _mav_put_char(buf, 37, number);
    _mav_put_char(buf, 38, year);
    _mav_put_char(buf, 39, month);
    _mav_put_char(buf, 40, day);
    _mav_put_char(buf, 41, hour);
    _mav_put_char(buf, 42, minute);
    _mav_put_char(buf, 43, second);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTK_GPS, buf, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
#else
    mavlink_rtk_gps_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.azimuth = azimuth;
    packet.height = height;
    packet.speed = speed;
    packet.orientation = orientation;
    packet.com_precision = com_precision;
    packet.level_precision = level_precision;
    packet.vertical_precision = vertical_precision;
    packet.status = status;
    packet.number = number;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.minute = minute;
    packet.second = second;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTK_GPS, (const char *)&packet, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
#endif
}

/**
 * @brief Send a rtk_gps message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_rtk_gps_send_struct(mavlink_channel_t chan, const mavlink_rtk_gps_t* rtk_gps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rtk_gps_send(chan, rtk_gps->status, rtk_gps->longitude, rtk_gps->latitude, rtk_gps->azimuth, rtk_gps->height, rtk_gps->speed, rtk_gps->orientation, rtk_gps->com_precision, rtk_gps->level_precision, rtk_gps->vertical_precision, rtk_gps->number, rtk_gps->year, rtk_gps->month, rtk_gps->day, rtk_gps->hour, rtk_gps->minute, rtk_gps->second);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTK_GPS, (const char *)rtk_gps, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
#endif
}

#if MAVLINK_MSG_ID_RTK_GPS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rtk_gps_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  char status, float longitude, float latitude, float azimuth, float height, float speed, float orientation, float com_precision, float level_precision, float vertical_precision, char number, char year, char month, char day, char hour, char minute, char second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, orientation);
    _mav_put_float(buf, 24, com_precision);
    _mav_put_float(buf, 28, level_precision);
    _mav_put_float(buf, 32, vertical_precision);
    _mav_put_char(buf, 36, status);
    _mav_put_char(buf, 37, number);
    _mav_put_char(buf, 38, year);
    _mav_put_char(buf, 39, month);
    _mav_put_char(buf, 40, day);
    _mav_put_char(buf, 41, hour);
    _mav_put_char(buf, 42, minute);
    _mav_put_char(buf, 43, second);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTK_GPS, buf, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
#else
    mavlink_rtk_gps_t *packet = (mavlink_rtk_gps_t *)msgbuf;
    packet->longitude = longitude;
    packet->latitude = latitude;
    packet->azimuth = azimuth;
    packet->height = height;
    packet->speed = speed;
    packet->orientation = orientation;
    packet->com_precision = com_precision;
    packet->level_precision = level_precision;
    packet->vertical_precision = vertical_precision;
    packet->status = status;
    packet->number = number;
    packet->year = year;
    packet->month = month;
    packet->day = day;
    packet->hour = hour;
    packet->minute = minute;
    packet->second = second;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTK_GPS, (const char *)packet, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
#endif
}
#endif

#endif

// MESSAGE RTK_GPS UNPACKING


/**
 * @brief Get field status from rtk_gps message
 *
 * @return  status component.
 */
static inline char mavlink_msg_rtk_gps_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  36);
}

/**
 * @brief Get field longitude from rtk_gps message
 *
 * @return  longitude component.
 */
static inline float mavlink_msg_rtk_gps_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field latitude from rtk_gps message
 *
 * @return   component.
 */
static inline float mavlink_msg_rtk_gps_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field azimuth from rtk_gps message
 *
 * @return   component.
 */
static inline float mavlink_msg_rtk_gps_get_azimuth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field height from rtk_gps message
 *
 * @return  longitude component.
 */
static inline float mavlink_msg_rtk_gps_get_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field speed from rtk_gps message
 *
 * @return   component.
 */
static inline float mavlink_msg_rtk_gps_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field orientation from rtk_gps message
 *
 * @return   component.
 */
static inline float mavlink_msg_rtk_gps_get_orientation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field com_precision from rtk_gps message
 *
 * @return  longitude component.
 */
static inline float mavlink_msg_rtk_gps_get_com_precision(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field level_precision from rtk_gps message
 *
 * @return   component.
 */
static inline float mavlink_msg_rtk_gps_get_level_precision(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field vertical_precision from rtk_gps message
 *
 * @return   component.
 */
static inline float mavlink_msg_rtk_gps_get_vertical_precision(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field number from rtk_gps message
 *
 * @return   component.
 */
static inline char mavlink_msg_rtk_gps_get_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  37);
}

/**
 * @brief Get field year from rtk_gps message
 *
 * @return   component.
 */
static inline char mavlink_msg_rtk_gps_get_year(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  38);
}

/**
 * @brief Get field month from rtk_gps message
 *
 * @return   component.
 */
static inline char mavlink_msg_rtk_gps_get_month(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  39);
}

/**
 * @brief Get field day from rtk_gps message
 *
 * @return   component.
 */
static inline char mavlink_msg_rtk_gps_get_day(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  40);
}

/**
 * @brief Get field hour from rtk_gps message
 *
 * @return   component.
 */
static inline char mavlink_msg_rtk_gps_get_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  41);
}

/**
 * @brief Get field minute from rtk_gps message
 *
 * @return   component.
 */
static inline char mavlink_msg_rtk_gps_get_minute(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  42);
}

/**
 * @brief Get field second from rtk_gps message
 *
 * @return   component.
 */
static inline char mavlink_msg_rtk_gps_get_second(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  43);
}

/**
 * @brief Decode a rtk_gps message into a struct
 *
 * @param msg The message to decode
 * @param rtk_gps C-struct to decode the message contents into
 */
static inline void mavlink_msg_rtk_gps_decode(const mavlink_message_t* msg, mavlink_rtk_gps_t* rtk_gps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    rtk_gps->longitude = mavlink_msg_rtk_gps_get_longitude(msg);
    rtk_gps->latitude = mavlink_msg_rtk_gps_get_latitude(msg);
    rtk_gps->azimuth = mavlink_msg_rtk_gps_get_azimuth(msg);
    rtk_gps->height = mavlink_msg_rtk_gps_get_height(msg);
    rtk_gps->speed = mavlink_msg_rtk_gps_get_speed(msg);
    rtk_gps->orientation = mavlink_msg_rtk_gps_get_orientation(msg);
    rtk_gps->com_precision = mavlink_msg_rtk_gps_get_com_precision(msg);
    rtk_gps->level_precision = mavlink_msg_rtk_gps_get_level_precision(msg);
    rtk_gps->vertical_precision = mavlink_msg_rtk_gps_get_vertical_precision(msg);
    rtk_gps->status = mavlink_msg_rtk_gps_get_status(msg);
    rtk_gps->number = mavlink_msg_rtk_gps_get_number(msg);
    rtk_gps->year = mavlink_msg_rtk_gps_get_year(msg);
    rtk_gps->month = mavlink_msg_rtk_gps_get_month(msg);
    rtk_gps->day = mavlink_msg_rtk_gps_get_day(msg);
    rtk_gps->hour = mavlink_msg_rtk_gps_get_hour(msg);
    rtk_gps->minute = mavlink_msg_rtk_gps_get_minute(msg);
    rtk_gps->second = mavlink_msg_rtk_gps_get_second(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RTK_GPS_LEN? msg->len : MAVLINK_MSG_ID_RTK_GPS_LEN;
        memset(rtk_gps, 0, MAVLINK_MSG_ID_RTK_GPS_LEN);
    memcpy(rtk_gps, _MAV_PAYLOAD(msg), len);
#endif
}
