//
// Created by Julian on 30.10.18.
//

#ifndef ROSBRIDGECLIENT_LOGGER_H
#define ROSBRIDGECLIENT_LOGGER_H

#include <string>
#include <sstream>
#include <memory>
#include <fstream>
#include <iostream>
#include <rbc/exceptions/logger_init_exception.h>

namespace rbc::logging
{

struct Logger
{
  Logger();

  ~Logger();

  template<typename T, typename... Targs>
  void log(T value, Targs... Fargs);

private:
  void log();

  std::ofstream std_log_file;
  std::ofstream ws_log_file;
  std::stringstream stream;
};

} // namespace rbc::logging

#include <rbc/logging/logger_impl.h>

#endif //ROSBRIDGECLIENT_LOGGER_H
