//
// Created by julian on 01.11.18.
//

#ifndef ROSBRIDGECLIENT_ACCEL_STAMPED_H
#define ROSBRIDGECLIENT_ACCEL_STAMPED_H

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
#include <ros_bridge_client/msgs/message_base.h>

namespace ros_bridge_client
{

namespace msgs
{

namespace geometry_msgs
{

struct AccelStamped : public MessageBase
{
  AccelStamped(std::string ros_msg_type = "geometry_msgs/AccelStamped");

  AccelStamped(const Accel &accel, std::string frame_id, std::string ros_msg_type = "geometry_msgs/AccelStamped");

  AccelStamped(const Vector3 &linear, const Vector3 &angular, std::string frame_id,
               std::string ros_msg_type = "geometry_msgs/AccelStamped");

  AccelStamped(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id,
               std::string ros_msg_type = "geometry_msgs/AccelStamped");

  explicit AccelStamped(const web::json::value &response, std::string ros_msg_type = "geometry_msgs/AccelStamped");

  ~AccelStamped() override = default;

  std_msgs::Header header;
  Accel accel;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::AccelStamped &a);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::AccelStamped> &a);


#endif //ROSBRIDGECLIENT_ACCEL_STAMPED_H
