//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_POSE2_D_MESSAGE_HPP
#define ROSBRIDGECLIENT_POSE2_D_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>
#include "ros_bridge_client/ros_types/ros_types.h"

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class Pose2DMessage : public RBCMessage
{
public:
  Pose2DMessage() = delete;

  Pose2DMessage(double x, double y, double theta);

  explicit Pose2DMessage(const ros_types::Pose2D &pose_2d);

  ~Pose2DMessage() final = default;

private:
  const std::string ros_msg_type;
  ros_types::Pose2D pose_2d;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_POSE2_D_MESSAGE_HPP