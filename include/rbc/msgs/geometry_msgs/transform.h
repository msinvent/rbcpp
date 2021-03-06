//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_TRANSFORM_HPP
#define ROSBRIDGECLIENT_TRANSFORM_HPP

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/geometry_msgs/vector3.h>
#include <rbc/msgs/geometry_msgs/quaternion.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct Transform : public ROSTypeBase
{
  Transform();

  Transform(double tx, double ty, double tz, double rx, double ry, double rz, double rw);

  Transform(const Vector3 &translation, const Quaternion &rotation);

  explicit Transform(const web::json::value &response);

  ~Transform() override = default;

  Vector3 translation;
  Quaternion rotation;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Transform &t);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Transform> &t);

#endif //ROSBRIDGECLIENT_TRANSFORM_HPP