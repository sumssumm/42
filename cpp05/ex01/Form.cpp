#include "Form.hpp"

#include "Bureaucrat.hpp"


Form::Form(const std::string &name, const int signGrade, const int execGrade)
    : mName(name),
      mIsSigned(false),
      mSignGrade(signGrade),
      mExecGrade(execGrade) {
  if (signGrade < 1 || execGrade < 1)
    throw GradeTooHighException();
  if (signGrade > 150 || execGrade > 150)
    throw GradeTooLowException();
}

const std::string &Form::getName() const { return mName; }

bool Form::getIsSigned() const { return mIsSigned; }

int Form::getSignGrade() const { return mSignGrade; }

int Form::getExecuteGrade() const { return mExecGrade; }

void Form::beSigned(const Bureaucrat &b) {
  if (mSignGrade < b.getGrade()) throw GradeTooLowException();
  mIsSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low...";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << f.getName() << ", is signed: " << std::boolalpha << f.getIsSigned()
      << ", signGrade: " << f.getSignGrade()
      << ", executeGrade: " << f.getExecuteGrade();
  return out;
}

Form::Form() : mName("default"), mIsSigned(false), mSignGrade(75), mExecGrade(75) {}

Form::~Form() {}

Form::Form(const Form &f)
    : mName(f.mName),
      mIsSigned(f.mIsSigned),
      mSignGrade(f.mSignGrade),
      mExecGrade(f.mExecGrade) {}

Form &Form::operator=(const Form &f) {
  if (this != &f) {
    *(const_cast<std::string *>(&mName)) = f.mName;
    mIsSigned = f.mIsSigned;
    const_cast<int &>(mSignGrade) = f.mSignGrade;
    const_cast<int &>(mExecGrade) = f.mExecGrade;
  }
  return *this;
}