#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer {
 private:
  Serializer(/* args */);
  ~Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif