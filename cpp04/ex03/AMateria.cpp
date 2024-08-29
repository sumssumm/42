#include "AMateria.hpp"

AMateria::AMateria() : mType("default") {}

AMateria::AMateria(std::string const &type) : mType(type) {}

AMateria::AMateria(const AMateria &other) : mType(other.mType) { (void)other; }

AMateria &AMateria::operator=(const AMateria &other) {
  (void)other;
  return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return mType; }

void AMateria::use(ICharacter &target) { (void)target; }