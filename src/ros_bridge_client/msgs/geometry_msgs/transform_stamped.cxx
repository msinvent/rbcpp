//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/transform_stamped.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

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

  std::tie(header.seq, header.stamp.sec, header.stamp.nsec, header.frame_id) =
    utils::ResponseConverter::responseToHeader(msg.at(U("header")), true);

  std::tie(transform.translation.x, transform.translation.y, transform.translation.z) =
    utils::ResponseConverter::responseToVector3(transform_msg.at(U("translation")), true);

  std::tie(transform.rotation.x, transform.rotation.y, transform.rotation.z, transform.rotation.w) =
    utils::ResponseConverter::responseToQuaternion(transform_msg.at(U("rotation")), true);
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

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::TransformStamped &p)
{
  os << "\nTransformStamped: header/transform";
  os << p.header;
  os << p.transform;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::TransformStamped> &p)
{
  return os << p.get();
}

