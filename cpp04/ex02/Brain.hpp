#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
  std::string ideas_[100];

public:
  Brain();
  Brain(std::string idea);
  Brain(const Brain &brain);
  Brain &operator=(const Brain &brain);
  ~Brain();
};

#endif