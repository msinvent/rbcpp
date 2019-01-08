//
// Created by julian on 08.01.19.
//

#ifndef ROSBRIDGECLIENT_MAP_META_DATA_H
#define ROSBRIDGECLIENT_MAP_META_DATA_H

#include <rbc/msgs/ros_type_base.h>

namespace rbc::msgs::nav_msgs
{

struct MapMetaData : ROSTypeBase
{
  MapMetaData();
  ~MapMetaData() final = default;
};

} // namespace rbc::msgs::nav_msgs

#endif //ROSBRIDGECLIENT_MAP_META_DATA_H
