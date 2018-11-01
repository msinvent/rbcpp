//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_QUATERNION_STAMPED_MESSAGE_H
#define ROSBRIDGECLIENT_QUATERNION_STAMPED_MESSAGE_H

#include <ros_bridge_client/msgs/geometry_msgs/quaternion_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class QuaternionStampedMessage : public QuaternionMessage
{
public:
  QuaternionStampedMessage() = delete;

  explicit QuaternionStampedMessage(ros_bridge_client::ros_types::Quaternion q, std::string frame_id = "world");

  QuaternionStampedMessage(const double x, const double y, const double z, const double w,
                           std::string frame_id = "world");

  ~QuaternionStampedMessage() final = default;

private:
  const std::string ros_type;
  const std::string frame_id;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_QUATERNION_STAMPED_MESSAGE_H
