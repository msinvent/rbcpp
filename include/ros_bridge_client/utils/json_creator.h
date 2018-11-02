//
// Created by Julian on 20.10.18.
//

#ifndef ROSBRIDGECLIENT_JSON_CREATER_H
#define ROSBRIDGECLIENT_JSON_CREATER_H

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/xyzmessage.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped.h>

namespace ros_bridge_client
{

namespace utils
{

class JsonCreator
{
private:
  web::json::value json_;
public:
  JsonCreator();

  ~JsonCreator() = default;

  const web::json::value &json() const;

  template<typename T>
  web::json::value &toJson(const msgs::XYZMessage<T> &xyz, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::PointStamped &point_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Pose &pose, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Accel &accel, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Inertia &inertia, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::AccelStamped &accel_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::PoseStamped &pose_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Vector3Stamped &vector3_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::Quaternion &quaternion, bool sub_json = false);

  web::json::value &toJson(const msgs::geometry_msgs::QuaternionStamped &quaternion_stamped, bool sub_json = false);

  web::json::value &toJson(const msgs::std_msgs::Header &header, bool sub_json = false);

  web::json::value &completeJson(const msgs::MessageBase &msg, const web::json::value &sub_json);
};

template<typename T>
web::json::value &JsonCreator::toJson(const msgs::XYZMessage<T> &xyz, bool sub_json)
{
  static web::json::value json_xyz;
  json_xyz[U("x")] = xyz.x;
  json_xyz[U("y")] = xyz.y;
  json_xyz[U("z")] = xyz.z;

  return not sub_json ? completeJson(xyz, json_xyz) : json_xyz;
}

} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_JSON_CREATER_H
