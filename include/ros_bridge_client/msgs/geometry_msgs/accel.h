//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_ACCEL_HPP
#define ROSBRIDGECLIENT_ACCEL_HPP

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/message_base.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <memory>
#include <iostream>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

struct Accel : public MessageBase
{
  Accel();

  Accel(double lx, double ly, double lz, double ax, double ay, double az);

  Accel(const Vector3 &linear, const Vector3 &angular);

  explicit Accel(const web::json::value &response);

  ~Accel() override = default;

  Vector3 linear;
  Vector3 angular;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Accel &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Accel> &p);

#endif //ROSBRIDGECLIENT_ACCEL_HPP