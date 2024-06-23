#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  const std::string mName;
  bool mIsSigned;
  const int mSignGrade;
  const int mExecGrade;

 public:
  Form();
  Form(const std::string name, const int signGrade, const int execGrade);
  ~Form();
  Form(const Form &f);
  Form &operator=(const Form &f);
  void beSigned(const Bureaucrat &b);
  std::string getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;
  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif