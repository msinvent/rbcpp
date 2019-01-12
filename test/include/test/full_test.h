//
// Created by julian on 29.11.18.
//

#ifndef ROSBRIDGECLIENT_FULL_TEST_H
#define ROSBRIDGECLIENT_FULL_TEST_H

#include <unordered_map>
#include <iostream>
#include <string>
#include <atomic>
#include <thread>
#include <memory>
#include <chrono>
#include <rbc/ros_bridge_client.h>
#include <rbc/publisher/rbc_publisher.h>

#include <rbc/msgs/nav_msgs/odometry.h>
#include <rbc/msgs/nav_msgs/path.h>

#include <rbc/msgs/sensor_msgs/imu.h>
#include <rbc/msgs/sensor_msgs/joy.h>
#include <rbc/msgs/sensor_msgs/image.h>
#include <rbc/msgs/sensor_msgs/temperature.h>
#include <rbc/msgs/sensor_msgs/joint_state.h>
#include <rbc/msgs/sensor_msgs/fluid_pressure.h>

#include <rbc/msgs/geometry_msgs/pose.h>
#include <rbc/msgs/geometry_msgs/point.h>
#include <rbc/msgs/geometry_msgs/accel.h>
#include <rbc/msgs/geometry_msgs/twist.h>
#include <rbc/msgs/geometry_msgs/point32.h>
#include <rbc/msgs/geometry_msgs/pose2d.h>
#include <rbc/msgs/geometry_msgs/vector3.h>
#include <rbc/msgs/geometry_msgs/transform.h>
#include <rbc/msgs/geometry_msgs/wrench.h>
#include <rbc/msgs/geometry_msgs/inertia.h>
#include <rbc/msgs/geometry_msgs/polygon.h>
#include <rbc/msgs/geometry_msgs/quaternion.h>
#include <rbc/msgs/geometry_msgs/pose_array.h>
#include <rbc/msgs/geometry_msgs/point_stamped.h>
#include <rbc/msgs/geometry_msgs/accel_stamped.h>
#include <rbc/msgs/geometry_msgs/wrench_stamped.h>
#include <rbc/msgs/geometry_msgs/transform_stamped.h>
#include <rbc/msgs/geometry_msgs/polygon_stamped.h>
#include <rbc/msgs/geometry_msgs/pose_stamped.h>
#include <rbc/msgs/geometry_msgs/twist_stamped.h>
#include <rbc/msgs/geometry_msgs/vector3_stamped.h>
#include <rbc/msgs/geometry_msgs/inertia_stamped.h>
#include <rbc/msgs/geometry_msgs/quaternion_stamped.h>
#include <rbc/msgs/geometry_msgs/twist_with_covariance_stamped.h>
#include <rbc/msgs/geometry_msgs/accel_with_covariance_stamped.h>
#include <rbc/msgs/geometry_msgs/twist_with_covariance.h>
#include <rbc/msgs/geometry_msgs/accel_with_covariance.h>
#include <rbc/msgs/geometry_msgs/pose_with_covariance.h>
#include <rbc/msgs/geometry_msgs/pose_with_covariance_stamped.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/std_msgs/string.h>
#include <rbc/msgs/std_msgs/int8.h>
#include <rbc/msgs/std_msgs/int16.h>
#include <rbc/msgs/std_msgs/int32.h>
#include <rbc/msgs/std_msgs/int64.h>
#include <rbc/msgs/std_msgs/uint8.h>
#include <rbc/msgs/std_msgs/uint16.h>
#include <rbc/msgs/std_msgs/uint32.h>
#include <rbc/msgs/std_msgs/uint64.h>
#include <rbc/msgs/std_msgs/float32.h>
#include <rbc/msgs/std_msgs/float64.h>
#include <rbc/msgs/std_msgs/color_rgba.h>
#include <config_parser/config_parser.h>
#include <cassert>

namespace test
{

struct TestException : public std::exception
{
  inline const char *what() const throw()
  {
    return "TestException\n  Test Error! \n  Didn't receive all messages! \n  Exiting.\n";
  }
};

} // namespace test

