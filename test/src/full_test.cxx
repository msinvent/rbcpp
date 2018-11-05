#include <iostream>
#include <atomic>
#include <thread>
#include <memory>
#include <chrono>
#include <ros_bridge_client/ros_bridge_client.h>
#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/publisher/rbc_publisher.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <cassert>

using namespace std::chrono;
using namespace ros_bridge_client;
using namespace ros_bridge_client::msgs;


std::atomic<size_t> messages_received;
size_t num_publishers = 16;

void hcallback(const std::shared_ptr<std_msgs::Header> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Header]\n";
  assert((msg->frame_id == "a frame"));
}

void pocallback(const std::shared_ptr<geometry_msgs::Pose> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Pose]\n";
  assert((msg->point.x == .1));
  assert((msg->point.y == .2));
  assert((msg->point.z == .3));
  assert((msg->quaternion.x == .1));
  assert((msg->quaternion.y == .2));
  assert((msg->quaternion.z == .3));
  assert((msg->quaternion.w == .4));
}

void pcallback(const std::shared_ptr<geometry_msgs::Point> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Point]\n";
  assert((msg->x == .1));
  assert((msg->y == .2));
  assert((msg->z == .3));
}

void acallback(const std::shared_ptr<geometry_msgs::Accel> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Accel]\n";
  assert((msg->linear.x == .1));
  assert((msg->linear.y == .2));
  assert((msg->linear.z == .3));
  assert((msg->angular.x == .3));
  assert((msg->angular.y == .2));
  assert((msg->angular.z == .1));
}

void p32callback(const std::shared_ptr<geometry_msgs::Point32> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Point32]\n";
  assert((msg->x == .1f));
  assert((msg->y == .2f));
  assert((msg->z == .3f));
}

void pscallback(const std::shared_ptr<geometry_msgs::PointStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[PointStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->point.x == .1));
  assert((msg->point.y == .2));
  assert((msg->point.z == .3));
}

void poscallback(const std::shared_ptr<geometry_msgs::PoseStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[PointStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->pose.point.x == .1));
  assert((msg->pose.point.y == .2));
  assert((msg->pose.point.z == .3));
  assert((msg->pose.quaternion.x == .1));
  assert((msg->pose.quaternion.y == .2));
  assert((msg->pose.quaternion.z == .3));
  assert((msg->pose.quaternion.w == .4));
}

void vcallback(const std::shared_ptr<geometry_msgs::Vector3> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Vector3]\n";
  assert((msg->x == .1));
  assert((msg->y == .2));
  assert((msg->z == .3));
}

void vscallback(const std::shared_ptr<geometry_msgs::Vector3Stamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Vector3Stamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->vector.x == .1));
  assert((msg->vector.y == .2));
  assert((msg->vector.z == .3));
}

void qcallback(const std::shared_ptr<geometry_msgs::Quaternion> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Quaternion]\n";
  assert((msg->x == .1));
  assert((msg->y == .2));
  assert((msg->z == .3));
  assert((msg->w == .4));
}

void qscallback(const std::shared_ptr<geometry_msgs::QuaternionStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[QuaternionStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->quaternion.x == .1));
  assert((msg->quaternion.y == .2));
  assert((msg->quaternion.z == .3));
  assert((msg->quaternion.w == .4));
}

void ascallback(const std::shared_ptr<geometry_msgs::AccelStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[AccelStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->accel.linear.x == .1));
  assert((msg->accel.linear.y == .2));
  assert((msg->accel.linear.z == .3));
  assert((msg->accel.angular.x == .3));
  assert((msg->accel.angular.y == .2));
  assert((msg->accel.angular.z == .1));
}

void wcallback(const std::shared_ptr<geometry_msgs::Wrench> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Wrench]\n";
  assert((msg->force.x == .1));
  assert((msg->force.y == .2));
  assert((msg->force.z == .3));
  assert((msg->torque.x == .3));
  assert((msg->torque.y == .2));
  assert((msg->torque.z == .1));
}

