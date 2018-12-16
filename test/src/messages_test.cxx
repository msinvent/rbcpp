//
// Created by Julian on 15.09.18.
//
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <test/message_test.h>

test::CSVReader reader("../../test/test_messages.csv", ";");
test::DataFrame dataframe(reader);

test::HeaderTest header_test(dataframe);
test::StringTest string_test(dataframe);
test::Float32Test float32_test(dataframe);
test::Float64Test float64_test(dataframe);
test::Int8Test int8_test(dataframe);
test::Int16Test int16_test(dataframe);
test::Int32Test int32_test(dataframe);
test::Int64Test int64_test(dataframe);
test::UInt8Test uint8_test(dataframe);
test::UInt16Test uint16_test(dataframe);
test::UInt32Test uint32_test(dataframe);
test::UInt64Test uint64_test(dataframe);
test::ColorRGBATest color_rgba_test(dataframe);

test::PointTest point_test(dataframe);
test::PoseTest pose_test(dataframe);
test::AccelTest accel_test(dataframe);
test::Point32Test point32_test(dataframe);
test::Vector3Test vector3_test(dataframe);
test::WrenchTest wrench_test(dataframe);
test::InertiaTest inertia_test(dataframe);
test::PolygonTest polygon_test(dataframe);
test::PolygonStampedTest polygon_stamped_test(dataframe);
test::TransformTest transform_test(dataframe);
test::Pose2DTest pose2d_test(dataframe);
test::PoseArrayTest pose_array_test(dataframe);
test::PoseWithCovarianceTest pose_with_cov_test(dataframe);
test::PoseWithCovarianceStampedTest pose_with_cov_stamp_test(dataframe);
test::PoseStampedTest pose_stamped_test(dataframe);
test::PointStampedTest point_stamped_test(dataframe);
test::AccelStampedTest accel_stamped_test(dataframe);
test::WrenchStampedTest wrench_stamped_test(dataframe);
test::InertiaStampedTest inertia_stamped_test(dataframe);
test::TransformStampedTest transform_stamped_test(dataframe);
test::TwistWithCovTest twist_with_cov_test(dataframe);
test::AccelWithCovarianceTest accel_with_cov_test(dataframe);
test::AccelWithCovarianceStampedTest accel_with_cov_stamped_test(dataframe);
test::TwistWithCovarianceStampedTest twist_cov_stamp_test(dataframe);
test::QuaternionTest quaternion_test(dataframe);
test::QuaternionStampedTest quaternion_stamped_test(dataframe);
test::Vector3StampedTest vector3_stamped_test(dataframe);
test::TwistTest twist_test(dataframe);
test::TwistStampedTest twist_stamped_test(dataframe);

test::OdometryTest odometry_test(dataframe);

test::ImuTest imu_test(dataframe);

TEST_CASE("Header test", "[header]")
{
  REQUIRE(header_test.getMessage() == header_test.test1);
  REQUIRE(header_test.getMessage("test_frame") == header_test.test2);
}

TEST_CASE("String test", "[string_messages]")
{
  REQUIRE(string_test.getMessage("A Test") == string_test.test1);
  REQUIRE(string_test.getMessage("Test 2") == string_test.test2);
}
//
//TEST_CASE("Service Messages test", "[service_messages]")
//{
//  REQUIRE(service_messages.getMessage() == service_messages.test1);
//  REQUIRE(service_messages.getMessage({"this", "is", "a", "test"}) == service_messages.test2);
//}

TEST_CASE("Float32 test", "[float32_test]")
{
  REQUIRE(float32_test.getMessage(2.) == float32_test.test1);
  REQUIRE(float32_test.getMessage(2.5f) == float32_test.test2);
}

TEST_CASE("Float64 test", "[float64_test]")
{
  REQUIRE(float64_test.getMessage(1.f) == float64_test.test1);
  REQUIRE(float64_test.getMessage(1.5) == float64_test.test2);
}

TEST_CASE("Int8 test", "[int8_test]")
{
  REQUIRE(int8_test.getMessage(-1) == int8_test.test1);
  REQUIRE(int8_test.getMessage(2) == int8_test.test2);
}

TEST_CASE("Int16 test", "[int16_test]")
{
  REQUIRE(int16_test.getMessage(-1) == int16_test.test1);
  REQUIRE(int16_test.getMessage(2) == int16_test.test2);
}

TEST_CASE("Int32 test", "[int32_test]")
{
  REQUIRE(int32_test.getMessage(-1) == int32_test.test1);
  REQUIRE(int32_test.getMessage(2) == int32_test.test2);
}

