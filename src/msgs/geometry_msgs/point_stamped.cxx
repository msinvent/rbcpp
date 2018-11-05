//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

PointStamped::PointStamped(double x, double y, double z, std::string frame_id)
  : MessageBase("geometry_msgs/PointStamped"),
    header(frame_id),
    point(x, y, z)
{}

PointStamped::PointStamped(const web::json::value &response)
  : MessageBase("geometry_msgs/PointStamped"),
    header(),
    point()
{
  std::tie(header.seq, header.stamp.sec, header.stamp.nsec, header.frame_id) =
    utils::ResponseConverter::responseToHeader(response.at(U("msg")).at(U("header")), true);

  std::tie(point.x, point.y, point.z) =
    utils::ResponseConverter::responseToPoint(response.at(U("msg")).at(U("point")), true);
}

PointStamped::PointStamped()
  : MessageBase("geometry_msgs/PointStamped"),
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