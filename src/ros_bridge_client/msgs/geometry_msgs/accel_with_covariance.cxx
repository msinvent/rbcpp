//
// Created by Julian on 29.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/accel_with_covariance.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

AccelWithCovariance::AccelWithCovariance()
    : ROSTypeBase("geometry_msgs/AccelWithCovariance"),
      accel(),
      covariance()
{}

AccelWithCovariance::AccelWithCovariance(double lx, double ly, double lz, double ax, double ay, double az,
                                         const std::array<double, 36> &covariance)
    : ROSTypeBase("geometry_msgs/AccelWithCovariance"),
      accel(lx, ly, lz, ax, ay, az),
      covariance(covariance)
{}

AccelWithCovariance::AccelWithCovariance(const Vector3 &linear, const Vector3 &angular,
                                         const std::array<double, 36> &covariance)
    : ROSTypeBase("geometry_msgs/AccelWithCovariance"),
      accel(linear, angular),
      covariance(covariance)
{}

AccelWithCovariance::AccelWithCovariance(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/AccelWithCovariance"),
      accel(),
      covariance()
{
  const auto &msg = response.at(U("msg"));
  const auto &accel_msg = msg.at(U("accel"));
  const auto &cov_msg = msg.at(U("covariance"));
  
  std::tie(accel.linear.x, accel.linear.y, accel.linear.z) =
      utils::Deserializer::toVector3(accel_msg.at(U("linear")), true);

  std::tie(accel.angular.x, accel.angular.y, accel.angular.z) =
      utils::Deserializer::toVector3(accel_msg.at(U("angular")), true);
  
  covariance = utils::Deserializer::toArray<double, 36>(cov_msg);
}

AccelWithCovariance::AccelWithCovariance(const Accel &accel, const std::array<double, 36> &covariance)
    : ROSTypeBase("geometry_msgs/AccelWithCovariance"),
      accel(accel),
      covariance(covariance)
{}

std::ostream &operator<<(std::ostream &os, const AccelWithCovariance &a)
{
  os << "\nAccel With Covariance";
  os << a.accel;
  os << util::Covariance<double, 36>(a.covariance);
  return os;
}

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<AccelWithCovariance> &a)
{
  return os << *a.get();
}
