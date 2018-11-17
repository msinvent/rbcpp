//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_QUATERNION_HPP
#define ROSBRIDGECLIENT_QUATERNION_HPP

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/xyzmessage.h>
#include <memory>
#include <iostream>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct Quaternion : public XYZMessage<double>
{
  Quaternion();

  Quaternion(double x, double y, double z, double w);

  explicit Quaternion(const web::json::value &response);

  ~Quaternion() override = default;

  double w;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Quaternion &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Quaternion> &p);

#endif //ROSBRIDGECLIENT_QUATERNION_HPP