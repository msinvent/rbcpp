//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_TRANSFORM_HPP
#define ROSBRIDGECLIENT_TRANSFORM_HPP

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/message_base.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <memory>
#include <iostream>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

struct Transform : public MessageBase
{
  Transform();

  Transform(double tx, double ty, double tz, double rx, double ry, double rz, double rw);

  Transform(const Vector3 &translation, const Quaternion &rotation);

  explicit Transform(const web::json::value &response);

  ~Transform() override = default;

  Vector3 translation;
  Quaternion rotation;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Transform &t);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Transform> &t);

#endif //ROSBRIDGECLIENT_TRANSFORM_HPP