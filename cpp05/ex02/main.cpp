#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    // 성공적인 경우
    Bureaucrat bob("Bob", 1);
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("target1");
    PresidentialPardonForm pardon("target2");

    bob.signForm(shrubbery);
    bob.executeForm(shrubbery);
    std::cout << std::endl;

    bob.signForm(robotomy);
    bob.executeForm(robotomy);
    std::cout << std::endl;

    bob.signForm(pardon);
    bob.executeForm(pardon);
    std::cout << std::endl;

    // 실패 사례: 서명이 안 된 경우
    Bureaucrat alice("Alice", 50);
    ShrubberyCreationForm shrubberyFail("home2");

    alice.executeForm(shrubberyFail);  // 서명이 안 되어 실패
    std::cout << std::endl;

    // 실패 사례: 등급이 낮은 경우
    Bureaucrat john("John", 72);  // 서명 등급을 만족
    RobotomyRequestForm robotomyFail("Bob");

    john.signForm(robotomyFail);     // 서명 가능
    john.executeForm(robotomyFail);  // 등급이 낮아 실행 실패
    std::cout << std::endl;

  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
