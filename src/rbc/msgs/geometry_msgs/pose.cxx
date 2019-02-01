//
// Created by Julian on 27.10.18.
//

#include <rbc/msgs/geometry_msgs/pose.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

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
  utils::Deserializer::deserialize(point, response.at(U("msg")).at(U("position")), true);

  utils::Deserializer::deserialize(orientation, response.at(U("msg")).at(U("orientation")), true);
}

bool Pose::operator==(const Pose &pose)
{
  return point == pose.point && orientation == pose.orientation;
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Pose &p)
{
  os << "\nPose:";
  os << p.point;
  os << p.orientation;
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Pose> &p)
{
  return os << *p.get();
}
