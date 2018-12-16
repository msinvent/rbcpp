//
// Created by julian on 22.11.18.
//

#ifndef ROSBRIDGECLIENT_COLOR_RGBA_H
#define ROSBRIDGECLIENT_COLOR_RGBA_H

#include <rbc/msgs/ros_type_base.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct ColorRGBA : public ROSTypeBase
{
  ColorRGBA();

  ColorRGBA(float r, float g, float b, float a);

  explicit ColorRGBA(const web::json::value &response);

  ~ColorRGBA() final = default;

  float r, g, b, a;
};

std::ostream &operator<<(std::ostream &os, const ColorRGBA &c);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<ColorRGBA> &c);

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_COLOR_RGBA_H
