//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_INERTIA_STAMPED_MESSAGE_HPP
#define ROSBRIDGECLIENT_INERTIA_STAMPED_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia_message.h>
#include "inertia_message.h"

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class InertiaStampedMessage : public InertiaMessage
{
public:
  InertiaStampedMessage() = delete;

  InertiaStampedMessage(double m, const ros_bridge_client::ros_types::Vector3 &com, double ixx, double ixy, double ixz,
                        double iyy,
                        double iyz, double izz, std::string frame_id = "world");

  ~InertiaStampedMessage() final = default;

private:
  const std::string ros_msg_type;
  const std::string frame_id;

  web::json::value createJsonMsg() const final;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_INERTIA_STAMPED_MESSAGE_HPP