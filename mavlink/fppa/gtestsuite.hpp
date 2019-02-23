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

TEST(fppa, MOTOR_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::MOTOR_STATUS packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.status = 101;
    packet_in.RxL1 = 73.0;
    packet_in.RxL2 = 101.0;
    packet_in.RxL3 = 129.0;
    packet_in.TxL1 = 157.0;
    packet_in.TxL2 = 185.0;
    packet_in.TxL3 = 213.0;

    mavlink::fppa::msg::MOTOR_STATUS packet1{};
    mavlink::fppa::msg::MOTOR_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.status, packet2.status);
    EXPECT_EQ(packet1.RxL1, packet2.RxL1);
    EXPECT_EQ(packet1.RxL2, packet2.RxL2);
    EXPECT_EQ(packet1.RxL3, packet2.RxL3);
    EXPECT_EQ(packet1.TxL1, packet2.TxL1);
    EXPECT_EQ(packet1.TxL2, packet2.TxL2);
    EXPECT_EQ(packet1.TxL3, packet2.TxL3);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, MOTOR_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_motor_status_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 101
    };

    mavlink::fppa::msg::MOTOR_STATUS packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.status = 101;
    packet_in.RxL1 = 73.0;
    packet_in.RxL2 = 101.0;
    packet_in.RxL3 = 129.0;
    packet_in.TxL1 = 157.0;
    packet_in.TxL2 = 185.0;
    packet_in.TxL3 = 213.0;

    mavlink::fppa::msg::MOTOR_STATUS packet2{};

    mavlink_msg_motor_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.status, packet2.status);
    EXPECT_EQ(packet_in.RxL1, packet2.RxL1);
    EXPECT_EQ(packet_in.RxL2, packet2.RxL2);
    EXPECT_EQ(packet_in.RxL3, packet2.RxL3);
    EXPECT_EQ(packet_in.TxL1, packet2.TxL1);
    EXPECT_EQ(packet_in.TxL2, packet2.TxL2);
    EXPECT_EQ(packet_in.TxL3, packet2.TxL3);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, ATTITUDE_BODY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::ATTITUDE_BODY packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.roll_speed = 157.0;
    packet_in.pitch_speed = 185.0;
    packet_in.yaw_speed = 213.0;
    packet_in.roll_observed = 241.0;
    packet_in.pitch_observed = 269.0;
    packet_in.yaw_observed = 297.0;
    packet_in.roll_obs_sub_pred = 325.0;
    packet_in.pitch_obs_sub_pred = 353.0;
    packet_in.yaw_obs_sub_pred = 381.0;
    packet_in.gyro_x_noise = 409.0;
    packet_in.gyro_y_noise = 437.0;
    packet_in.gyro_z_noise = 465.0;
    packet_in.acc_x_noise = 493.0;
    packet_in.acc_y_noise = 521.0;
    packet_in.acc_z_noise = 549.0;
    packet_in.mag_x_noise = 577.0;
    packet_in.mag_y_noise = 605.0;
    packet_in.mag_z_noise = 633.0;
    packet_in.static_flag = 25;

    mavlink::fppa::msg::ATTITUDE_BODY packet1{};
    mavlink::fppa::msg::ATTITUDE_BODY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.roll_speed, packet2.roll_speed);
    EXPECT_EQ(packet1.pitch_speed, packet2.pitch_speed);
    EXPECT_EQ(packet1.yaw_speed, packet2.yaw_speed);
    EXPECT_EQ(packet1.roll_observed, packet2.roll_observed);
    EXPECT_EQ(packet1.pitch_observed, packet2.pitch_observed);
    EXPECT_EQ(packet1.yaw_observed, packet2.yaw_observed);
    EXPECT_EQ(packet1.roll_obs_sub_pred, packet2.roll_obs_sub_pred);
    EXPECT_EQ(packet1.pitch_obs_sub_pred, packet2.pitch_obs_sub_pred);
    EXPECT_EQ(packet1.yaw_obs_sub_pred, packet2.yaw_obs_sub_pred);
    EXPECT_EQ(packet1.gyro_x_noise, packet2.gyro_x_noise);
    EXPECT_EQ(packet1.gyro_y_noise, packet2.gyro_y_noise);
    EXPECT_EQ(packet1.gyro_z_noise, packet2.gyro_z_noise);
    EXPECT_EQ(packet1.acc_x_noise, packet2.acc_x_noise);
    EXPECT_EQ(packet1.acc_y_noise, packet2.acc_y_noise);
    EXPECT_EQ(packet1.acc_z_noise, packet2.acc_z_noise);
    EXPECT_EQ(packet1.mag_x_noise, packet2.mag_x_noise);
    EXPECT_EQ(packet1.mag_y_noise, packet2.mag_y_noise);
    EXPECT_EQ(packet1.mag_z_noise, packet2.mag_z_noise);
    EXPECT_EQ(packet1.static_flag, packet2.static_flag);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, ATTITUDE_BODY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_attitude_body_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 577.0, 605.0, 633.0, 25
    };

    mavlink::fppa::msg::ATTITUDE_BODY packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.roll_speed = 157.0;
    packet_in.pitch_speed = 185.0;
    packet_in.yaw_speed = 213.0;
    packet_in.roll_observed = 241.0;
    packet_in.pitch_observed = 269.0;
    packet_in.yaw_observed = 297.0;
    packet_in.roll_obs_sub_pred = 325.0;
    packet_in.pitch_obs_sub_pred = 353.0;
    packet_in.yaw_obs_sub_pred = 381.0;
    packet_in.gyro_x_noise = 409.0;
    packet_in.gyro_y_noise = 437.0;
    packet_in.gyro_z_noise = 465.0;
    packet_in.acc_x_noise = 493.0;
    packet_in.acc_y_noise = 521.0;
    packet_in.acc_z_noise = 549.0;
    packet_in.mag_x_noise = 577.0;
    packet_in.mag_y_noise = 605.0;
    packet_in.mag_z_noise = 633.0;
    packet_in.static_flag = 25;

    mavlink::fppa::msg::ATTITUDE_BODY packet2{};

    mavlink_msg_attitude_body_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.roll_speed, packet2.roll_speed);
    EXPECT_EQ(packet_in.pitch_speed, packet2.pitch_speed);
    EXPECT_EQ(packet_in.yaw_speed, packet2.yaw_speed);
    EXPECT_EQ(packet_in.roll_observed, packet2.roll_observed);
    EXPECT_EQ(packet_in.pitch_observed, packet2.pitch_observed);
    EXPECT_EQ(packet_in.yaw_observed, packet2.yaw_observed);
    EXPECT_EQ(packet_in.roll_obs_sub_pred, packet2.roll_obs_sub_pred);
    EXPECT_EQ(packet_in.pitch_obs_sub_pred, packet2.pitch_obs_sub_pred);
    EXPECT_EQ(packet_in.yaw_obs_sub_pred, packet2.yaw_obs_sub_pred);
    EXPECT_EQ(packet_in.gyro_x_noise, packet2.gyro_x_noise);
    EXPECT_EQ(packet_in.gyro_y_noise, packet2.gyro_y_noise);
    EXPECT_EQ(packet_in.gyro_z_noise, packet2.gyro_z_noise);
    EXPECT_EQ(packet_in.acc_x_noise, packet2.acc_x_noise);
    EXPECT_EQ(packet_in.acc_y_noise, packet2.acc_y_noise);
    EXPECT_EQ(packet_in.acc_z_noise, packet2.acc_z_noise);
    EXPECT_EQ(packet_in.mag_x_noise, packet2.mag_x_noise);
    EXPECT_EQ(packet_in.mag_y_noise, packet2.mag_y_noise);
    EXPECT_EQ(packet_in.mag_z_noise, packet2.mag_z_noise);
    EXPECT_EQ(packet_in.static_flag, packet2.static_flag);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, ATTITUDE_BEAM_TARGET)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::ATTITUDE_BEAM_TARGET packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.q = {{ 73.0, 74.0, 75.0, 76.0 }};
    packet_in.roll = 185.0;
    packet_in.pitch = 213.0;
    packet_in.yaw = 241.0;

    mavlink::fppa::msg::ATTITUDE_BEAM_TARGET packet1{};
    mavlink::fppa::msg::ATTITUDE_BEAM_TARGET packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.q, packet2.q);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, ATTITUDE_BEAM_TARGET)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_attitude_beam_target_t packet_c {
         93372036854775807ULL, { 73.0, 74.0, 75.0, 76.0 }, 185.0, 213.0, 241.0
    };

    mavlink::fppa::msg::ATTITUDE_BEAM_TARGET packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.q = {{ 73.0, 74.0, 75.0, 76.0 }};
    packet_in.roll = 185.0;
    packet_in.pitch = 213.0;
    packet_in.yaw = 241.0;

    mavlink::fppa::msg::ATTITUDE_BEAM_TARGET packet2{};

    mavlink_msg_attitude_beam_target_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.q, packet2.q);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(fppa, ATTITUDE_BEAM)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::ATTITUDE_BEAM packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.altitude = 157.0;
    packet_in.q = {{ 185.0, 186.0, 187.0, 188.0 }};

    mavlink::fppa::msg::ATTITUDE_BEAM packet1{};
    mavlink::fppa::msg::ATTITUDE_BEAM packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.altitude, packet2.altitude);
    EXPECT_EQ(packet1.q, packet2.q);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, ATTITUDE_BEAM)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_attitude_beam_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, { 185.0, 186.0, 187.0, 188.0 }
    };

    mavlink::fppa::msg::ATTITUDE_BEAM packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.roll = 73.0;
    packet_in.pitch = 101.0;
    packet_in.yaw = 129.0;
    packet_in.altitude = 157.0;
    packet_in.q = {{ 185.0, 186.0, 187.0, 188.0 }};

    mavlink::fppa::msg::ATTITUDE_BEAM packet2{};

    mavlink_msg_attitude_beam_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.altitude, packet2.altitude);
    EXPECT_EQ(packet_in.q, packet2.q);

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
    packet_in.xacc = 73.0;
    packet_in.yacc = 101.0;
    packet_in.zacc = 129.0;
    packet_in.xgyro = 157.0;
    packet_in.ygyro = 185.0;
    packet_in.zgyro = 213.0;
    packet_in.xmag = 241.0;
    packet_in.ymag = 269.0;
    packet_in.zmag = 297.0;
    packet_in.x_delta_v = 325.0;
    packet_in.y_delta_v = 353.0;
    packet_in.z_delta_v = 381.0;
    packet_in.x_angle = 409.0;
    packet_in.y_angle = 437.0;
    packet_in.z_angle = 465.0;

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
    EXPECT_EQ(packet1.x_delta_v, packet2.x_delta_v);
    EXPECT_EQ(packet1.y_delta_v, packet2.y_delta_v);
    EXPECT_EQ(packet1.z_delta_v, packet2.z_delta_v);
    EXPECT_EQ(packet1.x_angle, packet2.x_angle);
    EXPECT_EQ(packet1.y_angle, packet2.y_angle);
    EXPECT_EQ(packet1.z_angle, packet2.z_angle);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, RAW_IMU)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_raw_imu_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0
    };

    mavlink::fppa::msg::RAW_IMU packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.xacc = 73.0;
    packet_in.yacc = 101.0;
    packet_in.zacc = 129.0;
    packet_in.xgyro = 157.0;
    packet_in.ygyro = 185.0;
    packet_in.zgyro = 213.0;
    packet_in.xmag = 241.0;
    packet_in.ymag = 269.0;
    packet_in.zmag = 297.0;
    packet_in.x_delta_v = 325.0;
    packet_in.y_delta_v = 353.0;
    packet_in.z_delta_v = 381.0;
    packet_in.x_angle = 409.0;
    packet_in.y_angle = 437.0;
    packet_in.z_angle = 465.0;

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
    EXPECT_EQ(packet_in.x_delta_v, packet2.x_delta_v);
    EXPECT_EQ(packet_in.y_delta_v, packet2.y_delta_v);
    EXPECT_EQ(packet_in.z_delta_v, packet2.z_delta_v);
    EXPECT_EQ(packet_in.x_angle, packet2.x_angle);
    EXPECT_EQ(packet_in.y_angle, packet2.y_angle);
    EXPECT_EQ(packet_in.z_angle, packet2.z_angle);

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
    packet_in.fix_type = 113;
    packet_in.longitude = 17.0;
    packet_in.latitude = 45.0;
    packet_in.azimuth = 73.0;
    packet_in.height = 101.0;
    packet_in.speed = 129.0;
    packet_in.course = 157.0;
    packet_in.pdop = 185.0;
    packet_in.hdop = 213.0;
    packet_in.vdop = 241.0;
    packet_in.satellite_nums = 180;
    packet_in.year = 247;
    packet_in.month = 58;
    packet_in.day = 125;
    packet_in.hour = 192;
    packet_in.minute = 3;
    packet_in.second = 70;

    mavlink::fppa::msg::RTK_GPS packet1{};
    mavlink::fppa::msg::RTK_GPS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.fix_type, packet2.fix_type);
    EXPECT_EQ(packet1.longitude, packet2.longitude);
    EXPECT_EQ(packet1.latitude, packet2.latitude);
    EXPECT_EQ(packet1.azimuth, packet2.azimuth);
    EXPECT_EQ(packet1.height, packet2.height);
    EXPECT_EQ(packet1.speed, packet2.speed);
    EXPECT_EQ(packet1.course, packet2.course);
    EXPECT_EQ(packet1.pdop, packet2.pdop);
    EXPECT_EQ(packet1.hdop, packet2.hdop);
    EXPECT_EQ(packet1.vdop, packet2.vdop);
    EXPECT_EQ(packet1.satellite_nums, packet2.satellite_nums);
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
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 113, 180, 247, 58, 125, 192, 3, 70
    };

    mavlink::fppa::msg::RTK_GPS packet_in{};
    packet_in.fix_type = 113;
    packet_in.longitude = 17.0;
    packet_in.latitude = 45.0;
    packet_in.azimuth = 73.0;
    packet_in.height = 101.0;
    packet_in.speed = 129.0;
    packet_in.course = 157.0;
    packet_in.pdop = 185.0;
    packet_in.hdop = 213.0;
    packet_in.vdop = 241.0;
    packet_in.satellite_nums = 180;
    packet_in.year = 247;
    packet_in.month = 58;
    packet_in.day = 125;
    packet_in.hour = 192;
    packet_in.minute = 3;
    packet_in.second = 70;

    mavlink::fppa::msg::RTK_GPS packet2{};

    mavlink_msg_rtk_gps_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.fix_type, packet2.fix_type);
    EXPECT_EQ(packet_in.longitude, packet2.longitude);
    EXPECT_EQ(packet_in.latitude, packet2.latitude);
    EXPECT_EQ(packet_in.azimuth, packet2.azimuth);
    EXPECT_EQ(packet_in.height, packet2.height);
    EXPECT_EQ(packet_in.speed, packet2.speed);
    EXPECT_EQ(packet_in.course, packet2.course);
    EXPECT_EQ(packet_in.pdop, packet2.pdop);
    EXPECT_EQ(packet_in.hdop, packet2.hdop);
    EXPECT_EQ(packet_in.vdop, packet2.vdop);
    EXPECT_EQ(packet_in.satellite_nums, packet2.satellite_nums);
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

