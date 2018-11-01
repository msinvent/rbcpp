//
// Created by Julian
//
#ifndef ROSBRIDGECLIENT_TWIST_MESSAGE_HPP
#define ROSBRIDGECLIENT_TWIST_MESSAGE_HPP

#include <ros_bridge_client/msgs/geometry_msgs/accel_message.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

class TwistMessage : public Accel
{
public:
  TwistMessage() = delete;

  TwistMessage(const ros_types::Vector3 &linear, const ros_types::Vector3 &angular);

  TwistMessage(double lx, double ly, double lz, double ax, double ay, double az);

  ~TwistMessage() override = default;

private:
  const std::string ros_msg_type;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client::msgs


#endif //ROSBRIDGECLIENT_TWIST_MESSAGE_HPP
