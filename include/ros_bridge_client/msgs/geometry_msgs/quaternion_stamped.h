//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_QUATERNION_STAMPEDMESSAGE_HPP
#define ROSBRIDGECLIENT_QUATERNION_STAMPEDMESSAGE_HPP

#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <ros_bridge_client/msgs/ros_type_base.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct QuaternionStamped : public ROSTypeBase
{
public:
  QuaternionStamped();

  QuaternionStamped(double x, double y, double z, double w, std::string frame_id = "world");

  explicit QuaternionStamped(const web::json::value &response);

  ~QuaternionStamped() override = default;

  std_msgs::Header header;
  Quaternion quaternion;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::QuaternionStamped &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::QuaternionStamped> &p);

#endif //ROSBRIDGECLIENT_QUATERNION_STAMPEDMESSAGE_HPP