TEST(fppa, HUMITURE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::fppa::msg::HUMITURE packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.tempreture = 73.0;
    packet_in.humidity = 101.0;

    mavlink::fppa::msg::HUMITURE packet1{};
    mavlink::fppa::msg::HUMITURE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.tempreture, packet2.tempreture);
    EXPECT_EQ(packet1.humidity, packet2.humidity);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, HUMITURE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_humiture_t packet_c {
         93372036854775807ULL, 73.0, 101.0
    };

    mavlink::fppa::msg::HUMITURE packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.tempreture = 73.0;
    packet_in.humidity = 101.0;

    mavlink::fppa::msg::HUMITURE packet2{};

    mavlink_msg_humiture_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.tempreture, packet2.tempreture);
    EXPECT_EQ(packet_in.humidity, packet2.humidity);

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
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.frequency = 73.0;
    packet_in.power = 101.0;
    packet_in.LNB_voltage = 129.0;
    packet_in.isLock = 65;
    packet_in.isValid = 132;

    mavlink::fppa::msg::BEACON_POWER packet1{};
    mavlink::fppa::msg::BEACON_POWER packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.frequency, packet2.frequency);
    EXPECT_EQ(packet1.power, packet2.power);
    EXPECT_EQ(packet1.LNB_voltage, packet2.LNB_voltage);
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
         93372036854775807ULL, 73.0, 101.0, 129.0, 65, 132
    };

    mavlink::fppa::msg::BEACON_POWER packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.frequency = 73.0;
    packet_in.power = 101.0;
    packet_in.LNB_voltage = 129.0;
    packet_in.isLock = 65;
    packet_in.isValid = 132;

    mavlink::fppa::msg::BEACON_POWER packet2{};

    mavlink_msg_beacon_power_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.frequency, packet2.frequency);
    EXPECT_EQ(packet_in.power, packet2.power);
    EXPECT_EQ(packet_in.LNB_voltage, packet2.LNB_voltage);
    EXPECT_EQ(packet_in.isLock, packet2.isLock);
    EXPECT_EQ(packet_in.isValid, packet2.isValid);

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
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.roll_desired = 73.0;
    packet_in.roll_achieved = 101.0;
    packet_in.roll_FF = 129.0;
    packet_in.roll_P = 157.0;
    packet_in.roll_I = 185.0;
    packet_in.roll_D = 213.0;
    packet_in.pitch_desired = 241.0;
    packet_in.pitch_achieved = 269.0;
    packet_in.pitchl_FF = 297.0;
    packet_in.pitch_P = 325.0;
    packet_in.pitch_I = 353.0;
    packet_in.pitch_D = 381.0;
    packet_in.yaw_desired = 409.0;
    packet_in.yaw_achieved = 437.0;
    packet_in.yaw_FF = 465.0;
    packet_in.yaw_P = 493.0;
    packet_in.yaw_I = 521.0;
    packet_in.yaw_D = 549.0;

    mavlink::fppa::msg::PID_TUNING packet1{};
    mavlink::fppa::msg::PID_TUNING packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.roll_desired, packet2.roll_desired);
    EXPECT_EQ(packet1.roll_achieved, packet2.roll_achieved);
    EXPECT_EQ(packet1.roll_FF, packet2.roll_FF);
    EXPECT_EQ(packet1.roll_P, packet2.roll_P);
    EXPECT_EQ(packet1.roll_I, packet2.roll_I);
    EXPECT_EQ(packet1.roll_D, packet2.roll_D);
    EXPECT_EQ(packet1.pitch_desired, packet2.pitch_desired);
    EXPECT_EQ(packet1.pitch_achieved, packet2.pitch_achieved);
    EXPECT_EQ(packet1.pitchl_FF, packet2.pitchl_FF);
    EXPECT_EQ(packet1.pitch_P, packet2.pitch_P);
    EXPECT_EQ(packet1.pitch_I, packet2.pitch_I);
    EXPECT_EQ(packet1.pitch_D, packet2.pitch_D);
    EXPECT_EQ(packet1.yaw_desired, packet2.yaw_desired);
    EXPECT_EQ(packet1.yaw_achieved, packet2.yaw_achieved);
    EXPECT_EQ(packet1.yaw_FF, packet2.yaw_FF);
    EXPECT_EQ(packet1.yaw_P, packet2.yaw_P);
    EXPECT_EQ(packet1.yaw_I, packet2.yaw_I);
    EXPECT_EQ(packet1.yaw_D, packet2.yaw_D);
}

