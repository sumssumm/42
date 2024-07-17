#include "Span.hpp"

Span::Span() : mN(0) {}

Span::Span(unsigned int N) : mN(N) {}

Span::Span(const Span &src) : mN(src.mN), mNumbers(src.mNumbers) {}

Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
    mN = rhs.mN;
    mNumbers = rhs.mNumbers;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (mNumbers.size() >= mN) {
    throw std::out_of_range("Span is already full");
  }
  mNumbers.push_back(number);
}

int Span::shortestSpan() const {
  if (mNumbers.size() < 2) {
    throw std::logic_error("Number of elements is too short");
  }
  std::vector<int> sorted = mNumbers;
  std::sort(sorted.begin(), sorted.end());
  int shortest = sorted[1] - sorted[0];
  for (unsigned int i = 2; i < sorted.size(); i++) {
    int diff = sorted[i] - sorted[i - 1];
    if (diff < shortest) {
      shortest = diff;
    }
  }
  return shortest;
}

int Span::longestSpan() const {
  if (mNumbers.size() < 2) {
    throw std::logic_error("Number of elements is too short");
  }
  std::vector<int> sorted = mNumbers;
  std::sort(sorted.begin(), sorted.end());
  return sorted.back() - sorted.front();
}
