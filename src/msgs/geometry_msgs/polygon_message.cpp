//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/polygon_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32_message.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

PolygonMessage::PolygonMessage()
  : RBCArrayMessage("points"),
    ros_msg_type("geometry_msgs/Polygon")
{
  json[U("type")] = json::value::string(ros_msg_type);
}

PolygonMessage::PolygonMessage(std::string array_descriptor)
  : RBCArrayMessage(array_descriptor),
    ros_msg_type("geometry_msgs/Polygon")
{
  json[U("type")] = json::value::string(ros_msg_type);
}

PolygonMessage::PolygonMessage(const ros_bridge_client::ros_types::Point32 &point)
  : RBCArrayMessage("points"),
    ros_msg_type("geometry_msgs/Polygon")
{
  json[U("type")] = json::value::string(ros_msg_type);
  add(point);
}

void PolygonMessage::add(const ros_bridge_client::ros_types::Point32 &point)
{
  using namespace ros_bridge_client::msgs::geometry_msgs;
  Point32Message point_message(point);

  auto &current_cells = json.at(U("msg")).at(U(array_descriptor)).as_array();
  current_cells[next_index()] = point_message.getJsonAt("msg");
}
