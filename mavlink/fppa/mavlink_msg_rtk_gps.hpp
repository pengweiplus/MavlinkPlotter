// MESSAGE RTK_GPS support class

#pragma once

namespace mavlink {
namespace fppa {
namespace msg {

/**
 * @brief RTK_GPS message
 *
 * RTK_GPS PARAMETERS
 */
struct RTK_GPS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 16;
    static constexpr size_t LENGTH = 44;
    static constexpr size_t MIN_LENGTH = 44;
    static constexpr uint8_t CRC_EXTRA = 220;
    static constexpr auto NAME = "RTK_GPS";


    uint8_t fix_type; /*<  GPS fix type 1:no-fix,2:2D-fix,3:3D-fix. */
    float longitude; /*<  longitude.(deg) */
    float latitude; /*<   latitude.(deg) */
    float azimuth; /*<   azimuth.(-180..180)(deg) */
    float height; /*<  height (-999.9..9999.9)(meter). */
    float speed; /*<   speed (000.0..999.9)(Knots). */
    float course; /*<   course (-180.0..180.0)(deg). */
    float pdop; /*<  pdop (0.5..99.9). */
    float hdop; /*<   hdop (0.5..99.9). */
    float vdop; /*<   vdop (0.5..99.9). */
    uint8_t satellite_nums; /*<   satellite_nums (0..24)(GPS+BDS). */
    uint8_t year; /*<   component. */
    uint8_t month; /*<   component. */
    uint8_t day; /*<   component. */
    uint8_t hour; /*<   component. */
    uint8_t minute; /*<   component. */
    uint8_t second; /*<   component. */


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
        ss << "  fix_type: " << +fix_type << std::endl;
        ss << "  longitude: " << longitude << std::endl;
        ss << "  latitude: " << latitude << std::endl;
        ss << "  azimuth: " << azimuth << std::endl;
        ss << "  height: " << height << std::endl;
        ss << "  speed: " << speed << std::endl;
        ss << "  course: " << course << std::endl;
        ss << "  pdop: " << pdop << std::endl;
        ss << "  hdop: " << hdop << std::endl;
        ss << "  vdop: " << vdop << std::endl;
        ss << "  satellite_nums: " << +satellite_nums << std::endl;
        ss << "  year: " << +year << std::endl;
        ss << "  month: " << +month << std::endl;
        ss << "  day: " << +day << std::endl;
        ss << "  hour: " << +hour << std::endl;
        ss << "  minute: " << +minute << std::endl;
        ss << "  second: " << +second << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << longitude;                     // offset: 0
        map << latitude;                      // offset: 4
        map << azimuth;                       // offset: 8
        map << height;                        // offset: 12
        map << speed;                         // offset: 16
        map << course;                        // offset: 20
        map << pdop;                          // offset: 24
        map << hdop;                          // offset: 28
        map << vdop;                          // offset: 32
        map << fix_type;                      // offset: 36
        map << satellite_nums;                // offset: 37
        map << year;                          // offset: 38
        map << month;                         // offset: 39
        map << day;                           // offset: 40
        map << hour;                          // offset: 41
        map << minute;                        // offset: 42
        map << second;                        // offset: 43
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> longitude;                     // offset: 0
        map >> latitude;                      // offset: 4
        map >> azimuth;                       // offset: 8
        map >> height;                        // offset: 12
        map >> speed;                         // offset: 16
        map >> course;                        // offset: 20
        map >> pdop;                          // offset: 24
        map >> hdop;                          // offset: 28
        map >> vdop;                          // offset: 32
        map >> fix_type;                      // offset: 36
        map >> satellite_nums;                // offset: 37
        map >> year;                          // offset: 38
        map >> month;                         // offset: 39
        map >> day;                           // offset: 40
        map >> hour;                          // offset: 41
        map >> minute;                        // offset: 42
        map >> second;                        // offset: 43
    }
};

} // namespace msg
} // namespace fppa
} // namespace mavlink
