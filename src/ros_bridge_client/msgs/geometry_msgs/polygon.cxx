//
// Created by julian on 03.12.18.
//

#include <rbc/msgs/geometry_msgs/polygon.h>
#include <rbc/utils/deserializer.h>
#include <iterator>

using namespace rbc::msgs::geometry_msgs;

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
{
  utils::Deserializer::deserialize(*this, response.at(U("msg")), true);
}

void Polygon::add(const Point32 &p32)
{
  points.push_back(p32);
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Polygon &p)
{
  os << "\nPolygon";
  if (p.points.empty())
    return os << "\n\t<empty>\n";

  for (const auto &po: p.points)
  {
    os << "\n\t-";
    os << "\n\t" << po.x;
    os << "\n\t" << po.y;
    os << "\n\t" << po.z;
  }
  return os << "\n";
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Polygon> &p)
{
  return os << *p.get();
}
