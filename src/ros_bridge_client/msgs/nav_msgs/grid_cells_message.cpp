//
// Created by Julian
//
#include <ros_bridge_client/msgs/nav_msgs/grid_cells_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::nav_msgs;
using namespace web;

GridCellsMessage::GridCellsMessage(float cell_width, float cell_height, std::string frame_id)
  : ros_msg_type("nav_msgs/GridCells"),
    frame_id(frame_id),
    cell_width(cell_width),
    cell_height(cell_height)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value GridCellsMessage::createJsonMsg() const
{
  json::value nav_msgs_json;

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header_message(frame_id);
  nav_msgs_json[U("header")] = header_message.getJsonAt("msg");

  nav_msgs_json[U("cell_width")] = cell_width;
  nav_msgs_json[U("cell_height")] = cell_height;
  nav_msgs_json[U("cells")] = json::value::array();
  return nav_msgs_json;
}

void GridCellsMessage::add(const ros_bridge_client::ros_types::Point32 &point)
{
  json::value point_json;

  using namespace ros_bridge_client::msgs::geometry_msgs;
  Point32Message point_message(point.x, point.y, point.z);

  auto &current_cells = json.at(U("msg")).at(U("cells")).as_array();
  current_cells[next_index()] = point_message.getJsonAt("msg");
}

size_t GridCellsMessage::next_index() const
{
  const auto &array = json.at(U("msg")).at(U("cells")).as_array();
  return std::distance(array.begin(), array.end());
}
