#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& i);
  Intern& operator=(const Intern& i);
  ~Intern();

  AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif