//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINTSTAMPEDMESSAGE_HPP
#define ROSBRIDGECLIENT_POINTSTAMPEDMESSAGE_HPP

#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/message_base.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct PointStamped : public MessageBase
{
public:
  PointStamped();

  PointStamped(double x, double y, double z, std::string frame_id = "world");

  explicit PointStamped(const web::json::value &response);

  ~PointStamped() = default;

  std_msgs::Header header;
  Point point;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::PointStamped &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::PointStamped> &p);

#endif //ROSBRIDGECLIENT_POINTSTAMPEDMESSAGE_HPP
