//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_POSE_MESSAGE_H
#define ROSBRIDGECLIENT_POSE_MESSAGE_H

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class PoseMessage : public RBCMessage
{
public:
  PoseMessage() = delete;

  PoseMessage(const ros_bridge_client::ros_types::Pose &pose);

  PoseMessage(const ros_bridge_client::ros_types::Point &position,
              const ros_bridge_client::ros_types::Quaternion &orientation);

  PoseMessage(double x, double y, double z, double xx, double yy, double zz, double ww);

  ~PoseMessage() override = default;

private:
  const std::string ros_type;
protected:
  ros_bridge_client::ros_types::Point position;
  ros_bridge_client::ros_types::Quaternion orientation;

  web::json::value createJsonMsg() const override;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_POSE_MESSAGE_H
