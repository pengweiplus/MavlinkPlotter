#pragma once
// MESSAGE ATTITUDE_BODY PACKING

#define MAVLINK_MSG_ID_ATTITUDE_BODY 12

MAVPACKED(
typedef struct __mavlink_attitude_body_t {
 uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float roll; /*< [rad] Roll angle (-pi..+pi)*/
 float pitch; /*< [rad] Pitch angle (-pi..+pi)*/
 float yaw; /*< [rad] Yaw angle (-pi..+pi)*/
 float roll_speed; /*< [rad/s] Roll angular speed*/
 float pitch_speed; /*< [rad/s] Pitch angular speed*/
 float yaw_speed; /*< [rad/s] Yaw angular speed*/
 float roll_observed; /*< [deg] Roll observed value (-180..180)*/
 float pitch_observed; /*< [deg] Pitch observed value (-90..90)*/
 float yaw_observed; /*< [deg] Yaw observed value (-180..180)*/
 float roll_obs_sub_pred; /*< [deg]  Error between roll angle observed value and prediction value (-180..180)*/
 float pitch_obs_sub_pred; /*< [deg] Error between pitch angle observed value and prediction value (-90..90)*/
 float yaw_obs_sub_pred; /*< [deg]  Error between yaw angle observed value and prediction value (-180..180)*/
 float gyro_x_noise; /*< [deg] X axis gyroscope noise value in body frame (-180..180)*/
 float gyro_y_noise; /*< [deg] Y axis gyroscope noise value in body frame (-180..180)*/
 float gyro_z_noise; /*< [deg] Z axis gyroscope noise value in body frame (-180..180)*/
 float acc_x_noise; /*< [m/s/s] X axis acceleration noise value in body frame (-30..30)*/
 float acc_y_noise; /*< [m/s/s] Y axis acceleration noise value in body frame (-30..30)*/
 float acc_z_noise; /*< [m/s/s] Z axis acceleration noise value in body frame (-30..30)*/
 float mag_x_noise; /*< [mgauss] X axis magnetometer noise value in body frame (-1000..1000)*/
 float mag_y_noise; /*< [mgauss] Y axis magnetometer noise value in body frame (-1000..1000)*/
 float mag_z_noise; /*< [mgauss] Z axis magnetometer noise value in body frame (-1000..1000)*/
 uint8_t static_flag; /*<  Flag of body state. 0:body is moving 1:body is static*/
}) mavlink_attitude_body_t;

#define MAVLINK_MSG_ID_ATTITUDE_BODY_LEN 93
#define MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN 93
#define MAVLINK_MSG_ID_12_LEN 93
#define MAVLINK_MSG_ID_12_MIN_LEN 93

