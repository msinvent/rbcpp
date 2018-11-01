//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_TRANSFORM_MESSAGE_HPP
#define ROSBRIDGECLIENT_TRANSFORM_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class TransformMessage : public RBCMessage
{
public:
  TransformMessage() = delete;

  TransformMessage(const ros_types::Vector3 &translation, const ros_types::Quaternion &rotation);

  ~TransformMessage() override = default;

private:
  const ros_types::Vector3 &translation;
  const ros_types::Quaternion &rotation;
  const std::string ros_msg_type;

  web::json::value createJsonMsg() const override;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_TRANSFORM_MESSAGE_HPP