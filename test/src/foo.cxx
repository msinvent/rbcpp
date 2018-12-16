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

  geometry_msgs::Point32 p(.1, .2, .3);
  geometry_msgs::PolygonStamped poly;
  poly.add(p);
  poly.add(p);

  std::cout << poly;
}