//
// Created by julian on 11.12.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/pose_array.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PoseArray::PoseArray(std::string frame_id)
  : ROSTypeBase("geometry_msgs/PoseArray"),
    header(frame_id),
    poses()
{}

void PoseArray::add(const Pose &pose)
{
  poses.emplace_back(pose);
}
