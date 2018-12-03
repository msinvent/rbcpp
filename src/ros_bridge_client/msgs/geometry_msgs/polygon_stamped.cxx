//
// Created by julian on 03.12.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/polygon_stamped.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PolygonStamped::PolygonStamped(std::string frame_id)
    : ROSTypeBase("geometry_msgs/PolygonStamped"),
      polygon(),
      header(frame_id)
{}

PolygonStamped::PolygonStamped(unsigned int size, std::string frame_id)
    : ROSTypeBase("geometry_msgs/PolygonStamped"),
      polygon(size),
      header(frame_id)
{}

PolygonStamped::PolygonStamped(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/PolygonStamped"),
      polygon(),
      header()
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::toPolygon(polygon, msg, true);

  utils::Deserializer::toHeader(header, msg, true);
}

void PolygonStamped::add(const Point32 &p32)
{
  polygon.add(p32);
}
