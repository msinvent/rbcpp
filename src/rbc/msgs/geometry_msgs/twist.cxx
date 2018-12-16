//
// Created by Julian on 29.10.18.
//

#include <rbc/msgs/geometry_msgs/twist.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

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
{}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Twist &p)
{
  os << "\nTwist: linear/angular";
  os << p.linear;
  os << p.angular;
  return os;
}

std::ostream & operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Twist> &p)
{
  return os << *p.get();
}

