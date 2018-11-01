//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_COLOR_RGBA_MESSAGE_HPP
#define ROSBRIDGECLIENT_COLOR_RGBA_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

class ColorRGBAMessage : public RBCMessage
{
public:
  ColorRGBAMessage() = delete;

  explicit ColorRGBAMessage(const ros_types::ColorRGBA &q);

  ColorRGBAMessage(float r, float g, float b, float a);

  ~ColorRGBAMessage() override = default;

private:
  const std::string ros_msg_type;
  ros_types::ColorRGBA rgba;

  web::json::value createJsonMsg() const final;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_COLOR_RGBA_MESSAGE_HPP