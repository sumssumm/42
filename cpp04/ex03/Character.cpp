#include "Character.hpp"

Character::Character() : mName("default") {
  for (int i = 0; i < 4; i++) {
    mInventory[i] = NULL;
  }
}

Character::Character(std::string const &name) : mName(name) {
  for (int i = 0; i < 4; ++i) mInventory[i] = NULL;
}

Character::Character(Character const &other) : mName(other.mName) {
  for (int i = 0; i < 4; ++i) {
    if (other.mInventory[i])
      mInventory[i] = other.mInventory[i]->clone();
    else
      mInventory[i] = NULL;
  }
}

Character &Character::operator=(Character const &other) {
  if (this != &other) {
    mName = other.mName;
    for (int i = 0; i < 4; ++i) {
      if (mInventory[i]) delete mInventory[i];
      if (other.mInventory[i])
        mInventory[i] = other.mInventory[i]->clone();
      else
        mInventory[i] = NULL;
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; ++i) {
    if (mInventory[i]) delete mInventory[i];
  }
}

std::string const &Character::getName() const { return mName; }

void Character::equip(AMateria *m) {
  if (m == NULL) return;
  for (int i = 0; i < 4; ++i) {
    if (mInventory[i] == NULL) {
      mInventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) mInventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && mInventory[idx] != NULL)
    mInventory[idx]->use(target);
}
