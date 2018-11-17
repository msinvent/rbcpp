//
// Created by julian on 01.11.18.
//

#ifndef ROSBRIDGECLIENT_WRENCH_STAMPED_H
#define ROSBRIDGECLIENT_WRENCH_STAMPED_H

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench.h>
#include <ros_bridge_client/msgs/message_base.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct WrenchStamped : public MessageBase
{
  WrenchStamped();

  WrenchStamped(const Wrench &accel, std::string frame_id);

  WrenchStamped(const Vector3 &force, const Vector3 &torque, std::string frame_id);

  WrenchStamped(double fx, double fy, double fz, double tx, double ty, double tz, std::string frame_id);

  explicit WrenchStamped(const web::json::value &response);

  ~WrenchStamped() override = default;
  
  std_msgs::Header header;
  Wrench wrench;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::WrenchStamped &a);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::WrenchStamped> &a);


#endif //ROSBRIDGECLIENT_WRENCH_STAMPED_H
