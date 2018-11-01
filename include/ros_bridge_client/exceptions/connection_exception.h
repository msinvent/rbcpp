//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_CONNECTION_EXCEPTION_H
#define ROSBRIDGECLIENT_CONNECTION_EXCEPTION_H

#include <exception>

namespace ros_bridge_client
{

namespace exception
{

struct ConnectionException : public std::exception
{
  inline const char *what() const throw()
  {
    return "\n  Connection Error! \n  Is the websocket online? \n  Exiting.";
  }
};

} // namespace exception
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_CONNECTION_EXCEPTION_H
