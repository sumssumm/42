#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    mInventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (int i = 0; i < 4; i++) {
    if (other.mInventory[i])
      mInventory[i] = other.mInventory[i]->clone();
    else
      mInventory[i] = NULL;
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
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

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (mInventory[i])
      delete mInventory[i];
  }
}

// Member functions
void MateriaSource::learnMateria(AMateria *m) {
  if (m == NULL)
    return;

  for (int i = 0; i < 4; i++) {
    if (mInventory[i] == NULL) {
      mInventory[i] = m;
      std::cout << "learning materia " << m->getType() << "..." << std::endl;
      return;
    }
  }
  delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (mInventory[i] && mInventory[i]->getType() == type) {
      std::cout << "creating materia " << type << "..." << std::endl;
      return mInventory[i]->clone();
    }
  }
  return NULL;
}