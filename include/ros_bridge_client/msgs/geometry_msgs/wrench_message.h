//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_WRENCH_MESSAGE_HPP
#define ROSBRIDGECLIENT_WRENCH_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class WrenchMessage : public RBCMessage
{
public:
  WrenchMessage() = delete;

  WrenchMessage(const ros_types::Vector3 &force, const ros_types::Vector3 &torque);

  ~WrenchMessage() override = default;

private:
  const ros_types::Vector3 &force;
  const ros_types::Vector3 &torque;
  const std::string ros_msg_type;

  web::json::value createJsonMsg() const override;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_WRENCH_MESSAGE_HPP