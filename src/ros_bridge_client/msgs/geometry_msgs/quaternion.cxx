//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Quaternion::Quaternion()
    : XYZMessage<double>("geometry_msgs/Quaternion"), w(0)
{}

Quaternion::Quaternion(double x, double y, double z, double w)
    : XYZMessage<double>("geometry_msgs/Quaternion", x, y, z), w(w)
{}

Quaternion::Quaternion(const web::json::value &response)
    : XYZMessage<double>("geometry_msgs/Quaternion"), w(0)
{
  std::tie(x, y, z, w) = utils::Deserializer::toQuaternion(response, false);
}

std::ostream& operator <<(std::ostream &os, const Quaternion &q)
{
  os << "\nQuaternion:";
  os << "\n\tx: " << q.x;
  os << "\n\ty: " << q.y;
  os << "\n\tz: " << q.x;
  os << "\n\tw: " << q.w;
  return os;
}

std::ostream& operator<<(std::ostream &os, const std::shared_ptr<Quaternion> &q)
{
  return os << q.get();
}