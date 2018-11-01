//
// Created by julian on 01.11.18.
//

#include <ros_bridge_client/utils/response_converter.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

AccelStamped::AccelStamped()
  : MessageBase("geometry_msgs/AccelStamped"),
    header(),
    accel()
{}

AccelStamped::AccelStamped(const Accel &accel, std::string frame_id)
  : MessageBase("geometry_msgs/AccelStamped"),
    header(frame_id),
    accel(accel)
{}

AccelStamped::AccelStamped(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id)
  : MessageBase("geometry_msgs/AccelStamped"),
    header(frame_id),
    accel(lx, ly, lz, ax, ay, az)
{}

AccelStamped::AccelStamped(const Vector3 &linear, const Vector3 &angular, std::string frame_id)
  : MessageBase("geometry_msgs/AccelStamped"),
    header(frame_id),
    accel(linear, angular)
{}

AccelStamped::AccelStamped(const web::json::value &response)
  : MessageBase("geometry_msgs/AccelStamped"),
    header(),
    accel()
{
  const auto &msg = response.at(U("msg"));
  const auto &accel_msg = msg.at(U("accel"));

  std::tie(header.seq, header.stamp.sec, header.stamp.nsec, header.frame_id) =
    utils::ResponseConverter::responseToHeader(msg.at(U("header")), true);

  std::tie(accel.linear.x, accel.linear.y, accel.linear.z) =
    utils::ResponseConverter::responseToVector3(accel_msg.at(U("linear")), true);

  std::tie(accel.angular.x, accel.angular.y, accel.angular.z) =
    utils::ResponseConverter::responseToVector3(accel_msg.at(U("angular")), true);
}

std::ostream &operator<<(std::ostream &os, const AccelStamped &p)
{
  os << "\nAccel Stamped:";
  os << p.header;
  os << p.accel;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<AccelStamped> &p)
{
  return os << p.get();
}