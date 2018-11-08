//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/point2d.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Point2D::Point2D()
  : XYZMessage<double>("geometry_msgs/Point2D"),
    theta(0)
{}

Point2D::Point2D(double x, double y, double theta)
  : XYZMessage<double>("geometry_msgs/Point2D", x, y, 0),
    theta(theta)
{}

Point2D::Point2D(const web::json::value &response)
  : XYZMessage<double>("geometry_msgs/Point2D"),
    theta(0)
{
  std::tie(x, y, theta) = utils::ResponseConverter::responseToPoint2D(response, false);
}

std::ostream &operator<<(std::ostream &os, const Point2D &p)
{
  os << "\nPoint2D:";
  os << "\n\tx: " << p.x;
  os << "\n\ty: " << p.y;
  os << "\n\ttheta: " << p.theta;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Point2D> &p)
{
  return os << p.get();
}
