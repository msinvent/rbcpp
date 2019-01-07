//
// Created by julian on 07.01.19.
//

#include <rbc/msgs/sensor_msgs/fluid_pressure.h>

using namespace rbc::msgs::sensor_msgs;

FluidPressure::FluidPressure()
  : ROSTypeBase("sensor_msgs/FluidPressure"),
    header(),
    fluid_pressure(0.0),
    variance(0.0)
{}

FluidPressure::FluidPressure(std::string frame_id, double pressure, double variance)
    : ROSTypeBase("sensor_msgs/FluidPressure"),
      header(frame_id),
      fluid_pressure(pressure),
      variance(variance)
{}

FluidPressure::FluidPressure(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/FluidPressure"),
      header(),
      fluid_pressure(0.0),
      variance(0.0)
{}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::FluidPressure &fp)
{
  os << "Fluid Pressure";
  os << fp.header;
  os << "\n\tFluid Pressure: " << fp.fluid_pressure;
  os << "\n\tVariance: " << fp.variance;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::FluidPressure> fp)
{
  return os << *fp.get();
}
