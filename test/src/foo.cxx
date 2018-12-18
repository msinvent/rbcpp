//
// Created by julian on 26.11.18.
//

#include <cpprest/json.h>
#include <array>
#include <iostream>
#include <iterator>
#include <rbc/msgs/geometry_msgs/polygon.h>
#include <rbc/utils/serializer.h>
#include <rbc/utils/deserializer.h>
#include <rbc/msgs/geometry_msgs/util/covariance.h>

int main(void)
{
  using namespace rbc::msgs;

  rbc::utils::Serializer s;
  std::array<std::uint8_t, 25> data{1,2,3,4,5,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
  web::json::value json = web::json::value::array(s.serializeSingles<std::uint8_t, 25>(data));
  std::array<std::uint8_t, 25> data2;

  rbc::utils::Deserializer::toArray<std::uint8_t, 25>(data2, json);
  assert((data2 == data));
}