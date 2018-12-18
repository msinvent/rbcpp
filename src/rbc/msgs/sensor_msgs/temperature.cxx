//
// Created by julian on 18.12.18.
//

#include <rbc/msgs/sensor_msgs/temperature.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::sensor_msgs;

Temperature::Temperature()
  : ROSTypeBase("sensor_msgs/Temperature"),
    header(),
    temperature(),
    variance()
{}

Temperature::Temperature(std::string frame_id, double temperature, double variance)
    : ROSTypeBase("sensor_msgs/Temperature"),
      header(frame_id),
      temperature(temperature),
      variance(variance)
{}

Temperature::Temperature(const rbc::msgs::std_msgs::Header &header, double temperature, double variance)
    : ROSTypeBase("sensor_msgs/Temperature"),
      header(header),
      temperature(temperature),
      variance(variance)
{}

Temperature::Temperature(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/Temperature"),
      header(),
      temperature(),
      variance()
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);

  utils::Deserializer::deserializeSingle<double>(temperature, msg.at(U("temperature")));

  utils::Deserializer::deserializeSingle<double>(variance, msg.at(U("variance")));
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::Temperature &temp)
{
  os << "\nTemperature";
  os << "\n\ttemperature: " << temp.temperature;
  os << "\n\tvariance" << temp.variance;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::Temperature> temp)
{
  return os << *temp.get();
}
