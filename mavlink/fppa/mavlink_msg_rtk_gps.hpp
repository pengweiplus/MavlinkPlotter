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
    static constexpr msgid_t MSG_ID = 154;
    static constexpr size_t LENGTH = 44;
    static constexpr size_t MIN_LENGTH = 44;
    static constexpr uint8_t CRC_EXTRA = 195;
    static constexpr auto NAME = "RTK_GPS";


    char status; /*<  status component. */
    float longitude; /*<  longitude component. */
    float latitude; /*<   component. */
    float azimuth; /*<   component. */
    float height; /*<  longitude component. */
    float speed; /*<   component. */
    float orientation; /*<   component. */
    float com_precision; /*<  longitude component. */
    float level_precision; /*<   component. */
    float vertical_precision; /*<   component. */
    char number; /*<   component. */
    char year; /*<   component. */
    char month; /*<   component. */
    char day; /*<   component. */
    char hour; /*<   component. */
    char minute; /*<   component. */
    char second; /*<   component. */


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
        ss << "  status: " << +status << std::endl;
        ss << "  longitude: " << longitude << std::endl;
        ss << "  latitude: " << latitude << std::endl;
        ss << "  azimuth: " << azimuth << std::endl;
        ss << "  height: " << height << std::endl;
        ss << "  speed: " << speed << std::endl;
        ss << "  orientation: " << orientation << std::endl;
        ss << "  com_precision: " << com_precision << std::endl;
        ss << "  level_precision: " << level_precision << std::endl;
        ss << "  vertical_precision: " << vertical_precision << std::endl;
        ss << "  number: " << +number << std::endl;
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
        map << orientation;                   // offset: 20
        map << com_precision;                 // offset: 24
        map << level_precision;               // offset: 28
        map << vertical_precision;            // offset: 32
        map << status;                        // offset: 36
        map << number;                        // offset: 37
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
        map >> orientation;                   // offset: 20
        map >> com_precision;                 // offset: 24
        map >> level_precision;               // offset: 28
        map >> vertical_precision;            // offset: 32
        map >> status;                        // offset: 36
        map >> number;                        // offset: 37
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
