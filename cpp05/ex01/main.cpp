#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Bureaucrat john("John", 3);
    Bureaucrat jane("Jane", 150);

    std::cout << john << std::endl;
    std::cout << jane << std::endl;

    Form formA("FormA", 5, 10);
    Form formB("FormB", 150, 150);

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

    john.signForm(formA);
    jane.signForm(formB);

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

    john.signForm(formB);
    jane.signForm(formA);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return (0);
}