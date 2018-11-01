//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_RBC_MESSAGES_H
#define ROSBRIDGECLIENT_RBC_MESSAGES_H

#include <ros_bridge_client/publisher/rbc_publisher.h>
#include <ros_bridge_client/msgs/std_msgs/string_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/nav_msgs/grid_cells_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_2d_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_array_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform_stamped_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped_message.h>

using RBCStringPublisher            = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::std_msgs::StringMessage>;
using RBCHeaderPublisher            = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::std_msgs::Header>;
using RBCPointPublisher             = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::Point>;
using RBCPoint32Publisher           = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::Point32Message>;
using RBCPointStampedPublisher      = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::PointStamped>;
using RBCQuaternionPublisher        = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::QuaternionMessage>;
using RBCQuaternionStampedPublisher = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::QuaternionStampedMessage>;
using RBCVector3Publisher           = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::Vector3Message>;
using RBCVector3StampedPublisher    = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::Vector3StampedMessage>;
using RBCPosePublisher              = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::PoseMessage>;
using RBCPoseStampedPublisher       = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::PoseStampedMessage>;
using RBCAccelPublisher             = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::Accel>;
using RBCAccelStampedPublisher      = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::AccelStampedMessage>;
using RBCTwistPublisher             = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::TwistMessage>;
using RBCTwistStampedPublisher      = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::TwistStampedMessage>;
using RBCWrenchPublisher            = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::WrenchMessage>;
using RBCWrenchStampedPublisher     = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::WrenchStampedMessage>;
using RBCTransformPublisher         = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::TransformMessage>;
using RBCTransformStampedPublisher  = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::TransformStampedMessage>;
using RBCPoseArrayPublisher         = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::PoseArrayMessage>;
using RBCGridCellsPublisher         = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::nav_msgs::GridCellsMessage>;
using RBCPolygonPublisher           = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::PolygonMessage>;
using RBCPolygonStampedPublisher    = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::PolygonStampedMessage>;
using RBCInertiaPublisher           = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::InertiaMessage>;
using RBCInertiaStampedPublisher    = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::InertiaStampedMessage>;
using RBCPose2DPublisher            = ros_bridge_client::publisher::RBCPublisher<ros_bridge_client::msgs::geometry_msgs::Pose2DMessage>;

#endif //ROSBRIDGECLIENT_RBC_MESSAGES_H
