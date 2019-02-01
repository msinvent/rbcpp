//
// Created by julian on 16.12.18.
//

#include <rbc/msgs/sensor_msgs/imu.h>
#include <rbc/msgs/geometry_msgs/util/covariance.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::sensor_msgs;

Imu::Imu()
    : ROSTypeBase("sensor_msgs/Imu"),
      orientation(),
      orientation_covariance(),
      angular_velocity(),
      angular_velocity_covariance(),
      linear_acceleration(),
      linear_acceleration_covariance()
{}

Imu::Imu(const geometry_msgs::Quaternion &orientation, const geometry_msgs::Vector3 &angular_velocity,
         const geometry_msgs::Vector3 &linear_velocity)
    : ROSTypeBase("sensor_msgs/Imu"),
      orientation(orientation),
      orientation_covariance(),
      angular_velocity(angular_velocity),
      angular_velocity_covariance(),
      linear_acceleration(linear_velocity),
      linear_acceleration_covariance()
{}

Imu::Imu(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/Imu"),
      orientation(),
      orientation_covariance(),
      angular_velocity(),
      angular_velocity_covariance(),
      linear_acceleration(),
      linear_acceleration_covariance()
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::deserialize(linear_acceleration, msg.at(U("linear_acceleration")), true);

  utils::Deserializer::deserialize(angular_velocity, msg.at(U("angular_velocity")), true);

  utils::Deserializer::deserialize(orientation, msg.at(U("orientation")), true);

  utils::Deserializer::toArray<float, 9>(linear_acceleration_covariance, msg.at(U("linear_acceleration_covariance")));

  utils::Deserializer::toArray<float, 9>(angular_velocity_covariance, msg.at(U("angular_velocity_covariance")));

  utils::Deserializer::toArray<float, 9>(orientation_covariance, msg.at(U("orientation_covariance")));
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::Imu &imu)
{
  using namespace rbc::msgs::geometry_msgs;

  os << "\nImu";
  os << imu.orientation;
  os << util::Covariance<float, 9>(imu.orientation_covariance);
  os << imu.angular_velocity;
  os << util::Covariance<float, 9>(imu.angular_velocity_covariance);
  os << imu.linear_acceleration;
  os << util::Covariance<float, 9>(imu.linear_acceleration_covariance);
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::Imu> &imu)
{
  return os << *imu.get();
}
