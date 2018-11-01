//
// Created by Julian on 06.10.18.
//

#ifndef ROSBRIDGECLIENT_POSE_STAMPED_H
#define ROSBRIDGECLIENT_POSE_STAMPED_H

#include <ros_bridge_client/msgs/geometry_msgs/pose_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class PoseStampedMessage : public PoseMessage
{
public:
  PoseStampedMessage() = delete;

  PoseStampedMessage(const ros_bridge_client::ros_types::Pose &pose, std::string frame_id = "world");

  PoseStampedMessage(const ros_types::Point &position, const ros_bridge_client::ros_types::Quaternion &orientation,
                     std::string frame_id = "world");

  PoseStampedMessage(double x, double y, double z, double xx, double yy, double zz, double ww,
                     std::string frame_id = "world");

  ~PoseStampedMessage() final = default;

private:
  const std::string frame_id;
  const std::string ros_type;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_POSE_STAMPED_H
