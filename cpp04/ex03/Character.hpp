#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class Character : public ICharacter {
private:
  AMateria *mInventory[4];
  AMateria *mBackup[4];
  std::string mName;

  Character(const Character &other);
  Character &operator=(const Character &other);

public:
  Character();
  Character(std::string const &name);
  virtual ~Character();

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
  //   AMateria getInventory(int idx) const;
};

#endif