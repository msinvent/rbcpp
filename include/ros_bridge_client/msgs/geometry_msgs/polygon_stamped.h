//
// Created by julian on 03.12.18.
//

#ifndef ROSBRIDGECLIENT_POLYGON_STAMPED_H
#define ROSBRIDGECLIENT_POLYGON_STAMPED_H

#include <string>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct PolygonStamped : public ROSTypeBase
{
  explicit PolygonStamped(std::string frame_id = "world");

  explicit PolygonStamped(unsigned int size, std::string frame_id = "world");

  explicit PolygonStamped(const web::json::value &response);

  ~PolygonStamped() final = default;

  void add(const Point32 &p32);

  Polygon polygon;
  std_msgs::Header header;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

#endif //ROSBRIDGECLIENT_POLYGON_STAMPED_H
