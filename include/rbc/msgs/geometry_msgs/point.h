//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINTMESSAGE_HPP
#define ROSBRIDGECLIENT_POINTMESSAGE_HPP

#include <cpprest/json.h>
#include <rbc/msgs/xyzmessage.h>
#include <rbc/ros_types/ros_types.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct Point : public XYZMessage<double>
{
  Point();

  Point(double x, double y, double z);

  explicit Point(const web::json::value &response);

  ~Point() override = default;

  bool operator==(const Point &point);
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Point &p);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Point> &p);

#endif //ROSBRIDGECLIENT_POINTMESSAGE_HPP
