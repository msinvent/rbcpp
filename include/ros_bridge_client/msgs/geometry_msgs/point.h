//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINTMESSAGE_HPP
#define ROSBRIDGECLIENT_POINTMESSAGE_HPP

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/xyzmessage.h>
#include <ros_bridge_client/ros_types/ros_types.h>
#include <memory>
#include <iostream>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct Point : public XYZMessage<double>
{
  Point();

  Point(double x, double y, double z);

  explicit Point(const web::json::value &response);

  ~Point() override = default;

  bool operator==(const Point &point);
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Point &p);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Point> &p);

#endif //ROSBRIDGECLIENT_POINTMESSAGE_HPP
