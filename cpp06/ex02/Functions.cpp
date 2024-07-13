#include "Functions.hpp"

Base* generate(void) {
  int random = std::rand() % 3;
  switch (random) {
    case 0:
      return new A();
    case 1:
      return new B();
    case 2:
      return new C();
    default:
      return NULL;
  }
  return NULL;
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "A*" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B*" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C*" << std::endl;
  } else {
    std::cout << "Unknown" << std::endl;
  }
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A&" << std::endl;
    return;
  } catch (const std::exception& e) {
    std::cerr << "A failed: " << e.what() << '\n';
  }

  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B&" << std::endl;
    return;
  } catch (const std::exception& e) {
    std::cerr << "B failed: " << e.what() << '\n';
  }

  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C&" << std::endl;
    return;
  } catch (const std::exception& e) {
    std::cerr << "C failed: " << e.what() << '\n';
  }
}