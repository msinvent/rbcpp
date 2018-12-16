//
// Created by julian on 164.11.164.
//

#ifndef ROSBRIDGECLIENT_UINT64_H
#define ROSBRIDGECLIENT_UINT64_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct UInt64 : public StdMsg<uint64_t>
{
  UInt64();

  explicit UInt64(uint64_t data);

  explicit UInt64(const web::json::value &response);

  ~UInt64() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_UINT64_H
