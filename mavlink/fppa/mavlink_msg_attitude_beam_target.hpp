// MESSAGE ATTITUDE_BEAM_TARGET support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief ATTITUDE_BEAM_TARGET message
 *
 * Reports the current commanded attitude of the vehicle as specified by the autopilot. This should match the commands sent in a SET_ATTITUDE_TARGET message if the vehicle is being controlled this way.
 */
struct ATTITUDE_BEAM_TARGET : mavlink::Message {
    static constexpr msgid_t MSG_ID = 13;
    static constexpr size_t LENGTH = 36;
    static constexpr size_t MIN_LENGTH = 36;
    static constexpr uint8_t CRC_EXTRA = 11;
    static constexpr auto NAME = "ATTITUDE_BEAM_TARGET";


    uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    std::array<float, 4> q; /*<  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    float roll; /*< [deg] Beam roll rate(-90.0..90.0)(deg) */
    float pitch; /*< [deg] Beam pitch rate(-90.0..90.0)(deg) */
    float yaw; /*< [deg] Beam yaw rate(-180.0..180.0)(deg) */


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
        ss << "  q: [" << to_string(q) << "]" << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  yaw: " << yaw << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << q;                             // offset: 8
        map << roll;                          // offset: 24
        map << pitch;                         // offset: 28
        map << yaw;                           // offset: 32
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> q;                             // offset: 8
        map >> roll;                          // offset: 24
        map >> pitch;                         // offset: 28
        map >> yaw;                           // offset: 32
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
