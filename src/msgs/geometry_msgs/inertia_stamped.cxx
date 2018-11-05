//
// Created by julian on 02.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped.h>
#include <ros_bridge_client/utils/response_converter.h>


using namespace ros_bridge_client::msgs::geometry_msgs;

InertiaStamped::InertiaStamped()
  : MessageBase("geometry_msgs/InertiaStamped"),
    header(),
    inertia()
{}

InertiaStamped::InertiaStamped(std::string frame_id)
  : MessageBase("geometry_msgs/InertiaStamped"),
    header(frame_id),
    inertia()
{}

InertiaStamped::InertiaStamped(double m, const Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz,
                               double izz, std::string frame_id)
  : MessageBase("geometry_msgs/InertiaStamped"),
    header(frame_id),
    inertia(m, com, ixx, ixy, ixz, iyy, iyz, izz)
{}

InertiaStamped::InertiaStamped(const Inertia &inertia, std::string frame_id)
  : MessageBase("geometry_msgs/InertiaStamped"),
    header(frame_id),
    inertia(inertia)
{}

InertiaStamped::InertiaStamped(const web::json::value &response)
  : MessageBase("geometry_msgs/InertiaStamped"),
    header(),
    inertia()
{
  const auto &msg = response.at(U("msg"));
  const auto &inertia_msg = msg.at(U("inertia"));

  std::tie(header.seq, header.stamp.sec, header.stamp.nsec, header.frame_id) =
    utils::ResponseConverter::responseToHeader(msg.at(U("header")), true);

  std::tie(inertia.m, inertia.ixx, inertia.ixy, inertia.ixz, inertia.iyy, inertia.iyz, inertia.izz) =
    utils::ResponseConverter::responseToInertia(inertia_msg, true);

  std::tie(inertia.com.x, inertia.com.y, inertia.com.z) =
    utils::ResponseConverter::responseToVector3(inertia_msg.at(U("com")), true);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::InertiaStamped &is)
{
  os << "\nInertiaStamped";
  os << is.header;
  os << is.inertia;
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::InertiaStamped> &is)
{
  return os << is.get();
}