#define MAVLINK_MSG_ID_ATTITUDE_BODY_CRC 243
#define MAVLINK_MSG_ID_12_CRC 243



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATTITUDE_BODY { \
    12, \
    "ATTITUDE_BODY", \
    23, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_attitude_body_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_attitude_body_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_attitude_body_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_attitude_body_t, yaw) }, \
         { "roll_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_attitude_body_t, roll_speed) }, \
         { "pitch_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_attitude_body_t, pitch_speed) }, \
         { "yaw_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_attitude_body_t, yaw_speed) }, \
         { "roll_observed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_attitude_body_t, roll_observed) }, \
         { "pitch_observed", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_attitude_body_t, pitch_observed) }, \
         { "yaw_observed", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_attitude_body_t, yaw_observed) }, \
         { "roll_obs_sub_pred", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_attitude_body_t, roll_obs_sub_pred) }, \
         { "pitch_obs_sub_pred", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_attitude_body_t, pitch_obs_sub_pred) }, \
         { "yaw_obs_sub_pred", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_attitude_body_t, yaw_obs_sub_pred) }, \
         { "gyro_x_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_attitude_body_t, gyro_x_noise) }, \
         { "gyro_y_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_attitude_body_t, gyro_y_noise) }, \
         { "gyro_z_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_attitude_body_t, gyro_z_noise) }, \
         { "acc_x_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_attitude_body_t, acc_x_noise) }, \
         { "acc_y_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_attitude_body_t, acc_y_noise) }, \
         { "acc_z_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_attitude_body_t, acc_z_noise) }, \
         { "mag_x_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_attitude_body_t, mag_x_noise) }, \
         { "mag_y_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_attitude_body_t, mag_y_noise) }, \
         { "mag_z_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_attitude_body_t, mag_z_noise) }, \
         { "static_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_attitude_body_t, static_flag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATTITUDE_BODY { \
    "ATTITUDE_BODY", \
    23, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_attitude_body_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_attitude_body_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_attitude_body_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_attitude_body_t, yaw) }, \
         { "roll_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_attitude_body_t, roll_speed) }, \
         { "pitch_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_attitude_body_t, pitch_speed) }, \
         { "yaw_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_attitude_body_t, yaw_speed) }, \
         { "roll_observed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_attitude_body_t, roll_observed) }, \
         { "pitch_observed", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_attitude_body_t, pitch_observed) }, \
         { "yaw_observed", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_attitude_body_t, yaw_observed) }, \
         { "roll_obs_sub_pred", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_attitude_body_t, roll_obs_sub_pred) }, \
         { "pitch_obs_sub_pred", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_attitude_body_t, pitch_obs_sub_pred) }, \
         { "yaw_obs_sub_pred", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_attitude_body_t, yaw_obs_sub_pred) }, \
         { "gyro_x_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_attitude_body_t, gyro_x_noise) }, \
         { "gyro_y_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_attitude_body_t, gyro_y_noise) }, \
         { "gyro_z_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_attitude_body_t, gyro_z_noise) }, \
         { "acc_x_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_attitude_body_t, acc_x_noise) }, \
         { "acc_y_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_attitude_body_t, acc_y_noise) }, \
         { "acc_z_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_attitude_body_t, acc_z_noise) }, \
         { "mag_x_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_attitude_body_t, mag_x_noise) }, \
         { "mag_y_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_attitude_body_t, mag_y_noise) }, \
         { "mag_z_noise", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_attitude_body_t, mag_z_noise) }, \
         { "static_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_attitude_body_t, static_flag) }, \
         } \
}
#endif

/**
 * @brief Pack a attitude_body message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll [rad] Roll angle (-pi..+pi)
 * @param pitch [rad] Pitch angle (-pi..+pi)
 * @param yaw [rad] Yaw angle (-pi..+pi)
 * @param roll_speed [rad/s] Roll angular speed
 * @param pitch_speed [rad/s] Pitch angular speed
 * @param yaw_speed [rad/s] Yaw angular speed
 * @param roll_observed [deg] Roll observed value (-180..180)
 * @param pitch_observed [deg] Pitch observed value (-90..90)
 * @param yaw_observed [deg] Yaw observed value (-180..180)
 * @param roll_obs_sub_pred [deg]  Error between roll angle observed value and prediction value (-180..180)
 * @param pitch_obs_sub_pred [deg] Error between pitch angle observed value and prediction value (-90..90)
 * @param yaw_obs_sub_pred [deg]  Error between yaw angle observed value and prediction value (-180..180)
 * @param gyro_x_noise [deg] X axis gyroscope noise value in body frame (-180..180)
 * @param gyro_y_noise [deg] Y axis gyroscope noise value in body frame (-180..180)
 * @param gyro_z_noise [deg] Z axis gyroscope noise value in body frame (-180..180)
 * @param acc_x_noise [m/s/s] X axis acceleration noise value in body frame (-30..30)
 * @param acc_y_noise [m/s/s] Y axis acceleration noise value in body frame (-30..30)
 * @param acc_z_noise [m/s/s] Z axis acceleration noise value in body frame (-30..30)
 * @param mag_x_noise [mgauss] X axis magnetometer noise value in body frame (-1000..1000)
 * @param mag_y_noise [mgauss] Y axis magnetometer noise value in body frame (-1000..1000)
 * @param mag_z_noise [mgauss] Z axis magnetometer noise value in body frame (-1000..1000)
 * @param static_flag  Flag of body state. 0:body is moving 1:body is static
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_body_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_boot_ms, float roll, float pitch, float yaw, float roll_speed, float pitch_speed, float yaw_speed, float roll_observed, float pitch_observed, float yaw_observed, float roll_obs_sub_pred, float pitch_obs_sub_pred, float yaw_obs_sub_pred, float gyro_x_noise, float gyro_y_noise, float gyro_z_noise, float acc_x_noise, float acc_y_noise, float acc_z_noise, float mag_x_noise, float mag_y_noise, float mag_z_noise, uint8_t static_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BODY_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_speed);
    _mav_put_float(buf, 24, pitch_speed);
    _mav_put_float(buf, 28, yaw_speed);
    _mav_put_float(buf, 32, roll_observed);
    _mav_put_float(buf, 36, pitch_observed);
    _mav_put_float(buf, 40, yaw_observed);
    _mav_put_float(buf, 44, roll_obs_sub_pred);
    _mav_put_float(buf, 48, pitch_obs_sub_pred);
    _mav_put_float(buf, 52, yaw_obs_sub_pred);
    _mav_put_float(buf, 56, gyro_x_noise);
    _mav_put_float(buf, 60, gyro_y_noise);
    _mav_put_float(buf, 64, gyro_z_noise);
    _mav_put_float(buf, 68, acc_x_noise);
    _mav_put_float(buf, 72, acc_y_noise);
    _mav_put_float(buf, 76, acc_z_noise);
    _mav_put_float(buf, 80, mag_x_noise);
    _mav_put_float(buf, 84, mag_y_noise);
    _mav_put_float(buf, 88, mag_z_noise);
    _mav_put_uint8_t(buf, 92, static_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN);
#else
    mavlink_attitude_body_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_speed = roll_speed;
    packet.pitch_speed = pitch_speed;
    packet.yaw_speed = yaw_speed;
    packet.roll_observed = roll_observed;
    packet.pitch_observed = pitch_observed;
    packet.yaw_observed = yaw_observed;
    packet.roll_obs_sub_pred = roll_obs_sub_pred;
    packet.pitch_obs_sub_pred = pitch_obs_sub_pred;
    packet.yaw_obs_sub_pred = yaw_obs_sub_pred;
    packet.gyro_x_noise = gyro_x_noise;
    packet.gyro_y_noise = gyro_y_noise;
    packet.gyro_z_noise = gyro_z_noise;
    packet.acc_x_noise = acc_x_noise;
    packet.acc_y_noise = acc_y_noise;
    packet.acc_z_noise = acc_z_noise;
    packet.mag_x_noise = mag_x_noise;
    packet.mag_y_noise = mag_y_noise;
    packet.mag_z_noise = mag_z_noise;
    packet.static_flag = static_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATTITUDE_BODY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_CRC);
}

/**
 * @brief Pack a attitude_body message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll [rad] Roll angle (-pi..+pi)
 * @param pitch [rad] Pitch angle (-pi..+pi)
 * @param yaw [rad] Yaw angle (-pi..+pi)
 * @param roll_speed [rad/s] Roll angular speed
 * @param pitch_speed [rad/s] Pitch angular speed
 * @param yaw_speed [rad/s] Yaw angular speed
 * @param roll_observed [deg] Roll observed value (-180..180)
 * @param pitch_observed [deg] Pitch observed value (-90..90)
 * @param yaw_observed [deg] Yaw observed value (-180..180)
 * @param roll_obs_sub_pred [deg]  Error between roll angle observed value and prediction value (-180..180)
 * @param pitch_obs_sub_pred [deg] Error between pitch angle observed value and prediction value (-90..90)
 * @param yaw_obs_sub_pred [deg]  Error between yaw angle observed value and prediction value (-180..180)
 * @param gyro_x_noise [deg] X axis gyroscope noise value in body frame (-180..180)
 * @param gyro_y_noise [deg] Y axis gyroscope noise value in body frame (-180..180)
 * @param gyro_z_noise [deg] Z axis gyroscope noise value in body frame (-180..180)
 * @param acc_x_noise [m/s/s] X axis acceleration noise value in body frame (-30..30)
 * @param acc_y_noise [m/s/s] Y axis acceleration noise value in body frame (-30..30)
 * @param acc_z_noise [m/s/s] Z axis acceleration noise value in body frame (-30..30)
 * @param mag_x_noise [mgauss] X axis magnetometer noise value in body frame (-1000..1000)
 * @param mag_y_noise [mgauss] Y axis magnetometer noise value in body frame (-1000..1000)
 * @param mag_z_noise [mgauss] Z axis magnetometer noise value in body frame (-1000..1000)
 * @param static_flag  Flag of body state. 0:body is moving 1:body is static
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_body_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_boot_ms,float roll,float pitch,float yaw,float roll_speed,float pitch_speed,float yaw_speed,float roll_observed,float pitch_observed,float yaw_observed,float roll_obs_sub_pred,float pitch_obs_sub_pred,float yaw_obs_sub_pred,float gyro_x_noise,float gyro_y_noise,float gyro_z_noise,float acc_x_noise,float acc_y_noise,float acc_z_noise,float mag_x_noise,float mag_y_noise,float mag_z_noise,uint8_t static_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BODY_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_speed);
    _mav_put_float(buf, 24, pitch_speed);
    _mav_put_float(buf, 28, yaw_speed);
    _mav_put_float(buf, 32, roll_observed);
    _mav_put_float(buf, 36, pitch_observed);
    _mav_put_float(buf, 40, yaw_observed);
    _mav_put_float(buf, 44, roll_obs_sub_pred);
    _mav_put_float(buf, 48, pitch_obs_sub_pred);
    _mav_put_float(buf, 52, yaw_obs_sub_pred);
    _mav_put_float(buf, 56, gyro_x_noise);
    _mav_put_float(buf, 60, gyro_y_noise);
    _mav_put_float(buf, 64, gyro_z_noise);
    _mav_put_float(buf, 68, acc_x_noise);
    _mav_put_float(buf, 72, acc_y_noise);
    _mav_put_float(buf, 76, acc_z_noise);
    _mav_put_float(buf, 80, mag_x_noise);
    _mav_put_float(buf, 84, mag_y_noise);
    _mav_put_float(buf, 88, mag_z_noise);
    _mav_put_uint8_t(buf, 92, static_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN);
#else
    mavlink_attitude_body_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_speed = roll_speed;
    packet.pitch_speed = pitch_speed;
    packet.yaw_speed = yaw_speed;
    packet.roll_observed = roll_observed;
    packet.pitch_observed = pitch_observed;
    packet.yaw_observed = yaw_observed;
    packet.roll_obs_sub_pred = roll_obs_sub_pred;
    packet.pitch_obs_sub_pred = pitch_obs_sub_pred;
    packet.yaw_obs_sub_pred = yaw_obs_sub_pred;
    packet.gyro_x_noise = gyro_x_noise;
    packet.gyro_y_noise = gyro_y_noise;
    packet.gyro_z_noise = gyro_z_noise;
    packet.acc_x_noise = acc_x_noise;
    packet.acc_y_noise = acc_y_noise;
    packet.acc_z_noise = acc_z_noise;
    packet.mag_x_noise = mag_x_noise;
    packet.mag_y_noise = mag_y_noise;
    packet.mag_z_noise = mag_z_noise;
    packet.static_flag = static_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATTITUDE_BODY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_CRC);
}

/**
 * @brief Encode a attitude_body struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param attitude_body C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_body_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_attitude_body_t* attitude_body)
{
    return mavlink_msg_attitude_body_pack(system_id, component_id, msg, attitude_body->time_boot_ms, attitude_body->roll, attitude_body->pitch, attitude_body->yaw, attitude_body->roll_speed, attitude_body->pitch_speed, attitude_body->yaw_speed, attitude_body->roll_observed, attitude_body->pitch_observed, attitude_body->yaw_observed, attitude_body->roll_obs_sub_pred, attitude_body->pitch_obs_sub_pred, attitude_body->yaw_obs_sub_pred, attitude_body->gyro_x_noise, attitude_body->gyro_y_noise, attitude_body->gyro_z_noise, attitude_body->acc_x_noise, attitude_body->acc_y_noise, attitude_body->acc_z_noise, attitude_body->mag_x_noise, attitude_body->mag_y_noise, attitude_body->mag_z_noise, attitude_body->static_flag);
}

/**
 * @brief Encode a attitude_body struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param attitude_body C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_body_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_attitude_body_t* attitude_body)
{
    return mavlink_msg_attitude_body_pack_chan(system_id, component_id, chan, msg, attitude_body->time_boot_ms, attitude_body->roll, attitude_body->pitch, attitude_body->yaw, attitude_body->roll_speed, attitude_body->pitch_speed, attitude_body->yaw_speed, attitude_body->roll_observed, attitude_body->pitch_observed, attitude_body->yaw_observed, attitude_body->roll_obs_sub_pred, attitude_body->pitch_obs_sub_pred, attitude_body->yaw_obs_sub_pred, attitude_body->gyro_x_noise, attitude_body->gyro_y_noise, attitude_body->gyro_z_noise, attitude_body->acc_x_noise, attitude_body->acc_y_noise, attitude_body->acc_z_noise, attitude_body->mag_x_noise, attitude_body->mag_y_noise, attitude_body->mag_z_noise, attitude_body->static_flag);
}

/**
 * @brief Send a attitude_body message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param roll [rad] Roll angle (-pi..+pi)
 * @param pitch [rad] Pitch angle (-pi..+pi)
 * @param yaw [rad] Yaw angle (-pi..+pi)
 * @param roll_speed [rad/s] Roll angular speed
 * @param pitch_speed [rad/s] Pitch angular speed
 * @param yaw_speed [rad/s] Yaw angular speed
 * @param roll_observed [deg] Roll observed value (-180..180)
 * @param pitch_observed [deg] Pitch observed value (-90..90)
 * @param yaw_observed [deg] Yaw observed value (-180..180)
 * @param roll_obs_sub_pred [deg]  Error between roll angle observed value and prediction value (-180..180)
 * @param pitch_obs_sub_pred [deg] Error between pitch angle observed value and prediction value (-90..90)
 * @param yaw_obs_sub_pred [deg]  Error between yaw angle observed value and prediction value (-180..180)
 * @param gyro_x_noise [deg] X axis gyroscope noise value in body frame (-180..180)
 * @param gyro_y_noise [deg] Y axis gyroscope noise value in body frame (-180..180)
 * @param gyro_z_noise [deg] Z axis gyroscope noise value in body frame (-180..180)
 * @param acc_x_noise [m/s/s] X axis acceleration noise value in body frame (-30..30)
 * @param acc_y_noise [m/s/s] Y axis acceleration noise value in body frame (-30..30)
 * @param acc_z_noise [m/s/s] Z axis acceleration noise value in body frame (-30..30)
 * @param mag_x_noise [mgauss] X axis magnetometer noise value in body frame (-1000..1000)
 * @param mag_y_noise [mgauss] Y axis magnetometer noise value in body frame (-1000..1000)
 * @param mag_z_noise [mgauss] Z axis magnetometer noise value in body frame (-1000..1000)
 * @param static_flag  Flag of body state. 0:body is moving 1:body is static
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_attitude_body_send(mavlink_channel_t chan, uint64_t time_boot_ms, float roll, float pitch, float yaw, float roll_speed, float pitch_speed, float yaw_speed, float roll_observed, float pitch_observed, float yaw_observed, float roll_obs_sub_pred, float pitch_obs_sub_pred, float yaw_obs_sub_pred, float gyro_x_noise, float gyro_y_noise, float gyro_z_noise, float acc_x_noise, float acc_y_noise, float acc_z_noise, float mag_x_noise, float mag_y_noise, float mag_z_noise, uint8_t static_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATTITUDE_BODY_LEN];
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_speed);
    _mav_put_float(buf, 24, pitch_speed);
    _mav_put_float(buf, 28, yaw_speed);
    _mav_put_float(buf, 32, roll_observed);
    _mav_put_float(buf, 36, pitch_observed);
    _mav_put_float(buf, 40, yaw_observed);
    _mav_put_float(buf, 44, roll_obs_sub_pred);
    _mav_put_float(buf, 48, pitch_obs_sub_pred);
    _mav_put_float(buf, 52, yaw_obs_sub_pred);
    _mav_put_float(buf, 56, gyro_x_noise);
    _mav_put_float(buf, 60, gyro_y_noise);
    _mav_put_float(buf, 64, gyro_z_noise);
    _mav_put_float(buf, 68, acc_x_noise);
    _mav_put_float(buf, 72, acc_y_noise);
    _mav_put_float(buf, 76, acc_z_noise);
    _mav_put_float(buf, 80, mag_x_noise);
    _mav_put_float(buf, 84, mag_y_noise);
    _mav_put_float(buf, 88, mag_z_noise);
    _mav_put_uint8_t(buf, 92, static_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BODY, buf, MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_CRC);
#else
    mavlink_attitude_body_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_speed = roll_speed;
    packet.pitch_speed = pitch_speed;
    packet.yaw_speed = yaw_speed;
    packet.roll_observed = roll_observed;
    packet.pitch_observed = pitch_observed;
    packet.yaw_observed = yaw_observed;
    packet.roll_obs_sub_pred = roll_obs_sub_pred;
    packet.pitch_obs_sub_pred = pitch_obs_sub_pred;
    packet.yaw_obs_sub_pred = yaw_obs_sub_pred;
    packet.gyro_x_noise = gyro_x_noise;
    packet.gyro_y_noise = gyro_y_noise;
    packet.gyro_z_noise = gyro_z_noise;
    packet.acc_x_noise = acc_x_noise;
    packet.acc_y_noise = acc_y_noise;
    packet.acc_z_noise = acc_z_noise;
    packet.mag_x_noise = mag_x_noise;
    packet.mag_y_noise = mag_y_noise;
    packet.mag_z_noise = mag_z_noise;
    packet.static_flag = static_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BODY, (const char *)&packet, MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_CRC);
#endif
}

/**
 * @brief Send a attitude_body message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_attitude_body_send_struct(mavlink_channel_t chan, const mavlink_attitude_body_t* attitude_body)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_attitude_body_send(chan, attitude_body->time_boot_ms, attitude_body->roll, attitude_body->pitch, attitude_body->yaw, attitude_body->roll_speed, attitude_body->pitch_speed, attitude_body->yaw_speed, attitude_body->roll_observed, attitude_body->pitch_observed, attitude_body->yaw_observed, attitude_body->roll_obs_sub_pred, attitude_body->pitch_obs_sub_pred, attitude_body->yaw_obs_sub_pred, attitude_body->gyro_x_noise, attitude_body->gyro_y_noise, attitude_body->gyro_z_noise, attitude_body->acc_x_noise, attitude_body->acc_y_noise, attitude_body->acc_z_noise, attitude_body->mag_x_noise, attitude_body->mag_y_noise, attitude_body->mag_z_noise, attitude_body->static_flag);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BODY, (const char *)attitude_body, MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_CRC);
#endif
}

#if MAVLINK_MSG_ID_ATTITUDE_BODY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_attitude_body_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_boot_ms, float roll, float pitch, float yaw, float roll_speed, float pitch_speed, float yaw_speed, float roll_observed, float pitch_observed, float yaw_observed, float roll_obs_sub_pred, float pitch_obs_sub_pred, float yaw_obs_sub_pred, float gyro_x_noise, float gyro_y_noise, float gyro_z_noise, float acc_x_noise, float acc_y_noise, float acc_z_noise, float mag_x_noise, float mag_y_noise, float mag_z_noise, uint8_t static_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_speed);
    _mav_put_float(buf, 24, pitch_speed);
    _mav_put_float(buf, 28, yaw_speed);
    _mav_put_float(buf, 32, roll_observed);
    _mav_put_float(buf, 36, pitch_observed);
    _mav_put_float(buf, 40, yaw_observed);
    _mav_put_float(buf, 44, roll_obs_sub_pred);
    _mav_put_float(buf, 48, pitch_obs_sub_pred);
    _mav_put_float(buf, 52, yaw_obs_sub_pred);
    _mav_put_float(buf, 56, gyro_x_noise);
    _mav_put_float(buf, 60, gyro_y_noise);
    _mav_put_float(buf, 64, gyro_z_noise);
    _mav_put_float(buf, 68, acc_x_noise);
    _mav_put_float(buf, 72, acc_y_noise);
    _mav_put_float(buf, 76, acc_z_noise);
    _mav_put_float(buf, 80, mag_x_noise);
    _mav_put_float(buf, 84, mag_y_noise);
    _mav_put_float(buf, 88, mag_z_noise);
    _mav_put_uint8_t(buf, 92, static_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BODY, buf, MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_CRC);
#else
    mavlink_attitude_body_t *packet = (mavlink_attitude_body_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->roll_speed = roll_speed;
    packet->pitch_speed = pitch_speed;
    packet->yaw_speed = yaw_speed;
    packet->roll_observed = roll_observed;
    packet->pitch_observed = pitch_observed;
    packet->yaw_observed = yaw_observed;
    packet->roll_obs_sub_pred = roll_obs_sub_pred;
    packet->pitch_obs_sub_pred = pitch_obs_sub_pred;
    packet->yaw_obs_sub_pred = yaw_obs_sub_pred;
    packet->gyro_x_noise = gyro_x_noise;
    packet->gyro_y_noise = gyro_y_noise;
    packet->gyro_z_noise = gyro_z_noise;
    packet->acc_x_noise = acc_x_noise;
    packet->acc_y_noise = acc_y_noise;
    packet->acc_z_noise = acc_z_noise;
    packet->mag_x_noise = mag_x_noise;
    packet->mag_y_noise = mag_y_noise;
    packet->mag_z_noise = mag_z_noise;
    packet->static_flag = static_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATTITUDE_BODY, (const char *)packet, MAVLINK_MSG_ID_ATTITUDE_BODY_MIN_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN, MAVLINK_MSG_ID_ATTITUDE_BODY_CRC);
#endif
}
#endif

#endif

// MESSAGE ATTITUDE_BODY UNPACKING


/**
 * @brief Get field time_boot_ms from attitude_body message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint64_t mavlink_msg_attitude_body_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field roll from attitude_body message
 *
 * @return [rad] Roll angle (-pi..+pi)
 */
static inline float mavlink_msg_attitude_body_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field pitch from attitude_body message
 *
 * @return [rad] Pitch angle (-pi..+pi)
 */
static inline float mavlink_msg_attitude_body_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw from attitude_body message
 *
 * @return [rad] Yaw angle (-pi..+pi)
 */
static inline float mavlink_msg_attitude_body_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field roll_speed from attitude_body message
 *
 * @return [rad/s] Roll angular speed
 */
static inline float mavlink_msg_attitude_body_get_roll_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pitch_speed from attitude_body message
 *
 * @return [rad/s] Pitch angular speed
 */
static inline float mavlink_msg_attitude_body_get_pitch_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field yaw_speed from attitude_body message
 *
 * @return [rad/s] Yaw angular speed
 */
static inline float mavlink_msg_attitude_body_get_yaw_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field roll_observed from attitude_body message
 *
 * @return [deg] Roll observed value (-180..180)
 */
static inline float mavlink_msg_attitude_body_get_roll_observed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field pitch_observed from attitude_body message
 *
 * @return [deg] Pitch observed value (-90..90)
 */
static inline float mavlink_msg_attitude_body_get_pitch_observed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field yaw_observed from attitude_body message
 *
 * @return [deg] Yaw observed value (-180..180)
 */
static inline float mavlink_msg_attitude_body_get_yaw_observed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field roll_obs_sub_pred from attitude_body message
 *
 * @return [deg]  Error between roll angle observed value and prediction value (-180..180)
 */
static inline float mavlink_msg_attitude_body_get_roll_obs_sub_pred(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field pitch_obs_sub_pred from attitude_body message
 *
 * @return [deg] Error between pitch angle observed value and prediction value (-90..90)
 */
static inline float mavlink_msg_attitude_body_get_pitch_obs_sub_pred(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field yaw_obs_sub_pred from attitude_body message
 *
 * @return [deg]  Error between yaw angle observed value and prediction value (-180..180)
 */
static inline float mavlink_msg_attitude_body_get_yaw_obs_sub_pred(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field gyro_x_noise from attitude_body message
 *
 * @return [deg] X axis gyroscope noise value in body frame (-180..180)
 */
static inline float mavlink_msg_attitude_body_get_gyro_x_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field gyro_y_noise from attitude_body message
 *
 * @return [deg] Y axis gyroscope noise value in body frame (-180..180)
 */
static inline float mavlink_msg_attitude_body_get_gyro_y_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field gyro_z_noise from attitude_body message
 *
 * @return [deg] Z axis gyroscope noise value in body frame (-180..180)
 */
static inline float mavlink_msg_attitude_body_get_gyro_z_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field acc_x_noise from attitude_body message
 *
 * @return [m/s/s] X axis acceleration noise value in body frame (-30..30)
 */
static inline float mavlink_msg_attitude_body_get_acc_x_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field acc_y_noise from attitude_body message
 *
 * @return [m/s/s] Y axis acceleration noise value in body frame (-30..30)
 */
static inline float mavlink_msg_attitude_body_get_acc_y_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field acc_z_noise from attitude_body message
 *
 * @return [m/s/s] Z axis acceleration noise value in body frame (-30..30)
 */
static inline float mavlink_msg_attitude_body_get_acc_z_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field mag_x_noise from attitude_body message
 *
 * @return [mgauss] X axis magnetometer noise value in body frame (-1000..1000)
 */
static inline float mavlink_msg_attitude_body_get_mag_x_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field mag_y_noise from attitude_body message
 *
 * @return [mgauss] Y axis magnetometer noise value in body frame (-1000..1000)
 */
static inline float mavlink_msg_attitude_body_get_mag_y_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field mag_z_noise from attitude_body message
 *
 * @return [mgauss] Z axis magnetometer noise value in body frame (-1000..1000)
 */
static inline float mavlink_msg_attitude_body_get_mag_z_noise(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field static_flag from attitude_body message
 *
 * @return  Flag of body state. 0:body is moving 1:body is static
 */
static inline uint8_t mavlink_msg_attitude_body_get_static_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  92);
}

/**
 * @brief Decode a attitude_body message into a struct
 *
 * @param msg The message to decode
 * @param attitude_body C-struct to decode the message contents into
 */
static inline void mavlink_msg_attitude_body_decode(const mavlink_message_t* msg, mavlink_attitude_body_t* attitude_body)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    attitude_body->time_boot_ms = mavlink_msg_attitude_body_get_time_boot_ms(msg);
    attitude_body->roll = mavlink_msg_attitude_body_get_roll(msg);
    attitude_body->pitch = mavlink_msg_attitude_body_get_pitch(msg);
    attitude_body->yaw = mavlink_msg_attitude_body_get_yaw(msg);
    attitude_body->roll_speed = mavlink_msg_attitude_body_get_roll_speed(msg);
    attitude_body->pitch_speed = mavlink_msg_attitude_body_get_pitch_speed(msg);
    attitude_body->yaw_speed = mavlink_msg_attitude_body_get_yaw_speed(msg);
    attitude_body->roll_observed = mavlink_msg_attitude_body_get_roll_observed(msg);
    attitude_body->pitch_observed = mavlink_msg_attitude_body_get_pitch_observed(msg);
    attitude_body->yaw_observed = mavlink_msg_attitude_body_get_yaw_observed(msg);
    attitude_body->roll_obs_sub_pred = mavlink_msg_attitude_body_get_roll_obs_sub_pred(msg);
    attitude_body->pitch_obs_sub_pred = mavlink_msg_attitude_body_get_pitch_obs_sub_pred(msg);
    attitude_body->yaw_obs_sub_pred = mavlink_msg_attitude_body_get_yaw_obs_sub_pred(msg);
    attitude_body->gyro_x_noise = mavlink_msg_attitude_body_get_gyro_x_noise(msg);
    attitude_body->gyro_y_noise = mavlink_msg_attitude_body_get_gyro_y_noise(msg);
    attitude_body->gyro_z_noise = mavlink_msg_attitude_body_get_gyro_z_noise(msg);
    attitude_body->acc_x_noise = mavlink_msg_attitude_body_get_acc_x_noise(msg);
    attitude_body->acc_y_noise = mavlink_msg_attitude_body_get_acc_y_noise(msg);
    attitude_body->acc_z_noise = mavlink_msg_attitude_body_get_acc_z_noise(msg);
    attitude_body->mag_x_noise = mavlink_msg_attitude_body_get_mag_x_noise(msg);
    attitude_body->mag_y_noise = mavlink_msg_attitude_body_get_mag_y_noise(msg);
    attitude_body->mag_z_noise = mavlink_msg_attitude_body_get_mag_z_noise(msg);
    attitude_body->static_flag = mavlink_msg_attitude_body_get_static_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ATTITUDE_BODY_LEN? msg->len : MAVLINK_MSG_ID_ATTITUDE_BODY_LEN;
        memset(attitude_body, 0, MAVLINK_MSG_ID_ATTITUDE_BODY_LEN);
    memcpy(attitude_body, _MAV_PAYLOAD(msg), len);
#endif
}
