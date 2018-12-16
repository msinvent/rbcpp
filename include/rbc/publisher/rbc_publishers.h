//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_RBC_MESSAGES_H
#define ROSBRIDGECLIENT_RBC_MESSAGES_H

#include <rbc/publisher/rbc_publisher.h>
#include <rbc/msgs/std_msgs/string_message.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/nav_msgs/grid_cells_message.h>
#include <rbc/msgs/geometry_msgs/pose_message.h>
#include <rbc/msgs/geometry_msgs/accel_message.h>
#include <rbc/msgs/geometry_msgs/point32_message.h>
#include <rbc/msgs/geometry_msgs/twist_message.h>
#include <rbc/msgs/geometry_msgs/wrench_message.h>
#include <rbc/msgs/geometry_msgs/pose_2d_message.h>
#include <rbc/msgs/geometry_msgs/vector3_message.h>
#include <rbc/msgs/geometry_msgs/polygon_message.h>
#include <rbc/msgs/geometry_msgs/inertia_message.h>
#include <rbc/msgs/geometry_msgs/transform_message.h>
#include <rbc/msgs/geometry_msgs/quaternion_message.h>
#include <rbc/msgs/geometry_msgs/pose_array_message.h>
#include <rbc/msgs/geometry_msgs/pose_stamped_message.h>
#include <rbc/msgs/geometry_msgs/accel_stamped_message.h>
#include <rbc/msgs/geometry_msgs/point_stamped.h>
#include <rbc/msgs/geometry_msgs/twist_stamped_message.h>
#include <rbc/msgs/geometry_msgs/wrench_stamped_message.h>
#include <rbc/msgs/geometry_msgs/polygon_stamped_message.h>
#include <rbc/msgs/geometry_msgs/inertia_stamped_message.h>
#include <rbc/msgs/geometry_msgs/vector3_stamped_message.h>
#include <rbc/msgs/geometry_msgs/transform_stamped_message.h>
#include <rbc/msgs/geometry_msgs/quaternion_stamped_message.h>

using RBCStringPublisher            = rbc::publisher::RBCPublisher<rbc::msgs::std_msgs::StringMessage>;
using RBCHeaderPublisher            = rbc::publisher::RBCPublisher<rbc::msgs::std_msgs::Header>;
using RBCPointPublisher             = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::Point>;
using RBCPoint32Publisher           = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::Point32Message>;
using RBCPointStampedPublisher      = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::PointStamped>;
using RBCQuaternionPublisher        = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::QuaternionMessage>;
using RBCQuaternionStampedPublisher = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::QuaternionStampedMessage>;
using RBCVector3Publisher           = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::Vector3Message>;
using RBCVector3StampedPublisher    = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::Vector3StampedMessage>;
using RBCPosePublisher              = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::PoseMessage>;
using RBCPoseStampedPublisher       = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::PoseStampedMessage>;
using RBCAccelPublisher             = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::Accel>;
using RBCAccelStampedPublisher      = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::AccelStampedMessage>;
using RBCTwistPublisher             = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::TwistMessage>;
using RBCTwistStampedPublisher      = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::TwistStampedMessage>;
using RBCWrenchPublisher            = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::WrenchMessage>;
using RBCWrenchStampedPublisher     = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::WrenchStampedMessage>;
using RBCTransformPublisher         = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::TransformMessage>;
using RBCTransformStampedPublisher  = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::TransformStampedMessage>;
using RBCPoseArrayPublisher         = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::PoseArrayMessage>;
using RBCGridCellsPublisher         = rbc::publisher::RBCPublisher<rbc::msgs::nav_msgs::GridCellsMessage>;
using RBCPolygonPublisher           = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::PolygonMessage>;
using RBCPolygonStampedPublisher    = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::PolygonStampedMessage>;
using RBCInertiaPublisher           = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::InertiaMessage>;
using RBCInertiaStampedPublisher    = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::InertiaStampedMessage>;
using RBCPose2DPublisher            = rbc::publisher::RBCPublisher<rbc::msgs::geometry_msgs::Pose2DMessage>;

#endif //ROSBRIDGECLIENT_RBC_MESSAGES_H
