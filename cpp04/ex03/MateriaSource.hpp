#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria *mInventory[4];

  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);

 public:
  MateriaSource();
  ~MateriaSource();

  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);
};

#endif