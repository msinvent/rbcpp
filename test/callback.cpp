//
// Created by Julian on 16.10.18.
//

#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include "manager.h"
#include "a.h"

void x(int x)
{
  std::cout << "x: " << x << "\n";
}

void y(double x)
{
  std::cout << "y: " << x << "\n";
}

void z(float x)
{
  std::cout << "z: " << x << "\n";
}

int main(void)
{
  auto m  = ROSBridgeClient::init("ws://127.0.0.1:2000/");
  auto p1 = m->addPublisher<int>("test_topic_1");
  auto d1 = m->addSubscriber<int>("test_topic_1", x);
  auto d2 = m->addSubscriber<double>("test_topic_2", y);
  auto d3 = m->addSubscriber<float>("test_topic_3", z);
//  p1->publish(1);

  return 0;
}