#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm()
    : mName("default"), mIsSigned(false), mSignGrade(1), mExecGrade(1) {}

AForm::AForm(const std::string name, const int signGrade, const int execGrade)
    : mName(name),
      mIsSigned(false),
      mSignGrade(signGrade),
      mExecGrade(execGrade) {
  if (signGrade < 1 || execGrade < 1)
    throw GradeTooHighException();
  if (signGrade > 150 || execGrade > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &f)
    : mName(f.mName),
      mIsSigned(f.mIsSigned),
      mSignGrade(f.mSignGrade),
      mExecGrade(f.mExecGrade) {}

AForm &AForm::operator=(const AForm &f) {
  if (this != &f) {
    *(const_cast<std::string *>(&mName)) = f.mName;
    mIsSigned = f.mIsSigned;
    const_cast<int &>(mSignGrade) = f.mSignGrade;
    const_cast<int &>(mExecGrade) = f.mExecGrade;
  }
  return *this;
}

void AForm::beSigned(const Bureaucrat &b) {
  if (mSignGrade < b.getGrade()) throw GradeTooLowException();
  mIsSigned = true;
}

const std::string &AForm::getName() const { return mName; }

bool AForm::getIsSigned() const { return mIsSigned; }

int AForm::getSignGrade() const { return mSignGrade; }

int AForm::getExecuteGrade() const { return mExecGrade; }

void AForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) throw FormNotSignedException();
  if (executor.getGrade() > getExecuteGrade()) throw GradeTooLowException();
  action();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low...";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << f.getName() << ", is signed: " << std::boolalpha << f.getIsSigned()
      << ", signGrade: " << f.getSignGrade()
      << ", executeGrade: " << f.getExecuteGrade();
  return out;
}
