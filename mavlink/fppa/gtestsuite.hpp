/** @file
 *	@brief MAVLink comm testsuite protocol generated from fppa.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "fppa.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(fppa, HEARTBEAT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::HEARTBEAT packet_in{};
    packet_in.type = 17;
    packet_in.autopilot = 84;
    packet_in.base_mode = 151;
    packet_in.custom_mode = 963497464;
    packet_in.system_status = 218;
    packet_in.mavlink_version = 2;

    mavlink::fppa::msg::HEARTBEAT packet1{};
    mavlink::fppa::msg::HEARTBEAT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.type, packet2.type);
    EXPECT_EQ(packet1.autopilot, packet2.autopilot);
    EXPECT_EQ(packet1.base_mode, packet2.base_mode);
    EXPECT_EQ(packet1.custom_mode, packet2.custom_mode);
    EXPECT_EQ(packet1.system_status, packet2.system_status);
    EXPECT_EQ(packet1.mavlink_version, packet2.mavlink_version);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, HEARTBEAT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_heartbeat_t packet_c {
         963497464, 17, 84, 151, 218, 2
    };

    mavlink::fppa::msg::HEARTBEAT packet_in{};
    packet_in.type = 17;
    packet_in.autopilot = 84;
    packet_in.base_mode = 151;
    packet_in.custom_mode = 963497464;
    packet_in.system_status = 218;
    packet_in.mavlink_version = 2;

    mavlink::fppa::msg::HEARTBEAT packet2{};

    mavlink_msg_heartbeat_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.type, packet2.type);
    EXPECT_EQ(packet_in.autopilot, packet2.autopilot);
    EXPECT_EQ(packet_in.base_mode, packet2.base_mode);
    EXPECT_EQ(packet_in.custom_mode, packet2.custom_mode);
    EXPECT_EQ(packet_in.system_status, packet2.system_status);
    EXPECT_EQ(packet_in.mavlink_version, packet2.mavlink_version);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, GPS_RAW_INT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::GPS_RAW_INT packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.fix_type = 89;
    packet_in.lat = 963497880;
    packet_in.lon = 963498088;
    packet_in.alt = 963498296;
    packet_in.eph = 18275;
    packet_in.epv = 18379;
    packet_in.vel = 18483;
    packet_in.cog = 18587;
    packet_in.satellites_visible = 156;
    packet_in.alt_ellipsoid = 963499024;
    packet_in.h_acc = 963499232;
    packet_in.v_acc = 963499440;
    packet_in.vel_acc = 963499648;
    packet_in.hdg_acc = 963499856;

    mavlink::fppa::msg::GPS_RAW_INT packet1{};
    mavlink::fppa::msg::GPS_RAW_INT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
    EXPECT_EQ(packet1.fix_type, packet2.fix_type);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lon, packet2.lon);
    EXPECT_EQ(packet1.alt, packet2.alt);
    EXPECT_EQ(packet1.eph, packet2.eph);
    EXPECT_EQ(packet1.epv, packet2.epv);
    EXPECT_EQ(packet1.vel, packet2.vel);
    EXPECT_EQ(packet1.cog, packet2.cog);
    EXPECT_EQ(packet1.satellites_visible, packet2.satellites_visible);
    EXPECT_EQ(packet1.alt_ellipsoid, packet2.alt_ellipsoid);
    EXPECT_EQ(packet1.h_acc, packet2.h_acc);
    EXPECT_EQ(packet1.v_acc, packet2.v_acc);
    EXPECT_EQ(packet1.vel_acc, packet2.vel_acc);
    EXPECT_EQ(packet1.hdg_acc, packet2.hdg_acc);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, GPS_RAW_INT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gps_raw_int_t packet_c {
         93372036854775807ULL, 963497880, 963498088, 963498296, 18275, 18379, 18483, 18587, 89, 156, 963499024, 963499232, 963499440, 963499648, 963499856
    };

    mavlink::fppa::msg::GPS_RAW_INT packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.fix_type = 89;
    packet_in.lat = 963497880;
    packet_in.lon = 963498088;
    packet_in.alt = 963498296;
    packet_in.eph = 18275;
    packet_in.epv = 18379;
    packet_in.vel = 18483;
    packet_in.cog = 18587;
    packet_in.satellites_visible = 156;
    packet_in.alt_ellipsoid = 963499024;
    packet_in.h_acc = 963499232;
    packet_in.v_acc = 963499440;
    packet_in.vel_acc = 963499648;
    packet_in.hdg_acc = 963499856;

    mavlink::fppa::msg::GPS_RAW_INT packet2{};

    mavlink_msg_gps_raw_int_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);
    EXPECT_EQ(packet_in.fix_type, packet2.fix_type);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lon, packet2.lon);
    EXPECT_EQ(packet_in.alt, packet2.alt);
    EXPECT_EQ(packet_in.eph, packet2.eph);
    EXPECT_EQ(packet_in.epv, packet2.epv);
    EXPECT_EQ(packet_in.vel, packet2.vel);
    EXPECT_EQ(packet_in.cog, packet2.cog);
    EXPECT_EQ(packet_in.satellites_visible, packet2.satellites_visible);
    EXPECT_EQ(packet_in.alt_ellipsoid, packet2.alt_ellipsoid);
    EXPECT_EQ(packet_in.h_acc, packet2.h_acc);
    EXPECT_EQ(packet_in.v_acc, packet2.v_acc);
    EXPECT_EQ(packet_in.vel_acc, packet2.vel_acc);
    EXPECT_EQ(packet_in.hdg_acc, packet2.hdg_acc);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, RAW_IMU)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::RAW_IMU packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.xacc = 17651;
    packet_in.yacc = 17755;
    packet_in.zacc = 17859;
    packet_in.xgyro = 17963;
    packet_in.ygyro = 18067;
    packet_in.zgyro = 18171;
    packet_in.xmag = 18275;
    packet_in.ymag = 18379;
    packet_in.zmag = 18483;

    mavlink::fppa::msg::RAW_IMU packet1{};
    mavlink::fppa::msg::RAW_IMU packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
    EXPECT_EQ(packet1.xacc, packet2.xacc);
    EXPECT_EQ(packet1.yacc, packet2.yacc);
    EXPECT_EQ(packet1.zacc, packet2.zacc);
    EXPECT_EQ(packet1.xgyro, packet2.xgyro);
    EXPECT_EQ(packet1.ygyro, packet2.ygyro);
    EXPECT_EQ(packet1.zgyro, packet2.zgyro);
    EXPECT_EQ(packet1.xmag, packet2.xmag);
    EXPECT_EQ(packet1.ymag, packet2.ymag);
    EXPECT_EQ(packet1.zmag, packet2.zmag);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, RAW_IMU)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_raw_imu_t packet_c {
         93372036854775807ULL, 17651, 17755, 17859, 17963, 18067, 18171, 18275, 18379, 18483
    };

    mavlink::fppa::msg::RAW_IMU packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.xacc = 17651;
    packet_in.yacc = 17755;
    packet_in.zacc = 17859;
    packet_in.xgyro = 17963;
    packet_in.ygyro = 18067;
    packet_in.zgyro = 18171;
    packet_in.xmag = 18275;
    packet_in.ymag = 18379;
    packet_in.zmag = 18483;

    mavlink::fppa::msg::RAW_IMU packet2{};

    mavlink_msg_raw_imu_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);
    EXPECT_EQ(packet_in.xacc, packet2.xacc);
    EXPECT_EQ(packet_in.yacc, packet2.yacc);
    EXPECT_EQ(packet_in.zacc, packet2.zacc);
    EXPECT_EQ(packet_in.xgyro, packet2.xgyro);
    EXPECT_EQ(packet_in.ygyro, packet2.ygyro);
    EXPECT_EQ(packet_in.zgyro, packet2.zgyro);
    EXPECT_EQ(packet_in.xmag, packet2.xmag);
    EXPECT_EQ(packet_in.ymag, packet2.ymag);
    EXPECT_EQ(packet_in.zmag, packet2.zmag);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, ATTITUDE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::ATTITUDE packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.rollspeed = 129.0;
    packet_in.pitchspeed = 157.0;
    packet_in.yawspeed = 185.0;

    mavlink::fppa::msg::ATTITUDE packet1{};
    mavlink::fppa::msg::ATTITUDE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.rollspeed, packet2.rollspeed);
    EXPECT_EQ(packet1.pitchspeed, packet2.pitchspeed);
    EXPECT_EQ(packet1.yawspeed, packet2.yawspeed);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, ATTITUDE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_attitude_t packet_c {
         963497464, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0
    };

    mavlink::fppa::msg::ATTITUDE packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.rollspeed = 129.0;
    packet_in.pitchspeed = 157.0;
    packet_in.yawspeed = 185.0;

    mavlink::fppa::msg::ATTITUDE packet2{};

    mavlink_msg_attitude_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.rollspeed, packet2.rollspeed);
    EXPECT_EQ(packet_in.pitchspeed, packet2.pitchspeed);
    EXPECT_EQ(packet_in.yawspeed, packet2.yawspeed);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, ATTITUDE_QUATERNION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::ATTITUDE_QUATERNION packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.q1 = 45.0;
    packet_in.q2 = 73.0;
    packet_in.q3 = 101.0;
    packet_in.q4 = 129.0;
    packet_in.rollspeed = 157.0;
    packet_in.pitchspeed = 185.0;
    packet_in.yawspeed = 213.0;

    mavlink::fppa::msg::ATTITUDE_QUATERNION packet1{};
    mavlink::fppa::msg::ATTITUDE_QUATERNION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.q1, packet2.q1);
    EXPECT_EQ(packet1.q2, packet2.q2);
    EXPECT_EQ(packet1.q3, packet2.q3);
    EXPECT_EQ(packet1.q4, packet2.q4);
    EXPECT_EQ(packet1.rollspeed, packet2.rollspeed);
    EXPECT_EQ(packet1.pitchspeed, packet2.pitchspeed);
    EXPECT_EQ(packet1.yawspeed, packet2.yawspeed);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, ATTITUDE_QUATERNION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_attitude_quaternion_t packet_c {
         963497464, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0
    };

    mavlink::fppa::msg::ATTITUDE_QUATERNION packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.q1 = 45.0;
    packet_in.q2 = 73.0;
    packet_in.q3 = 101.0;
    packet_in.q4 = 129.0;
    packet_in.rollspeed = 157.0;
    packet_in.pitchspeed = 185.0;
    packet_in.yawspeed = 213.0;

    mavlink::fppa::msg::ATTITUDE_QUATERNION packet2{};

    mavlink_msg_attitude_quaternion_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.q1, packet2.q1);
    EXPECT_EQ(packet_in.q2, packet2.q2);
    EXPECT_EQ(packet_in.q3, packet2.q3);
    EXPECT_EQ(packet_in.q4, packet2.q4);
    EXPECT_EQ(packet_in.rollspeed, packet2.rollspeed);
    EXPECT_EQ(packet_in.pitchspeed, packet2.pitchspeed);
    EXPECT_EQ(packet_in.yawspeed, packet2.yawspeed);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, LOCAL_POSITION_NED)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::LOCAL_POSITION_NED packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.x = 45.0;
    packet_in.y = 73.0;
    packet_in.z = 101.0;
    packet_in.vx = 129.0;
    packet_in.vy = 157.0;
    packet_in.vz = 185.0;

    mavlink::fppa::msg::LOCAL_POSITION_NED packet1{};
    mavlink::fppa::msg::LOCAL_POSITION_NED packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.x, packet2.x);
    EXPECT_EQ(packet1.y, packet2.y);
    EXPECT_EQ(packet1.z, packet2.z);
    EXPECT_EQ(packet1.vx, packet2.vx);
    EXPECT_EQ(packet1.vy, packet2.vy);
    EXPECT_EQ(packet1.vz, packet2.vz);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, LOCAL_POSITION_NED)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_local_position_ned_t packet_c {
         963497464, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0
    };

    mavlink::fppa::msg::LOCAL_POSITION_NED packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.x = 45.0;
    packet_in.y = 73.0;
    packet_in.z = 101.0;
    packet_in.vx = 129.0;
    packet_in.vy = 157.0;
    packet_in.vz = 185.0;

    mavlink::fppa::msg::LOCAL_POSITION_NED packet2{};

    mavlink_msg_local_position_ned_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.x, packet2.x);
    EXPECT_EQ(packet_in.y, packet2.y);
    EXPECT_EQ(packet_in.z, packet2.z);
    EXPECT_EQ(packet_in.vx, packet2.vx);
    EXPECT_EQ(packet_in.vy, packet2.vy);
    EXPECT_EQ(packet_in.vz, packet2.vz);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, COMMAND_LONG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::COMMAND_LONG packet_in{};
    packet_in.target_system = 223;
    packet_in.target_component = 34;
    packet_in.command = 18691;
    packet_in.confirmation = 101;
    packet_in.param1 = 17.0;
    packet_in.param2 = 45.0;
    packet_in.param3 = 73.0;
    packet_in.param4 = 101.0;
    packet_in.param5 = 129.0;
    packet_in.param6 = 157.0;
    packet_in.param7 = 185.0;

    mavlink::fppa::msg::COMMAND_LONG packet1{};
    mavlink::fppa::msg::COMMAND_LONG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.command, packet2.command);
    EXPECT_EQ(packet1.confirmation, packet2.confirmation);
    EXPECT_EQ(packet1.param1, packet2.param1);
    EXPECT_EQ(packet1.param2, packet2.param2);
    EXPECT_EQ(packet1.param3, packet2.param3);
    EXPECT_EQ(packet1.param4, packet2.param4);
    EXPECT_EQ(packet1.param5, packet2.param5);
    EXPECT_EQ(packet1.param6, packet2.param6);
    EXPECT_EQ(packet1.param7, packet2.param7);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, COMMAND_LONG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_command_long_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 18691, 223, 34, 101
    };

    mavlink::fppa::msg::COMMAND_LONG packet_in{};
    packet_in.target_system = 223;
    packet_in.target_component = 34;
    packet_in.command = 18691;
    packet_in.confirmation = 101;
    packet_in.param1 = 17.0;
    packet_in.param2 = 45.0;
    packet_in.param3 = 73.0;
    packet_in.param4 = 101.0;
    packet_in.param5 = 129.0;
    packet_in.param6 = 157.0;
    packet_in.param7 = 185.0;

    mavlink::fppa::msg::COMMAND_LONG packet2{};

    mavlink_msg_command_long_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.command, packet2.command);
    EXPECT_EQ(packet_in.confirmation, packet2.confirmation);
    EXPECT_EQ(packet_in.param1, packet2.param1);
    EXPECT_EQ(packet_in.param2, packet2.param2);
    EXPECT_EQ(packet_in.param3, packet2.param3);
    EXPECT_EQ(packet_in.param4, packet2.param4);
    EXPECT_EQ(packet_in.param5, packet2.param5);
    EXPECT_EQ(packet_in.param6, packet2.param6);
    EXPECT_EQ(packet_in.param7, packet2.param7);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, MANUAL_SETPOINT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::MANUAL_SETPOINT packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.thrust = 129.0;
    packet_in.mode_switch = 65;
    packet_in.manual_override_switch = 132;

    mavlink::fppa::msg::MANUAL_SETPOINT packet1{};
    mavlink::fppa::msg::MANUAL_SETPOINT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.thrust, packet2.thrust);
    EXPECT_EQ(packet1.mode_switch, packet2.mode_switch);
    EXPECT_EQ(packet1.manual_override_switch, packet2.manual_override_switch);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, MANUAL_SETPOINT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_manual_setpoint_t packet_c {
         963497464, 45.0, 73.0, 101.0, 129.0, 65, 132
    };

    mavlink::fppa::msg::MANUAL_SETPOINT packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.thrust = 129.0;
    packet_in.mode_switch = 65;
    packet_in.manual_override_switch = 132;

    mavlink::fppa::msg::MANUAL_SETPOINT packet2{};

    mavlink_msg_manual_setpoint_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.thrust, packet2.thrust);
    EXPECT_EQ(packet_in.mode_switch, packet2.mode_switch);
    EXPECT_EQ(packet_in.manual_override_switch, packet2.manual_override_switch);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, ATTITUDE_TARGET)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::ATTITUDE_TARGET packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.type_mask = 113;
    packet_in.q = {{ 45.0, 46.0, 47.0, 48.0 }};
    packet_in.body_roll_rate = 157.0;
    packet_in.body_pitch_rate = 185.0;
    packet_in.body_yaw_rate = 213.0;
    packet_in.thrust = 241.0;

    mavlink::fppa::msg::ATTITUDE_TARGET packet1{};
    mavlink::fppa::msg::ATTITUDE_TARGET packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.type_mask, packet2.type_mask);
    EXPECT_EQ(packet1.q, packet2.q);
    EXPECT_EQ(packet1.body_roll_rate, packet2.body_roll_rate);
    EXPECT_EQ(packet1.body_pitch_rate, packet2.body_pitch_rate);
    EXPECT_EQ(packet1.body_yaw_rate, packet2.body_yaw_rate);
    EXPECT_EQ(packet1.thrust, packet2.thrust);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, ATTITUDE_TARGET)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_attitude_target_t packet_c {
         963497464, { 45.0, 46.0, 47.0, 48.0 }, 157.0, 185.0, 213.0, 241.0, 113
    };

    mavlink::fppa::msg::ATTITUDE_TARGET packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.type_mask = 113;
    packet_in.q = {{ 45.0, 46.0, 47.0, 48.0 }};
    packet_in.body_roll_rate = 157.0;
    packet_in.body_pitch_rate = 185.0;
    packet_in.body_yaw_rate = 213.0;
    packet_in.thrust = 241.0;

    mavlink::fppa::msg::ATTITUDE_TARGET packet2{};

    mavlink_msg_attitude_target_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.type_mask, packet2.type_mask);
    EXPECT_EQ(packet_in.q, packet2.q);
    EXPECT_EQ(packet_in.body_roll_rate, packet2.body_roll_rate);
    EXPECT_EQ(packet_in.body_pitch_rate, packet2.body_pitch_rate);
    EXPECT_EQ(packet_in.body_yaw_rate, packet2.body_yaw_rate);
    EXPECT_EQ(packet_in.thrust, packet2.thrust);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, AHRS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::AHRS packet_in{};
    packet_in.omegaIx = 17.0;
    packet_in.omegaIy = 45.0;
    packet_in.omegaIz = 73.0;
    packet_in.accel_weight = 101.0;
    packet_in.renorm_val = 129.0;
    packet_in.error_rp = 157.0;
    packet_in.error_yaw = 185.0;

    mavlink::fppa::msg::AHRS packet1{};
    mavlink::fppa::msg::AHRS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.omegaIx, packet2.omegaIx);
    EXPECT_EQ(packet1.omegaIy, packet2.omegaIy);
    EXPECT_EQ(packet1.omegaIz, packet2.omegaIz);
    EXPECT_EQ(packet1.accel_weight, packet2.accel_weight);
    EXPECT_EQ(packet1.renorm_val, packet2.renorm_val);
    EXPECT_EQ(packet1.error_rp, packet2.error_rp);
    EXPECT_EQ(packet1.error_yaw, packet2.error_yaw);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, AHRS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ahrs_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0
    };

    mavlink::fppa::msg::AHRS packet_in{};
    packet_in.omegaIx = 17.0;
    packet_in.omegaIy = 45.0;
    packet_in.omegaIz = 73.0;
    packet_in.accel_weight = 101.0;
    packet_in.renorm_val = 129.0;
    packet_in.error_rp = 157.0;
    packet_in.error_yaw = 185.0;

    mavlink::fppa::msg::AHRS packet2{};

    mavlink_msg_ahrs_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.omegaIx, packet2.omegaIx);
    EXPECT_EQ(packet_in.omegaIy, packet2.omegaIy);
    EXPECT_EQ(packet_in.omegaIz, packet2.omegaIz);
    EXPECT_EQ(packet_in.accel_weight, packet2.accel_weight);
    EXPECT_EQ(packet_in.renorm_val, packet2.renorm_val);
    EXPECT_EQ(packet_in.error_rp, packet2.error_rp);
    EXPECT_EQ(packet_in.error_yaw, packet2.error_yaw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, AHRS2)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::AHRS2 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;

    mavlink::fppa::msg::AHRS2 packet1{};
    mavlink::fppa::msg::AHRS2 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.altitude, packet2.altitude);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, AHRS2)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ahrs2_t packet_c {
         17.0, 45.0, 73.0, 101.0, 963498296, 963498504
    };

    mavlink::fppa::msg::AHRS2 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;

    mavlink::fppa::msg::AHRS2 packet2{};

    mavlink_msg_ahrs2_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.altitude, packet2.altitude);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, AHRS3)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::AHRS3 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;
    packet_in.v1 = 185.0;
    packet_in.v2 = 213.0;
    packet_in.v3 = 241.0;
    packet_in.v4 = 269.0;

    mavlink::fppa::msg::AHRS3 packet1{};
    mavlink::fppa::msg::AHRS3 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.altitude, packet2.altitude);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
    EXPECT_EQ(packet1.v1, packet2.v1);
    EXPECT_EQ(packet1.v2, packet2.v2);
    EXPECT_EQ(packet1.v3, packet2.v3);
    EXPECT_EQ(packet1.v4, packet2.v4);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, AHRS3)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ahrs3_t packet_c {
         17.0, 45.0, 73.0, 101.0, 963498296, 963498504, 185.0, 213.0, 241.0, 269.0
    };

    mavlink::fppa::msg::AHRS3 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;
    packet_in.v1 = 185.0;
    packet_in.v2 = 213.0;
    packet_in.v3 = 241.0;
    packet_in.v4 = 269.0;

    mavlink::fppa::msg::AHRS3 packet2{};

    mavlink_msg_ahrs3_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.altitude, packet2.altitude);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);
    EXPECT_EQ(packet_in.v1, packet2.v1);
    EXPECT_EQ(packet_in.v2, packet2.v2);
    EXPECT_EQ(packet_in.v3, packet2.v3);
    EXPECT_EQ(packet_in.v4, packet2.v4);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, PID_TUNING)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::PID_TUNING packet_in{};
    packet_in.axis = 77;
    packet_in.desired = 17.0;
    packet_in.achieved = 45.0;
    packet_in.FF = 73.0;
    packet_in.P = 101.0;
    packet_in.I = 129.0;
    packet_in.D = 157.0;

    mavlink::fppa::msg::PID_TUNING packet1{};
    mavlink::fppa::msg::PID_TUNING packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.axis, packet2.axis);
    EXPECT_EQ(packet1.desired, packet2.desired);
    EXPECT_EQ(packet1.achieved, packet2.achieved);
    EXPECT_EQ(packet1.FF, packet2.FF);
    EXPECT_EQ(packet1.P, packet2.P);
    EXPECT_EQ(packet1.I, packet2.I);
    EXPECT_EQ(packet1.D, packet2.D);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, PID_TUNING)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_pid_tuning_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 77
    };

    mavlink::fppa::msg::PID_TUNING packet_in{};
    packet_in.axis = 77;
    packet_in.desired = 17.0;
    packet_in.achieved = 45.0;
    packet_in.FF = 73.0;
    packet_in.P = 101.0;
    packet_in.I = 129.0;
    packet_in.D = 157.0;

    mavlink::fppa::msg::PID_TUNING packet2{};

    mavlink_msg_pid_tuning_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.axis, packet2.axis);
    EXPECT_EQ(packet_in.desired, packet2.desired);
    EXPECT_EQ(packet_in.achieved, packet2.achieved);
    EXPECT_EQ(packet_in.FF, packet2.FF);
    EXPECT_EQ(packet_in.P, packet2.P);
    EXPECT_EQ(packet_in.I, packet2.I);
    EXPECT_EQ(packet_in.D, packet2.D);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, RTK_GPS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::RTK_GPS packet_in{};
    packet_in.status = 'K';
    packet_in.longitude = 17.0;
    packet_in.latitude = 45.0;
    packet_in.azimuth = 73.0;
    packet_in.height = 101.0;
    packet_in.speed = 129.0;
    packet_in.orientation = 157.0;
    packet_in.com_precision = 185.0;
    packet_in.level_precision = 213.0;
    packet_in.vertical_precision = 241.0;
    packet_in.number = 'L';
    packet_in.year = 'M';
    packet_in.month = 'N';
    packet_in.day = 'O';
    packet_in.hour = 'P';
    packet_in.minute = 'Q';
    packet_in.second = 'R';

    mavlink::fppa::msg::RTK_GPS packet1{};
    mavlink::fppa::msg::RTK_GPS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.status, packet2.status);
    EXPECT_EQ(packet1.longitude, packet2.longitude);
    EXPECT_EQ(packet1.latitude, packet2.latitude);
    EXPECT_EQ(packet1.azimuth, packet2.azimuth);
    EXPECT_EQ(packet1.height, packet2.height);
    EXPECT_EQ(packet1.speed, packet2.speed);
    EXPECT_EQ(packet1.orientation, packet2.orientation);
    EXPECT_EQ(packet1.com_precision, packet2.com_precision);
    EXPECT_EQ(packet1.level_precision, packet2.level_precision);
    EXPECT_EQ(packet1.vertical_precision, packet2.vertical_precision);
    EXPECT_EQ(packet1.number, packet2.number);
    EXPECT_EQ(packet1.year, packet2.year);
    EXPECT_EQ(packet1.month, packet2.month);
    EXPECT_EQ(packet1.day, packet2.day);
    EXPECT_EQ(packet1.hour, packet2.hour);
    EXPECT_EQ(packet1.minute, packet2.minute);
    EXPECT_EQ(packet1.second, packet2.second);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, RTK_GPS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rtk_gps_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'
    };

    mavlink::fppa::msg::RTK_GPS packet_in{};
    packet_in.status = 'K';
    packet_in.longitude = 17.0;
    packet_in.latitude = 45.0;
    packet_in.azimuth = 73.0;
    packet_in.height = 101.0;
    packet_in.speed = 129.0;
    packet_in.orientation = 157.0;
    packet_in.com_precision = 185.0;
    packet_in.level_precision = 213.0;
    packet_in.vertical_precision = 241.0;
    packet_in.number = 'L';
    packet_in.year = 'M';
    packet_in.month = 'N';
    packet_in.day = 'O';
    packet_in.hour = 'P';
    packet_in.minute = 'Q';
    packet_in.second = 'R';

    mavlink::fppa::msg::RTK_GPS packet2{};

    mavlink_msg_rtk_gps_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.status, packet2.status);
    EXPECT_EQ(packet_in.longitude, packet2.longitude);
    EXPECT_EQ(packet_in.latitude, packet2.latitude);
    EXPECT_EQ(packet_in.azimuth, packet2.azimuth);
    EXPECT_EQ(packet_in.height, packet2.height);
    EXPECT_EQ(packet_in.speed, packet2.speed);
    EXPECT_EQ(packet_in.orientation, packet2.orientation);
    EXPECT_EQ(packet_in.com_precision, packet2.com_precision);
    EXPECT_EQ(packet_in.level_precision, packet2.level_precision);
    EXPECT_EQ(packet_in.vertical_precision, packet2.vertical_precision);
    EXPECT_EQ(packet_in.number, packet2.number);
    EXPECT_EQ(packet_in.year, packet2.year);
    EXPECT_EQ(packet_in.month, packet2.month);
    EXPECT_EQ(packet_in.day, packet2.day);
    EXPECT_EQ(packet_in.hour, packet2.hour);
    EXPECT_EQ(packet_in.minute, packet2.minute);
    EXPECT_EQ(packet_in.second, packet2.second);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, BEACON_POWER)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::BEACON_POWER packet_in{};
    packet_in.power = 17.0;
    packet_in.isLock = 'E';
    packet_in.isValid = 'F';

    mavlink::fppa::msg::BEACON_POWER packet1{};
    mavlink::fppa::msg::BEACON_POWER packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.power, packet2.power);
    EXPECT_EQ(packet1.isLock, packet2.isLock);
    EXPECT_EQ(packet1.isValid, packet2.isValid);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, BEACON_POWER)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_beacon_power_t packet_c {
         17.0, 'E', 'F'
    };

    mavlink::fppa::msg::BEACON_POWER packet_in{};
    packet_in.power = 17.0;
    packet_in.isLock = 'E';
    packet_in.isValid = 'F';

    mavlink::fppa::msg::BEACON_POWER packet2{};

    mavlink_msg_beacon_power_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.power, packet2.power);
    EXPECT_EQ(packet_in.isLock, packet2.isLock);
    EXPECT_EQ(packet_in.isValid, packet2.isValid);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, HUMITURE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::HUMITURE packet_in{};
    packet_in.TEMPRETURE = 17.0;
    packet_in.HUMIDITY = 45.0;

    mavlink::fppa::msg::HUMITURE packet1{};
    mavlink::fppa::msg::HUMITURE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.TEMPRETURE, packet2.TEMPRETURE);
    EXPECT_EQ(packet1.HUMIDITY, packet2.HUMIDITY);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, HUMITURE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_humiture_t packet_c {
         17.0, 45.0
    };

    mavlink::fppa::msg::HUMITURE packet_in{};
    packet_in.TEMPRETURE = 17.0;
    packet_in.HUMIDITY = 45.0;

    mavlink::fppa::msg::HUMITURE packet2{};

    mavlink_msg_humiture_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.TEMPRETURE, packet2.TEMPRETURE);
    EXPECT_EQ(packet_in.HUMIDITY, packet2.HUMIDITY);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
