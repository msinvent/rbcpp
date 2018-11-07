//
// Created by Julian on 27.10.18.
//

#include <ros_bridge_client/utils/response_converter.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PoseStamped::PoseStamped()
  : MessageBase("geometry_msgs/PoseStamped"),
    header(),
    pose()
{}

PoseStamped::PoseStamped(const Pose &pose, std::string frame_id)
  : MessageBase("geometry_msgs/PoseStamped"),
    header(frame_id),
    pose(pose)
{}

PoseStamped::PoseStamped(double x, double y, double z, double xx, double yy, double zz, double ww, std::string frame_id)
  : MessageBase("geometry_msgs/PoseStamped"),
    header(frame_id),
    pose(x, y, z, xx, yy, zz, ww)
{}

PoseStamped::PoseStamped(const web::json::value &response)
  : MessageBase("geometry_msgs/PoseStamped"),
    header(),
    pose()
{
  const auto &msg = response.at(U("msg"));
  const auto &pose_msg = msg.at(U("pose"));

  std::tie(header.seq, header.stamp.sec, header.stamp.nsec, header.frame_id) =
    utils::ResponseConverter::responseToHeader(msg.at(U("header")), true);

  std::tie(pose.point.x, pose.point.y, pose.point.z) =
    utils::ResponseConverter::responseToPoint(pose_msg.at(U("position")), true);

  std::tie(pose.quaternion.x, pose.quaternion.y, pose.quaternion.z, pose.quaternion.w) =
    utils::ResponseConverter::responseToQuaternion(pose_msg.at(U("orientation")), true);
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