namespace callbacks
{
std::atomic<size_t> messages_received;
size_t num_publishers;
std::unordered_map<std::string, unsigned int> test_map;
const std::vector<std::string> messages = {"header",
                                           "string",
                                           "float32",
                                           "float64",
                                           "int8",
                                           "int16",
                                           "int32",
                                           "int64",
                                           "uint8",
                                           "uint16",
                                           "uint32",
                                           "uint64",
                                           "pose",
                                           "pose_stamp",
                                           "pose_cov",
                                           "pose_cov_stamp",
                                           "point",
                                           "polygon",
                                           "polygon_stamp",
                                           "pose2d",
                                           "accel",
                                           "accel_stamp",
                                           "accel_cov",
                                           "accel_cov_stamp",
                                           "twist",
                                           "twist_cov",
                                           "twist_cov_stamp",
                                           "twist_stamp",
                                           "transform",
                                           "transform_stamp",
                                           "point32",
                                           "colorrgba",
                                           "point_stamp",
                                           "pose_stamp",
                                           "vector3",
                                           "vector3_stamp",
                                           "quaternion",
                                           "quaternion_stamp",
                                           "wrench",
                                           "wrench_stamp",
                                           "inertia",
                                           "inertia_stamp",
                                           "odometry",
                                           "path",
                                           "imu",
                                           "joy",
                                           "image",
                                           "temperature",
                                           "joint_state",
                                           "fluid_pressure"};

static void init()
{
  for (const auto &msg : messages)
  {
    test_map[msg] = 0;
  }
}

void update(std::string msg)
{
  try
  {
    test_map.at(msg) += 1;
  }
  catch (std::exception &e)
  {
    std::cout << "'" << msg << "' doesn't exist in map: " << e.what() << "\n";
  }
}

static void results()
{
  for (const auto[k, v]: test_map)
  {
    if (v != 10)
      std::cerr << "\nmissing type: " << k << ": " << v << " of 10";
  }
}

static inline void hcallback(const std::shared_ptr<std_msgs::Header> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Header]\n";
  assert((msg->frame_id == "a frame"));
  update("header");
}

static inline void scallback(const std::shared_ptr<std_msgs::String> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[String]\n";
  assert((msg->data == "a string"));
  update("string");
}

static inline void f32callback(const std::shared_ptr<std_msgs::Float32> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Float32]\n";
  assert((msg->data == .1f));
  update("float32");
}

static inline void f64callback(const std::shared_ptr<std_msgs::Float64> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Float64]\n";
  assert((msg->data == .1));
  update("float64");
}

static inline void int8callback(const std::shared_ptr<std_msgs::Int8> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Int8]\n";
  assert((msg->data == 1));
  update("int8");
}

static inline void int16callback(const std::shared_ptr<std_msgs::Int16> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Int16]\n";
  assert((msg->data == 1));
  update("int16");
}

static inline void int32callback(const std::shared_ptr<std_msgs::Int32> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Int32]\n";
  assert((msg->data == 1));
  update("int32");
}

static inline void int64callback(const std::shared_ptr<std_msgs::Int64> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Int64]\n";
  assert((msg->data == 1));
  update("int64");
}

static inline void uint8callback(const std::shared_ptr<std_msgs::UInt8> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[UInt8]\n";
  assert((msg->data == 1));
  update("uint8");
}

static inline void uint16callback(const std::shared_ptr<std_msgs::UInt16> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[UInt16]\n";
  assert((msg->data == 1));
  update("uint16");
}

static inline void uint32callback(const std::shared_ptr<std_msgs::UInt32> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[UInt32]\n";
  assert((msg->data == 1));
  update("uint32");
}

static inline void uint64callback(const std::shared_ptr<std_msgs::UInt64> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[UInt64]\n";
  assert((msg->data == 1));
  update("uint64");
}

static inline void pocallback(const std::shared_ptr<geometry_msgs::Pose> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Pose]\n";
  assert((msg->point.x == .1));
  assert((msg->point.y == .2));
  assert((msg->point.z == .3));
  assert((msg->orientation.x == .1));
  assert((msg->orientation.y == .2));
  assert((msg->orientation.z == .3));
  assert((msg->orientation.w == .4));
  update("pose");
}

