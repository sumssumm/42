#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span {
 public:
  Span(unsigned int N);
  Span(const Span &src);
  Span &operator=(const Span &rhs);
  ~Span();

  void addNumber(int number);
  template <typename InputIter>
  void addNumbers(InputIter begin, InputIter end);
  int shortestSpan() const;
  int longestSpan() const;

 private:
  Span();
  unsigned int mN;
  std::vector<int> mNumbers;
};

#include "Span.tpp"

#endif