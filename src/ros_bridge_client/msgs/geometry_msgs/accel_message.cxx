//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/accel_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

Accel::Accel(const ros_types::Vector3 &linear, const ros_types::Vector3 &angular)
  : linear_msg(linear.x, linear.y, linear.z),
    angular_msg(angular.x, angular.y, angular.z),
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

Accel::Accel(double lx, double ly, double lz, double ax, double ay, double az)
  : linear_msg(lx, ly, lz),
    angular_msg(ax, ay, az),
    ros_msg_type("geometry_msgs/Accel")
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

Accel::Accel(const web::json::value &msg)
  : linear_msg(msg.at("msg").at("linear").at("x").as_double(), msg.at("msg").at("angular").at("y").as_double(),
               msg.at("msg").at("angular").at("z").as_double()),
    angular_msg(msg.at("msg").at("angular").at("x").as_double(), msg.at("msg").at("angular").at("y").as_double(),
                msg.at("msg").at("angular").at("z").as_double()),
    ros_msg_type("geometry_msgs/Accel")
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = msg.at("msg");
}

json::value Accel::createJsonMsg() const
{
  json::value geometry_msgs_json;

  geometry_msgs_json[U("linear")] = linear_msg.getJsonAt("msg");
  geometry_msgs_json[U("angular")] = angular_msg.getJsonAt("msg");

  return geometry_msgs_json;
}
