//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_GRID_CELLS_MESSAGE_HPP
#define ROSBRIDGECLIENT_GRID_CELLS_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32_message.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace nav_msgs
{

class GridCellsMessage : public RBCMessage
{
public:
  GridCellsMessage(float cell_width, float cell_height, std::string frame_id = "world");

  GridCellsMessage() = delete;

  ~GridCellsMessage() final = default;

  void add(const ros_bridge_client::ros_types::Point32 &point);

private:
  const std::string ros_msg_type;
  const std::string frame_id;
  const float cell_width;
  const float cell_height;

  size_t next_index() const;

  web::json::value createJsonMsg() const final;
};

} // namespace nav_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_GRID_CELLS_MESSAGE_HPP