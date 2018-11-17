//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_LOGGER_INIT_EXCEPTION_H
#define ROSBRIDGECLIENT_LOGGER_INIT_EXCEPTION_H

#include <exception>

namespace ros_bridge_client::exception
{

struct LoggerInitException : public std::exception
{
  inline const char *what() const throw()
  {
    return "\n  Logger Init Error! \n  Can't create logging file. \n  Exiting.";
  }
};

} // namespace ros_bridge_client::exception

#endif //ROSBRIDGECLIENT_LOGGER_INIT_EXCEPTION_H
