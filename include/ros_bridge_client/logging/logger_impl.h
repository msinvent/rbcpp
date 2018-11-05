//
// Created by Julian on 30.10.18.
//

#ifndef ROSBRIDGECLIENT_LOGGER_IMPL_H
#define ROSBRIDGECLIENT_LOGGER_IMPL_H

#include <ros_bridge_client/logging/logger.h>

using namespace ros_bridge_client::logging;

Logger::Logger()
{
  std_log_file.open(".log");
  ws_log_file.open(".ws_log");

  if (not std_log_file or not ws_log_file)
    throw exception::LoggerInitException();
}

Logger::~Logger()
{
  if (std_log_file)
    std_log_file.close();

  if (ws_log_file)
    ws_log_file.close();
}

void Logger::log()
{
  std_log_file << stream.str() << "\n";
  stream.str(std::string());
}

template<typename T, typename... Targs>
void Logger::log(T value, Targs... Fargs) // recursive variadic function. TODO C++17 makes this easier, port in future?
{
  stream << value;
  log(Fargs...);
}

#endif //ROSBRIDGECLIENT_LOGGER_IMPL_H
