//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_TRANSFORM_STAMPED_MESSAGE_HPP
#define ROSBRIDGECLIENT_TRANSFORM_STAMPED_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform_message.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class TransformStampedMessage : public TransformMessage
{
public:
  TransformStampedMessage() = delete;

  TransformStampedMessage(const ros_types::Vector3 &translation, const ros_types::Quaternion &rotation,
                          std::string child_frame_id = "world");

  ~TransformStampedMessage() final = default;

private:
  const std::string ros_msg_type;
  const std::string child_frame_id;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_TRANSFORM_STAMPED_MESSAGE_HPP