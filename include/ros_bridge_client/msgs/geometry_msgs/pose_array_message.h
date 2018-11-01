//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_POSE_ARRAY_MESSAGE_HPP
#define ROSBRIDGECLIENT_POSE_ARRAY_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_array_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class PoseArrayMessage : public RBCArrayMessage
{
public:
  PoseArrayMessage() = delete;

  PoseArrayMessage(std::string frame_id);

  ~PoseArrayMessage() final = default;

  void add(const ros_bridge_client::ros_types::Pose &pose);

  void add(float x, float y, float z, float xx, float yy, float zz, float ww);

private:
  const std::string ros_msg_type;
  const std::string frame_id;
  const std::string array_descriptor;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_POSE_ARRAY_MESSAGE_HPP