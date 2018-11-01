//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_WRENCH_STAMPED_MESSAGE_HPP
#define ROSBRIDGECLIENT_WRENCH_STAMPED_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench_message.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class WrenchStampedMessage : public WrenchMessage
{
public:
  WrenchStampedMessage() = delete;

  WrenchStampedMessage(const ros_types::Vector3 &force, const ros_types::Vector3 &torque,
                       std::string frame_id = "world");

  ~WrenchStampedMessage() final = default;

private:
  const std::string ros_msg_type;
  const std::string frame_id;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_WRENCH_STAMPED_MESSAGE_HPP