static inline void posacallback(const std::shared_ptr<geometry_msgs::PoseArray> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[PoseArray]\n";
  assert((msg->header.frame_id == "a frame"));

  geometry_msgs::Pose po(.1, .2, .3, .1, .2, .3, .4);
  assert((msg->poses[0] == po));
  assert((msg->poses[1] == po));
}

static inline void pocovcallback(const std::shared_ptr<geometry_msgs::PoseWithCovariance> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[PoseWithCov]\n";
  assert((msg->pose.point.x == .1));
  assert((msg->pose.point.z == .3));
  assert((msg->pose.orientation.x == .1));
  assert((msg->pose.orientation.y == .2));
  assert((msg->pose.orientation.z == .3));
  assert((msg->pose.orientation.w == .4));
  assert((msg->covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                    .7, .8, .9, 1., 1.1, 1.2,
                                                    1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                    1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                    2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                    3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));
  update("pose_cov");
}

static inline void pocovscallback(const std::shared_ptr<geometry_msgs::PoseWithCovarianceStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[PoseCovStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->pose.pose.point.x == .1));
  assert((msg->pose.pose.point.z == .3));
  assert((msg->pose.pose.orientation.x == .1));
  assert((msg->pose.pose.orientation.y == .2));
  assert((msg->pose.pose.orientation.z == .3));
  assert((msg->pose.pose.orientation.w == .4));
  assert((msg->pose.covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                         .7, .8, .9, 1., 1.1, 1.2,
                                                         1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                         1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                         2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                         3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));
  update("pose_cov_stamp");
}

static inline void pcallback(const std::shared_ptr<geometry_msgs::Point> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Point]\n";
  assert((msg->x == .1));
  assert((msg->y == .2));
  assert((msg->z == .3));
  update("point");
}

static inline void polycallback(const std::shared_ptr<geometry_msgs::Polygon> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Polygon]\n";
  assert((msg->points[0].x == .1f));
  assert((msg->points[0].y == .2f));
  assert((msg->points[0].z == .3f));
  assert((msg->points[1].x == .1f));
  assert((msg->points[1].y == .2f));
  assert((msg->points[1].z == .3f));
  update("polygon");
}

static inline void polyscallback(const std::shared_ptr<geometry_msgs::PolygonStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[PolygonStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->polygon.points[0].x == .1f));
  assert((msg->polygon.points[0].y == .2f));
  assert((msg->polygon.points[0].z == .3f));
  assert((msg->polygon.points[1].x == .1f));
  assert((msg->polygon.points[1].y == .2f));
  assert((msg->polygon.points[1].z == .3f));
  update("polygon_stamp");
}


static inline void p2dcallback(const std::shared_ptr<geometry_msgs::Pose2D> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Point2d]\n";
  assert((msg->x == .1));
  assert((msg->y == .2));
  assert((msg->theta == .3));
  update("pose2d");
}

static inline void acallback(const std::shared_ptr<geometry_msgs::Accel> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Accel]\n";
  assert((msg->linear.x == .1));
  assert((msg->linear.y == .2));
  assert((msg->linear.z == .3));
  assert((msg->angular.x == .3));
  assert((msg->angular.y == .2));
  assert((msg->angular.z == .1));
  update("accel");
}

static inline void acovcallback(const std::shared_ptr<geometry_msgs::AccelWithCovariance> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[AccelWithCov]\n";
  assert((msg->accel.linear.x == .1));
  assert((msg->accel.linear.y == .2));
  assert((msg->accel.linear.z == .3));
  assert((msg->accel.angular.x == .3));
  assert((msg->accel.angular.y == .2));
  assert((msg->accel.angular.z == .1));
  assert((msg->covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                    .7, .8, .9, 1., 1.1, 1.2,
                                                    1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                    1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                    2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                    3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));
  update("accel_cov");
}

static inline void acovscallback(const std::shared_ptr<geometry_msgs::AccelWithCovarianceStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10)
            << " messages \t[AccelWithCovStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->accel.accel.linear.x == .1));
  assert((msg->accel.accel.linear.y == .2));
  assert((msg->accel.accel.linear.z == .3));
  assert((msg->accel.accel.angular.x == .3));
  assert((msg->accel.accel.angular.y == .2));
  assert((msg->accel.accel.angular.z == .1));
  assert((msg->accel.covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                          .7, .8, .9, 1., 1.1, 1.2,
                                                          1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                          1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                          2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                          3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));
  update("accel_cov_stamp");
}

