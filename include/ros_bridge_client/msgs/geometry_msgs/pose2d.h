//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINT_2DHPP
#define ROSBRIDGECLIENT_POINT_2DHPP

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/xyzmessage.h>
#include <memory>
#include <iostream>

namespace ros_bridge_client
{
namespace msgs
{
namespace geometry_msgs
{

struct Pose2D : public XYZMessage<double>
{
  Pose2D();

  Pose2D(double x, double y, double theta);

  explicit Pose2D(const web::json::value &response);

  ~Pose2D() override = default;
  
  double theta;
};

} // namespace geometry_msgs
} // namespace msgs
} // namespace ros_bridge_client

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Pose2D &p);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Pose2D> &p);

#endif //ROSBRIDGECLIENT_POINT_2DHPP
