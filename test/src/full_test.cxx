#include <test/full_test.h>

using namespace std::chrono;
using namespace rbc;
using namespace rbc::msgs;
using namespace test;

int main(void)
{
  size_t messages = 0;
  auto& config = config_parser::ConfigParser::init("config.json");
  std::chrono::milliseconds pause(config.pause());
  callbacks::init();
  callbacks::messages_received = 0;
  callbacks::num_publishers = config.publishers();
  auto rbc = ROSBridgeClient::init(config.host());

  auto header_pub = rbc->addPublisher<std_msgs::Header>("/rosbridge/header/");
  auto string_pub = rbc->addPublisher<std_msgs::String>("/rosbridge/string/");
  auto float32_pub = rbc->addPublisher<std_msgs::Float32>("/rosbridge/float32/");
  auto float64_pub = rbc->addPublisher<std_msgs::Float64>("/rosbridge/float64/");
  auto int8_pub = rbc->addPublisher<std_msgs::Int8>("/rosbridge/int8/");
  auto int16_pub = rbc->addPublisher<std_msgs::Int16>("/rosbridge/int16/");
  auto int32_pub = rbc->addPublisher<std_msgs::Int32>("/rosbridge/int32/");
  auto int64_pub = rbc->addPublisher<std_msgs::Int64>("/rosbridge/int64/");
  auto uint8_pub = rbc->addPublisher<std_msgs::UInt8>("/rosbridge/uint8/");
  auto uint16_pub = rbc->addPublisher<std_msgs::UInt16>("/rosbridge/uint16/");
  auto uint32_pub = rbc->addPublisher<std_msgs::UInt32>("/rosbridge/uint32/");
  auto uint64_pub = rbc->addPublisher<std_msgs::UInt64>("/rosbridge/uint64/");
  auto color_pub = rbc->addPublisher<std_msgs::ColorRGBA>("/rosbridge/color/");
  auto point_pub = rbc->addPublisher<geometry_msgs::Point>("/rosbridge/point/");
  auto accel_pub = rbc->addPublisher<geometry_msgs::Accel>("/rosbridge/accel/");
  auto twist_pub = rbc->addPublisher<geometry_msgs::Twist>("/rosbridge/twist/");
  auto wrench_pub = rbc->addPublisher<geometry_msgs::Wrench>("/rosbridge/wrench/");
  auto pose_pub = rbc->addPublisher<geometry_msgs::Pose>("/rosbridge/pose/");
  auto pose_array_pub = rbc->addPublisher<geometry_msgs::PoseArray>("/rosbridge/pose_array/");
  auto point32_pub = rbc->addPublisher<geometry_msgs::Point32>("/rosbridge/point32/");
  auto pose2d_pub = rbc->addPublisher<geometry_msgs::Pose2D>("/rosbridge/pose2d/");
  auto inertia_pub = rbc->addPublisher<geometry_msgs::Inertia>("/rosbridge/inertia/");
  auto polygon_pub = rbc->addPublisher<geometry_msgs::Polygon>("/rosbridge/polygon/");
  auto polygon_stamped_pub = rbc->addPublisher<geometry_msgs::PolygonStamped>("/rosbridge/polygon_stamped/");
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
  auto quaternion_pub = rbc->addPublisher<geometry_msgs::Quaternion>("/rosbridge/orientation/");
  auto quaternion_stamped_pub = rbc->addPublisher<geometry_msgs::QuaternionStamped>("/rosbridge/quaternion_stamped/");
  auto odom_pub = rbc->addPublisher<nav_msgs::Odometry>("/rosbridge/odometry");
  auto path_pub = rbc->addPublisher<nav_msgs::Path>("/rosbridge/path");
  auto imu_pub = rbc->addPublisher<sensor_msgs::Imu>("/rosbridge/imu");
  auto joy_pub = rbc->addPublisher<sensor_msgs::Joy>("/rosbridge/joy");
  auto img_pub = rbc->addPublisher<sensor_msgs::Image<5, 5>>("/rosbridge/image");
  auto temp_pub = rbc->addPublisher<sensor_msgs::Temperature>("/rosbridge/temperature");
  auto joint_state_pub = rbc->addPublisher<sensor_msgs::JointState>("/rosbridge/joint_state");
  auto fluid_pressure_pub = rbc->addPublisher<sensor_msgs::FluidPressure>("/rosbridge/fluid_pressure");

  rbc->addSubscriber<std_msgs::Header>("/rosbridge/header/", 100, callbacks::hcallback);
  rbc->addSubscriber<std_msgs::String>("/rosbridge/string/", 100, callbacks::scallback);
  rbc->addSubscriber<std_msgs::Float32>("/rosbridge/float32/", 100, callbacks::f32callback);
  rbc->addSubscriber<std_msgs::Float64>("/rosbridge/float64/", 100, callbacks::f64callback);
  rbc->addSubscriber<std_msgs::Int8>("/rosbridge/int8/", 100, callbacks::int8callback);
  rbc->addSubscriber<std_msgs::Int16>("/rosbridge/int16/", 100, callbacks::int16callback);
  rbc->addSubscriber<std_msgs::Int32>("/rosbridge/int32/", 100, callbacks::int32callback);
  rbc->addSubscriber<std_msgs::Int64>("/rosbridge/int64/", 100, callbacks::int64callback);
  rbc->addSubscriber<std_msgs::UInt8>("/rosbridge/uint8/", 100, callbacks::uint8callback);
  rbc->addSubscriber<std_msgs::UInt16>("/rosbridge/uint16/", 100, callbacks::uint16callback);
  rbc->addSubscriber<std_msgs::UInt32>("/rosbridge/uint32/", 100, callbacks::uint32callback);
  rbc->addSubscriber<std_msgs::UInt64>("/rosbridge/uint64/", 100, callbacks::uint64callback);
  rbc->addSubscriber<std_msgs::ColorRGBA>("/rosbridge/color/", 100, callbacks::ccallback);
  rbc->addSubscriber<geometry_msgs::Point>("/rosbridge/point/", 100, callbacks::pcallback);
  rbc->addSubscriber<geometry_msgs::Accel>("/rosbridge/accel/", 100, callbacks::acallback);
  rbc->addSubscriber<geometry_msgs::Twist>("/rosbridge/twist/", 100, callbacks::twcallback);
  rbc->addSubscriber<geometry_msgs::Wrench>("/rosbridge/wrench/", 100, callbacks::wcallback);
  rbc->addSubscriber<geometry_msgs::Pose>("/rosbridge/pose/", 100, callbacks::pocallback);
  rbc->addSubscriber<geometry_msgs::PoseArray>("/rosbridge/pose_array/", 100, callbacks::posacallback);
  rbc->addSubscriber<geometry_msgs::PoseWithCovariance>("/rosbridge/pose_with_covariance/", 100, callbacks::pocovcallback);
  rbc->addSubscriber<geometry_msgs::PoseWithCovarianceStamped>("/rosbridge/pose_with_covariance_stamped/", 100, callbacks::pocovscallback);
  rbc->addSubscriber<geometry_msgs::Point32>("/rosbridge/point32/", 100, callbacks::p32callback);
  rbc->addSubscriber<geometry_msgs::Pose2D>("/rosbridge/pose2d/", 100, callbacks::p2dcallback);
  rbc->addSubscriber<geometry_msgs::Inertia>("/rosbridge/inertia/", 100, callbacks::icallback);
  rbc->addSubscriber<geometry_msgs::Transform>("/rosbridge/transform/", 100, callbacks::tcallback);
  rbc->addSubscriber<geometry_msgs::TransformStamped>("/rosbridge/transform_stamped/", 100, callbacks::tscallback);
  rbc->addSubscriber<geometry_msgs::InertiaStamped>("/rosbridge/inertia_stamped/", 100, callbacks::iscallback);
  rbc->addSubscriber<geometry_msgs::PointStamped>("/rosbridge/point_stamped/", 100, callbacks::pscallback);
  rbc->addSubscriber<geometry_msgs::Polygon>("/rosbridge/polygon/", 100, callbacks::polycallback);
  rbc->addSubscriber<geometry_msgs::PolygonStamped>("/rosbridge/polygon_stamped/", 100, callbacks::polyscallback);
  rbc->addSubscriber<geometry_msgs::AccelStamped>("/rosbridge/accel_stamped/", 100, callbacks::ascallback);
  rbc->addSubscriber<geometry_msgs::TwistStamped>("/rosbridge/twist_stamped/", 100, callbacks::twscallback);
  rbc->addSubscriber<geometry_msgs::TwistWithCovariance>("/rosbridge/twist_with_covariance/", 100, callbacks::twccallback);
  rbc->addSubscriber<geometry_msgs::AccelWithCovariance>("/rosbridge/accel_with_covariance/", 100, callbacks::acovcallback);
  rbc->addSubscriber<geometry_msgs::AccelWithCovarianceStamped>("/rosbridge/accel_with_covariance_stamped/", 100, callbacks::acovscallback);
  rbc->addSubscriber<geometry_msgs::TwistWithCovarianceStamped>("/rosbridge/twist_with_covariance_stamped/", 100, callbacks::twcscallback);
  rbc->addSubscriber<geometry_msgs::WrenchStamped>("/rosbridge/wrench_stamped/", 100, callbacks::wscallback);
  rbc->addSubscriber<geometry_msgs::PoseStamped>("/rosbridge/pose_stamped/", 100, callbacks::poscallback);
  rbc->addSubscriber<geometry_msgs::Vector3>("/rosbridge/vector3/", 100, callbacks::vcallback);
  rbc->addSubscriber<geometry_msgs::Vector3Stamped>("/rosbridge/vector3_stamped/", 100, callbacks::vscallback);
  rbc->addSubscriber<geometry_msgs::Quaternion>("/rosbridge/orientation/", 100, callbacks::qcallback);
  rbc->addSubscriber<geometry_msgs::QuaternionStamped>("/rosbridge/quaternion_stamped/", 100, callbacks::qscallback);
  rbc->addSubscriber<nav_msgs::Odometry>("/rosbridge/odometry", 100, callbacks::odomcallback);
  rbc->addSubscriber<nav_msgs::Path>("/rosbridge/path", 100, callbacks::pathcallback);
  rbc->addSubscriber<sensor_msgs::Imu>("/rosbridge/imu", 100, callbacks::imucallback);
  rbc->addSubscriber<sensor_msgs::Joy>("/rosbridge/joy", 100, callbacks::joycallback);
  //auto img_sub = rbc->addSubscriber<sensor_msgs::Image<5,5>>("/camera/rgb/image_rect_color", 100, callbacks::imgcallback<5, 5>);
  rbc->addSubscriber<sensor_msgs::Temperature>("/rosbridge/temperature", 100, callbacks::tempcallback);
  rbc->addSubscriber<sensor_msgs::JointState>("/rosbridge/joint_state", 100, callbacks::jscallback);
  rbc->addSubscriber<sensor_msgs::FluidPressure>("/rosbridge/fluid_pressure", 100, callbacks::fpcallback);


  auto srv_handler = rbc->addServiceHandler<srv::ServiceCall<int>>("add_two_ints", "sum", callbacks::srvcallback);

  std::array<double, 36> covariance( {.1, .2, 3., .4, .5, .6,
                                      .7, .8, .9, 1., 1.1, 1.2,
                                      1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                                      1.9, 2., 2.1, 2.2, 2.3, 2.4,
                                      2.5, 2.6, 2.7, 2.8, 2.9, 3.,
                                      3.1, 3.2, 3.3, 3.4, 3.5, 3.6} );
  std::array<float, 9> covariance2( {.1, .2, 3., .4, .5, .6, .7, .8, .9} );
  std::array<std::uint8_t, 25> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                    11, 12, 13, 14, 15, 16, 17,
                                    18, 19, 20, 21, 22, 23, 24, 25};

  std::vector<float> axes{.1, .2, .3, .4, .5, .6, .7, .8, .9};
  std::vector<int32_t> buttons{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<double> vec{.1, .2, .3, .4, .5, .6, .7, .8, .9};

  std::vector<std::string> name{"a joint", "another joint"};

  while (messages++ < 10)
  {
    std::this_thread::sleep_for(pause*2);

    std_msgs::Header h("a frame");
    header_pub->publish(h);

    std_msgs::String s("a string");
    string_pub->publish(s);

    std_msgs::ColorRGBA c(.1, .2, .3, .4);
    color_pub->publish(c);

    std_msgs::Int8 i8(1);
    int8_pub->publish(i8);

    std_msgs::Int16 i16(1);
    int16_pub->publish(i16);

    std_msgs::Int32 i32(1);
    int32_pub->publish(i32);

    std_msgs::Int64 i64(1);
    int64_pub->publish(i64);

    std_msgs::UInt8 ui8(1);
    uint8_pub->publish(ui8);

    std_msgs::UInt16 ui16(1);
    uint16_pub->publish(ui16);

    std_msgs::UInt32 ui32(1);
    uint32_pub->publish(ui32);

    std_msgs::UInt64 ui64(1);
    uint64_pub->publish(ui64);

    std_msgs::Float32 f32(.1);
    float32_pub->publish(f32);

    std_msgs::Float64 f64(.1);
    float64_pub->publish(f64);

    geometry_msgs::Pose po(0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.4);
    pose_pub->publish(po);

    geometry_msgs::PoseArray poa("a frame");
    poa.add(po);
    poa.add(po);
    pose_array_pub->publish(poa);

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

    geometry_msgs::Polygon poly;
    poly.add(p32);
    poly.add(p32);
    polygon_pub->publish(poly);

    geometry_msgs::PolygonStamped polys("a frame");
    polys.add(p32);
    polys.add(p32);
    polygon_stamped_pub->publish(polys);

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

    nav_msgs::Odometry o("a child frame", h, pocov, twc);
    odom_pub->publish(o);

    nav_msgs::Path path;
    path.add(pos);
    path_pub->publish(path);

    sensor_msgs::Imu imu;
    imu.angular_velocity_covariance = covariance2;
    imu.linear_acceleration_covariance = covariance2;
    imu.orientation_covariance = covariance2;
    imu.orientation = q;
    imu.linear_acceleration = v;
    imu.angular_velocity = v;
    imu_pub->publish(imu);

    sensor_msgs::Joy joy;
    joy.header = h;
    joy.axes = axes;
    joy.buttons = buttons;
    joy_pub->publish(joy);

    sensor_msgs::Image<5, 5> img;
    img.header = std_msgs::Header("a frame");
    img.height = 10;
    img.width = 10;
    img.encoding = "utf-8";
    img.is_bigendian = 1;
    img.step = 8;
    img.data = data;
//    img_pub->publish(img);

    sensor_msgs::Temperature temp;
    temp.header = h;
    temp.temperature = 5.55;
    temp.variance = 2.22;
    temp_pub->publish(temp);

    sensor_msgs::JointState js;
    js.header = h;
    js.name = name;
    js.position = vec;
    js.velocity = vec;
    js.effort = vec;
    joint_state_pub->publish(js);

    sensor_msgs::FluidPressure fp("a frame", 10, 0.2);
    fluid_pressure_pub->publish(fp);
  }

  srv::ServiceCall<int> srv_call("add_two_ints", std::vector{1, 2});
  srv_handler->callService(srv_call);

  std::this_thread::sleep_for(std::chrono::seconds(5)); // for last incoming messages

  try
  {
    if (callbacks::messages_received != callbacks::num_publishers * 10)
    {
      throw test::TestException();
    } else
    {
      std::cout << "Success: all messages received\n";
    }
  }
  catch(test::TestException &e)
  {
    callbacks::results();
  }

  return 0;
}
