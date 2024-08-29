#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain defualt constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
    this->ideas_[i] = "brain defualt ideas";
}

Brain::Brain(std::string idea) {
  std::cout << "Brain " << idea << " constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
    this->ideas_[i] = idea;
}

Brain::Brain(const Brain &brain) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
  std::cout << "Brain operator= called" << std::endl;
  if (this != &brain) {
    for (int i = 0; i < 100; i++)
      this->ideas_[i] = brain.ideas_[i];
  }
  return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }
