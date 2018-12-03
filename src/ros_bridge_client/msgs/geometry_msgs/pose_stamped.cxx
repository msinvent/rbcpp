//
// Created by Julian on 27.10.18.
//

#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PoseStamped::PoseStamped()
  : ROSTypeBase("geometry_msgs/PoseStamped"),
    header(),
    pose()
{}

PoseStamped::PoseStamped(const Pose &pose, std::string frame_id)
  : ROSTypeBase("geometry_msgs/PoseStamped"),
    header(frame_id),
    pose(pose)
{}

PoseStamped::PoseStamped(double x, double y, double z, double xx, double yy, double zz, double ww, std::string frame_id)
  : ROSTypeBase("geometry_msgs/PoseStamped"),
    header(frame_id),
    pose(x, y, z, xx, yy, zz, ww)
{}

PoseStamped::PoseStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/PoseStamped"),
    header(),
    pose()
{
  const auto &msg = response.at(U("msg"));
  const auto &pose_msg = msg.at(U("pose"));

  utils::Deserializer::toHeader(header, msg.at(U("header")), true);

  utils::Deserializer::toXYZ<double>(pose.point, pose_msg.at(U("position")), true);

  utils::Deserializer::toQuaternion(pose.orientation, pose_msg.at(U("orientation")), true);
}

std::ostream &operator<<(std::ostream &os, const PoseStamped &p)
{
  os << "\nPose Stamped:";
  os << p.header;
  os << p.pose;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<PoseStamped> &p)
{
  return os << p.get();
}