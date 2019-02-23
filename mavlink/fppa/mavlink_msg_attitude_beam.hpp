// MESSAGE ATTITUDE_BEAM support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief ATTITUDE_BEAM message
 *
 * Status of secondary AHRS filter if available.
 */
struct ATTITUDE_BEAM : mavlink::Message {
    static constexpr msgid_t MSG_ID = 14;
    static constexpr size_t LENGTH = 40;
    static constexpr size_t MIN_LENGTH = 40;
    static constexpr uint8_t CRC_EXTRA = 50;
    static constexpr auto NAME = "ATTITUDE_BEAM";


    uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    float roll; /*< [deg] Roll angle.(-90.0..90.0)(deg) */
    float pitch; /*< [deg] Pitch angle.(-90.0..90.0)(deg) */
    float yaw; /*< [deg] Yaw angle.(-180.0..180.0)(deg) */
    float altitude; /*< [m] Altitude (MSL). */
    std::array<float, 4> q; /*<  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */


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
        ss << "  altitude: " << altitude << std::endl;
        ss << "  q: [" << to_string(q) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << roll;                          // offset: 8
        map << pitch;                         // offset: 12
        map << yaw;                           // offset: 16
        map << altitude;                      // offset: 20
        map << q;                             // offset: 24
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> roll;                          // offset: 8
        map >> pitch;                         // offset: 12
        map >> yaw;                           // offset: 16
        map >> altitude;                      // offset: 20
        map >> q;                             // offset: 24
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
