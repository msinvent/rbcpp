//
// Created by julian on 02.11.18.
//

#ifndef ROSBRIDGECLIENT_INERTIA_STAMPED_H
#define ROSBRIDGECLIENT_INERTIA_STAMPED_H

#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/inertia.h>

namespace rbc::msgs::geometry_msgs
{

struct InertiaStamped : public ROSTypeBase
{
  InertiaStamped();

  InertiaStamped(std::string frame_id);

  InertiaStamped(const Inertia &inertia, std::string frame_id);

  InertiaStamped(double m, const Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz, double izz,
                 std::string frame_id);

  explicit InertiaStamped(const web::json::value &response);

  ~InertiaStamped() override = default;

  std_msgs::Header header;
  Inertia inertia;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::InertiaStamped &is);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::InertiaStamped> &is);

#endif //ROSBRIDGECLIENT_INERTIA_STAMPED_H