TEST_CASE("Int64 test", "[int64_test]")
{
  REQUIRE(int64_test.getMessage(-1) == int64_test.test1);
  REQUIRE(int64_test.getMessage(2) == int64_test.test2);
}

TEST_CASE("UInt8 Messages test", "[uint8_test]")
{
  REQUIRE(uint8_test.getMessage(1) == uint8_test.test1);
  REQUIRE(uint8_test.getMessage(2) == uint8_test.test2);
}

TEST_CASE("UInt16 test", "[uint16_test]")
{
  REQUIRE(uint16_test.getMessage(1) == uint16_test.test1);
  REQUIRE(uint16_test.getMessage(2) == uint16_test.test2);
}

TEST_CASE("UInt32 Messages test", "[uint32_test]")
{
  REQUIRE(uint32_test.getMessage(1) == uint32_test.test1);
  REQUIRE(uint32_test.getMessage(2) == uint32_test.test2);
}

TEST_CASE("UInt64 Messages test", "[uint64_test]")
{
  REQUIRE(uint64_test.getMessage(1) == uint64_test.test1);
  REQUIRE(uint64_test.getMessage(2) == uint64_test.test2);
}

TEST_CASE("Color RGBA Messages test", "[color_rgba_test]")
{
  REQUIRE(color_rgba_test.getMessage(.1, .2, .9, .0) == color_rgba_test.test1);
  REQUIRE(color_rgba_test.getMessage(.2, .2, .7, .1) == color_rgba_test.test2);
}

TEST_CASE("Point Test", "[point_test]")
{
  REQUIRE(point_test.getMessage(0.1, 0.2, 0.3) == point_test.test1);
  REQUIRE(point_test.getMessage(0.2, 0.2, 0.3) == point_test.test2);
}

TEST_CASE("Point 2D Test", "[pose2d_test]")
{
  REQUIRE(pose2d_test.getMessage(0.1, 0.2, 0.3) == pose2d_test.test1);
  REQUIRE(pose2d_test.getMessage(0.2, 0.2, 0.3) == pose2d_test.test2);
}

TEST_CASE("Point32 test", "[point32_test]")
{
  REQUIRE(point32_test.getMessage(0.1, 0.2, 0.3) == point32_test.test1);
  REQUIRE(point32_test.getMessage(0.2, 0.2, 0.3) == point32_test.test2);
}

TEST_CASE("PointStamped Test", "[point_stamped_test]")
{
  REQUIRE(point_stamped_test.getMessage(0.1, 0.2, 0.3) == point_stamped_test.test1);
  REQUIRE(point_stamped_test.getMessage(0.1, 0.50, 0.3, "a_frame") == point_stamped_test.test2);
}

TEST_CASE("Vector3 Test", "[vector3_test]")
{
  REQUIRE(vector3_test.getMessage(0.1, 0.2, 0.3) == vector3_test.test1);
  REQUIRE(vector3_test.getMessage(0.2, 0.2, 0.3) == vector3_test.test2);
}

TEST_CASE("Vector3Stamped test", "[vector3_stamped_test]")
{
  REQUIRE(vector3_stamped_test.getMessage(0.1, 0.2, 0.3) == vector3_stamped_test.test1);
  REQUIRE(vector3_stamped_test.getMessage(0.1, 0.2, 0.3, "a_test") == vector3_stamped_test.test2);
}


TEST_CASE("Quaternion test", "[quaternion_test]")
{
  REQUIRE(quaternion_test.getMessage(0.10, 0.20, 0.3, 0.4) == quaternion_test.test1);
  REQUIRE(quaternion_test.getMessage(0.2, 0.2, 0.3, 0.5) == quaternion_test.test2);
}

TEST_CASE("QuaternionStamped test", "[quaternion_stamped_test]")
{
  REQUIRE(quaternion_stamped_test.getMessage(0.10, 0.20, 0.3, 0.4) == quaternion_stamped_test.test1);
  REQUIRE(quaternion_stamped_test.getMessage(0.19, 0.27, 0.3, 0.4, "test_frame") == quaternion_stamped_test.test2);
}


TEST_CASE("Pose test", "[pose_test]")
{
  {
    REQUIRE(pose_test.getMessage(0.1, 0.2, 0.3, 0.1, 0., 0., 1.0) == pose_test.test1);

    geometry_msgs::Point p;
    p.x = 0.1;
    p.y = 0.2;
    p.z = 0.3;
    geometry_msgs::Quaternion q;
    q.x = 0.1;
    q.y = 0.;
    q.z = 0.;
    q.w = 1.0;
    REQUIRE(pose_test.getMessage(p, q) == pose_test.test1);
  }
  {
    REQUIRE(pose_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 0., 1.0) == pose_test.test2);

    geometry_msgs::Point p;
    p.x = 0.1;
    p.y = 0.5;
    p.z = 0.3;
    geometry_msgs::Quaternion q;
    q.x = 0.1;
    q.y = 0.9;
    q.z = 0.;
    q.w = 1.0;
    REQUIRE(pose_test.getMessage(p, q) == pose_test.test2);
  }
}

