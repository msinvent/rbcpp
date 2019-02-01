//
// Created by Julian on 18.09.18.
//

#include <rbc/msgs/geometry_msgs/vector3.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

Vector3::Vector3()
  : XYZMessage<double>("geometry_msgs/Vector3")
{}

Vector3::Vector3(double x, double y, double z)
  : XYZMessage<double>("geometry_msgs/Vector3", x, y, z)
{}

Vector3::Vector3(const Vector3 &vec)
  : XYZMessage<double>(vec)
{}

Vector3::Vector3(const web::json::value &response)
  : XYZMessage<double>("geometry_msgs/Vector3")
{
  utils::Deserializer::deserialize(*this, response);
}

std::ostream &operator<<(std::ostream &os, const Vector3 &v)
{
  os << "\nVector3:";
  os << "\n\tx: " << v.x;
  os << "\n\ty: " << v.y;
  os << "\n\tz: " << v.z;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Vector3> &v)
{
  return os << *v.get();
}