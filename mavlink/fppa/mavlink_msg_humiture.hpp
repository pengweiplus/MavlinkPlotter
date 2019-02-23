// MESSAGE HUMITURE support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief HUMITURE message
 *
 * HUMITURE PARAMETERS
 */
struct HUMITURE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 17;
    static constexpr size_t LENGTH = 16;
    static constexpr size_t MIN_LENGTH = 16;
    static constexpr uint8_t CRC_EXTRA = 3;
    static constexpr auto NAME = "HUMITURE";


    uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    float tempreture; /*<  The tempreture of chassis.(Celsius degree) */
    float humidity; /*<  The humidity of chassis..(0.0%..100.0%) */


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
        ss << "  tempreture: " << tempreture << std::endl;
        ss << "  humidity: " << humidity << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << tempreture;                    // offset: 8
        map << humidity;                      // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> tempreture;                    // offset: 8
        map >> humidity;                      // offset: 12
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