TEST_CASE("PoseArray test", "[pose_array_test]")
{
  REQUIRE(pose_array_test.getMessage() == pose_array_test.test1);
  REQUIRE(pose_array_test.getMessage("test_frame") == pose_array_test.test2);
}

TEST_CASE("Pose With Covariance test", "[pose_with_cov_test]")
{
  std::array<double, 36> covariance( {.1, .2, 3., .4, .5, .6,
                                      .7, .8, .9, 1., 1.1, 1.2,
                                      1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                      1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                      2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                      3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
  {
    REQUIRE(pose_with_cov_test.getMessage(0.1, 0.2, 0.3, 0.1, 0., 0., 1.0, covariance) == pose_with_cov_test.test1);

    geometry_msgs::Point p;
    p.x = 0.1;
    p.y = 0.2;
    p.z = 0.3;
    geometry_msgs::Quaternion q;
    q.x = 0.1;
    q.y = 0.;
    q.z = 0.;
    q.w = 1.0;
    REQUIRE(pose_with_cov_test.getMessage(p, q, covariance) == pose_with_cov_test.test1);
    
    geometry_msgs::Pose pose(p, q);
    REQUIRE(pose_with_cov_test.getMessage(pose, covariance) == pose_with_cov_test.test1);
  }
  {
    REQUIRE(pose_with_cov_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 0., 1.0, covariance) == pose_with_cov_test.test2);

    geometry_msgs::Point p;
    p.x = 0.1;
    p.y = 0.5;
    p.z = 0.3;
    geometry_msgs::Quaternion q;
    q.x = 0.1;
    q.y = 0.9;
    q.z = 0.;
    q.w = 1.0;
    REQUIRE(pose_with_cov_test.getMessage(p, q, covariance) == pose_with_cov_test.test2);

    geometry_msgs::Pose pose(p, q);
    REQUIRE(pose_with_cov_test.getMessage(pose, covariance) == pose_with_cov_test.test2);
  }
}

TEST_CASE("Pose With Covariance Stamped test", "[pose_with_cov_test]")
{
  std::array<double, 36> covariance( {.1, .2, 3., .4, .5, .6,
                                      .7, .8, .9, 1., 1.1, 1.2,
                                      1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                      1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                      2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                      3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
  {
    geometry_msgs::Point p;
    p.x = 0.1;
    p.y = 0.2;
    p.z = 0.3;
    geometry_msgs::Quaternion q;
    q.x = 0.1;
    q.y = 0.;
    q.z = 0.;
    q.w = 1.0;
    REQUIRE(pose_with_cov_stamp_test.getMessage(p, q, covariance, "a frame") == pose_with_cov_stamp_test.test1);

    geometry_msgs::Pose pose(p, q);
    REQUIRE(pose_with_cov_stamp_test.getMessage(pose, covariance, "a frame") == pose_with_cov_stamp_test.test1);
  }
  {
    geometry_msgs::Point p;
    p.x = 0.1;
    p.y = 0.5;
    p.z = 0.3;
    geometry_msgs::Quaternion q;
    q.x = 0.1;
    q.y = 0.9;
    q.z = 0.;
    q.w = 1.0;
    REQUIRE(pose_with_cov_stamp_test.getMessage(p, q, covariance) == pose_with_cov_stamp_test.test2);

    geometry_msgs::Pose pose(p, q);
    REQUIRE(pose_with_cov_stamp_test.getMessage(pose, covariance) == pose_with_cov_stamp_test.test2);
  }
}

TEST_CASE("Pose Stamped test", "[pose_stamped_test]")
{
  {
    REQUIRE(pose_stamped_test.getMessage(0.1, 0.2, 0.3, 0.1, 0., 0., 1.0) == pose_stamped_test.test1);

    geometry_msgs::Pose p;
    p.point.x = 0.1;
    p.point.y = 0.2;
    p.point.z = 0.3;
    p.orientation.x = 0.1;
    p.orientation.y = 0.;
    p.orientation.z = 0.;
    p.orientation.w = 1.0;
    REQUIRE(pose_stamped_test.getMessage(p) == pose_stamped_test.test1);
  }
  {
    REQUIRE(pose_stamped_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 0., 1.0, "a_frame") == pose_stamped_test.test2);

    geometry_msgs::Pose p;
    p.point.x = 0.1;
    p.point.y = 0.5;
    p.point.z = 0.3;
    p.orientation.x = 0.1;
    p.orientation.y = 0.9;
    p.orientation.z = 0.;
    p.orientation.w = 1.0;
    REQUIRE(pose_stamped_test.getMessage(p, "a_frame") == pose_stamped_test.test2);
  }
}

TEST_CASE("Accel test", "[accel_test]")
{
  {
    REQUIRE(accel_test.getMessage(0.1, 0.2, 0.3, 0.1, 0.2, 0.3) == accel_test.test1);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.2;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.2;
    angular.z = 0.3;
    REQUIRE(accel_test.getMessage(linear, angular) == accel_test.test1);
  }
  {
    REQUIRE(accel_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 1.0) == accel_test.test2);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.5;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.9;
    angular.z = 1.0;
    REQUIRE(accel_test.getMessage(linear, angular) == accel_test.test2);
  }
}

TEST_CASE("Accel With Covariance test", "[accel_with_covariance_test]")
{
  std::array<double, 36> covariance({.1, .2, 3., .4, .5, .6,
                                     .7, .8, .9, 1., 1.1, 1.2,
                                     1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                     1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                     2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                     3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
  {
    REQUIRE(accel_with_cov_test.getMessage(0.1, 0.2, 0.3, 0.1, 0.2, 0.3, covariance) == accel_with_cov_test.test1);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.2;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.2;
    angular.z = 0.3;
    REQUIRE(accel_with_cov_test.getMessage(linear, angular, covariance) == accel_with_cov_test.test1);
  }
  {
    REQUIRE(accel_with_cov_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 1.0, covariance) == accel_with_cov_test.test2);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.5;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.9;
    angular.z = 1.0;
    REQUIRE(accel_with_cov_test.getMessage(linear, angular, covariance) == accel_with_cov_test.test2);
  }
}

TEST_CASE("Accel With Covariance Stamped test", "[accel_with_covariance_stamped_test]")
{
  std::array<double, 36> covariance({.1, .2, 3., .4, .5, .6,
                                     .7, .8, .9, 1., 1.1, 1.2,
                                     1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                     1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                     2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                     3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
  {
    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.2;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.2;
    angular.z = 0.3;
    REQUIRE(accel_with_cov_stamped_test.getMessage(linear, angular, covariance, "a frame") == accel_with_cov_stamped_test.test1);

    geometry_msgs::Accel accell(linear, angular);
    REQUIRE(accel_with_cov_stamped_test.getMessage(accell, covariance, "a frame") == accel_with_cov_stamped_test.test1);
    
    geometry_msgs::AccelWithCovariance accel(linear, angular, covariance);
    REQUIRE(accel_with_cov_stamped_test.getMessage(accel, "a frame") == accel_with_cov_stamped_test.test1);
  }
  {
    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.5;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.9;
    angular.z = 1.0;
    REQUIRE(accel_with_cov_stamped_test.getMessage(linear, angular, covariance, "a frame") == accel_with_cov_stamped_test.test2);

    geometry_msgs::Accel accel(linear, angular);
    REQUIRE(accel_with_cov_stamped_test.getMessage(accel, covariance, "a frame") == accel_with_cov_stamped_test.test2);

    geometry_msgs::AccelWithCovariance accell(linear, angular, covariance);
    REQUIRE(accel_with_cov_stamped_test.getMessage(accell, "a frame") == accel_with_cov_stamped_test.test2);
  }
}

TEST_CASE("Accel Stamped test", "[accel_stamped_test]")
{
  {
    REQUIRE(accel_stamped_test.getMessage(0.10, 0.20, 0.30, 0.1, 0.2, 0.3) == accel_stamped_test.test1);

    geometry_msgs::Vector3 linear;
    linear.x = 0.10;
    linear.y = 0.20;
    linear.z = 0.30;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.2;
    angular.z = 0.3;
    REQUIRE(accel_stamped_test.getMessage(linear, angular) == accel_stamped_test.test1);
  }
  {
    REQUIRE(accel_stamped_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 1.0, "a_frame") == accel_stamped_test.test2);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.5;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.9;
    angular.z = 1.0;
    REQUIRE(accel_stamped_test.getMessage(linear, angular, "a_frame") == accel_stamped_test.test2);
  }
}

TEST_CASE("Twist test", "[twist_test]")
{
  {
    REQUIRE(twist_test.getMessage(0.1, 0.2, 0.3, 0.1, 0.2, 0.3) == twist_test.test1);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.2;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.2;
    angular.z = 0.3;
    REQUIRE(twist_test.getMessage(linear, angular) == twist_test.test1);
  }
  {
    REQUIRE(twist_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 1.0) == twist_test.test2);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.5;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.9;
    angular.z = 1.0;
    REQUIRE(twist_test.getMessage(linear, angular) == twist_test.test2);
  }
}

TEST_CASE("Twist Stamped test", "[twist_stamped_test]")
{
  {
    REQUIRE(twist_stamped_test.getMessage(0.10, 0.20, 0.30, 0.1, 0.2, 0.3) == twist_stamped_test.test1);

    geometry_msgs::Vector3 linear;
    linear.x = 0.10;
    linear.y = 0.20;
    linear.z = 0.30;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.2;
    angular.z = 0.3;
    REQUIRE(twist_stamped_test.getMessage(linear, angular) == twist_stamped_test.test1);

    geometry_msgs::Twist ts;
    ts.linear = linear;
    ts.angular = angular;
    REQUIRE(twist_stamped_test.getMessage(ts) == twist_stamped_test.test1);
  }
  {
    REQUIRE(twist_stamped_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 1.0, "a_frame") == twist_stamped_test.test2);

    geometry_msgs::Vector3 linear;
    linear.x = 0.1;
    linear.y = 0.5;
    linear.z = 0.3;
    geometry_msgs::Vector3 angular;
    angular.x = 0.1;
    angular.y = 0.9;
    angular.z = 1.0;
    REQUIRE(twist_stamped_test.getMessage(linear, angular, "a_frame") == twist_stamped_test.test2);

    geometry_msgs::Twist ts;
    ts.linear = linear;
    ts.angular = angular;
    REQUIRE(twist_stamped_test.getMessage(ts, "a_frame") == twist_stamped_test.test2);
  }
}

TEST_CASE("Twist With Covariance test", "[twist_with_covariance_test]")
{
  {
    geometry_msgs::Vector3 vec3(.1, .2, .3);
    geometry_msgs::Twist twist;
    twist.angular = vec3;
    twist.linear = vec3;
    std::array<double, 36> covariance({.1, .2, 3., .4, .5, .6,
                                       .7, .8, .9, 1., 1.1, 1.2,
                                       1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                       1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                       2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                       3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
    geometry_msgs::TwistWithCovariance twist_with_cov;
    twist_with_cov.twist = twist;
    twist_with_cov.covariance = covariance;

    REQUIRE(twist_with_cov_test.getMessage(twist_with_cov) == twist_with_cov_test.test1);
    REQUIRE(twist_with_cov_test.getMessage(twist, covariance) == twist_with_cov_test.test1);
    REQUIRE(twist_with_cov_test.getMessage(vec3, vec3, covariance) == twist_with_cov_test.test1);
  }
  {
    geometry_msgs::Vector3 vec3(.3, .2, .1);
    geometry_msgs::Twist twist;
    twist.angular = vec3;
    twist.linear = vec3;
    std::array<double, 36> covariance( {.1, .9, 3., .4, .5, .6,
                                        .7, .8, .9, 1., 1.1, 1.2,
                                        1.3, 1., 1.5, 1.6, 1., 1.8,
                                        1.9, 2., 2.1, .2, 2.3, 2.4,
                                        2.5, .6, 2.7, 2.8, .9, 3.,
                                        3.1, 3.2, 3.3, .4, 3.5, 3.6});
    geometry_msgs::TwistWithCovariance twist_with_cov;
    twist_with_cov.twist = twist;
    twist_with_cov.covariance = covariance;

    REQUIRE(twist_with_cov_test.getMessage(twist_with_cov) == twist_with_cov_test.test2);
    REQUIRE(twist_with_cov_test.getMessage(twist, covariance) == twist_with_cov_test.test2);
    REQUIRE(twist_with_cov_test.getMessage(vec3, vec3, covariance) == twist_with_cov_test.test2);
  }
}

TEST_CASE("Twist With Covariance Stamped test", "[twist_with_covariance_stamped_test]")
{
  {
    geometry_msgs::Vector3 vec3(.1, .2, .3);
    geometry_msgs::Twist twist;
    twist.angular = vec3;
    twist.linear = vec3;
    std::array<double, 36> covariance( {.1, .2, 3., .4, .5, .6,
                                        .7, .8, .9, 1., 1.1, 1.2,
                                        1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                        1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                        2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                        3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
    geometry_msgs::TwistWithCovariance twist_with_cov;
    twist_with_cov.twist = twist;
    twist_with_cov.covariance = covariance;

    REQUIRE(twist_cov_stamp_test.getMessage(twist_with_cov) == twist_cov_stamp_test.test1);
    REQUIRE(twist_cov_stamp_test.getMessage(twist, covariance) == twist_cov_stamp_test.test1);
    REQUIRE(twist_cov_stamp_test.getMessage(vec3, vec3, covariance) == twist_cov_stamp_test.test1);
  }
  {
    geometry_msgs::Vector3 vec3(.3, .2, .1);
    geometry_msgs::Twist twist;
    twist.angular = vec3;
    twist.linear = vec3;
    std::array<double, 36> covariance({.1, .9, 3., .4, .5, .6,
                                       .7, .8, .9, 1., 1.1, 1.2,
                                       1.3, 1., 1.5, 1.6, 1., 1.8,
                                       1.9, 2., 2.1, .2, 2.3, 2.4,
                                       2.5, .6, 2.7, 2.8, .9, 3.,
                                       3.1, 3.2, 3.3, .4, 3.5, 3.6});
    geometry_msgs::TwistWithCovariance twist_with_cov;
    twist_with_cov.twist = twist;
    twist_with_cov.covariance = covariance;

    REQUIRE(twist_cov_stamp_test.getMessage(twist_with_cov, "a_frame") == twist_cov_stamp_test.test2);
    REQUIRE(twist_cov_stamp_test.getMessage(twist, covariance, "a_frame") == twist_cov_stamp_test.test2);
    REQUIRE(twist_cov_stamp_test.getMessage(twist, covariance, "a_frame") == twist_cov_stamp_test.test2);
    REQUIRE(twist_cov_stamp_test.getMessage(vec3, vec3, covariance, "a_frame") == twist_cov_stamp_test.test2);
    REQUIRE(twist_cov_stamp_test.getMessage(vec3, vec3, covariance, "a_frame") == twist_cov_stamp_test.test2);
  }
}

//TEST_CASE("Gridcells Messages test", "[grid_cells_messages]")
//{
//  REQUIRE(grid_cell_messages.getMessage(.1, .2) == grid_cell_messages.test1);
//  REQUIRE(grid_cell_messages.getMessage(.1, .2, "a_frame") == grid_cell_messages.test2);
//}
//
TEST_CASE("Transform test", "[transform_test]")
{
  {
    geometry_msgs::Vector3 translation;
    translation.x = 0.10;
    translation.y = 0.20;
    translation.z = 0.30;
    geometry_msgs::Quaternion rotation;
    rotation.x = 0.1;
    rotation.y = 0.2;
    rotation.z = 0.3;
    rotation.w = 1.0;
    REQUIRE(transform_test.getMessage(translation, rotation) == transform_test.test1);

    REQUIRE(transform_test.getMessage(0.10, 0.20, 0.30, 0.1, 0.2, 0.3, 1.0) == transform_test.test1);
  }
  {
    geometry_msgs::Vector3 translation;
    translation.x = 0.1;
    translation.y = 0.5;
    translation.z = 0.3;
    geometry_msgs::Quaternion rotation;
    rotation.x = 0.1;
    rotation.y = 0.2;
    rotation.z = 0.3;
    rotation.w = 1.0;
    REQUIRE(transform_test.getMessage(translation, rotation) == transform_test.test2);

    REQUIRE(transform_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.2, 0.3, 1.0) == transform_test.test2);
  }
}

TEST_CASE("Transform Stamped test", "[transform_stamped_test]")
{
  {
    geometry_msgs::Vector3 translation;
    translation.x = 0.10;
    translation.y = 0.20;
    translation.z = 0.30;
    geometry_msgs::Quaternion rotation;
    rotation.x = 0.1;
    rotation.y = 0.2;
    rotation.z = 0.3;
    rotation.w = 1.0;
    REQUIRE(transform_stamped_test.getMessage(translation, rotation) == transform_stamped_test.test1);

    REQUIRE(transform_stamped_test.getMessage(0.10, 0.20, 0.30, 0.1, 0.2, 0.3, 1.0) == transform_stamped_test.test1);
  }
  {
    geometry_msgs::Vector3 translation;
    translation.x = 0.1;
    translation.y = 0.5;
    translation.z = 0.3;
    geometry_msgs::Quaternion rotation;
    rotation.x = 0.1;
    rotation.y = 0.2;
    rotation.z = 0.3;
    rotation.w = 1.0;
    REQUIRE(transform_stamped_test.getMessage(translation, rotation, "a_frame") == transform_stamped_test.test2);

    REQUIRE(transform_stamped_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.2, 0.3, 1.0, "a_frame") ==
            transform_stamped_test.test2);
  }
}

TEST_CASE("Wrench Messages test", "[wrench_test]")
{
  {
    geometry_msgs::Vector3 force;
    force.x = 0.10;
    force.y = 0.20;
    force.z = 0.30;
    geometry_msgs::Vector3 torque;
    torque.x = 0.1;
    torque.y = 0.5;
    torque.z = 0.3;
    REQUIRE(wrench_test.getMessage(force, torque) == wrench_test.test1);

    REQUIRE(wrench_test.getMessage(0.10, 0.20, 0.30, 0.1, 0.5, 0.3) == wrench_test.test1);
  }
  {
    geometry_msgs::Vector3 force;
    force.x = 0.1;
    force.y = 0.5;
    force.z = 0.3;
    geometry_msgs::Vector3 torque;
    torque.x = 0.10;
    torque.y = 0.20;
    torque.z = 0.80;
    REQUIRE(wrench_test.getMessage(force, torque) == wrench_test.test2);

    REQUIRE(wrench_test.getMessage(0.1, 0.5, 0.3, 0.10, 0.20, 0.80) == wrench_test.test2);
  }
}

TEST_CASE("Wrench Stamped test", "[wrench_stamped_test]")
{
  {
    geometry_msgs::Vector3 force;
    force.x = 0.10;
    force.y = 0.20;
    force.z = 0.30;
    geometry_msgs::Vector3 torque;
    torque.x = 0.1;
    torque.y = 0.5;
    torque.z = 0.3;
    REQUIRE(wrench_stamped_test.getMessage(force, torque) == wrench_stamped_test.test1);

    REQUIRE(wrench_stamped_test.getMessage(0.10, 0.20, 0.30, 0.1, 0.5, 0.3) == wrench_stamped_test.test1);
  }
  {
    geometry_msgs::Vector3 force;
    force.x = 0.1;
    force.y = 0.5;
    force.z = 0.3;
    geometry_msgs::Vector3 torque;
    torque.x = 0.10;
    torque.y = 0.20;
    torque.z = 0.80;
    REQUIRE(wrench_stamped_test.getMessage(force, torque, "a_frame") == wrench_stamped_test.test2);

    REQUIRE(wrench_stamped_test.getMessage(0.1, 0.5, 0.3, 0.10, 0.20, 0.80, "a_frame") == wrench_stamped_test.test2);
  }
}

TEST_CASE("Polygon test", "[polygon_test]")
{
  {
    geometry_msgs::Point32 point;
    point.x = 0.10;
    point.y = 0.20;
    point.z = 0.30;
    REQUIRE(polygon_test.getMessage(point) == polygon_test.test1);
    REQUIRE(polygon_test.getMessageWithAdd(point) == polygon_test.test1);
  }
  {
    geometry_msgs::Point32 point;
    point.x = 0.1;
    point.y = 0.5;
    point.z = 0.3;
    REQUIRE(polygon_test.getMessageWithAdd(point) == polygon_test.test2);
  }
}

TEST_CASE("Polygon Stamped test", "[polygon_stamped_test]")
{
  {
    geometry_msgs::Point32 point;
    point.x = 0.10;
    point.y = 0.20;
    point.z = 0.30;
    REQUIRE(polygon_stamped_test.getMessage(point) == polygon_stamped_test.test1);
    REQUIRE(polygon_stamped_test.getMessageWithAdd(point) == polygon_stamped_test.test1);
  }
  {
    geometry_msgs::Point32 point;
    point.x = 0.1;
    point.y = 0.5;
    point.z = 0.3;
    REQUIRE(polygon_stamped_test.getMessageWithAdd(point) == polygon_stamped_test.test2);
  }
}

TEST_CASE("Inertia test", "[inertia_test]")
{
  {
    geometry_msgs::Vector3 vec;
    vec.x = 0.10;
    vec.y = 0.20;
    vec.z = 0.30;
    REQUIRE(inertia_test.getMessage(.4, vec, .1, .2, .3, .4, .5, .6) == inertia_test.test1);

    geometry_msgs::Inertia inertia;
    inertia.m = .4;
    inertia.ixx = .1;
    inertia.ixy = .2;
    inertia.ixz = .3;
    inertia.iyy = .4;
    inertia.iyz = .5;
    inertia.izz = .6;
    inertia.com.x = vec.x;
    inertia.com.y = vec.y;
    inertia.com.z = vec.z;
    REQUIRE(inertia_test.getMessage(inertia) == inertia_test.test1);
  }
  {
    geometry_msgs::Vector3 vec;
    vec.x = 0.1;
    vec.y = 0.5;
    vec.z = 0.3;
    REQUIRE(inertia_test.getMessage(.4, vec, .6, .5, .4, 3., .2, .1) == inertia_test.test2);

    geometry_msgs::Inertia inertia;
    inertia.m = .4;
    inertia.ixx = .6;
    inertia.ixy = .5;
    inertia.ixz = .4;
    inertia.iyy = 3.;
    inertia.iyz = .2;
    inertia.izz = .1;
    inertia.com.x = vec.x;
    inertia.com.y = vec.y;
    inertia.com.z = vec.z;
    REQUIRE(inertia_test.getMessage(inertia) == inertia_test.test2);
  }
}

TEST_CASE("Inertia Stamped test", "[inertia_stamped_test]")
{
  {
    geometry_msgs::Vector3 vec;
    vec.x = 0.10;
    vec.y = 0.20;
    vec.z = 0.30;
    REQUIRE(inertia_stamped_test.getMessage(.4, vec, .1, .2, .3, .4, .5, .6) == inertia_stamped_test.test1);

    geometry_msgs::Inertia inertia;
    inertia.m = .4;
    inertia.ixx = .1;
    inertia.ixy = .2;
    inertia.ixz = .3;
    inertia.iyy = .4;
    inertia.iyz = .5;
    inertia.izz = .6;
    inertia.com.x = vec.x;
    inertia.com.y = vec.y;
    inertia.com.z = vec.z;
    REQUIRE(inertia_stamped_test.getMessage(inertia) == inertia_stamped_test.test1);
  }
  {
    geometry_msgs::Vector3 vec;
    vec.x = 0.1;
    vec.y = 0.5;
    vec.z = 0.3;
    REQUIRE(inertia_stamped_test.getMessage(.4, vec, .6, .5, .4, 3., .2, .1, "a_frame") == inertia_stamped_test.test2);

    geometry_msgs::Inertia inertia;
    inertia.m = .4;
    inertia.ixx = .6;
    inertia.ixy = .5;
    inertia.ixz = .4;
    inertia.iyy = 3.;
    inertia.iyz = .2;
    inertia.izz = .1;
    inertia.com.x = vec.x;
    inertia.com.y = vec.y;
    inertia.com.z = vec.z;
    REQUIRE(inertia_stamped_test.getMessage(inertia, "a_frame") == inertia_stamped_test.test2);
  }
}

TEST_CASE("Odometry test", "[odometry_test]")
{
  std::array<double, 36> covariance( {.1, .2, 3., .4, .5, .6,
                                      .7, .8, .9, 1., 1.1, 1.2,
                                      1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                      1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                      2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                      3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
  {
    nav_msgs::Odometry o;
    o.header.frame_id = "a frame";
    o.child_frame_id = "a child frame";
    REQUIRE(odometry_test.getMessage(o) == odometry_test.test1);
    REQUIRE(odometry_test.getMessage("a frame", "a child frame") == odometry_test.test1);
  }
  {
    nav_msgs::Odometry o;
    o.child_frame_id = "a child frame";
    o.header.frame_id = "a frame";
    o.pose.pose = geometry_msgs::Pose(.1, .2, .3, .1, .2, .3, .4);
    o.pose.covariance = covariance;
    o.twist.twist = geometry_msgs::Twist(geometry_msgs::Vector3(.1, .2, .3), geometry_msgs::Vector3(.4, .5, .6));
    o.twist.covariance = covariance;
    REQUIRE(odometry_test.getMessage(o) == odometry_test.test2);
  }
}

TEST_CASE("Imu test", "[imu_test]")
{
  std::array<float, 9> covariance({.1, .2, .3, .4, .5, .6, .7, .8, .9});

  {
    sensor_msgs::Imu imu;
    imu.orientation_covariance = covariance;
    imu.linear_acceleration_covariance = covariance;
    imu.angular_velocity_covariance = covariance;
    imu.orientation = geometry_msgs::Quaternion(.1, .2, .3, .4);
    imu.angular_velocity = geometry_msgs::Vector3(.1, .2, .3);
    imu.linear_acceleration = geometry_msgs::Vector3(.1, .2, .3);
    REQUIRE(imu_test.getMessage(imu) == imu_test.test1);
  }
  {
    sensor_msgs::Imu imu;
    imu.orientation = geometry_msgs::Quaternion(.1, .2, .3, .4);
    imu.angular_velocity = geometry_msgs::Vector3(.1, .2, .3);
    imu.linear_acceleration = geometry_msgs::Vector3(.1, .2, .3);
    REQUIRE(imu_test.getMessage(imu) == imu_test.test2);
  }
}
