//
// Created by julian on 28.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

TwistWithCovariance::TwistWithCovariance()
  : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
    twist(),
    covariance()
{}

TwistWithCovariance::TwistWithCovariance(const Vector3 &linear, const Vector3 &angular,
                                         std::array<double, 36> cov)
  : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
    twist(linear, angular),
    covariance(cov)
{}

TwistWithCovariance::TwistWithCovariance(const Twist &twist, std::array<double, 36> cov)
  : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
    twist(twist),
    covariance(cov)
{}

TwistWithCovariance::TwistWithCovariance(const TwistWithCovariance &twist_cov)
  : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
    twist(twist_cov.twist),
    covariance(twist_cov.covariance)
{}

TwistWithCovariance::TwistWithCovariance(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
      twist(),
      covariance()
{
  const auto &msg = response.at(U("msg"));
  const auto &twist_msg = msg.at(U("twist"));
  const auto &cov_msg = msg.at(U("covariance"));

  utils::Deserializer::deserialize<double>(twist.linear, twist_msg.at(U("linear")), true);

  utils::Deserializer::deserialize<double>(twist.angular, twist_msg.at(U("angular")), true);

  utils::Deserializer::toArray<double, 36>(covariance, cov_msg);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::TwistWithCovariance &t)
{
  os << "\nTwist With Covariance";
  os << t.twist;
  os << util::Covariance<double, 36>(t.covariance);
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::TwistWithCovariance> &t)
{
  return os << *t.get();
}
