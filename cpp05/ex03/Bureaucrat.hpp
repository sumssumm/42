#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>

class AForm;

class Bureaucrat {
 private:
  const std::string mName;
  int mGrade;

  Bureaucrat();
   Bureaucrat(const Bureaucrat& b);
  Bureaucrat& operator=(const Bureaucrat& b);

 public:
  Bureaucrat(const std::string& name, int grade);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
  
  void signForm(AForm& form);
  void executeForm(AForm const& form);

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif