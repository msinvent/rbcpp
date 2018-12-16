//
// Created by julian on 01.11.18.
//

#include <rbc/utils/deserializer.h>
#include <rbc/msgs/geometry_msgs/accel_stamped.h>

using namespace rbc::msgs::geometry_msgs;

AccelStamped::AccelStamped(std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    header(),
    accel()
{}

AccelStamped::AccelStamped(const Accel &accel, std::string frame_id, std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    header(frame_id),
    accel(accel)
{}

AccelStamped::AccelStamped(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id,
                           std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    header(frame_id),
    accel(lx, ly, lz, ax, ay, az)
{}

AccelStamped::AccelStamped(const Vector3 &linear, const Vector3 &angular, std::string frame_id,
                           std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    header(frame_id),
    accel(linear, angular)
{}

AccelStamped::AccelStamped(const web::json::value &response, std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    header(),
    accel()
{
  const auto &msg = response.at(U("msg"));
  const auto &accel_msg = msg.at(U("accel"));

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);

  utils::Deserializer::deserialize<double>(accel.linear, accel_msg.at(U("linear")), true);

  utils::Deserializer::deserialize<double>(accel.angular, accel_msg.at(U("angular")), true);
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
  return os << *p.get();
}