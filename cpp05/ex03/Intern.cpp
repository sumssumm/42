#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& i) { *this = i; }

Intern& Intern::operator=(const Intern& i) {
  (void)i;
  return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) {
  std::string formNames[] = {"shrubbery creation", "robotomy request",
                             "presidential pardon"};
  AForm* forms[] = {new ShrubberyCreationForm(target),
                    new RobotomyRequestForm(target),
                    new PresidentialPardonForm(target)};
  AForm* result = NULL;
  for (int i = 0; i < 3; i++) {
    if (formName == formNames[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      result = forms[i];
    } else
      delete forms[i];
  }
  if (result == NULL)
    std::cout << "Error: Form name " << formName << " does not exist."
              << std::endl;
  return result;
}