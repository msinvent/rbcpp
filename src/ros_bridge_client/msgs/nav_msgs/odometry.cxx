//
// Created by julian on 16.12.18.
//

#include <rbc/msgs/nav_msgs/odometry.h>

using namespace rbc::msgs::nav_msgs;

Odometry::Odometry()
    : ROSTypeBase("nav_msgs/Odometry"),
      child_frame_id("world"),
      header(),
      pose(),
      twist()
{}

Odometry::Odometry(std::string frame_id, std::string child_frame_id)
    : ROSTypeBase("nav_msgs/Odometry"),
      child_frame_id(child_frame_id),
      header(frame_id),
      pose(),
      twist()
{}

Odometry::Odometry(std::string child_frame_id, const rbc::msgs::std_msgs::Header &header,
                   const rbc::msgs::geometry_msgs::PoseWithCovariance &pose,
                   const rbc::msgs::geometry_msgs::TwistWithCovariance &twist)
    : ROSTypeBase("nav_msgs/Odometry"),
      child_frame_id(child_frame_id),
      header(header),
      pose(pose),
      twist(twist)
{}

Odometry::Odometry(const web::json::value &response)
    : ROSTypeBase("nav_msgs/Odometry"),
      child_frame_id("world"),
      header(),
      pose(),
      twist()
{}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::nav_msgs::Odometry &o)
{
  os << "\nOdometry";
  os << "\n\tchild_frame_id: " << o.child_frame_id;
  os << o.header;
  os << o.pose;
  os << o.twist;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::nav_msgs::Odometry> &o)
{
  return os << *o.get();
}
