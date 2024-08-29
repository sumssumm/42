#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria {
 private:
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);

 public:
  Ice();
  ~Ice();

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif