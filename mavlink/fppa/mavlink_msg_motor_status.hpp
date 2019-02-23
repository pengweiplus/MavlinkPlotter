// MESSAGE MOTOR_STATUS support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief MOTOR_STATUS message
 *
 * The filtered motor status (e.g. position,electric current).
 */
struct MOTOR_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11;
    static constexpr size_t LENGTH = 33;
    static constexpr size_t MIN_LENGTH = 33;
    static constexpr uint8_t CRC_EXTRA = 47;
    static constexpr auto NAME = "MOTOR_STATUS";


    uint64_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    uint8_t status; /*<   2bits per motor (0:xx 1:xx 2:xx 3:xx) */
    float RxL1; /*< [deg] Receive L1 Position(0..360)(deg) */
    float RxL2; /*< [deg] Receive L2 Position(0..360)(deg) */
    float RxL3; /*< [deg] Receive L3 Position(0..360)(deg) */
    float TxL1; /*< [deg] Transmit L1 Position(0..360)(deg) */
    float TxL2; /*< [deg] Transmit L2 Position(0..360)(deg) */
    float TxL3; /*< [deg] Transmit L3 Position(0..360)(deg) */


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
        ss << "  status: " << +status << std::endl;
        ss << "  RxL1: " << RxL1 << std::endl;
        ss << "  RxL2: " << RxL2 << std::endl;
        ss << "  RxL3: " << RxL3 << std::endl;
        ss << "  TxL1: " << TxL1 << std::endl;
        ss << "  TxL2: " << TxL2 << std::endl;
        ss << "  TxL3: " << TxL3 << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << RxL1;                          // offset: 8
        map << RxL2;                          // offset: 12
        map << RxL3;                          // offset: 16
        map << TxL1;                          // offset: 20
        map << TxL2;                          // offset: 24
        map << TxL3;                          // offset: 28
        map << status;                        // offset: 32
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> RxL1;                          // offset: 8
        map >> RxL2;                          // offset: 12
        map >> RxL3;                          // offset: 16
        map >> TxL1;                          // offset: 20
        map >> TxL2;                          // offset: 24
        map >> TxL3;                          // offset: 28
        map >> status;                        // offset: 32
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
