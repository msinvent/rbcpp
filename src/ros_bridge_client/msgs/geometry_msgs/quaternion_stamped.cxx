//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

QuaternionStamped::QuaternionStamped(double x, double y, double z, double w, std::string frame_id)
  : ROSTypeBase("geometry_msgs/QuaternionStamped"),
    header(frame_id),
    quaternion(x, y, z, w)
{}

QuaternionStamped::QuaternionStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/QuaternionStamped"),
    header(),
    quaternion()
{
  utils::Deserializer::toHeader(header, response.at(U("msg")).at(U("header")), true);

  utils::Deserializer::toQuaternion(quaternion, response.at(U("msg")).at(U("orientation")), true);
}

QuaternionStamped::QuaternionStamped()
  : ROSTypeBase("geometry_msgs/QuaternionStamped"),
    header(),
    quaternion()
{}

std::ostream &operator<<(std::ostream &os, const QuaternionStamped &q)
{
  os << "\nQuaternion Stamped:";
  os << q.header;
  os << q.quaternion;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<QuaternionStamped> &q)
{
  return os << q.get();
}