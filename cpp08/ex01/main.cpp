#include "Span.hpp"

void testEmptySpan() {
  try {
    Span sp = Span(5);
    std::cout << "Testing empty Span" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  try {
    Span sp = Span(5);
    std::cout << sp.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }
}

void testSingleNumberSpan() {
  try {
    Span sp = Span(5);
    sp.addNumber(42);
    std::cout << "Testing Span with a single number" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  try {
    Span sp = Span(5);
    sp.addNumber(42);
    std::cout << sp.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }
}

int main() {
  try {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan()
              << std::endl;  // Expected output: 2
    std::cout << "Longest Span: " << sp.longestSpan()
              << std::endl;  // Expected output: 14
    std::cout << "---------------------------------" << std::endl;

    // Test with range of iterators
    Span sp2 = Span(100000);

    std::vector<int> vec;
    for (int i = 0; i < 100000; ++i) {
      vec.push_back(i);
    }
    int minVal = *std::min_element(vec.begin(), vec.end());
    int maxVal = *std::max_element(vec.begin(), vec.end());
    std::cout << "Min value in vec: " << minVal << std::endl;
    std::cout << "Max value in vec: " << maxVal << std::endl;

    sp2.addNumbers(vec.begin(), vec.end());

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Additional tests
    testEmptySpan();
    std::cout << "---------------------------------" << std::endl;

    testSingleNumberSpan();
    std::cout << "---------------------------------" << std::endl;

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
