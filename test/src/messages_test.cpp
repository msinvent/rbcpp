//
// Created by Julian on 15.09.18.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <test/message_test.h>

test::CSVReader             reader("../../test/test_messages.csv", ";");
test::DataFrame             dataframe(reader);
//test::StringMessage             string_messages(dataframe);
//test::ServiceMessage            service_messages(dataframe);
//test::Int8Message               int8_messages(dataframe);
//test::Int16Message              int16_messages(dataframe);
//test::Int32Message              int32_messages(dataframe);
//test::Int64Message              int64_messages(dataframe);
//test::UInt8Message              uint8_messages(dataframe);
//test::UInt16Message             uint16_messages(dataframe);
//test::UInt32Message             uint32_messages(dataframe);
//test::UInt64Message             uint64_messages(dataframe);
//test::ColorRGBAMessage          color_rgba_messages(dataframe);
test::PointTest             point_test(dataframe);
test::PoseTest              pose_test(dataframe);
test::AccelTest             accel_test(dataframe);
test::Point32Test           point32_test(dataframe);
test::Vector3Test           vector3_test(dataframe);
test::WrenchTest            wrench_test(dataframe);
test::InertiaTest           inertia_test(dataframe);
test::TransformTest         transform_test(dataframe);
//test::Point32Message            point32_messages(dataframe);
test::PoseStampedTest       pose_stamped_test(dataframe);
test::PointStampedTest      point_stamped_test(dataframe);
test::AccelStampedTest      accel_stamped_test(dataframe);
test::WrenchStampedTest     wrench_stamped_test(dataframe);
test::InertiaStampedTest    inertia_stamped_test(dataframe);
test::TransformStampedTest  transform_stamped_test(dataframe);
test::QuaternionTest        quaternion_test(dataframe);
test::QuaternionStampedTest quaternion_stamped_test(dataframe);
//test::Vector3Message            vector3_messages(dataframe);
test::Vector3StampedTest    vector3_stamped_test(dataframe);
test::HeaderTest            header_test(dataframe);
//test::PoseMessage               pose_messages(dataframe);
//test::Pose2DMessage             pose_2d_messages(dataframe);
//test::PoseStampedMessage        pose_stamped_messages(dataframe);
//test::AccelMessage              accel_messages(dataframe);
//test::AccelStampedMessage       accel_stamped_messages(dataframe);
//test::TwistMessage              twist_messages(dataframe);
//test::TwistStampedMessage       twist_stamped_messages(dataframe);
//test::GridCellsMessage          grid_cell_messages(dataframe);
//test::PoseArrayMessage          pose_array_messages(dataframe);
//test::TransformMessage          transform_test(dataframe);
//test::TransformStampedMessage   transform_stamped_messages(dataframe);
//test::WrenchMessage             wrench_test(dataframe);
//test::WrenchStampedMessage      wrench_stamped_test(dataframe);
//test::PolygonMessage            polygon_messages(dataframe);
//test::PolygonStampedMessage     polygon_stamped_messages(dataframe);
//test::InertiaMessage            inertia_messages(dataframe);
//test::InertiaStampedMessage     inertia_stamped_messages(dataframe);

TEST_CASE("Header Messages test", "[header_messages]")
{
  REQUIRE(header_test.getMessage() == header_test.test1);
  REQUIRE(header_test.getMessage("test_frame") == header_test.test2);
}
//
//TEST_CASE("String Messages test", "[string_messages]")
//{
//  REQUIRE(string_messages.getMessage("A Message") == string_messages.test1);
//  REQUIRE(string_messages.getMessage("Message 2") == string_messages.test2);
//}
//
//TEST_CASE("Service Messages test", "[service_messages]")
//{
//  REQUIRE(service_messages.getMessage() == service_messages.test1);
//  REQUIRE(service_messages.getMessage({"this", "is", "a", "test"}) == service_messages.test2);
//}
//
//TEST_CASE("Int8 Messages test", "[int8_messages]")
//{
//  REQUIRE(int8_messages.getMessage(-1) == int8_messages.test1);
//  REQUIRE(int8_messages.getMessage(2) == int8_messages.test2);
//}
//
//TEST_CASE("Int16 Messages test", "[uint16_messages]")
//{
//  REQUIRE(int16_messages.getMessage(-1) == int16_messages.test1);
//  REQUIRE(int16_messages.getMessage(2) == int16_messages.test2);
//}
//
//TEST_CASE("Int32 Messages test", "[int32_messages]")
//{
//  REQUIRE(int32_messages.getMessage(-1) == int32_messages.test1);
//  REQUIRE(int32_messages.getMessage(2) == int32_messages.test2);
//}
//
//TEST_CASE("Int64 Messages test", "[int64_messages]")
//{
//  REQUIRE(int64_messages.getMessage(-1) == int64_messages.test1);
//  REQUIRE(int64_messages.getMessage(2) == int64_messages.test2);
//}
//
//TEST_CASE("UInt8 Messages test", "[uint8_messages]")
//{
//  REQUIRE(uint8_messages.getMessage(1) == uint8_messages.test1);
//  REQUIRE(uint8_messages.getMessage(2) == uint8_messages.test2);
//}
//
//TEST_CASE("UInt16 Messages test", "[uint16_messages]")
//{
//  REQUIRE(uint16_messages.getMessage(1) == uint16_messages.test1);
//  REQUIRE(uint16_messages.getMessage(2) == uint16_messages.test2);
//}
//
//TEST_CASE("UInt32 Messages test", "[uint32_messages]")
//{
//  REQUIRE(uint32_messages.getMessage(1) == uint32_messages.test1);
//  REQUIRE(uint32_messages.getMessage(2) == uint32_messages.test2);
//}
//
//TEST_CASE("UInt64 Messages test", "[uint64_messages]")
//{
//  REQUIRE(uint64_messages.getMessage(1) == uint64_messages.test1);
//  REQUIRE(uint64_messages.getMessage(2) == uint64_messages.test2);
//}
//
//TEST_CASE("Color RGBA Messages test", "[color_rgba_messages]")
//{
//  {
//    REQUIRE(color_rgba_messages.getMessage(.1, .2, .9, .0) == color_rgba_messages.test1);
//
//    ColorRGBA c;
//    c.r = .1;
//    c.g = .2;
//    c.b = .9;
//    c.a = .0;
//    REQUIRE(color_rgba_messages.getMessage(c) == color_rgba_messages.test1);
//  }
//  {
//    REQUIRE(color_rgba_messages.getMessage(.2, .2, .7, .1) == color_rgba_messages.test2);
//
//    ColorRGBA c;
//    c.r = .2;
//    c.g = .2;
//    c.b = .7;
//    c.a = .1;
//    REQUIRE(color_rgba_messages.getMessage(c) == color_rgba_messages.test2);
//  }
//}
//
TEST_CASE("Point Test", "[point_test]")
{
  REQUIRE(point_test.getMessage(0.1, 0.2, 0.3) == point_test.test1);
  REQUIRE(point_test.getMessage(0.2, 0.2, 0.3) == point_test.test2);
}

