//
// Created by julian on 01.11.18.
//

#include <ros_bridge_client/utils/response_converter.h>
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

  std::tie(header.seq, header.stamp.sec, header.stamp.nsec, header.frame_id) =
    utils::ResponseConverter::responseToHeader(msg.at(U("header")), true);

  std::tie(wrench.force.x, wrench.force.y, wrench.force.z) =
    utils::ResponseConverter::responseToVector3(wrench_msg.at(U("force")), true);

  std::tie(wrench.torque.x, wrench.torque.y, wrench.torque.z) =
    utils::ResponseConverter::responseToVector3(wrench_msg.at(U("torque")), true);
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