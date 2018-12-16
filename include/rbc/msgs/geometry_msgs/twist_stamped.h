//
// Created by julian on 01.11.18.
//

#ifndef ROSBRIDGECLIENT_TWIST_STAMPED_H
#define ROSBRIDGECLIENT_TWIST_STAMPED_H

#include <cpprest/json.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/twist.h>
#include <rbc/msgs/ros_type_base.h>

namespace rbc::msgs::geometry_msgs
{

struct TwistStamped : public ROSTypeBase
{
  TwistStamped();

  TwistStamped(const Twist &twist, std::string frame_id);

  TwistStamped(const Vector3 &linear, const Vector3 &angular, std::string frame_id);

  TwistStamped(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id);

  explicit TwistStamped(const web::json::value &response);

  ~TwistStamped() override = default;
  
  std_msgs::Header header;
  Twist twist;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::TwistStamped &a);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::TwistStamped> &a);


#endif //ROSBRIDGECLIENT_TWIST_STAMPED_H
