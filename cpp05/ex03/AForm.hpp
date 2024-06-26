#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
 private:
  const std::string mName;
  bool mIsSigned;
  const int mSignGrade;
  const int mExecGrade;

 public:
  AForm();
  AForm(const std::string name, const int signGrade, const int execGrade);
  AForm(const AForm &f);
  AForm &operator=(const AForm &f);
  virtual ~AForm();

  void beSigned(const Bureaucrat &b);
  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;
  void execute(Bureaucrat const &executor) const;
  virtual void action() const = 0;

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
   public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif