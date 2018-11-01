//
// Created by Julian on 15.09.18.
//

#ifndef ROSBRIDGECLIENT_Test_TEST_HPP
#define ROSBRIDGECLIENT_Test_TEST_HPP

#include <test/csv_reader.h>

#include <cpprest/ws_client.h>
#include <ros_bridge_client/ros_bridge_client.h>
#include <ros_bridge_client/msgs/message.h>
//#include <ros_bridge_client/msgs/std_msgs/int8_message.h>
//#include <ros_bridge_client/msgs/std_msgs/int16_message.h>
//#include <ros_bridge_client/msgs/std_msgs/int32_message.h>
//#include <ros_bridge_client/msgs/std_msgs/int64_message.h>
//#include <ros_bridge_client/msgs/std_msgs/uint8_message.h>
//#include <ros_bridge_client/msgs/std_msgs/uint16_message.h>
//#include <ros_bridge_client/msgs/std_msgs/uint32_message.h>
//#include <ros_bridge_client/msgs/std_msgs/uint64_message.h>
//#include <ros_bridge_client/msgs/std_msgs/string_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
//#include <ros_bridge_client/msgs/std_msgs/color_rgba_message.h>
//
//#include <ros_bridge_client/msgs/service/service_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/pose_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/twist_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
//#include <ros_bridge_client/msgs/geometry_msgs/wrench_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/pose_2d_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/polygon_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/inertia_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/point32_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped.h>
//#include <ros_bridge_client/msgs/geometry_msgs/transform_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/quaternion_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/pose_array_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/point_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/twist_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/wrench_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/vector3_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/polygon_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/transform_stamped_message.h>
//#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped_message.h>

//#include <ros_bridge_client/ros_types/ros_types.h>
//#include <ros_bridge_client/msgs/nav_msgs/grid_cells_message.h>

using namespace ros_bridge_client::msgs;
//using namespace ros_bridge_client::ros_types;

namespace test
{

struct DataFrame
{
  DataFrame() = delete;

  DataFrame(const test::CSVReader &reader)
    : reader(reader),
      data(reader.getData())
  {}

  ~DataFrame() = default;

  const test::CSVReader &reader;
  const std::unordered_map<std::string, std::vector<std::string>> &data;
};

struct Test
{
  Test() = default;

  virtual ~Test() = default;

  template<typename T>
  inline std::string messageToString(const T &t) const
  {
    Message<T> msg(t);
    return msg.toString();
  }
};

struct HeaderTest : public Test
{
  explicit HeaderTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("HeaderTest")[0]),
      test2(dataframe.data.at("HeaderTest")[1])
  {}

  ~HeaderTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(std::string frame_id = "world") const
  {
    std_msgs::Header msg(frame_id);
    return messageToString<std_msgs::Header>(msg);
  }
};

//
//struct StringTest : public Test
//{
//  StringTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("StringTest")[0]),
//        test2(dataframe.data.at("StringTest")[1])
//  {}
//
//  ~StringTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(std::string message) const
//  {
//    std_msgs::StringTest msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct UInt8Test : public Test
//{
//  UInt8Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("UInt8Test")[0]),
//        test2(dataframe.data.at("UInt8Test")[1])
//  {}
//
//  ~UInt8Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(uint8_t message) const
//  {
//    std_msgs::UInt8Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct UInt16Test : public Test
//{
//  UInt16Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("UInt16Test")[0]),
//        test2(dataframe.data.at("UInt16Test")[1])
//  {}
//
//  ~UInt16Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(uint16_t message) const
//  {
//    std_msgs::UInt16Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct UInt32Test : public Test
//{
//  UInt32Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("UInt32Test")[0]),
//        test2(dataframe.data.at("UInt32Test")[1])
//  {}
//
//  ~UInt32Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(uint32_t message) const
//  {
//    std_msgs::UInt32Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct UInt64Test : public Test
//{
//  UInt64Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("UInt64Test")[0]),
//        test2(dataframe.data.at("UInt64Test")[1])
//  {}
//
//  ~UInt64Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(uint64_t message) const
//  {
//    std_msgs::UInt64Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct Int8Test : public Test
//{
//  Int8Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("Int8Test")[0]),
//        test2(dataframe.data.at("Int8Test")[1])
//  {}
//
//  ~Int8Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(int8_t message) const
//  {
//    std_msgs::Int8Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct Int16Test : public Test
//{
//  Int16Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("Int16Test")[0]),
//        test2(dataframe.data.at("Int16Test")[1])
//  {}
//
//  ~Int16Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(int16_t message) const
//  {
//    std_msgs::Int16Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct Int32Test : public Test
//{
//  Int32Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("Int32Test")[0]),
//        test2(dataframe.data.at("Int32Test")[1])
//  {}
//
//  ~Int32Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(int32_t message) const
//  {
//    std_msgs::Int32Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct Int64Test : public Test
//{
//  Int64Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("Int64Test")[0]),
//        test2(dataframe.data.at("Int64Test")[1])
//  {}
//
//  ~Int64Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(int64_t message) const
//  {
//    std_msgs::Int64Test msg(message);
//    return messageToString(msg);
//  }
//};
//
//struct ColorRGBATest : public Test
//{
//  ColorRGBATest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("ColorRGBATest")[0]),
//        test2(dataframe.data.at("ColorRGBATest")[1])
//  {}
//
//  ~ColorRGBATest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(float r, float g, float b, float a) const
//  {
//    std_msgs::ColorRGBATest msg(r, g, b, a);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const ColorRGBA &c) const
//  {
//    std_msgs::ColorRGBATest msg(c);
//    return messageToString(msg);
//  }
//};
//
//
struct Point32Test : public Test
{
  explicit Point32Test(const DataFrame &dataframe)
    : test1(dataframe.data.at("Point32Test")[0]),
      test2(dataframe.data.at("Point32Test")[1])
  {}

  ~Point32Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(float x, float y, float z) const
  {
    geometry_msgs::Point32 msg(x, y, z);
    return messageToString(msg);
  }
};

struct PointTest : public Test
{
  explicit PointTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("PointTest")[0]),
      test2(dataframe.data.at("PointTest")[1])
  {}

  ~PointTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z) const
  {
    geometry_msgs::Point msg(x, y, z);
    return messageToString<geometry_msgs::Point>(msg);
  }
};

struct PointStampedTest : public Test
{
  explicit PointStampedTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("PointStampedTest")[0]),
      test2(dataframe.data.at("PointStampedTest")[1])
  {}

  ~PointStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, std::string frame_id = "world") const
  {
    geometry_msgs::PointStamped msg(x, y, z, frame_id);
    return messageToString<geometry_msgs::PointStamped>(msg);
  }
};

struct Vector3Test : public Test
{
  explicit Vector3Test(const DataFrame &dataframe)
    : test1(dataframe.data.at("Vector3Test")[0]),
      test2(dataframe.data.at("Vector3Test")[1])
  {}

  ~Vector3Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z) const
  {
    geometry_msgs::Vector3 msg(x, y, z);
    return messageToString<geometry_msgs::Vector3>(msg);
  }
};

struct Vector3StampedTest : public Test
{
  explicit Vector3StampedTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("Vector3StampedTest")[0]),
      test2(dataframe.data.at("Vector3StampedTest")[1])
  {}

  ~Vector3StampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, std::string frame_id = "world") const
  {
    geometry_msgs::Vector3Stamped msg(x, y, z, frame_id);
    return messageToString<geometry_msgs::Vector3Stamped>(msg);
  }
};

struct PoseTest : public Test
{
  explicit PoseTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("PoseTest")[0]),
      test2(dataframe.data.at("PoseTest")[1])
  {}

  ~PoseTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double xx, double yy, double zz, double ww) const
  {
    geometry_msgs::Pose msg(x, y, z, xx, yy, zz, ww);
    return messageToString<geometry_msgs::Pose>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Point &point, const geometry_msgs::Quaternion &quaternion) const
  {
    geometry_msgs::Pose msg(point, quaternion);
    return messageToString<geometry_msgs::Pose>(msg);
  }
};

struct PoseStampedTest : public Test
{
  explicit PoseStampedTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("PoseStampedTest")[0]),
      test2(dataframe.data.at("PoseStampedTest")[1])
  {}

  ~PoseStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double xx, double yy, double zz, double ww,
                                std::string frame_id = "world") const
  {
    geometry_msgs::PoseStamped msg(x, y, z, xx, yy, zz, ww, frame_id);
    return messageToString<geometry_msgs::PoseStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Pose &pose, std::string frame_id = "world") const
  {
    geometry_msgs::PoseStamped msg(pose, frame_id);
    return messageToString<geometry_msgs::PoseStamped>(msg);
  }
};

