//
// Created by Julian on 18.10.18.
//

#ifndef ROSBRIDGECLIENT_A_H
#define ROSBRIDGECLIENT_A_H

template <typename T>
struct B;

struct A {
  template <typename T>
  B<T>* add(T s);
};

#include "b.h"
template <typename T>
B<T>* A::add(T s) {
  auto b = new B<T>(s);
  return b;
}

#endif //ROSBRIDGECLIENT_A_H
