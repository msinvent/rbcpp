//
// Created by julian on 16.12.18.
//

#include <rbc/msgs/nav_msgs/odometry.h>
#include <rbc/utils/deserializer.h>

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
{
  const auto &msg = response.at(U("msg"));
  const auto &header_msg = msg.at(U("header"));

  const auto &twist_msg = msg.at(U("twist"));
  const auto &twist_twist_msg = twist_msg.at(U("twist"));

  const auto &pose_msg = msg.at(U("pose"));
  const auto &pose_pose_msg = pose_msg.at(U("pose"));

  child_frame_id = msg.at("child_frame_id").as_string();

  utils::Deserializer::deserialize(header, header_msg, true);

  utils::Deserializer::deserialize<double>(pose.pose.point, pose_pose_msg.at(U("position")), true);
  utils::Deserializer::deserialize(pose.pose.orientation, pose_pose_msg.at(U("orientation")), true);
  utils::Deserializer::toArray<double, 36>(pose.covariance, pose_msg.at(U("covariance")));

  utils::Deserializer::deserialize<double>(twist.twist.linear, twist_twist_msg.at(U("linear")), true);
  utils::Deserializer::deserialize<double>(twist.twist.angular, twist_twist_msg.at(U("angular")), true);
  utils::Deserializer::toArray<double, 36>(twist.covariance, twist_msg.at(U("covariance")));
}

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