struct QuaternionTest : public Test
{
  explicit QuaternionTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("QuaternionTest")[0]),
      test2(dataframe.data.at("QuaternionTest")[1])
  {}

  ~QuaternionTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double w) const
  {
    geometry_msgs::Quaternion msg(x, y, z, w);
    return messageToString<geometry_msgs::Quaternion>(msg);
  }
};

struct QuaternionStampedTest : public Test
{
  explicit QuaternionStampedTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("QuaternionStampedTest")[0]),
      test2(dataframe.data.at("QuaternionStampedTest")[1])
  {}

  ~QuaternionStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double w, std::string frame_id = "world") const
  {
    geometry_msgs::QuaternionStamped msg(x, y, z, w, frame_id);
    return messageToString<geometry_msgs::QuaternionStamped>(msg);
  }
};

//
//struct Vector3Test : public Test
//{
//  Vector3Test(const DataFrame &dataframe)
//      : test1(dataframe.data.at("Vector3Test")[0]),
//        test2(dataframe.data.at("Vector3Test")[1])
//  {}
//
//  ~Vector3Test() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(double x, double y, double z) const
//  {
//    geometry_msgs::Vector3Test msg(x, y, z);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Vector3 &vec) const
//  {
//    geometry_msgs::Vector3Test msg(vec);
//    return messageToString(msg);
//  }
//};
//
//struct Vector3StampedTest : public Test
//{
//  Vector3StampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("Vector3StampedTest")[0]),
//        test2(dataframe.data.at("Vector3StampedTest")[1])
//  {}
//
//  ~Vector3StampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(double x, double y, double z, std::string frame_id = "world") const
//  {
//    geometry_msgs::Vector3StampedTest msg(x, y, z, frame_id);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Vector3 &vec) const
//  {
//    geometry_msgs::Vector3StampedTest msg(vec);
//    return messageToString(msg);
//  }
//};
//
//struct PoseTest : public Test
//{
//  PoseTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("PoseTest")[0]),
//        test2(dataframe.data.at("PoseTest")[1])
//  {}
//
//  ~PoseTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(double x, double y, double z, double xx, double yy, double zz, double ww) const
//  {
//    geometry_msgs::PoseTest msg(x, y, z, xx, yy, zz, ww);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Point &p, const Quaternion &q) const
//  {
//    geometry_msgs::PoseTest msg(p, q);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Pose &p) const
//  {
//    geometry_msgs::PoseTest msg(p);
//    return messageToString(msg);
//  }
//};
//
//struct PoseStampedTest : public Test
//{
//  PoseStampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("PoseStampedTest")[0]),
//        test2(dataframe.data.at("PoseStampedTest")[1])
//  {}
//
//  ~PoseStampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string
//  getMessage(double x, double y, double z, double xx, double yy, double zz, double ww, std::string frame = "world") const
//  {
//    geometry_msgs::PoseStampedTest msg(x, y, z, xx, yy, zz, ww, frame);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Point &p, const Quaternion &q, std::string frame = "world") const
//  {
//    geometry_msgs::PoseStampedTest msg(p, q, frame);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Pose &p, std::string frame = "world") const
//  {
//    geometry_msgs::PoseStampedTest msg(p, frame);
//    return messageToString(msg);
//  }
//};
//
//struct PoseArrayTest : public Test
//{
//  PoseArrayTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("PoseArrayTest")[0]),
//        test2(dataframe.data.at("PoseArrayTest")[1])
//  {}
//
//  ~PoseArrayTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage1(std::string frame = "world") const
//  {
//    geometry_msgs::PoseArrayTest msg(frame);
//    Pose p;
//    p.p.x = 0.1;
//    p.p.y = 0.2;
//    p.p.z = 0.3;
//    p.q.x = 0.1;
//    p.q.y = 0.;
//    p.q.z = 0.;
//    p.q.w = 1.0;
//    msg.add(p);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage2(std::string frame = "world") const
//  {
//    geometry_msgs::PoseArrayTest msg(frame);
//    Pose p;
//    p.p.x = 0.1;
//    p.p.y = 0.2;
//    p.p.z = 0.3;
//    p.q.x = 0.1;
//    p.q.y = 0.;
//    p.q.z = 0.;
//    p.q.w = 1.0;
//    msg.add(p);
//    msg.add(4.1, 0.2, 0.3, 0.41, 0.5, 0., 0.3);
//    return messageToString(msg);
//  }
//};
//
struct AccelTest : public Test
{
  explicit AccelTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("AccelTest")[0]),
      test2(dataframe.data.at("AccelTest")[1])
  {}

  ~AccelTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double lx, double ly, double lz, double ax, double ay, double az) const
  {
    geometry_msgs::Accel msg(lx, ly, lz, ax, ay, az);
    return messageToString<geometry_msgs::Accel>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Vector3 &linear, const geometry_msgs::Vector3 &angular) const
  {
    geometry_msgs::Accel msg(linear, angular);
    return messageToString<geometry_msgs::Accel>(msg);
  }
};
//};

