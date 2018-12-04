//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/transform.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Transform::Transform()
  : ROSTypeBase("geometry_msgs/Transform"),
    translation(),
    rotation()
{}

Transform::Transform(const Vector3 &translation, const Quaternion &rotation)
  : ROSTypeBase("geometry_msgs/Transform"),
    translation(translation),
    rotation(rotation)
{}

Transform::Transform(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/Transform"),
    translation(),
    rotation()
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::toXYZ<double>(translation, msg.at(U("translation")), true);

  utils::Deserializer::toQuaternion(rotation, msg.at(U("rotation")), true);
}

Transform::Transform(double tx, double ty, double tz, double rx, double ry, double rz, double rw)
  : ROSTypeBase("geometry_msgs/Transform"),
    translation(tx, ty, tz),
    rotation(rx, ry, rz, rw)
{}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Transform &p)
{
  os << "\nTransform: translation/rotation";
  os << p.translation;
  os << p.rotation;
  return os;
}

std::ostream & operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Transform> &p)
{
  return os << *p.get();
}

