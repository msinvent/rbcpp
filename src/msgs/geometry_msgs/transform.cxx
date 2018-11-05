//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/transform.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Transform::Transform()
  : MessageBase("geometry_msgs/Transform"),
    translation(),
    rotation()
{}

Transform::Transform(const Vector3 &translation, const Quaternion &rotation)
  : MessageBase("geometry_msgs/Transform"),
    translation(translation),
    rotation(rotation)
{}

Transform::Transform(const web::json::value &response)
  : MessageBase("geometry_msgs/Transform"),
    translation(),
    rotation()
{
  const auto &msg = response.at(U("msg"));

  std::tie(translation.x, translation.y, translation.z) =
    utils::ResponseConverter::responseToVector3(msg.at(U("translation")), true);

  std::tie(rotation.x, rotation.y, rotation.z, rotation.w) =
    utils::ResponseConverter::responseToQuaternion(msg.at(U("rotation")), true);
}

Transform::Transform(double tx, double ty, double tz, double rx, double ry, double rz, double rw)
  : MessageBase("geometry_msgs/Transform"),
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
  return os << p.get();
}

