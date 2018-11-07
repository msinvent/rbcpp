//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_CONFIG_PARSER_EXCEPTION_H
#define ROSBRIDGECLIENT_CONFIG_PARSER_EXCEPTION_H

#include <exception>

namespace config_parser
{

namespace exception
{

struct ConfigParserException : public std::exception
{
  inline const char *what() const throw()
  {
    return "\n  Config Parser Error! \n  Can't turn filestream into json value. \n  Exiting.";
  }
};

} // namespace exception
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_CONFIG_PARSER_EXCEPTION_H
