#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
 private:
  const std::string mName;
  int mGrade;

 public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat& b);
  Bureaucrat& operator=(const Bureaucrat& b);
  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
  void signForm(Form& f);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif