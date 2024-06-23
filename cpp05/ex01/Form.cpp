#include "Form.hpp"

Form::Form()
    : mName("default"), mIsSigned(false), mSignGrade(1), mExecGrade(1) {}

Form::Form(const std::string name, const int signGrade, const int execGrade)
    : mName(name),
      mIsSigned(false),
      mSignGrade(signGrade),
      mExecGrade(execGrade) {
  if (signGrade < 1 || execGrade < 1)
    throw GradeTooHighException();
  else if (signGrade > 150 || execGrade > 150)
    throw GradeTooLowException();
}

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

void Form::beSigned(const Bureaucrat &b) {
  if (mSignGrade < b.getGrade()) throw GradeTooLowException();
  mIsSigned = true;
}

std::string Form::getName() const { return mName; }

bool Form::getIsSigned() const { return mIsSigned; }

int Form::getSignGrade() const { return mSignGrade; }

int Form::getExecuteGrade() const { return mExecGrade; }

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
