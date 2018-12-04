//
// Created by julian on 26.11.18.
//

#include <cpprest/json.h>
#include <array>
#include <iostream>
#include <iterator>
#include <ros_bridge_client/msgs/geometry_msgs/polygon.h>
#include <ros_bridge_client/utils/serializer.h>
#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/util/covariance.h>

int main(void)
{
  using namespace ros_bridge_client::msgs;

  geometry_msgs::Point32 p(.1, .2, .3);
  geometry_msgs::PolygonStamped poly;
  poly.add(p);
  poly.add(p);

  std::cout << poly;
}