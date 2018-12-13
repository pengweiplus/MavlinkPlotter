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
    static constexpr msgid_t MSG_ID = 156;
    static constexpr size_t LENGTH = 8;
    static constexpr size_t MIN_LENGTH = 8;
    static constexpr uint8_t CRC_EXTRA = 100;
    static constexpr auto NAME = "HUMITURE";


    float TEMPRETURE; /*<  power component. */
    float HUMIDITY; /*<  lock component. */


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
        ss << "  TEMPRETURE: " << TEMPRETURE << std::endl;
        ss << "  HUMIDITY: " << HUMIDITY << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << TEMPRETURE;                    // offset: 0
        map << HUMIDITY;                      // offset: 4
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> TEMPRETURE;                    // offset: 0
        map >> HUMIDITY;                      // offset: 4
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
