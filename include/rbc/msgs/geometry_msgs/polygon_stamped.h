//
// Created by julian on 03.12.18.
//

#ifndef ROSBRIDGECLIENT_POLYGON_STAMPED_H
#define ROSBRIDGECLIENT_POLYGON_STAMPED_H

#include <string>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/polygon.h>

namespace rbc::msgs::geometry_msgs
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

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::PolygonStamped &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::PolygonStamped> &p);

#endif //ROSBRIDGECLIENT_POLYGON_STAMPED_H
