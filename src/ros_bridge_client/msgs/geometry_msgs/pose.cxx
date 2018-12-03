//
// Created by Julian on 27.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Pose::Pose()
  : ROSTypeBase("geometry_msgs/Pose"),
    point(),
    orientation()
{}

Pose::Pose(double x, double y, double z, double xx, double yy, double zz, double ww)
  : ROSTypeBase("geometry_msgs/Pose"),
    point(x, y, z),
    orientation(xx, yy, zz, ww)
{}

Pose::Pose(const Point &p, const Quaternion &q)
  : ROSTypeBase("geometry_msgs/Pose"),
    point(p),
    orientation(q)
{}

Pose::Pose(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/Pose"),
    point(),
    orientation()
{
  std::tie(point.x, point.y, point.z) =
      utils::Deserializer::toPoint(response.at(U("msg")).at(U("position")), true);

  utils::Deserializer::toQuaternion(orientation, response.at(U("msg")).at(U("orientation")), true);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Pose &p)
{
  os << "\nPose:";
  os << p.point;
  os << p.orientation;
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Pose> &p)
{
  return os << p.get();
}
