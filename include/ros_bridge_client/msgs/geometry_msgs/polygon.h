//
// Created by julian on 03.12.18.
//

#ifndef ROSBRIDGECLIENT_POLYGON_H
#define ROSBRIDGECLIENT_POLYGON_H

#include <vector>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct Polygon : public ROSTypeBase
{
  Polygon();

  explicit Polygon(unsigned int size);

  explicit Polygon(const web::json::value &response);

  ~Polygon() final = default;

  void add(const Point32 &p32);

  std::vector<Point32> points;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Polygon &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Polygon> &p);

#endif //ROSBRIDGECLIENT_POLYGON_H
