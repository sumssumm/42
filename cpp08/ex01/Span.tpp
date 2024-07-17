#ifndef SPAN_TPP
#define SPAN_TPP

#include <iterator>

#include "Span.hpp"

template <typename InputIter>
void Span::addNumbers(InputIter begin, InputIter end) {
  if (mNumbers.size() + std::distance(begin, end) > mN) {
    throw std::out_of_range("Span is already full");
  }
  mNumbers.insert(mNumbers.end(), begin, end);
}

#endif