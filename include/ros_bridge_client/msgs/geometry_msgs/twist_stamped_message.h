//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_TWIST_STAMPED_MESSAGE_HPP
#define ROSBRIDGECLIENT_TWIST_STAMPED_MESSAGE_HPP

#include <ros_bridge_client/msgs/geometry_msgs/twist_message.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class TwistStampedMessage : public TwistMessage
{
public:
  TwistStampedMessage() = delete;

  TwistStampedMessage(const ros_types::Vector3 &linear, const ros_types::Vector3 &angular,
                      std::string frame_id = "world");

  TwistStampedMessage(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id = "world");

  ~TwistStampedMessage() final = default;

private:
  const std::string ros_msg_type;
  const std::string frame_id;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_TWIST_STAMPED_MESSAGE_HPP