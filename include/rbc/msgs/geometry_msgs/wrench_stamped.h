//
// Created by julian on 01.11.18.
//

#ifndef ROSBRIDGECLIENT_WRENCH_STAMPED_H
#define ROSBRIDGECLIENT_WRENCH_STAMPED_H

#include <cpprest/json.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/wrench.h>
#include <rbc/msgs/ros_type_base.h>

namespace rbc::msgs::geometry_msgs
{

struct WrenchStamped : public ROSTypeBase
{
  WrenchStamped();

  WrenchStamped(const Wrench &accel, std::string frame_id);

  WrenchStamped(const Vector3 &force, const Vector3 &torque, std::string frame_id);

  WrenchStamped(double fx, double fy, double fz, double tx, double ty, double tz, std::string frame_id);

  explicit WrenchStamped(const web::json::value &response);

  ~WrenchStamped() override = default;
  
  std_msgs::Header header;
  Wrench wrench;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::WrenchStamped &a);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::WrenchStamped> &a);


#endif //ROSBRIDGECLIENT_WRENCH_STAMPED_H