void wscallback(const std::shared_ptr<geometry_msgs::WrenchStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[WrenchStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->wrench.force.x == .1));
  assert((msg->wrench.force.y == .2));
  assert((msg->wrench.force.z == .3));
  assert((msg->wrench.torque.x == .3));
  assert((msg->wrench.torque.y == .2));
  assert((msg->wrench.torque.z == .1));
}

void icallback(const std::shared_ptr<geometry_msgs::Inertia> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[Inertia]\n";
  assert((msg->m == .1));
  assert((msg->ixx == .2));
  assert((msg->ixy == .3));
  assert((msg->ixz == .4));
  assert((msg->iyy == .5));
  assert((msg->iyz == .6));
  assert((msg->izz == .7));
  assert((msg->com.x == .1));
  assert((msg->com.y == .2));
  assert((msg->com.z == .3));
}

void iscallback(const std::shared_ptr<geometry_msgs::InertiaStamped> msg)
{
  std::cout << "Received " << ++messages_received << " / " << (num_publishers*10) << " messages \t[InertiaStamped]\n";
  assert((msg->header.frame_id == "a frame"));
  assert((msg->inertia.m == .1));
  assert((msg->inertia.ixx == .2));
  assert((msg->inertia.ixy == .3));
  assert((msg->inertia.ixz == .4));
  assert((msg->inertia.iyy == .5));
  assert((msg->inertia.iyz == .6));
  assert((msg->inertia.izz == .7));
  assert((msg->inertia.com.x == .1));
  assert((msg->inertia.com.y == .2));
  assert((msg->inertia.com.z == .3));
}

