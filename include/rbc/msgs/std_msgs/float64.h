//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_FLOAT64_H
#define ROSBRIDGECLIENT_FLOAT64_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct Float64 : public StdMsg<double>
{
  Float64();

  explicit Float64(double data);
  
  explicit Float64(const web::json::value &response);
  
  ~Float64() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_FLOAT64_H
