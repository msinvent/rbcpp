//
// Created by julian on 22.11.18.
//

#ifndef ROSBRIDGECLIENT_COLOR_RGBA_H
#define ROSBRIDGECLIENT_COLOR_RGBA_H

#include <ros_bridge_client/msgs/message_base.h>
#include <cpprest/json.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct ColorRGBA : public MessageBase
{
  ColorRGBA();

  ColorRGBA(float r, float g, float b, float a);

  explicit ColorRGBA(const web::json::value &response);

  ~ColorRGBA() final = default;

  float r, g, b, a;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_COLOR_RGBA_H
