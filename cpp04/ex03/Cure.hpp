#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria {
 private:
  Cure(const Cure& other);
  Cure& operator=(const Cure& other);

 public:
  Cure();
  ~Cure();

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif