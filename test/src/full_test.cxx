#include <test/full_test.h>

using namespace std::chrono;
using namespace ros_bridge_client;
using namespace ros_bridge_client::msgs;
using namespace test;

std::atomic<size_t> callbacks::messages_received = 0;
size_t callbacks::num_publishers = 0;

int main(void)
{
  size_t messages = 0;
  auto& config = config_parser::ConfigParser::init("config.json");
  std::chrono::milliseconds pause(config.pause());
  callbacks::messages_received = 0;
  callbacks::num_publishers = config.publishers();
  auto rbc = ROSBridgeClient::init(config.host());

  auto header_pub = rbc->addPublisher<std_msgs::Header>("/rosbridge/header/");
  auto string_pub = rbc->addPublisher<std_msgs::String>("/rosbridge/string/");
  auto float32_pub = rbc->addPublisher<std_msgs::Float32>("/rosbridge/float32/");
  auto float64_pub = rbc->addPublisher<std_msgs::Float64>("/rosbridge/float64/");
  auto color_pub = rbc->addPublisher<std_msgs::ColorRGBA>("/rosbridge/color/");
  auto point_pub = rbc->addPublisher<geometry_msgs::Point>("/rosbridge/point/");
  auto accel_pub = rbc->addPublisher<geometry_msgs::Accel>("/rosbridge/accel/");
  auto twist_pub = rbc->addPublisher<geometry_msgs::Twist>("/rosbridge/twist/");
  auto wrench_pub = rbc->addPublisher<geometry_msgs::Wrench>("/rosbridge/wrench/");
  auto pose_pub = rbc->addPublisher<geometry_msgs::Pose>("/rosbridge/pose/");
  auto point32_pub = rbc->addPublisher<geometry_msgs::Point32>("/rosbridge/point32/");
  auto pose2d_pub = rbc->addPublisher<geometry_msgs::Pose2D>("/rosbridge/pose2d/");
  auto inertia_pub = rbc->addPublisher<geometry_msgs::Inertia>("/rosbridge/inertia/");
  auto pose_cov_pub = rbc->addPublisher<geometry_msgs::PoseWithCovariance>("/rosbridge/pose_with_covariance/");
  auto pose_cov_stamp_pub = rbc->addPublisher<geometry_msgs::PoseWithCovarianceStamped>("/rosbridge/pose_with_covariance_stamped/");
  auto transform_pub = rbc->addPublisher<geometry_msgs::Transform>("/rosbridge/transform/");
  auto inertia_stamped_pub = rbc->addPublisher<geometry_msgs::InertiaStamped>("/rosbridge/inertia_stamped/");
  auto point_stamped_pub = rbc->addPublisher<geometry_msgs::PointStamped>("/rosbridge/point_stamped/");
  auto accel_stamped_pub = rbc->addPublisher<geometry_msgs::AccelStamped>("/rosbridge/accel_stamped/");
  auto twist_stamped_pub = rbc->addPublisher<geometry_msgs::TwistStamped>("/rosbridge/twist_stamped/");
  auto twc_pub = rbc->addPublisher<geometry_msgs::TwistWithCovariance>("/rosbridge/twist_with_covariance/");
  auto accelwc_pub = rbc->addPublisher<geometry_msgs::AccelWithCovariance>("/rosbridge/accel_with_covariance/");
  auto accelwcs_pub = rbc->addPublisher<geometry_msgs::AccelWithCovarianceStamped>("/rosbridge/accel_with_covariance_stamped/");
  auto twcs_pub = rbc->addPublisher<geometry_msgs::TwistWithCovarianceStamped>("/rosbridge/twist_with_covariance_stamped/");
  auto wrench_stamped_pub = rbc->addPublisher<geometry_msgs::WrenchStamped>("/rosbridge/wrench_stamped/");
  auto pose_stamped_pub = rbc->addPublisher<geometry_msgs::PoseStamped>("/rosbridge/pose_stamped/");
  auto transform_stamped_pub = rbc->addPublisher<geometry_msgs::TransformStamped>("/rosbridge/transform_stamped/");
  auto vector3_pub = rbc->addPublisher<geometry_msgs::Vector3>("/rosbridge/vector3/");
  auto vector3_stamped_pub = rbc->addPublisher<geometry_msgs::Vector3Stamped>("/rosbridge/vector3_stamped/");
  auto quaternion_pub = rbc->addPublisher<geometry_msgs::Quaternion>("/rosbridge/quaternion/");
  auto quaternion_stamped_pub = rbc->addPublisher<geometry_msgs::QuaternionStamped>("/rosbridge/quaternion_stamped/");


  auto header_sub = rbc->addSubscriber<std_msgs::Header>("/rosbridge/header/", 100, callbacks::hcallback);
  auto string_sub = rbc->addSubscriber<std_msgs::String>("/rosbridge/string/", 100, callbacks::scallback);
  auto f32_sub = rbc->addSubscriber<std_msgs::Float32>("/rosbridge/float32/", 100, callbacks::f32callback);
  auto f64_sub = rbc->addSubscriber<std_msgs::Float64>("/rosbridge/float64/", 100, callbacks::f64callback);
  auto color_sub = rbc->addSubscriber<std_msgs::ColorRGBA>("/rosbridge/color/", 100, callbacks::ccallback);
  auto point_sub = rbc->addSubscriber<geometry_msgs::Point>("/rosbridge/point/", 100, callbacks::pcallback);
  auto accel_sub = rbc->addSubscriber<geometry_msgs::Accel>("/rosbridge/accel/", 100, callbacks::acallback);
  auto twist_sub = rbc->addSubscriber<geometry_msgs::Twist>("/rosbridge/twist/", 100, callbacks::twcallback);
  auto wrench_sub = rbc->addSubscriber<geometry_msgs::Wrench>("/rosbridge/wrench/", 100, callbacks::wcallback);
  auto pose_sub = rbc->addSubscriber<geometry_msgs::Pose>("/rosbridge/pose/", 100, callbacks::pocallback);
  auto pose_cov_sub = rbc->addSubscriber<geometry_msgs::PoseWithCovariance>("/rosbridge/pose_with_covariance/", 100, callbacks::pocovcallback);
  auto pose_cov_stamp_sub = rbc->addSubscriber<geometry_msgs::PoseWithCovarianceStamped>("/rosbridge/pose_with_covariance_stamped/", 100, callbacks::pocovscallback);
  auto point32_sub = rbc->addSubscriber<geometry_msgs::Point32>("/rosbridge/point32/", 100, callbacks::p32callback);
  auto pose2d_sub = rbc->addSubscriber<geometry_msgs::Pose2D>("/rosbridge/pose2d/", 100, callbacks::p2dcallback);
  auto inertia_sub = rbc->addSubscriber<geometry_msgs::Inertia>("/rosbridge/inertia/", 100, callbacks::icallback);
  auto transform_sub = rbc->addSubscriber<geometry_msgs::Transform>("/rosbridge/transform/", 100, callbacks::tcallback);
  auto transform_stamped_sub = rbc->addSubscriber<geometry_msgs::TransformStamped>("/rosbridge/transform_stamped/", 100, callbacks::tscallback);
  auto inertia_stamped_sub = rbc->addSubscriber<geometry_msgs::InertiaStamped>("/rosbridge/inertia_stamped/", 100, callbacks::iscallback);
  auto point_stamped_sub = rbc->addSubscriber<geometry_msgs::PointStamped>("/rosbridge/point_stamped/", 100, callbacks::pscallback);
  auto accel_stamped_sub = rbc->addSubscriber<geometry_msgs::AccelStamped>("/rosbridge/accel_stamped/", 100, callbacks::ascallback);
  auto twist_stamped_sub = rbc->addSubscriber<geometry_msgs::TwistStamped>("/rosbridge/twist_stamped/", 100, callbacks::twscallback);
  auto twc_sub = rbc->addSubscriber<geometry_msgs::TwistWithCovariance>("/rosbridge/twist_with_covariance/", 100, callbacks::twccallback);
  auto accel_cov_sub = rbc->addSubscriber<geometry_msgs::AccelWithCovariance>("/rosbridge/accel_with_covariance/", 100, callbacks::acovcallback);
  auto accel_cov_stamp_sub = rbc->addSubscriber<geometry_msgs::AccelWithCovarianceStamped>("/rosbridge/accel_with_covariance_stamped/", 100, callbacks::acovscallback);
  auto twcs_sub = rbc->addSubscriber<geometry_msgs::TwistWithCovarianceStamped>("/rosbridge/twist_with_covariance_stamped/", 100, callbacks::twcscallback);
  auto wrench_stamped_sub = rbc->addSubscriber<geometry_msgs::WrenchStamped>("/rosbridge/wrench_stamped/", 100, callbacks::wscallback);
  auto pose_stamped_sub = rbc->addSubscriber<geometry_msgs::PoseStamped>("/rosbridge/pose_stamped/", 100, callbacks::poscallback);
  auto vector3_sub = rbc->addSubscriber<geometry_msgs::Vector3>("/rosbridge/vector3/", 100, callbacks::vcallback);
  auto vector3_stamped_sub = rbc->addSubscriber<geometry_msgs::Vector3Stamped>("/rosbridge/vector3_stamped/", 100, callbacks::vscallback);
  auto quaternion_sub = rbc->addSubscriber<geometry_msgs::Quaternion>("/rosbridge/quaternion/", 100, callbacks::qcallback);
  auto quaternion_stamped_sub = rbc->addSubscriber<geometry_msgs::QuaternionStamped>("/rosbridge/quaternion_stamped/", 100, callbacks::qscallback);

  std::array<double, 36> covariance( {.1, .2, 3., .4, .5, .6,
                                      .7, .8, .9, 1., 1.1, 1.2,
                                      1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                      1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                      2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                      3.1, 3.2, 3.3, 3.4, 3.5, 3.6});
  while (messages++ < 10)
  {
    std::this_thread::sleep_for(pause);

    std_msgs::Header h("a frame");
    header_pub->publish(h);

    std_msgs::String s("a string");
    string_pub->publish(s);

    std_msgs::ColorRGBA c(.1, .2, .3, .4);
    color_pub->publish(c);

    std_msgs::Float32 f32(.1);
    float32_pub->publish(f32);

    std_msgs::Float64 f64(.1);
    float64_pub->publish(f64);

    geometry_msgs::Pose po(0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.4);
    pose_pub->publish(po);

    geometry_msgs::Accel a(0.1, 0.2, 0.3, 0.3, 0.2, 0.1);
    accel_pub->publish(a);
    
    geometry_msgs::AccelWithCovariance acov(a, covariance);
    accelwc_pub->publish(acov);

    geometry_msgs::AccelWithCovarianceStamped acovs(acov, "a frame");
    accelwcs_pub->publish(acovs);

    geometry_msgs::Twist tw(0.1, 0.2, 0.3, 0.3, 0.2, 0.1);
    twist_pub->publish(tw);

    geometry_msgs::TwistStamped tws(0.1, 0.2, 0.3, 0.3, 0.2, 0.1, "a frame");
    twist_stamped_pub->publish(tws);

    geometry_msgs::Vector3 vec1(.1, .2, .3);
    geometry_msgs::Vector3 vec2(.3, .2, .1);


    geometry_msgs::TwistWithCovariance twc(vec1, vec2, covariance);
    twc_pub->publish(twc);

    geometry_msgs::TwistWithCovarianceStamped twcs(twc, "a frame");
    twcs_pub->publish(twcs);

    geometry_msgs::PoseWithCovariance pocov(po, covariance);
    pose_cov_pub->publish(pocov);

    geometry_msgs::PoseWithCovarianceStamped pocovs(pocov, "a frame");
    pose_cov_stamp_pub->publish(pocovs);
    
    geometry_msgs::Wrench w(0.1, 0.2, 0.3, 0.3, 0.2, 0.1);
    wrench_pub->publish(w);

    geometry_msgs::WrenchStamped ws(0.1, 0.2, 0.3, 0.3, 0.2, 0.1, "a frame");
    wrench_stamped_pub->publish(ws);

    geometry_msgs::PoseStamped pos(0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.4, "a frame");
    pose_stamped_pub->publish(pos);

    geometry_msgs::Point p(0.1, 0.2, 0.3);
    point_pub->publish(p);
    
    geometry_msgs::Pose2D p2d(0.1, 0.2, 0.3);
    pose2d_pub->publish(p2d);

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

    geometry_msgs::Transform t(0.1, 0.2, 0.3, 0.4, 0.3, 0.2, 0.1);
    transform_pub->publish(t);

    geometry_msgs::TransformStamped ts(0.1, 0.2, 0.3, 0.4, 0.3, 0.2, 0.1, "a frame");
    transform_stamped_pub->publish(ts);

    geometry_msgs::AccelStamped as(0.1, 0.2, 0.3, 0.3, 0.2, 0.1, "a frame");
    accel_stamped_pub->publish(as);
    
    geometry_msgs::Inertia i(0.1, geometry_msgs::Vector3(.1, .2, .3), 0.2, 0.3, 0.4, 0.5, 0.6, 0.7);
    inertia_pub->publish(i);

    geometry_msgs::InertiaStamped is(0.1, geometry_msgs::Vector3(.1, .2, .3), 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, "a frame");
    inertia_stamped_pub->publish(is);
  }

  std::this_thread::sleep_for(std::chrono::seconds(1)); // for last incoming messages

  if (callbacks::messages_received != callbacks::num_publishers*10)
  {
    throw test::TestException();
  }

  return 0;
}
