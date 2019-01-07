//
// Created by Julian on 20.10.18.
//

#ifndef ROSBRIDGECLIENT_JSON_CREATER_H
#define ROSBRIDGECLIENT_JSON_CREATER_H

#include <cpprest/json.h>
#include <rbc/msgs/xyzmessage.h>

#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/std_msgs/string.h>
#include <rbc/msgs/std_msgs/color_rgba.h>

#include <rbc/msgs/nav_msgs/odometry.h>

#include <rbc/msgs/sensor_msgs/imu.h>
#include <rbc/msgs/sensor_msgs/joy.h>
#include <rbc/msgs/sensor_msgs/image.h>
#include <rbc/msgs/sensor_msgs/temperature.h>
#include <rbc/msgs/sensor_msgs/joint_state.h>
#include <rbc/msgs/sensor_msgs/fluid_pressure.h>

#include <rbc/msgs/geometry_msgs/pose.h>
#include <rbc/msgs/geometry_msgs/accel.h>
#include <rbc/msgs/geometry_msgs/point.h>
#include <rbc/msgs/geometry_msgs/pose2d.h>
#include <rbc/msgs/geometry_msgs/wrench.h>
#include <rbc/msgs/geometry_msgs/inertia.h>
#include <rbc/msgs/geometry_msgs/point32.h>
#include <rbc/msgs/geometry_msgs/vector3.h>
#include <rbc/msgs/geometry_msgs/polygon.h>
#include <rbc/msgs/geometry_msgs/transform.h>
#include <rbc/msgs/geometry_msgs/quaternion.h>
#include <rbc/msgs/geometry_msgs/pose_array.h>
#include <rbc/msgs/geometry_msgs/pose_stamped.h>
#include <rbc/msgs/geometry_msgs/twist_stamped.h>
#include <rbc/msgs/geometry_msgs/point_stamped.h>
#include <rbc/msgs/geometry_msgs/accel_stamped.h>
#include <rbc/msgs/geometry_msgs/wrench_stamped.h>
#include <rbc/msgs/geometry_msgs/vector3_stamped.h>
#include <rbc/msgs/geometry_msgs/polygon_stamped.h>
#include <rbc/msgs/geometry_msgs/inertia_stamped.h>
#include <rbc/msgs/geometry_msgs/transform_stamped.h>
#include <rbc/msgs/geometry_msgs/quaternion_stamped.h>
#include <rbc/msgs/geometry_msgs/pose_with_covariance.h>
#include <rbc/msgs/geometry_msgs/pose_with_covariance.h>
#include <rbc/msgs/geometry_msgs/twist_with_covariance.h>
#include <rbc/msgs/geometry_msgs/accel_with_covariance.h>
#include <rbc/msgs/geometry_msgs/pose_with_covariance_stamped.h>
#include <rbc/msgs/geometry_msgs/twist_with_covariance_stamped.h>
#include <rbc/msgs/geometry_msgs/accel_with_covariance_stamped.h>

namespace rbc::utils
{

class Serializer
{
private:
  web::json::value json_;
  
public:
  Serializer();

  ~Serializer() = default;

  const web::json::value &json() const;

  web::json::value &serialize(const msgs::std_msgs::Header &header, bool sub_json = false);

  web::json::value &serialize(const msgs::std_msgs::String &string, bool sub_json = false);

  web::json::value &serialize(const msgs::std_msgs::ColorRGBA &rgba, bool sub_json = false);

  web::json::value &serialize(const msgs::nav_msgs::Odometry &o, bool sub_json = false);

  web::json::value &serialize(const msgs::sensor_msgs::Imu &imu, bool sub_json = false);

  web::json::value &serialize(const msgs::sensor_msgs::Joy &joy, bool sub_json = false);

  web::json::value &serialize(const msgs::sensor_msgs::Temperature &temp, bool sub_json = false);

  web::json::value &serialize(const msgs::sensor_msgs::JointState &js, bool sub_json = false);

  web::json::value &serialize(const msgs::sensor_msgs::FluidPressure &fp, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Pose2D &pose2d, bool sub_json = false);
  
