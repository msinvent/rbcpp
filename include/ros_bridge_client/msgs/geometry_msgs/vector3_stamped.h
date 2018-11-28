//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_VECTOR3_STAMPED_HPP
#define ROSBRIDGECLIENT_VECTOR3_STAMPED_HPP

#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/ros_type_base.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct Vector3Stamped : public ROSTypeBase
{
public:
  Vector3Stamped();

  Vector3Stamped(double x, double y, double z, std::string frame_id = "world");

  explicit Vector3Stamped(const web::json::value &response);

  ~Vector3Stamped() override = default;

  std_msgs::Header header;
  Vector3 vector;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Vector3Stamped &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Vector3Stamped> &p);

#endif //ROSBRIDGECLIENT_VECTOR3_STAMPED_HPP