int main()
{
  size_t messages = 0;

  std::chrono::milliseconds pause(500);
  auto rbc = ROSBridgeClient::init("ws://127.0.0.1:9090");

  auto header_pub = rbc->addPublisher<std_msgs::Header>("/rosbridge/header/");
  auto point_pub = rbc->addPublisher<geometry_msgs::Point>("/rosbridge/point/");
  auto accel_pub = rbc->addPublisher<geometry_msgs::Accel>("/rosbridge/accel/");
  auto wrench_pub = rbc->addPublisher<geometry_msgs::Wrench>("/rosbridge/wrench/");
  auto pose_pub = rbc->addPublisher<geometry_msgs::Pose>("/rosbridge/pose/");
  auto point32_pub = rbc->addPublisher<geometry_msgs::Point32>("/rosbridge/point32/");
  auto inertia_pub = rbc->addPublisher<geometry_msgs::Inertia>("/rosbridge/inertia/");
  auto inertia_stamped_pub = rbc->addPublisher<geometry_msgs::InertiaStamped>("/rosbridge/inertia_stamped/");
  auto point_stamped_pub = rbc->addPublisher<geometry_msgs::PointStamped>("/rosbridge/point_stamped/");
  auto accel_stamped_pub = rbc->addPublisher<geometry_msgs::AccelStamped>("/rosbridge/accel_stamped/");
  auto wrench_stamped_pub = rbc->addPublisher<geometry_msgs::WrenchStamped>("/rosbridge/wrench_stamped/");
  auto pose_stamped_pub = rbc->addPublisher<geometry_msgs::PoseStamped>("/rosbridge/pose_stamped/");
  auto vector3_pub = rbc->addPublisher<geometry_msgs::Vector3>("/rosbridge/vector3/");
  auto vector3_stamped_pub = rbc->addPublisher<geometry_msgs::Vector3Stamped>("/rosbridge/vector3_stamped/");
  auto quaternion_pub = rbc->addPublisher<geometry_msgs::Quaternion>("/rosbridge/quaternion/");
  auto quaternion_stamped_pub = rbc->addPublisher<geometry_msgs::QuaternionStamped>("/rosbridge/quaternion_stamped/");


  auto header_sub = rbc->addSubscriber<std_msgs::Header>("/rosbridge/header/", 100, hcallback);
  auto point_sub = rbc->addSubscriber<geometry_msgs::Point>("/rosbridge/point/", 100, pcallback);
  auto accel_sub = rbc->addSubscriber<geometry_msgs::Accel>("/rosbridge/accel/", 100, acallback);
  auto wrench_sub = rbc->addSubscriber<geometry_msgs::Wrench>("/rosbridge/wrench/", 100, wcallback);
  auto pose_sub = rbc->addSubscriber<geometry_msgs::Pose>("/rosbridge/pose/", 100, pocallback);
  auto point32_sub = rbc->addSubscriber<geometry_msgs::Point32>("/rosbridge/point32/", 100, p32callback);
  auto inertia_sub = rbc->addSubscriber<geometry_msgs::Inertia>("/rosbridge/inertia/", 100, icallback);
  auto inertia_stamped_sub = rbc->addSubscriber<geometry_msgs::InertiaStamped>("/rosbridge/inertia_stamped/", 100, iscallback);
  auto point_stamped_sub = rbc->addSubscriber<geometry_msgs::PointStamped>("/rosbridge/point_stamped/", 100, pscallback);
  auto accel_stamped_sub = rbc->addSubscriber<geometry_msgs::AccelStamped>("/rosbridge/accel_stamped/", 100, ascallback);
  auto wrench_stamped_sub = rbc->addSubscriber<geometry_msgs::WrenchStamped>("/rosbridge/wrench_stamped/", 100, wscallback);
  auto pose_stamped_sub = rbc->addSubscriber<geometry_msgs::PoseStamped>("/rosbridge/pose_stamped/", 100, poscallback);
  auto vector3_sub = rbc->addSubscriber<geometry_msgs::Vector3>("/rosbridge/vector3/", 100, vcallback);
  auto vector3_stamped_sub = rbc->addSubscriber<geometry_msgs::Vector3Stamped>("/rosbridge/vector3_stamped/", 100, vscallback);
  auto quaternion_sub = rbc->addSubscriber<geometry_msgs::Quaternion>("/rosbridge/quaternion/", 100, qcallback);
  auto quaternion_stamped_sub = rbc->addSubscriber<geometry_msgs::QuaternionStamped>("/rosbridge/quaternion_stamped/", 100, qscallback);


  while (messages++ < 10)
  {
    std_msgs::Header h("a frame");
    header_pub->publish(h);

    geometry_msgs::Pose po(0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.4);
    pose_pub->publish(po);

    geometry_msgs::Accel a(0.1, 0.2, 0.3, 0.3, 0.2, 0.1);
    accel_pub->publish(a);

    geometry_msgs::Wrench w(0.1, 0.2, 0.3, 0.3, 0.2, 0.1);
    wrench_pub->publish(w);

    geometry_msgs::WrenchStamped ws(0.1, 0.2, 0.3, 0.3, 0.2, 0.1, "a frame");
    wrench_stamped_pub->publish(ws);

    geometry_msgs::PoseStamped pos(0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.4, "a frame");
    pose_stamped_pub->publish(pos);

    geometry_msgs::Point p(0.1, 0.2, 0.3);
    point_pub->publish(p);

    geometry_msgs::Point32 p32(0.1f, 0.2f, 0.3f);
    point32_pub->publish(p32);

    geometry_msgs::PointStamped ps(0.1, 0.2, 0.3, "a frame");
    point_stamped_pub->publish(ps);

    geometry_msgs::Vector3 v(0.1, 0.2, 0.3);
    vector3_pub->publish(v);

    geometry_msgs::Vector3Stamped vs(0.1, 0.2, 0.3, "a frame");
    vector3_stamped_pub->publish(vs);

    geometry_msgs::Quaternion q(0.1, 0.2, 0.3, 0.4);
    quaternion_pub->publish(q);

    geometry_msgs::QuaternionStamped qs(0.1, 0.2, 0.3, 0.4, "a frame");
    quaternion_stamped_pub->publish(qs);

    geometry_msgs::AccelStamped as(0.1, 0.2, 0.3, 0.3, 0.2, 0.1, "a frame");
    accel_stamped_pub->publish(as);
    
    geometry_msgs::Inertia i(0.1, geometry_msgs::Vector3(.1, .2, .3), 0.2, 0.3, 0.4, 0.5, 0.6, 0.7);
    inertia_pub->publish(i);

    geometry_msgs::InertiaStamped is(0.1, geometry_msgs::Vector3(.1, .2, .3), 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, "a frame");
    inertia_stamped_pub->publish(is);
    
    std::this_thread::sleep_for(pause);
  }

  return messages_received == num_publishers*10 ? 0 : 1;
}
