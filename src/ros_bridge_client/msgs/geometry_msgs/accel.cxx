//
// Created by Julian on 29.10.18.
//

#include <rbc/msgs/geometry_msgs/accel.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

Accel::Accel(std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    linear(0, 0, 0),
    angular(0, 0, 0)
{}

Accel::Accel(double lx, double ly, double lz, double ax, double ay, double az, std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    linear(lx, ly, lz),
    angular(ax, ay, az)
{}

Accel::Accel(const Vector3 &linear, const Vector3 &angular, std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    linear(linear),
    angular(angular)
{}

Accel::Accel(const web::json::value &response, std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type),
    linear(0, 0, 0),
    angular(0, 0, 0)
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::deserialize<double>(linear, msg.at(U("linear")), true);

  utils::Deserializer::deserialize<double>(angular, msg.at(U("angular")), true);
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Accel &p)
{
  os << "\nAccel: linear/angular";
  os << p.linear;
  os << p.angular;
  return os;
}

std::ostream & operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Accel> &p)
{
  return os << *p.get();
}

