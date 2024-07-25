#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), mTarget(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const {
  std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(), mTarget("default") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
    : AForm(p), mTarget(p.mTarget) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& p) {
  if (this != &p) {
    AForm::operator=(p);
    mTarget = p.mTarget;
  }
  return *this;
}