//
// Created by julian on 26.11.18.
//

#include <cpprest/json.h>
#include <array>
#include <iostream>
#include <iterator>
#include <ros_bridge_client/utils/serializer.h>
#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/utils/covariance.h>

//std::ostream& operator<<(std::ostream& os, std::array<float, 2> &arr)
//{
//  return os << arr[1];
//}

int main(void)
{
  std::array<float, 2> arr{.1, .2};
  std::cout << arr;
  //  std::array<int, 2> x{1, 2};
//  ros_bridge_client::util::Serializer c;
//  const auto &j = web::json::value::array(c.toJson<int, 2>(x));
//  std::cout << j;
//  std::vector<int> response;
//  ros_bridge_client::util::Deserializer::toArray(response, j);
//  std::copy(std::begin(response), std::end(response), std::ostream_iterator<int>(std::cout, " "));
}