// MESSAGE BEACON_POWER support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief BEACON_POWER message
 *
 * BEACON_POWER PARAMETERS
 */
struct BEACON_POWER : mavlink::Message {
    static constexpr msgid_t MSG_ID = 155;
    static constexpr size_t LENGTH = 6;
    static constexpr size_t MIN_LENGTH = 6;
    static constexpr uint8_t CRC_EXTRA = 178;
    static constexpr auto NAME = "BEACON_POWER";


    float power; /*<  power component. */
    char isLock; /*<  lock component. */
    char isValid; /*<  valid component. */


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
        ss << "  power: " << power << std::endl;
        ss << "  isLock: " << +isLock << std::endl;
        ss << "  isValid: " << +isValid << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << power;                         // offset: 0
        map << isLock;                        // offset: 4
        map << isValid;                       // offset: 5
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> power;                         // offset: 0
        map >> isLock;                        // offset: 4
        map >> isValid;                       // offset: 5
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
