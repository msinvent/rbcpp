//
// Created by julian on 17.11.18.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <ros_bridge_client/utils/deserializer.h>
#include <cpprest/json.h>

TEST_CASE("Header test", "[header]")
{
  auto response = web::json::value::parse(U("{\"topic\": \"/rosbridge/header/\", \"msg\": {\"stamp\": {\"secs\": 1542491695, \"nsecs\": 832205057}, \"frame_id\": \"a frame\", \"seq\": 0}, \"op\": \"publish\"}"));
  const auto& msg = response.at(U("msg"));
  REQUIRE(msg.at(U("frame_id")).as_string() == "a frame");
}

//Received {"topic": "/rosbridge/header/", "msg": {"stamp": {"secs": 1542491695, "nsecs": 832205057}, "frame_id": "a frame", "seq": 0}, "op": "publish"}
//Received {"topic": "/rosbridge/string/", "msg": {"data": "a string"}, "op": "publish"}
//Received {"topic": "/rosbridge/pose/", "msg": {"position": {"y": 0.2, "x": 0.1, "z": 0.3}, "orientation": {"y": 0.2, "x": 0.1, "z": 0.3, "w": 0.4}}, "op": "publish"}
//Received {"topic": "/rosbridge/accel/", "msg": {"linear": {"y": 0.2, "x": 0.1, "z": 0.3}, "angular": {"y": 0.2, "x": 0.3, "z": 0.1}}, "op": "publish"}
//Received {"topic": "/rosbridge/twist/", "msg": {"linear": {"y": 0.2, "x": 0.1, "z": 0.3}, "angular": {"y": 0.2, "x": 0.3, "z": 0.1}}, "op": "publish"}
//Received {"topic": "/rosbridge/wrench/", "msg": {"torque": {"y": 0.2, "x": 0.3, "z": 0.1}, "force": {"y": 0.2, "x": 0.1, "z": 0.3}}, "op": "publish"}
//Received {"topic": "/rosbridge/twist_stamped/", "msg": {"twist": {"linear": {"y": 0.2, "x": 0.1, "z": 0.3}, "angular": {"y": 0.2, "x": 0.3, "z": 0.1}}, "header": {"stamp": {"secs": 1542491695, "nsecs": 836633920}, "frame_id": "a frame", "seq": 1}}, "op": "publish"}
//Received {"topic": "/rosbridge/wrench_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 838684082}, "frame_id": "a frame", "seq": 1}, "wrench": {"torque": {"y": 0.2, "x": 0.3, "z": 0.1}, "force": {"y": 0.2, "x": 0.1, "z": 0.3}}}, "op": "publish"}
//Received {"topic": "/rosbridge/pose_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 839984893}, "frame_id": "a frame", "seq": 1}, "pose": {"position": {"y": 0.2, "x": 0.1, "z": 0.3}, "orientation": {"y": 0.2, "x": 0.1, "z": 0.3, "w": 0.4}}}, "op": "publish"}
//Received {"topic": "/rosbridge/point/", "msg": {"y": 0.2, "x": 0.1, "z": 0.3}, "op": "publish"}
//Received {"topic": "/rosbridge/pose2d/", "msg": {"y": 0.2, "x": 0.1, "theta": 0.3}, "op": "publish"}
//Received {"topic": "/rosbridge/point32/", "msg": {"y": 0.20000000298023224, "x": 0.10000000149011612, "z": 0.30000001192092896}, "op": "publish"}
//Received {"topic": "/rosbridge/point_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 842492103}, "frame_id": "a frame", "seq": 1}, "point": {"y": 0.2, "x": 0.1, "z": 0.3}}, "op": "publish"}
//Received {"topic": "/rosbridge/vector3/", "msg": {"y": 0.2, "x": 0.1, "z": 0.3}, "op": "publish"}
//Received {"topic": "/rosbridge/vector3_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 843651056}, "frame_id": "a frame", "seq": 1}, "vector": {"y": 0.2, "x": 0.1, "z": 0.3}}, "op": "publish"}
//Received {"topic": "/rosbridge/quaternion/", "msg": {"y": 0.2, "x": 0.1, "z": 0.3, "w": 0.4}, "op": "publish"}
//Received {"topic": "/rosbridge/quaternion_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 844316005}, "frame_id": "a frame", "seq": 1}, "quaternion": {"y": 0.2, "x": 0.1, "z": 0.3, "w": 0.4}}, "op": "publish"}
//Received {"topic": "/rosbridge/transform/", "msg": {"translation": {"y": 0.2, "x": 0.1, "z": 0.3}, "rotation": {"y": 0.3, "x": 0.4, "z": 0.2, "w": 0.1}}, "op": "publish"}
//Received {"topic": "/rosbridge/transform_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 845418930}, "frame_id": "a frame", "seq": 1}, "transform": {"translation": {"y": 0.2, "x": 0.1, "z": 0.3}, "rotation": {"y": 0.3, "x": 0.4, "z": 0.2, "w": 0.1}}, "child_frame_id": ""}, "op": "publish"}
//Received {"topic": "/rosbridge/accel_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 846146106}, "frame_id": "a frame", "seq": 1}, "accel": {"linear": {"y": 0.2, "x": 0.1, "z": 0.3}, "angular": {"y": 0.2, "x": 0.3, "z": 0.1}}}, "op": "publish"}
//Received {"topic": "/rosbridge/inertia/", "msg": {"iyy": 0.5, "m": 0.1, "ixz": 0.4, "ixx": 0.2, "ixy": 0.3, "izz": 0.7, "com": {"y": 0.2, "x": 0.1, "z": 0.3}, "iyz": 0.6}, "op": "publish"}
//Received {"topic": "/rosbridge/inertia_stamped/", "msg": {"header": {"stamp": {"secs": 1542491695, "nsecs": 847259044}, "frame_id": "a frame", "seq": 1}, "inertia": {"iyy": 0.5, "m": 0.1, "ixz": 0.4, "ixx": 0.2, "ixy": 0.3, "izz": 0.7, "com": {"y": 0.2, "x": 0.1, "z": 0.3}, "iyz": 0.6}}, "op": "publish"}
