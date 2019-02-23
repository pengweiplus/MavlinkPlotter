#pragma once
// MESSAGE RTK_GPS PACKING

#define MAVLINK_MSG_ID_RTK_GPS 16

MAVPACKED(
typedef struct __mavlink_rtk_gps_t {
 float longitude; /*<  longitude.(deg)*/
 float latitude; /*<   latitude.(deg)*/
 float azimuth; /*<   azimuth.(-180..180)(deg)*/
 float height; /*<  height (-999.9..9999.9)(meter).*/
 float speed; /*<   speed (000.0..999.9)(Knots).*/
 float course; /*<   course (-180.0..180.0)(deg).*/
 float pdop; /*<  pdop (0.5..99.9).*/
 float hdop; /*<   hdop (0.5..99.9).*/
 float vdop; /*<   vdop (0.5..99.9).*/
 uint8_t fix_type; /*<  GPS fix type 1:no-fix,2:2D-fix,3:3D-fix.*/
 uint8_t satellite_nums; /*<   satellite_nums (0..24)(GPS+BDS).*/
 uint8_t year; /*<   component.*/
 uint8_t month; /*<   component.*/
 uint8_t day; /*<   component.*/
 uint8_t hour; /*<   component.*/
 uint8_t minute; /*<   component.*/
 uint8_t second; /*<   component.*/
}) mavlink_rtk_gps_t;

#define MAVLINK_MSG_ID_RTK_GPS_LEN 44
#define MAVLINK_MSG_ID_RTK_GPS_MIN_LEN 44
#define MAVLINK_MSG_ID_16_LEN 44
#define MAVLINK_MSG_ID_16_MIN_LEN 44

