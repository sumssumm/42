#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : mName(name), mGrade(grade) {
  int g = getGrade();
  if (g < 1)
    throw GradeTooHighException();
  else if (g > 150)
    throw GradeTooLowException();
}

const std::string& Bureaucrat::getName() const { return this->mName; }

int Bureaucrat::getGrade() const { return this->mGrade; }

void Bureaucrat::incrementGrade() {
  if (getGrade() <= 1)
    throw GradeTooHighException();
  else
    mGrade--;
}

void Bureaucrat::decrementGrade() {
  if (getGrade() >= 150)
    throw GradeTooLowException();
  else
    mGrade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low...";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
  out << b.getName() << ", bureaucrat grade " << b.getGrade();
  return out;
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
    : mName(b.mName), mGrade(b.mGrade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
  if (this != &b) {
    *(const_cast<std::string*>(&mName)) = b.mName;
    mGrade = b.mGrade;
  }
  return *this;
}