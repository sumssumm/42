#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : mSize(0), mData(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : mSize(n), mData(new T[n]) {}

template <typename T>
Array<T>::Array(const Array& other)
    : mSize(other.mSize), mData(new T[other.mSize]) {
  for (unsigned int i = 0; i < mSize; i++) {
    mData[i] = other.mData[i];
  }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this != &other) {
    delete[] mData;
    mSize = other.mSize;
    mData = new T[mSize];
    for (unsigned int i = 0; i < mSize; i++) {
      mData[i] = other.mData[i];
    }
  }
  return *this;
}

template <typename T>
Array<T>::~Array() {
  delete[] mData;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
  if (i >= mSize) {
    throw std::out_of_range("Index out of range");
  }
  return mData[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
  if (i >= mSize) {
    throw std::out_of_range("Index out of range");
  }
  return mData[i];
}

template <typename T>
unsigned int Array<T>::size() const {
  return mSize;
}

#endif