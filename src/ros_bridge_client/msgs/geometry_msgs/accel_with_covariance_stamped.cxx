//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/accel_with_covariance_stamped.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

AccelWithCovarianceStamped::AccelWithCovarianceStamped()
    : ROSTypeBase("geometry_msgs/AccelWithCovarianceStamped"),
      accel(),
      header()
{}

AccelWithCovarianceStamped::AccelWithCovarianceStamped(const Vector3 &linear, const Vector3 &angular,
                                                       const std::array<double, 36> &covariance, std::string frame_id)
    : ROSTypeBase("geometry_msgs/AccelWithCovarianceStamped"),
      accel(linear, angular, covariance),
      header(frame_id)
{}

AccelWithCovarianceStamped::AccelWithCovarianceStamped(const AccelWithCovariance &accel_cov, std::string frame_id)
    : ROSTypeBase("geometry_msgs/AccelWithCovarianceStamped"),
      accel(accel_cov),
      header(frame_id)
{}

AccelWithCovarianceStamped::AccelWithCovarianceStamped(const Accel &accel, const std::array<double, 36> &covariance,
                                                       std::string frame_id)
    : ROSTypeBase("geometry_msgs/AccelWithCovarianceStamped"),
      accel(accel, covariance),
      header(frame_id)
{}

AccelWithCovarianceStamped::AccelWithCovarianceStamped(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/AccelWithCovarianceStamped"),
      accel(),
      header()
{
  const auto &msg = response.at(U("msg"));
  const auto &accel_base_msg = msg.at(U("accel"));
  const auto &accel_msg = accel_base_msg.at(U("accel"));
  const auto &cov_msg = accel_base_msg.at(U("covariance"));
  const auto &header_msg = msg.at(U("header"));

  std::tie(accel.accel.linear.x, accel.accel.linear.y, accel.accel.linear.z) =
      utils::Deserializer::toVector3(accel_msg.at(U("linear")), true);

  std::tie(accel.accel.angular.x, accel.accel.angular.y, accel.accel.angular.z) =
      utils::Deserializer::toVector3(accel_msg.at(U("angular")), true);

  accel.covariance = utils::Deserializer::toArray<double, 36>(cov_msg);

  utils::Deserializer::toHeader(header, header_msg, true);
}

std::ostream &operator<<(std::ostream &os, const AccelWithCovarianceStamped &a)
{
  os << "\nAccel With Covariance Stamped";
  os << a.accel;
  os << a.header;
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<AccelWithCovarianceStamped> &a)
{
  return os << *a.get();
}