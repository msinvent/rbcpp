//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_POLYGON_MESSAGE_HPP
#define ROSBRIDGECLIENT_POLYGON_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_array_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class PolygonMessage : public RBCArrayMessage
{
public:
  PolygonMessage();

  PolygonMessage(const ros_bridge_client::ros_types::Point32 &point);

  ~PolygonMessage() override = default;

  virtual void add(const ros_bridge_client::ros_types::Point32 &Point);

protected:
  explicit PolygonMessage(std::string array_descriptor);

private:
  const std::string ros_msg_type;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_POLYGON_MESSAGE_HPP