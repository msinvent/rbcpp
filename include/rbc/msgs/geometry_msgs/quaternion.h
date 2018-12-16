//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_QUATERNION_HPP
#define ROSBRIDGECLIENT_QUATERNION_HPP

#include <cpprest/json.h>
#include <rbc/msgs/xyzmessage.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct Quaternion : public XYZMessage<double>
{
  Quaternion();

  Quaternion(double x, double y, double z, double w);

  explicit Quaternion(const web::json::value &response);

  ~Quaternion() override = default;

  double w;

  bool operator==(const Quaternion &q);
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Quaternion &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Quaternion> &p);

#endif //ROSBRIDGECLIENT_QUATERNION_HPP