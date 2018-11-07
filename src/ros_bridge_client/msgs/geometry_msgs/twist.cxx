//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/twist.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Twist::Twist()
  : Accel("geometry_msgs/Twist")
{}

Twist::Twist(double lx, double ly, double lz, double ax, double ay, double az)
  : Accel(lx, ly, lz, ax, ay, az, "geometry_msgs/Twist")
{}

Twist::Twist(const Vector3 &linear, const Vector3 &angular)
  : Accel(linear, angular, "geometry_msgs/Twist")
{}

Twist::Twist(const web::json::value &response)
  : Accel(response, "geometry_msgs/Twist")
{
  const auto &msg = response.at(U("msg"));

  std::tie(linear.x, linear.y, linear.z) =
    utils::ResponseConverter::responseToVector3(msg.at(U("linear")), true);

  std::tie(angular.x, angular.y, angular.z) =
    utils::ResponseConverter::responseToVector3(msg.at(U("angular")), true);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Twist &p)
{
  os << "\nTwist: linear/angular";
  os << p.linear;
  os << p.angular;
  return os;
}

std::ostream & operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Twist> &p)
{
  return os << p.get();
}

