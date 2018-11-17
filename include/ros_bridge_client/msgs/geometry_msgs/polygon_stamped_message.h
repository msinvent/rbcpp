//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_POLYGON_STAMPED_MESSAGE_HPP
#define ROSBRIDGECLIENT_POLYGON_STAMPED_MESSAGE_HPP

#include <ros_bridge_client/ros_types/ros_types.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon_message.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

class PolygonStampedMessage : public PolygonMessage
{
public:
  PolygonStampedMessage() = delete;

  PolygonStampedMessage(std::string frame_id = "world");

  PolygonStampedMessage(const ros_bridge_client::ros_types::Point32 &point, std::string frame_id = "world");

  ~PolygonStampedMessage() final = default;

private:
  const std::string ros_msg_type;
  const std::string frame_id;

  web::json::value createJsonMsg() const final;
};

} // namespace ros_bridge_client::msgs::geometry_msgs


#endif //ROSBRIDGECLIENT_POLYGON_STAMPED_MESSAGE_HPP