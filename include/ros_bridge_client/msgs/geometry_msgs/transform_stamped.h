//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_TRANSFORM_STAMPED_HPP
#define ROSBRIDGECLIENT_TRANSFORM_STAMPED_HPP

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <memory>
#include <iostream>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct TransformStamped : public ROSTypeBase
{
  TransformStamped(std::string frame_id = "world");

  TransformStamped(const Vector3 &translation, const Quaternion &rotation, std::string frame_id);

  TransformStamped(double tx, double ty, double tz, double rx, double ry, double rz, double rw, std::string frame_id);

  explicit TransformStamped(const web::json::value &response);

  ~TransformStamped() override = default;

  std_msgs::Header header;
  Transform transform;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<< (std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::TransformStamped &t);

std::ostream &
operator<< (std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::TransformStamped> &t);

#endif //ROSBRIDGECLIENT_TRANSFORM_STAMPED_HPP
