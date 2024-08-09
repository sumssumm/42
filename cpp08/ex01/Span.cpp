#include "Span.hpp"

Span::Span() : mN(0) {}

Span::Span(unsigned int N) : mN(N) {}

Span::Span(const Span &other) : mN(other.mN), mNumbers(other.mNumbers) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    mN = other.mN;
    mNumbers = other.mNumbers;
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
  if (mNumbers.size() < 2)
    throw std::logic_error("Number of elements is too short");

  std::vector<int> sorted = mNumbers;
  std::sort(sorted.begin(), sorted.end());

  int shortest = std::numeric_limits<int>::max();
  for (std::vector<int>::iterator it = sorted.begin() + 1; it != sorted.end();
       ++it) {
    int diff = *it - *(it - 1);
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
