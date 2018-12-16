target_sources(librbc
        PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/msgs/ros_type_base.cxx"

        #        nav_msgs
        "${CMAKE_CURRENT_LIST_DIR}/msgs/nav_msgs/odometry.cxx"

        #        sensor_msgs
        "${CMAKE_CURRENT_LIST_DIR}/msgs/sensor_msgs/imu.cxx"

        #        geometry_msgs
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/pose.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/point.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/accel.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/twist.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/pose2d.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/wrench.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/point32.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/vector3.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/inertia.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/polygon.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/transform.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/pose_array.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/quaternion.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/pose_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/point_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/accel_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/twist_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/wrench_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/vector3_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/polygon_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/inertia_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/transform_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/quaternion_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/pose_with_covariance.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/twist_with_covariance.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/accel_with_covariance.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/pose_with_covariance_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/twist_with_covariance_stamped.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/geometry_msgs/accel_with_covariance_stamped.cxx"

        #       std_msgs
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/int8.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/int16.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/int32.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/int64.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/uint8.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/uint16.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/uint32.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/uint64.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/header.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/string.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/float32.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/float64.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/msgs/std_msgs/color_rgba.cxx"

        #       misellaneous
        "${CMAKE_CURRENT_LIST_DIR}/utils/serializer.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/utils/deserializer.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/subscriber/rbc_subscriber_base.cxx")
