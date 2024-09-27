#include "Character.hpp"

Character::Character() : mName("default") {
  for (int i = 0; i < 4; i++) {
    mInventory[i] = NULL;
    mBackup[i] = NULL;
  }
}

Character::Character(std::string const &name) : mName(name) {
  for (int i = 0; i < 4; ++i) {
    mInventory[i] = NULL;
    mBackup[i] = NULL;
  }
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
      if (mInventory[i])
        delete mInventory[i];
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
    if (mInventory[i])
      delete mInventory[i];
    if (mBackup[i])
      delete mBackup[i];
  }
}

std::string const &Character::getName() const { return mName; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; ++i) {
    if (mBackup[i])
      delete mBackup[i];
  }
  if (m == NULL)
    return;

  for (int i = 0; i < 4; ++i) {
    if (mInventory[i] == NULL) {
      mInventory[i] = m;
      std::cout << mName << " equipping materia " << m->getType() << std::endl;
      return;
    }
  }
  delete m;
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4 && mInventory[idx] != NULL) {
    for (int i = 0; i < 4; ++i) {
      if (mBackup[i] == NULL) {
        std::cout << mName << " unequipping materia "
                  << mInventory[idx]->getType() << std::endl;
        mBackup[i] = mInventory[idx];
        mInventory[idx] = NULL;
        return;
      }
    }
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && mInventory[idx] != NULL) {
    std::cout << mName << " using materia " << mInventory[idx]->getType()
              << std::endl;
    mInventory[idx]->use(target);
  }
}
