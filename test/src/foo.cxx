//
// Created by julian on 26.11.18.
//

#include <cpprest/json.h>
#include <array>
#include <iostream>
#include <iterator>
#include <ros_bridge_client/utils/serializer.h>
#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/util/covariance.h>

int main(void)
{
  std::cout << static_cast<int8_t>(-9) << "\n";
  std::cout << static_cast<int16_t>(22) << "\n";
  std::cout << static_cast<int32_t>(22) << "\n";
  std::cout << static_cast<int64_t>(22) << "\n";
}