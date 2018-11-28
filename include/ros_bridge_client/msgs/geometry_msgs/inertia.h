//
// Created by julian on 02.11.18.
//

#ifndef ROSBRIDGECLIENT_INERTIA_H
#define ROSBRIDGECLIENT_INERTIA_H

#include <ros_bridge_client/msgs/ros_type_base.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct Inertia : public ROSTypeBase
{
  Inertia();

  Inertia(const Inertia &inertia);
  
  Inertia(double m, const Vector3 &com, double ixx, double ixy, double ixz,
          double iyy,
          double iyz, double izz);

  explicit Inertia(const web::json::value &response);

  ~Inertia() override = default;

  double m, ixx, ixy, ixz, iyy, iyz, izz;
  Vector3 com;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Inertia &i);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Inertia> &i);

#endif //ROSBRIDGECLIENT_INERTIA_H
