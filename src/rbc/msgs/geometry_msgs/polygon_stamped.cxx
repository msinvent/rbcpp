//
// Created by julian on 03.12.18.
//

#include <rbc/msgs/geometry_msgs/polygon_stamped.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

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

  utils::Deserializer::deserialize(polygon, msg.at(U("polygon")), true);

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);
}

void PolygonStamped::add(const Point32 &p32)
{
  polygon.add(p32);
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::PolygonStamped &p)
{
  os << "\nPolygon Stamped";
  os << p.header;
  os << p.polygon;
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::PolygonStamped> &p)
{
  return os << *p.get();
}
