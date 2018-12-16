//
// Created by Julian
//

#include <rbc/msgs/std_msgs/color_rgba_message.h>

using namespace rbc::msgs::std_msgs;
using namespace web;

ColorRGBAMessage::ColorRGBAMessage(float r, float g, float b, float a)
  : ros_msg_type("std_msgs/ColorRGBA")
{
  rgba.r = r;
  rgba.g = g;
  rgba.b = b;
  rgba.a = a;

  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}


ColorRGBAMessage::ColorRGBAMessage(const rbc::ros_types::ColorRGBA &r)
  : ros_msg_type("std_msgs/ColorRGBA")
{
  rgba = r;

  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value ColorRGBAMessage::createJsonMsg() const
{
  json::value color_rgba_message_json;
  color_rgba_message_json[U("r")] = rgba.r;
  color_rgba_message_json[U("g")] = rgba.g;
  color_rgba_message_json[U("b")] = rgba.b;
  color_rgba_message_json[U("a")] = rgba.a;
  return color_rgba_message_json;
}
