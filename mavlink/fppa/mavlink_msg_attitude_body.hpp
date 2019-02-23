// MESSAGE ATTITUDE_BODY support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief ATTITUDE_BODY message
 *
 * The attitude in the aeronautical frame (right-handed, Z-down, X-front, Y-right).
 */
struct ATTITUDE_BODY : mavlink::Message {
    static constexpr msgid_t MSG_ID = 12;
    static constexpr size_t LENGTH = 93;
    static constexpr size_t MIN_LENGTH = 93;
    static constexpr uint8_t CRC_EXTRA = 243;
    static constexpr auto NAME = "ATTITUDE_BODY";


    uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    float roll; /*< [rad] Roll angle (-pi..+pi) */
    float pitch; /*< [rad] Pitch angle (-pi..+pi) */
    float yaw; /*< [rad] Yaw angle (-pi..+pi) */
    float roll_speed; /*< [rad/s] Roll angular speed */
    float pitch_speed; /*< [rad/s] Pitch angular speed */
    float yaw_speed; /*< [rad/s] Yaw angular speed */
    float roll_observed; /*< [deg] Roll observed value (-180..180) */
    float pitch_observed; /*< [deg] Pitch observed value (-90..90) */
    float yaw_observed; /*< [deg] Yaw observed value (-180..180) */
    float roll_obs_sub_pred; /*< [deg]  Error between roll angle observed value and prediction value (-180..180) */
    float pitch_obs_sub_pred; /*< [deg] Error between pitch angle observed value and prediction value (-90..90) */
    float yaw_obs_sub_pred; /*< [deg]  Error between yaw angle observed value and prediction value (-180..180) */
    float gyro_x_noise; /*< [deg] X axis gyroscope noise value in body frame (-180..180) */
    float gyro_y_noise; /*< [deg] Y axis gyroscope noise value in body frame (-180..180) */
    float gyro_z_noise; /*< [deg] Z axis gyroscope noise value in body frame (-180..180) */
    float acc_x_noise; /*< [m/s/s] X axis acceleration noise value in body frame (-30..30) */
    float acc_y_noise; /*< [m/s/s] Y axis acceleration noise value in body frame (-30..30) */
    float acc_z_noise; /*< [m/s/s] Z axis acceleration noise value in body frame (-30..30) */
    float mag_x_noise; /*< [mgauss] X axis magnetometer noise value in body frame (-1000..1000) */
    float mag_y_noise; /*< [mgauss] Y axis magnetometer noise value in body frame (-1000..1000) */
    float mag_z_noise; /*< [mgauss] Z axis magnetometer noise value in body frame (-1000..1000) */
    uint8_t static_flag; /*<  Flag of body state. 0:body is moving 1:body is static */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  yaw: " << yaw << std::endl;
        ss << "  roll_speed: " << roll_speed << std::endl;
        ss << "  pitch_speed: " << pitch_speed << std::endl;
        ss << "  yaw_speed: " << yaw_speed << std::endl;
        ss << "  roll_observed: " << roll_observed << std::endl;
        ss << "  pitch_observed: " << pitch_observed << std::endl;
        ss << "  yaw_observed: " << yaw_observed << std::endl;
        ss << "  roll_obs_sub_pred: " << roll_obs_sub_pred << std::endl;
        ss << "  pitch_obs_sub_pred: " << pitch_obs_sub_pred << std::endl;
        ss << "  yaw_obs_sub_pred: " << yaw_obs_sub_pred << std::endl;
        ss << "  gyro_x_noise: " << gyro_x_noise << std::endl;
        ss << "  gyro_y_noise: " << gyro_y_noise << std::endl;
        ss << "  gyro_z_noise: " << gyro_z_noise << std::endl;
        ss << "  acc_x_noise: " << acc_x_noise << std::endl;
        ss << "  acc_y_noise: " << acc_y_noise << std::endl;
        ss << "  acc_z_noise: " << acc_z_noise << std::endl;
        ss << "  mag_x_noise: " << mag_x_noise << std::endl;
        ss << "  mag_y_noise: " << mag_y_noise << std::endl;
        ss << "  mag_z_noise: " << mag_z_noise << std::endl;
        ss << "  static_flag: " << +static_flag << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << roll;                          // offset: 8
        map << pitch;                         // offset: 12
        map << yaw;                           // offset: 16
        map << roll_speed;                    // offset: 20
        map << pitch_speed;                   // offset: 24
        map << yaw_speed;                     // offset: 28
        map << roll_observed;                 // offset: 32
        map << pitch_observed;                // offset: 36
        map << yaw_observed;                  // offset: 40
        map << roll_obs_sub_pred;             // offset: 44
        map << pitch_obs_sub_pred;            // offset: 48
        map << yaw_obs_sub_pred;              // offset: 52
        map << gyro_x_noise;                  // offset: 56
        map << gyro_y_noise;                  // offset: 60
        map << gyro_z_noise;                  // offset: 64
        map << acc_x_noise;                   // offset: 68
        map << acc_y_noise;                   // offset: 72
        map << acc_z_noise;                   // offset: 76
        map << mag_x_noise;                   // offset: 80
        map << mag_y_noise;                   // offset: 84
        map << mag_z_noise;                   // offset: 88
        map << static_flag;                   // offset: 92
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> roll;                          // offset: 8
        map >> pitch;                         // offset: 12
        map >> yaw;                           // offset: 16
        map >> roll_speed;                    // offset: 20
        map >> pitch_speed;                   // offset: 24
        map >> yaw_speed;                     // offset: 28
        map >> roll_observed;                 // offset: 32
        map >> pitch_observed;                // offset: 36
        map >> yaw_observed;                  // offset: 40
        map >> roll_obs_sub_pred;             // offset: 44
        map >> pitch_obs_sub_pred;            // offset: 48
        map >> yaw_obs_sub_pred;              // offset: 52
        map >> gyro_x_noise;                  // offset: 56
        map >> gyro_y_noise;                  // offset: 60
        map >> gyro_z_noise;                  // offset: 64
        map >> acc_x_noise;                   // offset: 68
        map >> acc_y_noise;                   // offset: 72
        map >> acc_z_noise;                   // offset: 76
        map >> mag_x_noise;                   // offset: 80
        map >> mag_y_noise;                   // offset: 84
        map >> mag_z_noise;                   // offset: 88
        map >> static_flag;                   // offset: 92
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