#ifdef TEST_INTEROP
TEST(fppa_interop, PID_TUNING)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_pid_tuning_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0
    };

    mavlink::fppa::msg::PID_TUNING packet_in{};
    packet_in.time_boot_ms = 93372036854775807ULL;
    packet_in.roll_desired = 73.0;
    packet_in.roll_achieved = 101.0;
    packet_in.roll_FF = 129.0;
    packet_in.roll_P = 157.0;
    packet_in.roll_I = 185.0;
    packet_in.roll_D = 213.0;
    packet_in.pitch_desired = 241.0;
    packet_in.pitch_achieved = 269.0;
    packet_in.pitchl_FF = 297.0;
    packet_in.pitch_P = 325.0;
    packet_in.pitch_I = 353.0;
    packet_in.pitch_D = 381.0;
    packet_in.yaw_desired = 409.0;
    packet_in.yaw_achieved = 437.0;
    packet_in.yaw_FF = 465.0;
    packet_in.yaw_P = 493.0;
    packet_in.yaw_I = 521.0;
    packet_in.yaw_D = 549.0;

    mavlink::fppa::msg::PID_TUNING packet2{};

    mavlink_msg_pid_tuning_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.roll_desired, packet2.roll_desired);
    EXPECT_EQ(packet_in.roll_achieved, packet2.roll_achieved);
    EXPECT_EQ(packet_in.roll_FF, packet2.roll_FF);
    EXPECT_EQ(packet_in.roll_P, packet2.roll_P);
    EXPECT_EQ(packet_in.roll_I, packet2.roll_I);
    EXPECT_EQ(packet_in.roll_D, packet2.roll_D);
    EXPECT_EQ(packet_in.pitch_desired, packet2.pitch_desired);
    EXPECT_EQ(packet_in.pitch_achieved, packet2.pitch_achieved);
    EXPECT_EQ(packet_in.pitchl_FF, packet2.pitchl_FF);
    EXPECT_EQ(packet_in.pitch_P, packet2.pitch_P);
    EXPECT_EQ(packet_in.pitch_I, packet2.pitch_I);
    EXPECT_EQ(packet_in.pitch_D, packet2.pitch_D);
    EXPECT_EQ(packet_in.yaw_desired, packet2.yaw_desired);
    EXPECT_EQ(packet_in.yaw_achieved, packet2.yaw_achieved);
    EXPECT_EQ(packet_in.yaw_FF, packet2.yaw_FF);
    EXPECT_EQ(packet_in.yaw_P, packet2.yaw_P);
    EXPECT_EQ(packet_in.yaw_I, packet2.yaw_I);
    EXPECT_EQ(packet_in.yaw_D, packet2.yaw_D);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
