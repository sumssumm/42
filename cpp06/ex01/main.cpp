#include <iostream>

#include "Serializer.hpp"

void testSerialization(Data& data) {
  uintptr_t raw = Serializer::serialize(&data);

  Data* deserializedPtr = Serializer::deserialize(raw);

  if (deserializedPtr == &data) {
    std::cout << "Serialization and deserialization successful!" << std::endl;
    std::cout << "Data value: " << deserializedPtr->value << std::endl;
  } else {
    std::cout << "Serialization and deserialization failed." << std::endl;
  }
}

int main() {
  // First test case
  Data myData;
  myData.value = 42;
  testSerialization(myData);

  // Second test case
  Data anotherData;
  anotherData.value = -1;
  testSerialization(anotherData);

  return 0;
}
