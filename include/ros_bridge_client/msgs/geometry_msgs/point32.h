//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINT32_MESSAGE_HPP
#define ROSBRIDGECLIENT_POINT32_MESSAGE_HPP

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/xyzmessage.h>
#include <ros_bridge_client/ros_types/ros_types.h>
#include <memory>
#include <iostream>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct Point32 : public XYZMessage<float>
{
  Point32();

  Point32(float x, float y, float z);

  explicit Point32(const web::json::value &response);

  ~Point32() override = default;
};

} // namespace geometry_msgs::msgs::namespace ros_bridge_client

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::Point32 &p);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::Point32> &p);

#endif //ROSBRIDGECLIENT_POINTMESSAGE_HPP
