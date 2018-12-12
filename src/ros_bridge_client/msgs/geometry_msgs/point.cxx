//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Point::Point()
  : XYZMessage<double>("geometry_msgs/Point")
{}

Point::Point(double x, double y, double z)
  : XYZMessage<double>("geometry_msgs/Point", x, y, z)
{}

Point::Point(const web::json::value &response)
  : XYZMessage<double>("geometry_msgs/Point")
{
  utils::Deserializer::deserialize<double>(*this, response, false);
}

bool Point::operator==(const Point &point)
{
  return x == point.x && y == point.y && z == point.z;
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
  os << "\nPoint:";
  os << "\n\tx: " << p.x;
  os << "\n\ty: " << p.y;
  os << "\n\tz: " << p.z;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Point> &p)
{
  return os << *p.get();
}
