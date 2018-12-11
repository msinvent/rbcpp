//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/wrench.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Wrench::Wrench()
  : ROSTypeBase("geometry_msgs/Wrench"),
    force(0, 0, 0),
    torque(0, 0, 0)
{}

Wrench::Wrench(double lx, double ly, double lz, double ax, double ay, double az)
  : ROSTypeBase("geometry_msgs/Wrench"),
    force(lx, ly, lz),
    torque(ax, ay, az)
{

}

Wrench::Wrench(const Vector3 &force, const Vector3 &torque)
  : ROSTypeBase("geometry_msgs/Wrench"),
    force(force),
    torque(torque)
{}

Wrench::Wrench(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/Wrench"),
    force(0, 0, 0),
    torque(0, 0, 0)
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::deserialize<double>(force, msg.at(U("force")), true);

  utils::Deserializer::deserialize<double>(torque, msg.at(U("torque")), true);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Wrench &w)
{
  os << "\nWrench: force/torque";
  os << w.force;
  os << w.torque;
  return os;
}

std::ostream & operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Wrench> &w)
{
  return os << *w.get();
}

