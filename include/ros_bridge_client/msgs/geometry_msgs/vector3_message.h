//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_VECTOR3_MESSAGE_H
#define ROSBRIDGECLIENT_VECTOR3_MESSAGE_H

#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class Vector3Message : public Point
{
public:
  Vector3Message() = delete;

  explicit Vector3Message(const ros_types::Vector3 &vec);

  Vector3Message(const double x, const double y, const double z);

  ~Vector3Message() override = default;

private:
  const std::string ros_type;
};


} // namespace geometry_msgs
} // namesapce msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_VECTOR3_MESSAGE_H
