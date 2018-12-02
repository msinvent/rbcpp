//
// Created by julian on 03.12.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/polygon.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Polygon::Polygon()
    : ROSTypeBase("geometry_msgs/Polygon"),
      points()
{}

Polygon::Polygon(unsigned int size)
    : ROSTypeBase("geometry_msgs/Polygon"),
      points()
{
  points.reserve(size);
}

Polygon::Polygon(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/Polygon"),
      points()
{}

void Polygon::add(const Point32 &p32)
{
  points.push_back(p32);
}
