//
// Created by julian on 01.11.18.
//

#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench_stamped.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

WrenchStamped::WrenchStamped()
  : ROSTypeBase("geometry_msgs/WrenchStamped"),
    header(),
    wrench()
{}

WrenchStamped::WrenchStamped(const Wrench &wrench, std::string frame_id)
  : ROSTypeBase("geometry_msgs/WrenchStamped"),
    header(frame_id),
    wrench(wrench)
{}

WrenchStamped::WrenchStamped(double fx, double fy, double fz, double tx, double ty, double tz, std::string frame_id)
  : ROSTypeBase("geometry_msgs/WrenchStamped"),
    header(frame_id),
    wrench(fx, fy, fz, tx, ty, tz)
{}

WrenchStamped::WrenchStamped(const Vector3 &force, const Vector3 &torque, std::string frame_id)
  : ROSTypeBase("geometry_msgs/WrenchStamped"),
    header(frame_id),
    wrench(force, torque)
{}

WrenchStamped::WrenchStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/WrenchStamped"),
    header(),
    wrench()
{
  const auto &msg = response.at(U("msg"));
  const auto &wrench_msg = msg.at(U("wrench"));

  utils::Deserializer::toHeader(header, msg.at(U("header")), true);

  utils::Deserializer::toXYZ<double>(wrench.force, wrench_msg.at(U("force")), true);

  utils::Deserializer::toXYZ<double>(wrench.torque, wrench_msg.at(U("torque")), true);
}

std::ostream &operator<<(std::ostream &os, const WrenchStamped &ws)
{
  os << "\nWrench Stamped:";
  os << ws.header;
  os << ws.wrench;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<WrenchStamped> &ws)
{
  return os << ws.get();
}