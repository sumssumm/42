#include "Bureaucrat.hpp"

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : mName("default"), mGrade(75) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : mName(name), mGrade(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

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

const std::string& Bureaucrat::getName() const { return mName; }

int Bureaucrat::getGrade() const { return mGrade; }

void Bureaucrat::incrementGrade() {
  if (mGrade <= 1)
    throw GradeTooHighException();
  else
    mGrade--;
}

void Bureaucrat::decrementGrade() {
  if (mGrade >= 150)
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

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << mName << " signed " << form.getName() << std::endl;
  } catch (AForm::GradeTooLowException& e) {
    std::cout << mName << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const& form) {
  try {
    form.execute(*this);
    std::cout << mName << " executed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << mName << " couldn't execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}