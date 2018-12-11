//
// Created by Julian on 27.10.18.
//

#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PoseWithCovariance::PoseWithCovariance()
  : ROSTypeBase("geometry_msgs/PoseWithCovariance"),
    pose(),
    covariance()
{}

PoseWithCovariance::PoseWithCovariance(double x, double y, double z, double xx, double yy, double zz, double ww,
                                       const std::array<double, 36> &arr)
  : ROSTypeBase("geometry_msgs/PoseWithCovariance"),
    pose(x, y, z, xx, yy, zz, ww),
    covariance(arr)
{}

PoseWithCovariance::PoseWithCovariance(const Point &p, const Quaternion &q, const std::array<double, 36> &arr)
  : ROSTypeBase("geometry_msgs/PoseWithCovariance"),
    pose(p, q),
    covariance(arr)
{}

PoseWithCovariance::PoseWithCovariance(const Pose &pose, const std::array<double, 36> &arr)
  : ROSTypeBase("geometry_msgs/PoseWithCovariance"),
    pose(pose),
    covariance(arr)
{}

PoseWithCovariance::PoseWithCovariance(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/PoseWithCovariance"),
    pose(),
    covariance()
{
  const auto &msg = response.at(U("msg"));
  const auto &pose_msg = msg.at(U("pose"));
  const auto &cov_msg = msg.at(U("covariance"));

  utils::Deserializer::deserialize<double>(pose.point, pose_msg.at(U("position")), true);

  utils::Deserializer::deserialize(pose.orientation, pose_msg.at(U("orientation")), true);

  utils::Deserializer::toArray<double, 36>(covariance, cov_msg);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::PoseWithCovariance &p)
{
  os << "\nPose With Covariance:";
  os << p.pose;
  os << util::Covariance<double, 36>(p.covariance);
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::PoseWithCovariance> &p)
{
  return os << *p.get();
}
