//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_INT32_H
#define ROSBRIDGECLIENT_INT32_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct Int32 : public StdMsg<int32_t>
{
  Int32();

  explicit Int32(int32_t data);

  explicit Int32(const web::json::value &response);

  ~Int32() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_INT32_H
