//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/pose2d.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Pose2D::Pose2D()
  : XYZMessage<double>("geometry_msgs/Pose2D"),
    theta(0)
{}

Pose2D::Pose2D(double x, double y, double theta)
  : XYZMessage<double>("geometry_msgs/Pose2D", x, y, 0),
    theta(theta)
{}

Pose2D::Pose2D(const web::json::value &response)
  : XYZMessage<double>("geometry_msgs/Pose2D"),
    theta(0)
{
  utils::Deserializer::deserialize(*this, response, false);
}

std::ostream &operator<<(std::ostream &os, const Pose2D &p)
{
  os << "\nPose2D:";
  os << "\n\tx: " << p.x;
  os << "\n\ty: " << p.y;
  os << "\n\ttheta: " << p.theta;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Pose2D> &p)
{
  return os << *p.get();
}
