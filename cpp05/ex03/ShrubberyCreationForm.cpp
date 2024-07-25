#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), mTarget(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
  std::string fileName = mTarget + "_shrubbery";
  std::ofstream file(fileName.c_str());
  if (file.is_open()) {
    file << "        /\\\n";
    file << "       /  \\\n";
    file << "      /    \\\n";
    file << "     /      \\\n";
    file << "    /        \\\n";
    file << "   /__________\\\n";
    file << "       ||||\n";
    file << "       ||||\n";
    file << "       ||||\n";
    file.close();
  } else
    std::cerr << "Unable to open file" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), mTarget("default") {}

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