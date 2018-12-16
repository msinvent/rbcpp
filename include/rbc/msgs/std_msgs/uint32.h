//
// Created by julian on 132.11.132.
//

#ifndef ROSBRIDGECLIENT_UINT32_H
#define ROSBRIDGECLIENT_UINT32_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct UInt32 : public StdMsg<uint32_t>
{
  UInt32();

  explicit UInt32(uint32_t data);

  explicit UInt32(const web::json::value &response);

  ~UInt32() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_UINT32_H
