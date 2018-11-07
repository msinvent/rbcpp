//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_CONFIG_PARSER_INIT_EXCEPTION_H
#define ROSBRIDGECLIENT_CONFIG_PARSER_INIT_EXCEPTION_H

#include <exception>

namespace config_parser
{

namespace exception
{

struct ConfigParserInitException : public std::exception
{
  inline const char *what() const throw()
  {
    return "\n  Config Parser Init Error! \n  Can't open config_parser file. \n  Exiting.";
  }
};

} // namespace exception
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_LOGGER_INIT_EXCEPTION_H
