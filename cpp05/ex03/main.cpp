#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
  try {
    Intern intern;

    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 50);

    // 로봇 요청 폼 생성
    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    if (form1) {
      std::cout << "Form created: " << form1->getName() << " targeting Bender"
                << std::endl;
      bob.signForm(*form1);
      bob.executeForm(*form1);
      delete form1;
    }
    std::cout << std::endl;

    // 나무 생성 폼 생성
    AForm* form2 = intern.makeForm("shrubbery creation", "Home");
    if (form2) {
      std::cout << "Form created: " << form2->getName() << " targeting Home"
                << std::endl;
      alice.signForm(*form2);
      alice.executeForm(*form2);
      delete form2;
    }
    std::cout << std::endl;

    // 사면 폼 생성
    AForm* form3 = intern.makeForm("presidential pardon", "Alice");
    if (form3) {
      std::cout << "Form created: " << form3->getName() << " targeting Alice"
                << std::endl;
      bob.signForm(*form3);
      bob.executeForm(*form3);
      delete form3;
    }
    std::cout << std::endl;

    // 존재하지 않는 폼 생성 시도
    AForm* form4 = intern.makeForm("unknown form", "Test");
    if (!form4) {
      std::cout << "Form creation failed for 'unknown form'" << std::endl;
    }
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}