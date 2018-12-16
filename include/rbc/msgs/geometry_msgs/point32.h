//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINT32_MESSAGE_HPP
#define ROSBRIDGECLIENT_POINT32_MESSAGE_HPP

#include <cpprest/json.h>
#include <rbc/msgs/xyzmessage.h>
#include <rbc/ros_types/ros_types.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct Point32 : public XYZMessage<float>
{
  Point32();

  Point32(float x, float y, float z);

  explicit Point32(const web::json::value &response);

  ~Point32() override = default;
};

} // namespace geometry_msgs::msgs::namespace rbc

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Point32 &p);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Point32> &p);

#endif //ROSBRIDGECLIENT_POINTMESSAGE_HPP
