// MESSAGE PID_TUNING support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief PID_TUNING message
 *
 * PID tuning information.
 */
struct PID_TUNING : mavlink::Message {
    static constexpr msgid_t MSG_ID = 255;
    static constexpr size_t LENGTH = 80;
    static constexpr size_t MIN_LENGTH = 80;
    static constexpr uint8_t CRC_EXTRA = 47;
    static constexpr auto NAME = "PID_TUNING";


    uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    float roll_desired; /*< [deg] Desired angle. */
    float roll_achieved; /*< [deg] Achieved angle. */
    float roll_FF; /*<  FF component. */
    float roll_P; /*<  P component. */
    float roll_I; /*<  I component. */
    float roll_D; /*<  D component. */
    float pitch_desired; /*< [deg] Desired angle. */
    float pitch_achieved; /*< [deg] Achieved angle. */
    float pitchl_FF; /*<  FF component. */
    float pitch_P; /*<  P component. */
    float pitch_I; /*<  I component. */
    float pitch_D; /*<  D component. */
    float yaw_desired; /*< [deg] Desired angle. */
    float yaw_achieved; /*< [deg] Achieved angle. */
    float yaw_FF; /*<  FF component. */
    float yaw_P; /*<  P component. */
    float yaw_I; /*<  I component. */
    float yaw_D; /*<  D component. */


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
        ss << "  roll_desired: " << roll_desired << std::endl;
        ss << "  roll_achieved: " << roll_achieved << std::endl;
        ss << "  roll_FF: " << roll_FF << std::endl;
        ss << "  roll_P: " << roll_P << std::endl;
        ss << "  roll_I: " << roll_I << std::endl;
        ss << "  roll_D: " << roll_D << std::endl;
        ss << "  pitch_desired: " << pitch_desired << std::endl;
        ss << "  pitch_achieved: " << pitch_achieved << std::endl;
        ss << "  pitchl_FF: " << pitchl_FF << std::endl;
        ss << "  pitch_P: " << pitch_P << std::endl;
        ss << "  pitch_I: " << pitch_I << std::endl;
        ss << "  pitch_D: " << pitch_D << std::endl;
        ss << "  yaw_desired: " << yaw_desired << std::endl;
        ss << "  yaw_achieved: " << yaw_achieved << std::endl;
        ss << "  yaw_FF: " << yaw_FF << std::endl;
        ss << "  yaw_P: " << yaw_P << std::endl;
        ss << "  yaw_I: " << yaw_I << std::endl;
        ss << "  yaw_D: " << yaw_D << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << roll_desired;                  // offset: 8
        map << roll_achieved;                 // offset: 12
        map << roll_FF;                       // offset: 16
        map << roll_P;                        // offset: 20
        map << roll_I;                        // offset: 24
        map << roll_D;                        // offset: 28
        map << pitch_desired;                 // offset: 32
        map << pitch_achieved;                // offset: 36
        map << pitchl_FF;                     // offset: 40
        map << pitch_P;                       // offset: 44
        map << pitch_I;                       // offset: 48
        map << pitch_D;                       // offset: 52
        map << yaw_desired;                   // offset: 56
        map << yaw_achieved;                  // offset: 60
        map << yaw_FF;                        // offset: 64
        map << yaw_P;                         // offset: 68
        map << yaw_I;                         // offset: 72
        map << yaw_D;                         // offset: 76
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> roll_desired;                  // offset: 8
        map >> roll_achieved;                 // offset: 12
        map >> roll_FF;                       // offset: 16
        map >> roll_P;                        // offset: 20
        map >> roll_I;                        // offset: 24
        map >> roll_D;                        // offset: 28
        map >> pitch_desired;                 // offset: 32
        map >> pitch_achieved;                // offset: 36
        map >> pitchl_FF;                     // offset: 40
        map >> pitch_P;                       // offset: 44
        map >> pitch_I;                       // offset: 48
        map >> pitch_D;                       // offset: 52
        map >> yaw_desired;                   // offset: 56
        map >> yaw_achieved;                  // offset: 60
        map >> yaw_FF;                        // offset: 64
        map >> yaw_P;                         // offset: 68
        map >> yaw_I;                         // offset: 72
        map >> yaw_D;                         // offset: 76
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