static inline void twcallback(const std::shared_ptr<geometry_msgs::Twist> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Twist]\n";
  assert((msg->linear.x == .1));
  assert((msg->linear.y == .2));
  assert((msg->linear.z == .3));
  assert((msg->angular.x == .3));
  assert((msg->angular.y == .2));
  assert((msg->angular.z == .1));
  update("twist");
}

static inline void twccallback(const std::shared_ptr<geometry_msgs::TwistWithCovariance> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10)
            << " messages \t[TwistWithCovariance]\n";
  assert((msg->twist.linear.x == .1));
  assert((msg->twist.linear.y == .2));
  assert((msg->twist.linear.z == .3));
  assert((msg->twist.angular.x == .3));
  assert((msg->twist.angular.y == .2));
  assert((msg->twist.angular.z == .1));
  assert((msg->covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                    .7, .8, .9, 1., 1.1, 1.2,
                                                    1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                    1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                    2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                    3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));
  update("twist_cov");
}

static inline void twcscallback(const std::shared_ptr<geometry_msgs::TwistWithCovarianceStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10)
            << " messages \t[TwistWithCovarianceStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->twist.twist.linear.x == .1));
  assert((msg->twist.twist.linear.y == .2));
  assert((msg->twist.twist.linear.z == .3));
  assert((msg->twist.twist.angular.x == .3));
  assert((msg->twist.twist.angular.y == .2));
  assert((msg->twist.twist.angular.z == .1));
  assert((msg->twist.covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                          .7, .8, .9, 1., 1.1, 1.2,
                                                          1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                          1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                          2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                          3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));
  update("twist_cov_stamp");
}

static inline void twscallback(const std::shared_ptr<geometry_msgs::TwistStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[TwistStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->twist.linear.x == .1));
  assert((msg->twist.linear.y == .2));
  assert((msg->twist.linear.z == .3));
  assert((msg->twist.angular.x == .3));
  assert((msg->twist.angular.y == .2));
  assert((msg->twist.angular.z == .1));
  update("twist_stamp");
}

static inline void tcallback(const std::shared_ptr<geometry_msgs::Transform> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Transform]\n";
  assert((msg->translation.x == .1));
  assert((msg->translation.y == .2));
  assert((msg->translation.z == .3));
  assert((msg->rotation.x == .4));
  assert((msg->rotation.y == .3));
  assert((msg->rotation.z == .2));
  assert((msg->rotation.w == .1));
  update("transform");
}

static inline void tscallback(const std::shared_ptr<geometry_msgs::TransformStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10)
            << " messages \t[TransformStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->transform.translation.x == .1));
  assert((msg->transform.translation.y == .2));
  assert((msg->transform.translation.z == .3));
  assert((msg->transform.rotation.x == .4));
  assert((msg->transform.rotation.y == .3));
  assert((msg->transform.rotation.z == .2));
  assert((msg->transform.rotation.w == .1));
  update("transform_stamp");
}

static inline void p32callback(const std::shared_ptr<geometry_msgs::Point32> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Point32]\n";
  assert((msg->x == .1f));
  assert((msg->y == .2f));
  assert((msg->z == .3f));
  update("point32");
}

static inline void ccallback(const std::shared_ptr<std_msgs::ColorRGBA> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[ColorRGBA]\n";
  assert((msg->r == .1f));
  assert((msg->g == .2f));
  assert((msg->b == .3f));
  assert((msg->a == .4f));
  update("colorrgba");
}

static inline void pscallback(const std::shared_ptr<geometry_msgs::PointStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[PointStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->point.x == .1));
  assert((msg->point.y == .2));
  assert((msg->point.z == .3));
  update("point_stamp");
}

static inline void poscallback(const std::shared_ptr<geometry_msgs::PoseStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[PointStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->pose.point.x == .1));
  assert((msg->pose.point.y == .2));
  assert((msg->pose.point.z == .3));
  assert((msg->pose.orientation.x == .1));
  assert((msg->pose.orientation.y == .2));
  assert((msg->pose.orientation.z == .3));
  assert((msg->pose.orientation.w == .4));
  update("pose_stamp");
}

static inline void vcallback(const std::shared_ptr<geometry_msgs::Vector3> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Vector3]\n";
  assert((msg->x == .1));
  assert((msg->y == .2));
  assert((msg->z == .3));
  update("vector3");
}

static inline void vscallback(const std::shared_ptr<geometry_msgs::Vector3Stamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Vector3Stamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->vector.x == .1));
  assert((msg->vector.y == .2));
  assert((msg->vector.z == .3));
  update("vector3_stamp");
}

static inline void qcallback(const std::shared_ptr<geometry_msgs::Quaternion> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Quaternion]\n";
  assert((msg->x == .1));
  assert((msg->y == .2));
  assert((msg->z == .3));
  assert((msg->w == .4));
  update("quaternion");
}

static inline void qscallback(const std::shared_ptr<geometry_msgs::QuaternionStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10)
            << " messages \t[QuaternionStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->quaternion.x == .1));
  assert((msg->quaternion.y == .2));
  assert((msg->quaternion.z == .3));
  assert((msg->quaternion.w == .4));
  update("quaternion_stamp");
}

static inline void ascallback(const std::shared_ptr<geometry_msgs::AccelStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[AccelStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->accel.linear.x == .1));
  assert((msg->accel.linear.y == .2));
  assert((msg->accel.linear.z == .3));
  assert((msg->accel.angular.x == .3));
  assert((msg->accel.angular.y == .2));
  assert((msg->accel.angular.z == .1));
  update("accel_stamp");
}

static inline void wcallback(const std::shared_ptr<geometry_msgs::Wrench> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Wrench]\n";
  assert((msg->force.x == .1));
  assert((msg->force.y == .2));
  assert((msg->force.z == .3));
  assert((msg->torque.x == .3));
  assert((msg->torque.y == .2));
  assert((msg->torque.z == .1));
  update("wrench");
}

static inline void wscallback(const std::shared_ptr<geometry_msgs::WrenchStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[WrenchStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->wrench.force.x == .1));
  assert((msg->wrench.force.y == .2));
  assert((msg->wrench.force.z == .3));
  assert((msg->wrench.torque.x == .3));
  assert((msg->wrench.torque.y == .2));
  assert((msg->wrench.torque.z == .1));
  update("wrench_stamp");
}

static inline void icallback(const std::shared_ptr<geometry_msgs::Inertia> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Inertia]\n";
  assert((msg->m == .1));
  assert((msg->ixx == .2));
  assert((msg->ixy == .3));
  assert((msg->ixz == .4));
  assert((msg->iyy == .5));
  assert((msg->iyz == .6));
  assert((msg->izz == .7));
  assert((msg->com.x == .1));
  assert((msg->com.y == .2));
  assert((msg->com.z == .3));
  update("inertia");
}

static inline void iscallback(const std::shared_ptr<geometry_msgs::InertiaStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[InertiaStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->inertia.m == .1));
  assert((msg->inertia.ixx == .2));
  assert((msg->inertia.ixy == .3));
  assert((msg->inertia.ixz == .4));
  assert((msg->inertia.iyy == .5));
  assert((msg->inertia.iyz == .6));
  assert((msg->inertia.izz == .7));
  assert((msg->inertia.com.x == .1));
  assert((msg->inertia.com.y == .2));
  assert((msg->inertia.com.z == .3));
  update("inertia_stamp");
}

static inline void odomcallback(const std::shared_ptr<nav_msgs::Odometry> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Odometry]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->child_frame_id == "a child frame"));

  assert((msg->pose.pose.point.x == .1));
  assert((msg->pose.pose.point.z == .3));
  assert((msg->pose.pose.orientation.x == .1));
  assert((msg->pose.pose.orientation.y == .2));
  assert((msg->pose.pose.orientation.z == .3));
  assert((msg->pose.pose.orientation.w == .4));
  assert((msg->pose.covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                    .7, .8, .9, 1., 1.1, 1.2,
                                                    1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                    1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                    2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                    3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));

  assert((msg->twist.twist.linear.x == .1));
  assert((msg->twist.twist.linear.y == .2));
  assert((msg->twist.twist.linear.z == .3));
  assert((msg->twist.twist.angular.x == .3));
  assert((msg->twist.twist.angular.y == .2));
  assert((msg->twist.twist.angular.z == .1));
  assert((msg->twist.covariance == std::array<double, 36>{.1, .2, 3., .4, .5, .6,
                                                    .7, .8, .9, 1., 1.1, 1.2,
                                                    1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                                    1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                                    2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                                    3.1, 3.2, 3.3, 3.4, 3.5, 3.6}));
  update("odometry");
}

