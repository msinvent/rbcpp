//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

PointStamped::PointStamped(double x, double y, double z, std::string frame_id)
  : ROSTypeBase("geometry_msgs/PointStamped"),
    header(frame_id),
    point(x, y, z)
{}

PointStamped::PointStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/PointStamped"),
    header(),
    point()
{
  utils::Deserializer::toHeader(header, response.at(U("msg")).at(U("header")), true);

  std::tie(point.x, point.y, point.z) =
      utils::Deserializer::toPoint(response.at(U("msg")).at(U("point")), true);
}

PointStamped::PointStamped()
  : ROSTypeBase("geometry_msgs/PointStamped"),
    header(),
    point()
{}

std::ostream &operator<<(std::ostream &os, const PointStamped &p)
{
  os << "\nPoint Stamped";
  os << p.header;
  os << p.point;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<PointStamped> &p)
{
  return os << *p.get();
}
