//
// Created by julian on 01.11.18.
//

#include <rbc/utils/deserializer.h>
#include <rbc/msgs/geometry_msgs/twist_stamped.h>

using namespace rbc::msgs::geometry_msgs;

TwistStamped::TwistStamped()
  : ROSTypeBase("geometry_msgs/TwistStamped"),
    header(),
    twist()
{}

TwistStamped::TwistStamped(const Twist &twist, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistStamped"),
    header(frame_id),
    twist(twist)
{}

TwistStamped::TwistStamped(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistStamped"),
    header(frame_id),
    twist(lx, ly, lz, ax,ay, az)
{}

TwistStamped::TwistStamped(const Vector3 &linear, const Vector3 &angular, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistStamped"),
    header(frame_id),
    twist(linear, angular)
{}

TwistStamped::TwistStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/TwistStamped"),
    header(),
    twist()
{
  const auto &msg = response.at(U("msg"));
  const auto &twist_msg = msg.at(U("twist"));

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);

  utils::Deserializer::deserialize<double>(twist.linear, twist_msg.at(U("linear")), true);

  utils::Deserializer::deserialize<double>(twist.angular, twist_msg.at(U("angular")), true);
}

std::ostream &operator<<(std::ostream &os, const TwistStamped &p)
{
  os << "\nTwist Stamped:";
  os << p.header;
  os << p.twist;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<TwistStamped> &p)
{
  return os << *p.get();
}