static inline void pathcallback(const std::shared_ptr<nav_msgs::Path> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Path]\n";

  assert((msg->header.frame_id == "world"));
  assert((msg->poses[0].pose.point.x == .1));
  assert((msg->poses[0].pose.point.y == .2));
  assert((msg->poses[0].pose.point.z == .3));
  assert((msg->poses[0].pose.orientation.x == .1));
  assert((msg->poses[0].pose.orientation.y == .2));
  assert((msg->poses[0].pose.orientation.z == .3));
  assert((msg->poses[0].pose.orientation.w == .4));

  update("path");
}

static inline void imucallback(const std::shared_ptr<sensor_msgs::Imu> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Imu]\n";
  std::array<float, 9> covariance( {.1, .2, 3., .4, .5, .6, .7, .8, .9} );

  assert((msg->linear_acceleration_covariance == covariance));
  assert((msg->angular_velocity_covariance == covariance));
  assert((msg->orientation_covariance == covariance));
  assert((msg->linear_acceleration.x == 0.1));
  assert((msg->linear_acceleration.y == 0.2));
  assert((msg->linear_acceleration.z == 0.3));
  assert((msg->angular_velocity.x == 0.1));
  assert((msg->angular_velocity.y == 0.2));
  assert((msg->angular_velocity.z == 0.3));
  assert((msg->orientation.x == 0.1));
  assert((msg->orientation.y == 0.2));
  assert((msg->orientation.z == 0.3));
  assert((msg->orientation.w == 0.4));

  update("imu");
}

static inline void joycallback(const std::shared_ptr<sensor_msgs::Joy> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Joy]\n";
  std::vector<float> axes{.1, .2, .3, .4, .5, .6, .7, .8, .9};
  std::vector<int32_t> buttons{1, 2, 3, 4, 5, 6, 7, 8, 9};

  assert((msg->header.frame_id == "a frame"));
  assert((msg->axes == axes));
  assert((msg->buttons == buttons));

  update("joy");
}

template <std::int32_t H, std::int32_t W>
static inline void imgcallback(const std::shared_ptr<sensor_msgs::Image<H,W>> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Image]\n";
  std::array<std::uint8_t, 25> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                    11, 12, 13, 14, 15, 16, 17,
                                    18, 19, 20, 21, 22, 23, 24, 25};

//  assert((msg->header.frame_id == "a frame"));
//  assert((msg->height == 10));
//  assert((msg->width == 10));
//  assert((msg->encoding == "utf-8"));
//  //assert((msg->is_bigendian == 0));
//  //assert((msg->step == 5));
//  //assert((msg->data == data));

  update("image");
}

static inline void tempcallback(const std::shared_ptr<sensor_msgs::Temperature> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[Temperature]\n";

  assert((msg->header.frame_id == "a frame"));
  assert((msg->temperature == 5.55));
  assert((msg->variance == 2.22));

  update("temperature");
}

static inline void jscallback(const std::shared_ptr<sensor_msgs::JointState> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[JointState]\n";
  std::vector<double> vec{.1, .2, .3, .4, .5, .6, .7, .8, .9};
  std::vector<std::string> name{"a joint", "another joint"};

  assert((msg->header.frame_id == "a frame"));
  assert((msg->name == name));
  assert((msg->position == vec));
  assert((msg->velocity == vec));
  assert((msg->effort == vec));

  update("joint_state");
}

static inline void fpcallback(const std::shared_ptr<sensor_msgs::FluidPressure> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers * 10) << " messages \t[FluidPressure]\n";

  assert((msg->header.frame_id == "a frame"));
  assert((msg->fluid_pressure == 10.0));
  assert((msg->variance == 0.2));

  update("fluid_pressure");
}

} // namespace callbacks

#endif //ROSBRIDGECLIENT_FULL_TEST_H
