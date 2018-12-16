//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_VECTOR3_HPP
#define ROSBRIDGECLIENT_VECTOR3_HPP

#include <cpprest/json.h>
#include <rbc/msgs/xyzmessage.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct Vector3 : public XYZMessage<double>
{
  Vector3();

  Vector3(double x, double y, double z);

  Vector3(const Vector3 &vec);

  explicit Vector3(const web::json::value &response);

  ~Vector3() override = default;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Vector3 &p);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Vector3> &p);

#endif //ROSBRIDGECLIENT_VECTOR3_HPP