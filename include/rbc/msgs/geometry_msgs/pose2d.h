//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINT_2DHPP
#define ROSBRIDGECLIENT_POINT_2DHPP

#include <cpprest/json.h>
#include <rbc/msgs/xyzmessage.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct Pose2D : public XYZMessage<double>
{
  Pose2D();

  Pose2D(double x, double y, double theta);

  explicit Pose2D(const web::json::value &response);

  ~Pose2D() final = default;
  
  double theta;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Pose2D &p);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Pose2D> &p);

#endif //ROSBRIDGECLIENT_POINT_2DHPP
