//
// Created by julian on 29.11.18.
//

#include <rbc/msgs/geometry_msgs/twist_with_covariance_stamped.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;

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

  utils::Deserializer::deserialize<double>(twist.twist.linear, twist_twist_msg.at(U("linear")), true);

  utils::Deserializer::deserialize<double>(twist.twist.angular, twist_twist_msg.at(U("angular")), true);

  utils::Deserializer::toArray<double, 36>(twist.covariance, cov_msg);

  utils::Deserializer::deserialize(header, response.at(U("msg")).at(U("header")), true);
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::TwistWithCovarianceStamped &t)
{
  os << "\nTwist With Covariance Stamped";
  os << t.twist;
  os << t.header;
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::TwistWithCovarianceStamped> &t)
{
  return os << *t.get();
}