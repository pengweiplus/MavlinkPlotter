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
    static constexpr msgid_t MSG_ID = 18;
    static constexpr size_t LENGTH = 22;
    static constexpr size_t MIN_LENGTH = 22;
    static constexpr uint8_t CRC_EXTRA = 202;
    static constexpr auto NAME = "BEACON_POWER";


    uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    float frequency; /*<  The frequency of satellite signal (17.7GHz..22GHz). */
    float power; /*<  The power of satellite signal dB. */
    float LNB_voltage; /*<  The voltage of LNB(13.4V 18.2V 14.6V 19.4V 0v). */
    uint8_t isLock; /*<  lock component(0:unlock 1:locked). */
    uint8_t isValid; /*<  valid component(0:invalid 1:valid). */


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
        ss << "  frequency: " << frequency << std::endl;
        ss << "  power: " << power << std::endl;
        ss << "  LNB_voltage: " << LNB_voltage << std::endl;
        ss << "  isLock: " << +isLock << std::endl;
        ss << "  isValid: " << +isValid << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << frequency;                     // offset: 8
        map << power;                         // offset: 12
        map << LNB_voltage;                   // offset: 16
        map << isLock;                        // offset: 20
        map << isValid;                       // offset: 21
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> frequency;                     // offset: 8
        map >> power;                         // offset: 12
        map >> LNB_voltage;                   // offset: 16
        map >> isLock;                        // offset: 20
        map >> isValid;                       // offset: 21
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
