//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_CONFIG_PARSER_VALIDITY_EXCEPTION_H
#define ROSBRIDGECLIENT_CONFIG_PARSER_VALIDITY_EXCEPTION_H

#include <exception>
#include <string>

namespace config_parser
{

namespace exception
{

struct ConfigParserValidityException : public std::exception
{
  inline const char *what() const throw()
  {
    return "\n  Config Parser Validity Error! \n  Invalid json value found. \n  Exiting.";
  }
};

} // namespace exception
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_CONFIG_PARSER_VALIDITY_EXCEPTION_H
