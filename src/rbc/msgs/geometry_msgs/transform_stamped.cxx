//
// Created by Julian on 29.10.18.
//

#include <rbc/msgs/geometry_msgs/transform_stamped.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

TransformStamped::TransformStamped(std::string frame_id)
  : ROSTypeBase("geometry_msgs/TransformStamped"),
    header(frame_id),
    transform()
{}

TransformStamped::TransformStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/TransformStamped"),
    header(),
    transform()
{
  const auto &msg = response.at(U("msg"));
  const auto &transform_msg = msg.at(U("transform"));

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);

  utils::Deserializer::deserialize(transform.translation, transform_msg.at(U("translation")), true);

  utils::Deserializer::deserialize(transform.rotation, transform_msg.at(U("rotation")), true);
}

TransformStamped::TransformStamped(const Vector3 &translation, const Quaternion &rotation, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TransformStamped"),
    header(frame_id),
    transform(translation, rotation)
{}

TransformStamped::TransformStamped(double tx, double ty, double tz, double rx, double ry, double rz, double rw, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TransformStamped"),
    header(frame_id),
    transform(tx, ty, tz, rx, ry, rz, rw)
{}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::TransformStamped &p)
{
  os << "\nTransformStamped: header/transform";
  os << p.header;
  os << p.transform;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::TransformStamped> &p)
{
  return os << *p.get();
}

