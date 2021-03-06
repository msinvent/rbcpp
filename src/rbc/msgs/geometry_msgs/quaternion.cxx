//
// Created by Julian on 18.09.18.
//

#include <rbc/msgs/geometry_msgs/quaternion.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

Quaternion::Quaternion()
    : XYZMessage<double>("geometry_msgs/Quaternion"), w(0)
{}

Quaternion::Quaternion(double x, double y, double z, double w)
    : XYZMessage<double>("geometry_msgs/Quaternion", x, y, z), w(w)
{}

Quaternion::Quaternion(const web::json::value &response)
    : XYZMessage<double>("geometry_msgs/Quaternion"), w(0)
{
  utils::Deserializer::deserialize(*this, response, false);
}

bool Quaternion::operator==(const Quaternion &q)
{
  return x == q.x && y == q.y && z == q.z && w == q.w;
}

std::ostream& operator <<(std::ostream &os, const Quaternion &q)
{
  os << "\nQuaternion:";
  os << "\n\tx: " << q.x;
  os << "\n\ty: " << q.y;
  os << "\n\tz: " << q.z;
  os << "\n\tw: " << q.w;
  os << "\n";
  return os;
}

std::ostream& operator<<(std::ostream &os, const std::shared_ptr<Quaternion> &q)
{
  return os << *q.get();
}