TEST_CASE("Point32 test", "[point32_messages]")
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
//
//TEST_CASE("Pose2D Messages test", "[pose_2d_messages]")
//{
//  {
//    REQUIRE(pose_2d_messages.getMessage(0.1, 0.2, 0.3) == pose_2d_messages.test1);
//
//    Pose2D p;
//    p.x = 0.1;
//    p.y = 0.2;
//    p.theta = 0.3;
//    REQUIRE(pose_2d_messages.getMessage(p) == pose_2d_messages.test1);
//  }
//  {
//    REQUIRE(pose_2d_messages.getMessage(.2, .0, .3) == pose_2d_messages.test2);
//
//    Pose2D p;
//    p.x = .2;
//    p.y = .0;
//    p.theta = .3;
//    REQUIRE(pose_2d_messages.getMessage(p) == pose_2d_messages.test2);
//  }
//}
//
TEST_CASE("Pose Stamped test", "[pose_stamped_test]")
{
  {
    REQUIRE(pose_stamped_test.getMessage(0.1, 0.2, 0.3, 0.1, 0., 0., 1.0) == pose_stamped_test.test1);

    geometry_msgs::Pose p;
    p.point.x = 0.1;
    p.point.y = 0.2;
    p.point.z = 0.3;
    p.quaternion.x = 0.1;
    p.quaternion.y = 0.;
    p.quaternion.z = 0.;
    p.quaternion.w = 1.0;
    REQUIRE(pose_stamped_test.getMessage(p) == pose_stamped_test.test1);
  }
  {
    REQUIRE(pose_stamped_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 0., 1.0, "a_frame") == pose_stamped_test.test2);

    geometry_msgs::Pose p;
    p.point.x = 0.1;
    p.point.y = 0.5;
    p.point.z = 0.3;
    p.quaternion.x = 0.1;
    p.quaternion.y = 0.9;
    p.quaternion.z = 0.;
    p.quaternion.w = 1.0;
    REQUIRE(pose_stamped_test.getMessage(p, "a_frame") == pose_stamped_test.test2);
  }
}
//}
//
//TEST_CASE("Pose Array Messages test", "[pose_array_messages]")
//{
//  REQUIRE(pose_array_messages.getMessage1() == pose_array_messages.test1);
//  REQUIRE(pose_array_messages.getMessage2("a_frame") == pose_array_messages.test2);
//}
//
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
//
//TEST_CASE("Twist Messages test", "[twist_messages]")
//{
//  {
//    REQUIRE(twist_messages.getMessage(0.1, 0.2, 0.3, 0.1, 0.2, 0.3) == twist_messages.test1);
//
//    Vector3 linear;
//    linear.x = 0.1;
//    linear.y = 0.2;
//    linear.z = 0.3;
//    Vector3 angular;
//    angular.x = 0.1;
//    angular.y = 0.2;
//    angular.z = 0.3;
//    REQUIRE(twist_messages.getMessage(linear, angular) == twist_messages.test1);
//  }
//  {
//    REQUIRE(twist_messages.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 1.0) == twist_messages.test2);
//
//    Vector3 linear;
//    linear.x = 0.1;
//    linear.y = 0.5;
//    linear.z = 0.3;
//    Vector3 angular;
//    angular.x = 0.1;
//    angular.y = 0.9;
//    angular.z = 1.0;
//    REQUIRE(twist_messages.getMessage(linear, angular) == twist_messages.test2);
//  }
//}
//
//TEST_CASE("Twist Stamped Messages test", "[twist_stamped_messages]")
//{
//  {
//    REQUIRE(twist_stamped_messages.getMessage(0.10, 0.20, 0.30, 0.1, 0.2, 0.3) == twist_stamped_messages.test1);
//
//    Vector3 linear;
//    linear.x = 0.10;
//    linear.y = 0.20;
//    linear.z = 0.30;
//    Vector3 angular;
//    angular.x = 0.1;
//    angular.y = 0.2;
//    angular.z = 0.3;
//    REQUIRE(twist_stamped_messages.getMessage(linear, angular) == twist_stamped_messages.test1);
//  }
//  {
//    REQUIRE(twist_stamped_messages.getMessage(0.1, 0.5, 0.3, 0.1, 0.9, 1.0, "a_frame") == twist_stamped_messages.test2);
//
//    Vector3 linear;
//    linear.x = 0.1;
//    linear.y = 0.5;
//    linear.z = 0.3;
//    Vector3 angular;
//    angular.x = 0.1;
//    angular.y = 0.9;
//    angular.z = 1.0;
//    REQUIRE(twist_stamped_messages.getMessage(linear, angular, "a_frame") == twist_stamped_messages.test2);
//  }
//}
//
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
   
   REQUIRE(transform_stamped_test.getMessage(0.1, 0.5, 0.3, 0.1, 0.2, 0.3, 1.0, "a_frame") == transform_stamped_test.test2);
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

//TEST_CASE("Polygon Messages test", "[polygon_messages]")
//{
//  {
//    Point32 point;
//    point.x = 0.10;
//    point.y = 0.20;
//    point.z = 0.30;
//    REQUIRE(polygon_messages.getMessage(point) == polygon_messages.test1);
//    REQUIRE(polygon_messages.getMessageWithAdd(point) == polygon_messages.test1);
//  }
//  {
//    Point32 point;
//    point.x = 0.1;
//    point.y = 0.5;
//    point.z = 0.3;
//    REQUIRE(polygon_messages.getMessageWithAdd(point) == polygon_messages.test2);
//  }
//}
//
//TEST_CASE("Polygon Stamped Messages test", "[polygon_stamped_messages]")
//{
//  {
//    Point32 point;
//    point.x = 0.10;
//    point.y = 0.20;
//    point.z = 0.30;
//    REQUIRE(polygon_stamped_messages.getMessage(point) == polygon_stamped_messages.test1);
//    REQUIRE(polygon_stamped_messages.getMessageWithAdd(point) == polygon_stamped_messages.test1);
//  }
//  {
//    Point32 point;
//    point.x = 0.1;
//    point.y = 0.5;
//    point.z = 0.3;
//    REQUIRE(polygon_stamped_messages.getMessageWithAdd(point) == polygon_stamped_messages.test2);
//  }
//}
//
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

}
