#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

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