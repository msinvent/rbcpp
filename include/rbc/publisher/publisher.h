//
// Created by Julian on 17.09.18.
//

#ifndef ROSBRIDGECLIENT_PUBLISHER_HPP
#define ROSBRIDGECLIENT_PUBLISHER_HPP

/**
 * Base class to be able to save templated derived classes in the same vector in client
 * see https://stackoverflow.com/a/39109659
 */
class Publisher
{
public:
  Publisher() = default;

  virtual ~Publisher() = default;

  virtual void advertise() = 0;

  virtual void unadvertise() = 0;
};

#endif //ROSBRIDGECLIENT_PUBLISHER_HPP
