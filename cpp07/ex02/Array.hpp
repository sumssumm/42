#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
 public:
  Array();
  Array(unsigned int n);
  Array(const Array& other);
  Array& operator=(const Array& other);
  ~Array();

  T& operator[](unsigned int i);
  const T& operator[](unsigned int i) const;
  unsigned int size() const;

 private:
  unsigned int mSize;
  T* mData;
};

#include "Array.tpp"

#endif