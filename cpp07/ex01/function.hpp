#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>

template <typename T>
void printElement(T const &element) {
  std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element) {
  ++element;
}

#endif