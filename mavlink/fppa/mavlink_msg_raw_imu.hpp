// MESSAGE RAW_IMU support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief RAW_IMU message
 *
 * The RAW IMU readings for the usual 9DOF sensor setup. This message should always contain the true raw values without any scaling to allow data capture and system debugging.
 */
struct RAW_IMU : mavlink::Message {
    static constexpr msgid_t MSG_ID = 15;
    static constexpr size_t LENGTH = 68;
    static constexpr size_t MIN_LENGTH = 68;
    static constexpr uint8_t CRC_EXTRA = 161;
    static constexpr auto NAME = "RAW_IMU";


    uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. */
    float xacc; /*<  X acceleration (raw) */
    float yacc; /*<  Y acceleration (raw) */
    float zacc; /*<  Z acceleration (raw) */
    float xgyro; /*<  Angular speed around X axis (raw) */
    float ygyro; /*<  Angular speed around Y axis (raw) */
    float zgyro; /*<  Angular speed around Z axis (raw) */
    float xmag; /*<  X Magnetic field (raw) */
    float ymag; /*<  Y Magnetic field (raw) */
    float zmag; /*<  Z Magnetic field (raw) */
    float x_delta_v; /*<  X delta vel (raw) */
    float y_delta_v; /*<  Y delta vel (raw) */
    float z_delta_v; /*<  Z delta vel (raw) */
    float x_angle; /*<  X delta angle (raw) */
    float y_angle; /*<  Y delta angle (raw) */
    float z_angle; /*<  Z delta angle (raw) */


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
        ss << "  time_usec: " << time_usec << std::endl;
        ss << "  xacc: " << xacc << std::endl;
        ss << "  yacc: " << yacc << std::endl;
        ss << "  zacc: " << zacc << std::endl;
        ss << "  xgyro: " << xgyro << std::endl;
        ss << "  ygyro: " << ygyro << std::endl;
        ss << "  zgyro: " << zgyro << std::endl;
        ss << "  xmag: " << xmag << std::endl;
        ss << "  ymag: " << ymag << std::endl;
        ss << "  zmag: " << zmag << std::endl;
        ss << "  x_delta_v: " << x_delta_v << std::endl;
        ss << "  y_delta_v: " << y_delta_v << std::endl;
        ss << "  z_delta_v: " << z_delta_v << std::endl;
        ss << "  x_angle: " << x_angle << std::endl;
        ss << "  y_angle: " << y_angle << std::endl;
        ss << "  z_angle: " << z_angle << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_usec;                     // offset: 0
        map << xacc;                          // offset: 8
        map << yacc;                          // offset: 12
        map << zacc;                          // offset: 16
        map << xgyro;                         // offset: 20
        map << ygyro;                         // offset: 24
        map << zgyro;                         // offset: 28
        map << xmag;                          // offset: 32
        map << ymag;                          // offset: 36
        map << zmag;                          // offset: 40
        map << x_delta_v;                     // offset: 44
        map << y_delta_v;                     // offset: 48
        map << z_delta_v;                     // offset: 52
        map << x_angle;                       // offset: 56
        map << y_angle;                       // offset: 60
        map << z_angle;                       // offset: 64
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_usec;                     // offset: 0
        map >> xacc;                          // offset: 8
        map >> yacc;                          // offset: 12
        map >> zacc;                          // offset: 16
        map >> xgyro;                         // offset: 20
        map >> ygyro;                         // offset: 24
        map >> zgyro;                         // offset: 28
        map >> xmag;                          // offset: 32
        map >> ymag;                          // offset: 36
        map >> zmag;                          // offset: 40
        map >> x_delta_v;                     // offset: 44
        map >> y_delta_v;                     // offset: 48
        map >> z_delta_v;                     // offset: 52
        map >> x_angle;                       // offset: 56
        map >> y_angle;                       // offset: 60
        map >> z_angle;                       // offset: 64
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
