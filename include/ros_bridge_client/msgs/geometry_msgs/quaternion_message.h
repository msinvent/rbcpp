//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_QUATERNION_MESSAGE_H
#define ROSBRIDGECLIENT_QUATERNION_MESSAGE_H

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class QuaternionMessage : public RBCMessage
{
public:
  QuaternionMessage() = delete;

  explicit QuaternionMessage(ros_bridge_client::ros_types::Quaternion q);

  QuaternionMessage(const double x, const double y, const double z, const double w);

  ~QuaternionMessage() override = default;

private:
  const std::string ros_type;
protected:
  ros_bridge_client::ros_types::Quaternion quaternion;

  web::json::value createJsonMsg() const override;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_QUATERNION_MESSAGE_H
