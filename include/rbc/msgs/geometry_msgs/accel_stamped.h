//
// Created by julian on 01.11.18.
//

#ifndef ROSBRIDGECLIENT_ACCEL_STAMPED_H
#define ROSBRIDGECLIENT_ACCEL_STAMPED_H

#include <cpprest/json.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/accel.h>
#include <rbc/msgs/ros_type_base.h>

namespace rbc::msgs::geometry_msgs
{

struct AccelStamped : public ROSTypeBase
{
  AccelStamped(std::string ros_msg_type = "geometry_msgs/AccelStamped");

  AccelStamped(const Accel &accel, std::string frame_id, std::string ros_msg_type = "geometry_msgs/AccelStamped");

  AccelStamped(const Vector3 &linear, const Vector3 &angular, std::string frame_id,
               std::string ros_msg_type = "geometry_msgs/AccelStamped");

  AccelStamped(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id,
               std::string ros_msg_type = "geometry_msgs/AccelStamped");

  explicit AccelStamped(const web::json::value &response, std::string ros_msg_type = "geometry_msgs/AccelStamped");

  ~AccelStamped() override = default;

  std_msgs::Header header;
  Accel accel;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::AccelStamped &a);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::AccelStamped> &a);

#endif //ROSBRIDGECLIENT_ACCEL_STAMPED_H
