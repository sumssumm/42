#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), mTarget("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), mTarget(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
    : AForm(s), mTarget(s.mTarget) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& s) {
  if (this != &s) {
    AForm::operator=(s);
    mTarget = s.mTarget;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
  std::ofstream file(mTarget + "_shrubbery");
  if (file.is_open()) {
    file << "ASCII trees" << std::endl;
    file.close();
  }
}