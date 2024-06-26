#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string mTarget;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& p);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
  ~PresidentialPardonForm();

  void action() const;
};

#endif