  web::json::value &serialize(const msgs::geometry_msgs::PointStamped &point_stamped, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Pose &pose, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::PoseArray &pose_arr, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Polygon &polygon, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::PolygonStamped &polygon_stamp, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::PoseWithCovariance &pose_cov, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::PoseWithCovarianceStamped &pose_cov, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Accel &accel, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::AccelWithCovarianceStamped &accel_cov, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Inertia &inertia, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::AccelStamped &accel_stamped, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::TwistStamped &twist_stamped, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::TwistWithCovariance &twist_cov, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::AccelWithCovariance &accel_cov, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::TwistWithCovarianceStamped &twist_st_cov, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::InertiaStamped &inertia_stamped, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Wrench &wrench, bool sub_json = false);
  
  web::json::value &serialize(const msgs::geometry_msgs::WrenchStamped &wrench, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::PoseStamped &pose_stamped, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Vector3Stamped &vector3_stamped, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Quaternion &quaternion, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::QuaternionStamped &quaternion_stamped, bool sub_json = false);

  web::json::value &serialize(const msgs::geometry_msgs::Transform &transform, bool sub_json = false);
  
  web::json::value &serialize(const msgs::geometry_msgs::TransformStamped &transform_stamped, bool sub_json = false);

  web::json::value &completeJson(const msgs::ROSTypeBase &msg, const web::json::value &sub_json);

  std::vector<web::json::value> &serializeSinglesStr(const std::vector<std::string> &vec);

  template <typename T>
  web::json::value &serialize(const msgs::std_msgs::StdMsg<T> &msg, bool sub_json = false);

  template<typename T>
  web::json::value &serialize(const msgs::XYZMessage<T> &xyz, bool sub_json = false);

  template <std::uint32_t HEIGTH, std::uint32_t WIDTH>
  web::json::value &serialize(const msgs::sensor_msgs::Image<HEIGTH, WIDTH> &image, bool sub_json = false);

  template <typename T, unsigned int N>
  std::vector<web::json::value> &serializeSingles(const std::array<T, N> &data);
private:

  template <typename T>
  std::vector<web::json::value> &serialize(const std::vector<T> &vec);

  template <typename T>
  std::vector<web::json::value> &serializeSingles(const std::vector<T> &vec);
};

template<typename T>
web::json::value &Serializer::serialize(const msgs::XYZMessage<T> &xyz, bool sub_json)
{
  static web::json::value json_xyz;
  json_xyz[U("x")] = xyz.x;
  json_xyz[U("y")] = xyz.y;
  json_xyz[U("z")] = xyz.z;

  return not sub_json ? completeJson(xyz, json_xyz) : json_xyz;
}

template<typename T>
web::json::value &Serializer::serialize(const msgs::std_msgs::StdMsg<T> &msg, bool sub_json)
{
  static web::json::value json_msg;

  json_msg[U("data")] = web::json::value(msg.data);

  return not sub_json ? completeJson(msg, json_msg) : json_msg;
}

template<typename T, unsigned int N>
std::vector<web::json::value> &Serializer::serializeSingles(const std::array<T, N> &data)
{
  static std::vector<web::json::value> array;
  array.clear();
  array.reserve(data.size());

  for (const auto& num: data)
  {
    array.push_back(web::json::value(num));
  }

  return array;
}

template <typename T>
std::vector<web::json::value> &Serializer::serialize(const std::vector<T> &vec)
{
  static std::vector<web::json::value> array;
  array.clear();
  array.reserve(vec.size());

  for (const auto& point: vec)
  {
    array.push_back(serialize(point, true));
  }

  return array;
}

template <typename T>
std::vector<web::json::value> &Serializer::serializeSingles(const std::vector<T> &vec)
{
  static std::vector<web::json::value> array;
  array.clear();
  array.reserve(vec.size());

  for (const auto& v: vec)
  {
    array.push_back(web::json::value(v));
  }

  return array;
}

template<uint32_t HEIGHT, uint32_t WIDTH>
web::json::value &Serializer::serialize(const Image<HEIGHT, WIDTH> &image, bool sub_json)
{
  static web::json::value image_json;

  image_json[U("header")] = serialize(image.header, true);
  image_json[U("height")] = web::json::value(image.height);
  image_json[U("width")] = web::json::value(image.width);
  image_json[U("encoding")] = web::json::value::string(image.encoding);
  image_json[U("is_bigendian")] = web::json::value(image.is_bigendian);
  image_json[U("step")] = web::json::value(image.step);
  image_json[U("data")] = web::json::value::array(serializeSingles<std::uint8_t, HEIGHT*WIDTH>(image.data));

  return not sub_json ? completeJson(image, image_json) : image_json;
}

} // namespace namespace rbc::util

#endif //ROSBRIDGECLIENT_JSON_CREATER_H
