//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINT32_MESSAGE_HPP
#define ROSBRIDGECLIENT_POINT32_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class Point32Message : public RBCMessage
{
public:
  Point32Message() = delete;

  explicit Point32Message(ros_bridge_client::ros_types::Point32 p);

  Point32Message(const float x, const float y, const float z);

  ~Point32Message() override = default;

private:
  const std::string ros_type;
protected:
  ros_bridge_client::ros_types::Point32 point;

  web::json::value createJsonMsg() const override;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_POINT32_MESSAGE_HPP
