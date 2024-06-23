#include "Bureaucrat.hpp"

int main(void) {
  try {
    try {
      Bureaucrat test1("test1", 200);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    try {
      Bureaucrat test2("test2", -1);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }

    Bureaucrat a("a", 150);
    Bureaucrat b("b", 1);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;

    // // a.decrementGrade();

    // b.incrementGrade();

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << std::endl;

    a.incrementGrade();
    b.decrementGrade();
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return (0);
}