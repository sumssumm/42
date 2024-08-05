#include "Functions.hpp"

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));

  for (int i = 0; i < 5; ++i) {
    Base *p = generate();
    std::cout << "<Pointer identify>" << std::endl;
    identify(p); // Identify type using pointer

    std::cout << "<Reference identify>" << std::endl;
    identify(*p); // Identify type using reference

    delete p;
    std::cout << "-----------" << std::endl;
  }
  return 0;
}