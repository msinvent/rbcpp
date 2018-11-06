//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Accel::Accel()
  : MessageBase("geometry_msgs/Accel"),
    linear(0, 0, 0),
    angular(0, 0, 0)
{}

Accel::Accel(double lx, double ly, double lz, double ax, double ay, double az)
  : MessageBase("geometry_msgs/Accel"),
    linear(lx, ly, lz),
    angular(ax, ay, az)
{}

Accel::Accel(const Vector3 &linear, const Vector3 &angular)
  : MessageBase("geometry_msgs/Accel"),
    linear(linear),
    angular(angular)
{}

Accel::Accel(const web::json::value &response)
  : MessageBase("geometry_msgs/Accel"),
    linear(0, 0, 0),
    angular(0, 0, 0)
{
  const auto &msg = response.at(U("msg"));

  std::tie(linear.x, linear.y, linear.z) =
    utils::ResponseConverter::responseToVector3(msg.at(U("linear")), true);

  std::tie(angular.x, angular.y, angular.z) =
    utils::ResponseConverter::responseToVector3(msg.at(U("angular")), true);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Accel &p)
{
  os << "\nAccel: linear/angular";
  os << p.linear;
  os << p.angular;
  return os;
}

std::ostream & operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Accel> &p)
{
  return os << p.get();
}

