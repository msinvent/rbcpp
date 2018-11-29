//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_POSE_H
#define ROSBRIDGECLIENT_POSE_H

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/ros_type_base.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct Pose : public ROSTypeBase
{
  Pose();
  Pose(double x, double y, double z, double xx, double yy, double zz, double ww);
  Pose(const Point &p, const Quaternion &q);
  Pose(const web::json::value &response);
  ~Pose() final = default;

  Point point;
  Quaternion quaternion;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Pose &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Pose> &p);

#endif //ROSBRIDGECLIENT_POSE_H
