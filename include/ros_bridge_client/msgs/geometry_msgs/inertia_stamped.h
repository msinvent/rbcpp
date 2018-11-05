//
// Created by julian on 02.11.18.
//

#ifndef ROSBRIDGECLIENT_INERTIA_STAMPED_H
#define ROSBRIDGECLIENT_INERTIA_STAMPED_H

#include <ros_bridge_client/msgs/message_base.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

struct InertiaStamped : public MessageBase
{
  InertiaStamped();

  InertiaStamped(std::string frame_id);

  InertiaStamped(const Inertia &inertia, std::string frame_id);

  InertiaStamped(double m, const Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz, double izz,
                 std::string frame_id);

  explicit InertiaStamped(const web::json::value &response);

  ~InertiaStamped() override = default;

  std_msgs::Header header;
  Inertia inertia;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_INERTIA_STAMPED_H
