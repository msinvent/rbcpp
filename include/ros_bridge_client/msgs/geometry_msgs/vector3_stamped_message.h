//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_VECTOR3_STAMPED_H
#define ROSBRIDGECLIENT_VECTOR3_STAMPED_H

#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class Vector3StampedMessage : public Vector3Message
{
public:
  Vector3StampedMessage() = delete;

  Vector3StampedMessage(double x, double y, double z, std::string frame_id = "world");

  Vector3StampedMessage(const ros_types::Vector3 &vec, std::string frame_id = "world");

  ~Vector3StampedMessage() final = default;

private:
  const std::string ros_type;
  const std::string frame_id;

  web::json::value createJsonMsg() const;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_VECTOR3_STAMPED_H