struct AccelStampedTest : public Test
{
  AccelStampedTest(const DataFrame &dataframe)
    : test1(dataframe.data.at("AccelStampedTest")[0]),
      test2(dataframe.data.at("AccelStampedTest")[1])
  {}

  ~AccelStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string
  getMessage(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id = "world") const
  {
    geometry_msgs::AccelStamped msg(lx, ly, lz, ax, ay, az, frame_id);
    return messageToString<geometry_msgs::AccelStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Vector3 &linear, const geometry_msgs::Vector3 &angular,
                                std::string frame_id = "world") const
  {
    geometry_msgs::AccelStamped msg(linear, angular, frame_id);
    return messageToString<geometry_msgs::AccelStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Accel &accel, std::string frame_id = "world") const
  {
    geometry_msgs::AccelStamped msg(accel, frame_id);
    return messageToString<geometry_msgs::AccelStamped>(msg);
  }
};
//
//struct TwistTest : public Test
//{
//  TwistTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("TwistTest")[0]),
//        test2(dataframe.data.at("TwistTest")[1])
//  {}
//
//  ~TwistTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(double lx, double ly, double lz, double ax, double ay, double az) const
//  {
//    geometry_msgs::TwistTest msg(lx, ly, lz, ax, ay, az);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Vector3 &linear, const Vector3 &angular) const
//  {
//    geometry_msgs::TwistTest msg(linear, angular);
//    return messageToString(msg);
//  }
//};
//
//struct TwistStampedTest : public Test
//{
//  TwistStampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("TwistStampedTest")[0]),
//        test2(dataframe.data.at("TwistStampedTest")[1])
//  {}
//
//  ~TwistStampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string
//  getMessage(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id = "world") const
//  {
//    geometry_msgs::TwistStampedTest msg(lx, ly, lz, ax, ay, az, frame_id);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const Vector3 &linear, const Vector3 &angular, std::string frame_id = "world") const
//  {
//    geometry_msgs::TwistStampedTest msg(linear, angular, frame_id);
//    return messageToString(msg);
//  }
//};
//
//struct GridCellsTest : public Test
//{
//  GridCellsTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("GridCellsTest")[0]),
//        test2(dataframe.data.at("GridCellsTest")[1])
//  {}
//
//  ~GridCellsTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(float width, float height, std::string frame_id = "world") const
//  {
//    nav_msgs::GridCellsTest msg(width, height, frame_id);
//    Point32 p;
//    p.x = .1;
//    p.y = .2;
//    p.z = .3;
//    msg.add(p);
//    msg.add(p);
//    return messageToString(msg);
//  }
//};
//
//struct TransformTest : public Test
//{
//  TransformTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("TransformTest")[0]),
//        test2(dataframe.data.at("TransformTest")[1])
//  {}
//
//  ~TransformTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(const Vector3 &translation, const Quaternion &rotation) const
//  {
//    geometry_msgs::TransformTest msg(translation, rotation);
//    return messageToString(msg);
//  }
//};
//
//struct TransformStampedTest : public Test
//{
//  TransformStampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("TransformStampedTest")[0]),
//        test2(dataframe.data.at("TransformStampedTest")[1])
//  {}
//
//  ~TransformStampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string
//  getMessage(const Vector3 &translation, const Quaternion &rotation, std::string frame_id = "world") const
//  {
//    geometry_msgs::TransformStampedTest msg(translation, rotation, frame_id);
//    return messageToString(msg);
//  }
//};
//
//struct WrenchTest : public Test
//{
//  WrenchTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("WrenchTest")[0]),
//        test2(dataframe.data.at("WrenchTest")[1])
//  {}
//
//  ~WrenchTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(const Vector3 &force, const Vector3 &torque) const
//  {
//    geometry_msgs::WrenchTest msg(force, torque);
//    return messageToString(msg);
//  }
//};
//
//struct WrenchStampedTest : public Test
//{
//  WrenchStampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("WrenchStampedTest")[0]),
//        test2(dataframe.data.at("WrenchStampedTest")[1])
//  {}
//
//  ~WrenchStampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(const Vector3 &force, const Vector3 &torque, std::string frame_id = "world") const
//  {
//    geometry_msgs::WrenchStampedTest msg(force, torque, frame_id);
//    return messageToString(msg);
//  }
//};
//
//struct PolygonTest : public Test
//{
//  PolygonTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("PolygonTest")[0]),
//        test2(dataframe.data.at("PolygonTest")[1])
//  {}
//
//  ~PolygonTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(const Point32 &point) const
//  {
//    geometry_msgs::PolygonTest msg(point);
//    msg.add(point);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessageWithAdd(const Point32 &point) const
//  {
//    geometry_msgs::PolygonTest msg;
//    msg.add(point);
//    msg.add(point);
//    return messageToString(msg);
//  }
//};
//
//struct PolygonStampedTest : public Test
//{
//  PolygonStampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("PolygonStampedTest")[0]),
//        test2(dataframe.data.at("PolygonStampedTest")[1])
//  {}
//
//  ~PolygonStampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(const Point32 &point, std::string frame_id = "world") const
//  {
//    geometry_msgs::PolygonStampedTest msg(point, frame_id);
//    msg.add(point);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessageWithAdd(const Point32 &point, std::string frame_id = "world") const
//  {
//    geometry_msgs::PolygonStampedTest msg(frame_id);
//    msg.add(point);
//    msg.add(point);
//    return messageToString(msg);
//  }
//};
//
//struct InertiaTest : public Test
//{
//  InertiaTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("InertiaTest")[0]),
//        test2(dataframe.data.at("InertiaTest")[1])
//  {}
//
//  ~InertiaTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string
//  getMessage(double m, Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz, double izz) const
//  {
//    geometry_msgs::InertiaTest msg(m, com, ixx, ixy, ixz, iyy, iyz, izz);
//    return messageToString(msg);
//  }
//};
//
//struct InertiaStampedTest : public Test
//{
//  InertiaStampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("InertiaStampedTest")[0]),
//        test2(dataframe.data.at("InertiaStampedTest")[1])
//  {}
//
//  ~InertiaStampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string
//  getMessage(double m, Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz, double izz,
//             std::string frame_id = "world") const
//  {
//    geometry_msgs::InertiaStampedTest msg(m, com, ixx, ixy, ixz, iyy, iyz, izz, frame_id);
//    return messageToString(msg);
//  }
//};
//
//struct Pose2DTest : public Test
//{
//  Pose2DTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("Pose2DTest")[0]),
//        test2(dataframe.data.at("Pose2DTest")[1])
//  {}
//
//  ~Pose2DTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(double x, double y, double theta) const
//  {
//    geometry_msgs::Pose2DTest msg(x, y, theta);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(Pose2D p) const
//  {
//    geometry_msgs::Pose2DTest msg(p);
//    return messageToString(msg);
//  }
//};
//
//struct ServiceTest : public Test
//{
//  ServiceTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("ServiceTest")[0]),
//        test2(dataframe.data.at("ServiceTest")[1])
//  {}
//
//  ~ServiceTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage() const
//  {
//    service::ServiceTest msg;
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const std::vector<std::string> &vec) const
//  {
//    service::ServiceTest msg(vec);
//    return messageToString(msg);
//  }
//};
//
//} // namespace test

#endif //ROSBRIDGECLIENT_Test_TEST_HPP