#define MAVLINK_MSG_ID_RTK_GPS_CRC 220
#define MAVLINK_MSG_ID_16_CRC 220



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RTK_GPS { \
    16, \
    "RTK_GPS", \
    17, \
    {  { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_rtk_gps_t, fix_type) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rtk_gps_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rtk_gps_t, latitude) }, \
         { "azimuth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_rtk_gps_t, azimuth) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_rtk_gps_t, height) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_rtk_gps_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_rtk_gps_t, course) }, \
         { "pdop", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_rtk_gps_t, pdop) }, \
         { "hdop", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_rtk_gps_t, hdop) }, \
         { "vdop", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_rtk_gps_t, vdop) }, \
         { "satellite_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_rtk_gps_t, satellite_nums) }, \
         { "year", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_rtk_gps_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_rtk_gps_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_rtk_gps_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_rtk_gps_t, hour) }, \
         { "minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_rtk_gps_t, minute) }, \
         { "second", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_rtk_gps_t, second) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RTK_GPS { \
    "RTK_GPS", \
    17, \
    {  { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_rtk_gps_t, fix_type) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_rtk_gps_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_rtk_gps_t, latitude) }, \
         { "azimuth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_rtk_gps_t, azimuth) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_rtk_gps_t, height) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_rtk_gps_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_rtk_gps_t, course) }, \
         { "pdop", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_rtk_gps_t, pdop) }, \
         { "hdop", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_rtk_gps_t, hdop) }, \
         { "vdop", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_rtk_gps_t, vdop) }, \
         { "satellite_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_rtk_gps_t, satellite_nums) }, \
         { "year", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_rtk_gps_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_rtk_gps_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_rtk_gps_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_rtk_gps_t, hour) }, \
         { "minute", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_rtk_gps_t, minute) }, \
         { "second", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_rtk_gps_t, second) }, \
         } \
}
#endif

/**
 * @brief Pack a rtk_gps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param fix_type  GPS fix type 1:no-fix,2:2D-fix,3:3D-fix.
 * @param longitude  longitude.(deg)
 * @param latitude   latitude.(deg)
 * @param azimuth   azimuth.(-180..180)(deg)
 * @param height  height (-999.9..9999.9)(meter).
 * @param speed   speed (000.0..999.9)(Knots).
 * @param course   course (-180.0..180.0)(deg).
 * @param pdop  pdop (0.5..99.9).
 * @param hdop   hdop (0.5..99.9).
 * @param vdop   vdop (0.5..99.9).
 * @param satellite_nums   satellite_nums (0..24)(GPS+BDS).
 * @param year   component.
 * @param month   component.
 * @param day   component.
 * @param hour   component.
 * @param minute   component.
 * @param second   component.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rtk_gps_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t fix_type, float longitude, float latitude, float azimuth, float height, float speed, float course, float pdop, float hdop, float vdop, uint8_t satellite_nums, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTK_GPS_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, course);
    _mav_put_float(buf, 24, pdop);
    _mav_put_float(buf, 28, hdop);
    _mav_put_float(buf, 32, vdop);
    _mav_put_uint8_t(buf, 36, fix_type);
    _mav_put_uint8_t(buf, 37, satellite_nums);
    _mav_put_uint8_t(buf, 38, year);
    _mav_put_uint8_t(buf, 39, month);
    _mav_put_uint8_t(buf, 40, day);
    _mav_put_uint8_t(buf, 41, hour);
    _mav_put_uint8_t(buf, 42, minute);
    _mav_put_uint8_t(buf, 43, second);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTK_GPS_LEN);
#else
    mavlink_rtk_gps_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.azimuth = azimuth;
    packet.height = height;
    packet.speed = speed;
    packet.course = course;
    packet.pdop = pdop;
    packet.hdop = hdop;
    packet.vdop = vdop;
    packet.fix_type = fix_type;
    packet.satellite_nums = satellite_nums;
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
 * @param fix_type  GPS fix type 1:no-fix,2:2D-fix,3:3D-fix.
 * @param longitude  longitude.(deg)
 * @param latitude   latitude.(deg)
 * @param azimuth   azimuth.(-180..180)(deg)
 * @param height  height (-999.9..9999.9)(meter).
 * @param speed   speed (000.0..999.9)(Knots).
 * @param course   course (-180.0..180.0)(deg).
 * @param pdop  pdop (0.5..99.9).
 * @param hdop   hdop (0.5..99.9).
 * @param vdop   vdop (0.5..99.9).
 * @param satellite_nums   satellite_nums (0..24)(GPS+BDS).
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
                                   uint8_t fix_type,float longitude,float latitude,float azimuth,float height,float speed,float course,float pdop,float hdop,float vdop,uint8_t satellite_nums,uint8_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTK_GPS_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, course);
    _mav_put_float(buf, 24, pdop);
    _mav_put_float(buf, 28, hdop);
    _mav_put_float(buf, 32, vdop);
    _mav_put_uint8_t(buf, 36, fix_type);
    _mav_put_uint8_t(buf, 37, satellite_nums);
    _mav_put_uint8_t(buf, 38, year);
    _mav_put_uint8_t(buf, 39, month);
    _mav_put_uint8_t(buf, 40, day);
    _mav_put_uint8_t(buf, 41, hour);
    _mav_put_uint8_t(buf, 42, minute);
    _mav_put_uint8_t(buf, 43, second);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTK_GPS_LEN);
#else
    mavlink_rtk_gps_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.azimuth = azimuth;
    packet.height = height;
    packet.speed = speed;
    packet.course = course;
    packet.pdop = pdop;
    packet.hdop = hdop;
    packet.vdop = vdop;
    packet.fix_type = fix_type;
    packet.satellite_nums = satellite_nums;
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
    return mavlink_msg_rtk_gps_pack(system_id, component_id, msg, rtk_gps->fix_type, rtk_gps->longitude, rtk_gps->latitude, rtk_gps->azimuth, rtk_gps->height, rtk_gps->speed, rtk_gps->course, rtk_gps->pdop, rtk_gps->hdop, rtk_gps->vdop, rtk_gps->satellite_nums, rtk_gps->year, rtk_gps->month, rtk_gps->day, rtk_gps->hour, rtk_gps->minute, rtk_gps->second);
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
    return mavlink_msg_rtk_gps_pack_chan(system_id, component_id, chan, msg, rtk_gps->fix_type, rtk_gps->longitude, rtk_gps->latitude, rtk_gps->azimuth, rtk_gps->height, rtk_gps->speed, rtk_gps->course, rtk_gps->pdop, rtk_gps->hdop, rtk_gps->vdop, rtk_gps->satellite_nums, rtk_gps->year, rtk_gps->month, rtk_gps->day, rtk_gps->hour, rtk_gps->minute, rtk_gps->second);
}

/**
 * @brief Send a rtk_gps message
 * @param chan MAVLink channel to send the message
 *
 * @param fix_type  GPS fix type 1:no-fix,2:2D-fix,3:3D-fix.
 * @param longitude  longitude.(deg)
 * @param latitude   latitude.(deg)
 * @param azimuth   azimuth.(-180..180)(deg)
 * @param height  height (-999.9..9999.9)(meter).
 * @param speed   speed (000.0..999.9)(Knots).
 * @param course   course (-180.0..180.0)(deg).
 * @param pdop  pdop (0.5..99.9).
 * @param hdop   hdop (0.5..99.9).
 * @param vdop   vdop (0.5..99.9).
 * @param satellite_nums   satellite_nums (0..24)(GPS+BDS).
 * @param year   component.
 * @param month   component.
 * @param day   component.
 * @param hour   component.
 * @param minute   component.
 * @param second   component.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rtk_gps_send(mavlink_channel_t chan, uint8_t fix_type, float longitude, float latitude, float azimuth, float height, float speed, float course, float pdop, float hdop, float vdop, uint8_t satellite_nums, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTK_GPS_LEN];
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, course);
    _mav_put_float(buf, 24, pdop);
    _mav_put_float(buf, 28, hdop);
    _mav_put_float(buf, 32, vdop);
    _mav_put_uint8_t(buf, 36, fix_type);
    _mav_put_uint8_t(buf, 37, satellite_nums);
    _mav_put_uint8_t(buf, 38, year);
    _mav_put_uint8_t(buf, 39, month);
    _mav_put_uint8_t(buf, 40, day);
    _mav_put_uint8_t(buf, 41, hour);
    _mav_put_uint8_t(buf, 42, minute);
    _mav_put_uint8_t(buf, 43, second);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTK_GPS, buf, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
#else
    mavlink_rtk_gps_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.azimuth = azimuth;
    packet.height = height;
    packet.speed = speed;
    packet.course = course;
    packet.pdop = pdop;
    packet.hdop = hdop;
    packet.vdop = vdop;
    packet.fix_type = fix_type;
    packet.satellite_nums = satellite_nums;
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
    mavlink_msg_rtk_gps_send(chan, rtk_gps->fix_type, rtk_gps->longitude, rtk_gps->latitude, rtk_gps->azimuth, rtk_gps->height, rtk_gps->speed, rtk_gps->course, rtk_gps->pdop, rtk_gps->hdop, rtk_gps->vdop, rtk_gps->satellite_nums, rtk_gps->year, rtk_gps->month, rtk_gps->day, rtk_gps->hour, rtk_gps->minute, rtk_gps->second);
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
static inline void mavlink_msg_rtk_gps_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t fix_type, float longitude, float latitude, float azimuth, float height, float speed, float course, float pdop, float hdop, float vdop, uint8_t satellite_nums, uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, longitude);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, azimuth);
    _mav_put_float(buf, 12, height);
    _mav_put_float(buf, 16, speed);
    _mav_put_float(buf, 20, course);
    _mav_put_float(buf, 24, pdop);
    _mav_put_float(buf, 28, hdop);
    _mav_put_float(buf, 32, vdop);
    _mav_put_uint8_t(buf, 36, fix_type);
    _mav_put_uint8_t(buf, 37, satellite_nums);
    _mav_put_uint8_t(buf, 38, year);
    _mav_put_uint8_t(buf, 39, month);
    _mav_put_uint8_t(buf, 40, day);
    _mav_put_uint8_t(buf, 41, hour);
    _mav_put_uint8_t(buf, 42, minute);
    _mav_put_uint8_t(buf, 43, second);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTK_GPS, buf, MAVLINK_MSG_ID_RTK_GPS_MIN_LEN, MAVLINK_MSG_ID_RTK_GPS_LEN, MAVLINK_MSG_ID_RTK_GPS_CRC);
#else
    mavlink_rtk_gps_t *packet = (mavlink_rtk_gps_t *)msgbuf;
    packet->longitude = longitude;
    packet->latitude = latitude;
    packet->azimuth = azimuth;
    packet->height = height;
    packet->speed = speed;
    packet->course = course;
    packet->pdop = pdop;
    packet->hdop = hdop;
    packet->vdop = vdop;
    packet->fix_type = fix_type;
    packet->satellite_nums = satellite_nums;
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
 * @brief Get field fix_type from rtk_gps message
 *
 * @return  GPS fix type 1:no-fix,2:2D-fix,3:3D-fix.
 */
static inline uint8_t mavlink_msg_rtk_gps_get_fix_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field longitude from rtk_gps message
 *
 * @return  longitude.(deg)
 */
static inline float mavlink_msg_rtk_gps_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field latitude from rtk_gps message
 *
 * @return   latitude.(deg)
 */
static inline float mavlink_msg_rtk_gps_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field azimuth from rtk_gps message
 *
 * @return   azimuth.(-180..180)(deg)
 */
static inline float mavlink_msg_rtk_gps_get_azimuth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field height from rtk_gps message
 *
 * @return  height (-999.9..9999.9)(meter).
 */
static inline float mavlink_msg_rtk_gps_get_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field speed from rtk_gps message
 *
 * @return   speed (000.0..999.9)(Knots).
 */
static inline float mavlink_msg_rtk_gps_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field course from rtk_gps message
 *
 * @return   course (-180.0..180.0)(deg).
 */
static inline float mavlink_msg_rtk_gps_get_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pdop from rtk_gps message
 *
 * @return  pdop (0.5..99.9).
 */
static inline float mavlink_msg_rtk_gps_get_pdop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field hdop from rtk_gps message
 *
 * @return   hdop (0.5..99.9).
 */
static inline float mavlink_msg_rtk_gps_get_hdop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field vdop from rtk_gps message
 *
 * @return   vdop (0.5..99.9).
 */
static inline float mavlink_msg_rtk_gps_get_vdop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field satellite_nums from rtk_gps message
 *
 * @return   satellite_nums (0..24)(GPS+BDS).
 */
static inline uint8_t mavlink_msg_rtk_gps_get_satellite_nums(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field year from rtk_gps message
 *
 * @return   component.
 */
static inline uint8_t mavlink_msg_rtk_gps_get_year(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  38);
}

/**
 * @brief Get field month from rtk_gps message
 *
 * @return   component.
 */
static inline uint8_t mavlink_msg_rtk_gps_get_month(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  39);
}

/**
 * @brief Get field day from rtk_gps message
 *
 * @return   component.
 */
static inline uint8_t mavlink_msg_rtk_gps_get_day(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field hour from rtk_gps message
 *
 * @return   component.
 */
static inline uint8_t mavlink_msg_rtk_gps_get_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Get field minute from rtk_gps message
 *
 * @return   component.
 */
static inline uint8_t mavlink_msg_rtk_gps_get_minute(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field second from rtk_gps message
 *
 * @return   component.
 */
static inline uint8_t mavlink_msg_rtk_gps_get_second(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
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
    rtk_gps->course = mavlink_msg_rtk_gps_get_course(msg);
    rtk_gps->pdop = mavlink_msg_rtk_gps_get_pdop(msg);
    rtk_gps->hdop = mavlink_msg_rtk_gps_get_hdop(msg);
    rtk_gps->vdop = mavlink_msg_rtk_gps_get_vdop(msg);
    rtk_gps->fix_type = mavlink_msg_rtk_gps_get_fix_type(msg);
    rtk_gps->satellite_nums = mavlink_msg_rtk_gps_get_satellite_nums(msg);
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
