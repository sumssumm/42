#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
 private:
  std::string mTarget;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& r);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
  ~RobotomyRequestForm();

  void action() const;
};

#endif