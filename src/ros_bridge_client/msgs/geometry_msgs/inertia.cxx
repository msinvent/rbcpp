//
// Created by julian on 02.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>
#include <ros_bridge_client/utils/deserializer.h>


using namespace ros_bridge_client::msgs::geometry_msgs;


Inertia::Inertia()
  : ROSTypeBase("geometry_msgs/Inertia"),
    m(0),
    ixx(0), ixy(0), ixz(0),
    iyy(0), iyz(0), izz(0),
    com(0, 0, 0)
{}

Inertia::Inertia(double m, const Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz, double izz)
  : ROSTypeBase("geometry_msgs/Inertia"),
    m(m),
    ixx(ixx), ixy(ixy), ixz(ixz),
    iyy(iyy), iyz(iyz), izz(izz),
    com(com)
{}

Inertia::Inertia(const Inertia &inertia)
  : ROSTypeBase("geometry_msgs/Inertia"),
    m(inertia.m),
    ixx(inertia.ixx), ixy(inertia.ixy), ixz(inertia.ixz),
    iyy(inertia.iyy), iyz(inertia.iyz), izz(inertia.izz),
    com(inertia.com)
{}

Inertia::Inertia(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/Inertia"),
    m(0),
    ixx(0), ixy(0), ixz(0),
    iyy(0), iyz(0), izz(0),
    com(0, 0, 0)
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::toInertia(*this, msg, true);

  utils::Deserializer::toXYZ<double>(com, msg.at(U("com")), true);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Inertia &i)
{
  os << "\nInertia:";
  os << "\n\tixx: " << i.ixx;
  os << "\n\tixy: " << i.ixy;
  os << "\n\tixz: " << i.ixz;
  os << "\n\tiyy: " << i.iyy;
  os << "\n\tiyz: " << i.iyz;
  os << "\n\tizz: " << i.izz;
  os << "\n\tm: " << i.m;
  os << i.com;
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Inertia> &i)
{
  return os << i.get();
}
