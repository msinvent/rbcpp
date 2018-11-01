//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_INERTIA_MESSAGE_HPP
#define ROSBRIDGECLIENT_INERTIA_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class InertiaMessage : public RBCMessage
{
public:
  InertiaMessage() = delete;

  InertiaMessage(double m, const ros_bridge_client::ros_types::Vector3 &com, double ixx, double ixy, double ixz,
                 double iyy,
                 double iyz, double izz);

  ~InertiaMessage() override = default;

private:
  const std::string ros_msg_type;
  const double m;
  const ros_bridge_client::ros_types::Vector3 &com;
  const double ixx;
  const double ixy;
  const double ixz;
  const double iyy;
  const double iyz;
  const double izz;

  web::json::value createJsonMsg() const override;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_INERTIA_MESSAGE_HPP