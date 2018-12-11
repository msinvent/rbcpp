//
// Created by julian on 02.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped.h>
#include <ros_bridge_client/utils/deserializer.h>


using namespace ros_bridge_client::msgs::geometry_msgs;

InertiaStamped::InertiaStamped()
  : ROSTypeBase("geometry_msgs/InertiaStamped"),
    header(),
    inertia()
{}

InertiaStamped::InertiaStamped(std::string frame_id)
  : ROSTypeBase("geometry_msgs/InertiaStamped"),
    header(frame_id),
    inertia()
{}

InertiaStamped::InertiaStamped(double m, const Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz,
                               double izz, std::string frame_id)
  : ROSTypeBase("geometry_msgs/InertiaStamped"),
    header(frame_id),
    inertia(m, com, ixx, ixy, ixz, iyy, iyz, izz)
{}

InertiaStamped::InertiaStamped(const Inertia &inertia, std::string frame_id)
  : ROSTypeBase("geometry_msgs/InertiaStamped"),
    header(frame_id),
    inertia(inertia)
{}

InertiaStamped::InertiaStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/InertiaStamped"),
    header(),
    inertia()
{
  const auto &msg = response.at(U("msg"));
  const auto &inertia_msg = msg.at(U("inertia"));

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);

  utils::Deserializer::deserialize(inertia, inertia_msg, true);

  utils::Deserializer::deserialize<double>(inertia.com, inertia_msg.at(U("com")), true);
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
  return os << *is.get();
}
