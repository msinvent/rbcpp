//
// Created by Julian on 20.10.18.
//

#ifndef ROSBRIDGECLIENT_JSON_CREATER_H
#define ROSBRIDGECLIENT_JSON_CREATER_H

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/xyzmessage.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/std_msgs/string.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/msgs/std_msgs/color_rgba.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose2d.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_with_covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_with_covariance_stamped.h>

namespace ros_bridge_client::utils
{

class Serializer
{
private:
  web::json::value json_;
  
public:
  Serializer();

  ~Serializer() = default;

  const web::json::value &json() const;

  web::json::value &toJson(const msgs::std_msgs::Header &header, bool sub_json = false);

  web::json::value &toJson(const msgs::std_msgs::String &string, bool sub_json = false);

  web::json::value &toJson(const msgs::std_msgs::ColorRGBA &rgba, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Pose2D &pose2d, bool sub_json = false);
  
  web::json::value &toJson(const msgs::geometry_msgs::PointStamped &point_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Pose &pose, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Polygon &polygon, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::PolygonStamped &polygon_stamp, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::PoseWithCovariance &pose_cov, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::PoseWithCovarianceStamped &pose_cov, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Accel &accel, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::AccelWithCovarianceStamped &accel_cov, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Inertia &inertia, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::AccelStamped &accel_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::TwistStamped &twist_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::TwistWithCovariance &twist_cov, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::AccelWithCovariance &accel_cov, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::TwistWithCovarianceStamped &twist_st_cov, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::InertiaStamped &inertia_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Wrench &wrench, bool sub_json = false);
  
  web::json::value &toJson(const msgs::geometry_msgs::WrenchStamped &wrench, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::PoseStamped &pose_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Vector3Stamped &vector3_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Quaternion &quaternion, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::QuaternionStamped &quaternion_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Transform &transform, bool sub_json = false);
  
  web::json::value &toJson(const msgs::geometry_msgs::TransformStamped &transform_stamped, bool sub_json = false);

  web::json::value &completeJson(const msgs::ROSTypeBase &msg, const web::json::value &sub_json);

  template <typename T>
  web::json::value &toJson(const msgs::std_msgs::StdMsg<T> &msg, bool sub_json = false);

  template<typename T>
  web::json::value &toJson(const msgs::XYZMessage<T> &xyz, bool sub_json = false);

private:
  template <typename T, unsigned int N>
  std::vector<web::json::value> &toJsonArray(const std::array<T, N> &data);

  std::vector<web::json::value> &toJson(const std::vector<msgs::geometry_msgs::Point32> &vec);
};

template<typename T>
web::json::value &Serializer::toJson(const msgs::XYZMessage<T> &xyz, bool sub_json)
{
  static web::json::value json_xyz;
  json_xyz[U("x")] = xyz.x;
  json_xyz[U("y")] = xyz.y;
  json_xyz[U("z")] = xyz.z;

  return not sub_json ? completeJson(xyz, json_xyz) : json_xyz;
}

template<typename T>
web::json::value &Serializer::toJson(const msgs::std_msgs::StdMsg<T> &msg, bool sub_json)
{
  static web::json::value json_msg;
  
  json_msg[U("data")] = web::json::value(msg.data);

  return not sub_json ? completeJson(msg, json_msg) : json_msg;
}

template<typename T, unsigned int N>
std::vector<web::json::value> &Serializer::toJsonArray(const std::array<T, N> &data)
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

} // namespace namespace ros_bridge_client::util

#endif //ROSBRIDGECLIENT_JSON_CREATER_H
