//
// Created by julian on 29.11.18.
//

#ifndef ROSBRIDGECLIENT_COVARIANCE_H
#define ROSBRIDGECLIENT_COVARIANCE_H

#include <array>
#include <memory>
#include <cmath>
#include <iterator>

namespace ros_bridge_client::msgs::geometry_msgs
{

template<typename T, unsigned int N>
struct Covariance
{
  inline Covariance() = default;
  inline ~Covariance() = default;
  inline explicit Covariance(const std::array<T, N> &data)
    : data(data)
  {}

  Covariance& operator=(const Covariance &cov)
  {
    data = cov.data;
    return *this;
  }

  std::array<T, N> data;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

template <typename T, unsigned int N>
std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Covariance<T, N> &cov)
{
  os << "\nCovariance:";
  if (std::pow(std::sqrt(N), 2) != N)
  {
    return os << "invalid covariance matrix dimensions: m != n";
  }

  auto it = std::begin(cov.data);
  while (it != std::end(cov.data))
  {
    os << "\n\t";
    std::copy(it, it + static_cast<int>(std::sqrt(N)), std::ostream_iterator<T>(os, " "));
    it += static_cast<int>(std::sqrt(N));
  }

  return os;
}

template <typename T, unsigned int N>
std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Covariance<T, N>> &cov)
{
  return os << *cov.get();
}

#endif //ROSBRIDGECLIENT_COVARIANCE_H
