//
// Created by julian on 11.12.18.
//

#ifndef ROSBRIDGECLIENT_POSE_ARRAY_H
#define ROSBRIDGECLIENT_POSE_ARRAY_H

#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/ros_type_base.h>
#include <ros_bridge_client/msgs/array_base.h>
#include <cpprest/json.h>
#include <vector>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct PoseArray : public ROSTypeBase
{
  explicit PoseArray(std::string frame_id = "world");

  explicit PoseArray(const web::json::value &response);

  ~PoseArray() final = default;

  void add(const Pose &pose);
  
  std_msgs::Header header;
  std::vector<Pose> poses;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

#endif //ROSBRIDGECLIENT_POSE_ARRAY_H
