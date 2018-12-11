//
// Created by julian on 11.12.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/pose_array.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PoseArray::PoseArray(std::string frame_id)
  : ROSTypeBase(frame_id),
    header(),
    poses()
{
  poses.reserve(100);
}

void PoseArray::add(const Pose &pose)
{
  poses.emplace_back(pose);
}
