//
// Created by julian on 29.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance_stamped.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

TwistWithCovarianceStamped::TwistWithCovarianceStamped(std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(),
    header(frame_id)
{}

TwistWithCovarianceStamped::TwistWithCovarianceStamped(const TwistWithCovariance &twist_cov, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(twist_cov),
    header(frame_id)
{}

TwistWithCovarianceStamped::TwistWithCovarianceStamped(const Twist &twist, const std::array<double, 36> &covariance,
                                                       std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(twist, covariance),
    header(frame_id)
{}

TwistWithCovarianceStamped::TwistWithCovarianceStamped(const Vector3 &linear, const Vector3 &angular,
                                                       const std::array<double, 36> &covariance, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(linear, angular, covariance),
    header(frame_id)
{}

TwistWithCovarianceStamped::TwistWithCovarianceStamped(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
      twist(),
      header()
{
  const auto &msg = response.at(U("msg"));
  const auto &twist_msg = msg.at(U("twist"));
  const auto &twist_twist_msg = twist_msg.at(U("twist"));
  const auto &cov_msg = twist_msg.at(U("covariance"));

  std::tie(twist.twist.linear.x, twist.twist.linear.y, twist.twist.linear.z) =
      utils::Deserializer::toVector3(twist_twist_msg.at(U("linear")), true);

  std::tie(twist.twist.angular.x, twist.twist.angular.y, twist.twist.angular.z) =
      utils::Deserializer::toVector3(twist_twist_msg.at(U("angular")), true);

  twist.covariance = utils::Deserializer::toArray<double, 36>(cov_msg);

  utils::Deserializer::toHeader(header, response.at(U("msg")).at(U("header")), true);
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::TwistWithCovarianceStamped &t)
{
  os << "\nTwist With Covariance Stamped";
  os << t.twist;
  os << t.header;
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::TwistWithCovarianceStamped> &t)
{
  return os << *t.get();
}