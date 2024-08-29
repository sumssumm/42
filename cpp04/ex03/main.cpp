#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void checkLeak(void) { system("leaks a.out"); }

int main() {
  atexit(checkLeak);
  std::cout << "== test1 ==" << std::endl;
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");

  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  std::cout << "\n== test max inventory ==" << std::endl;
  ICharacter *maxInventory = new Character("maxInventory");
  maxInventory->use(0, *maxInventory);

  for (int i = 0; i < 5; ++i) {
    tmp = new Ice();
    maxInventory->equip(tmp);
  }

  maxInventory->use(0, *maxInventory);
  maxInventory->use(1, *maxInventory);
  maxInventory->use(2, *maxInventory);
  maxInventory->use(3, *maxInventory);
  maxInventory->use(4, *maxInventory);
  maxInventory->use(5, *maxInventory);

  delete maxInventory;

  std::cout << "\n== unequip test (memory leak) ==" << std::endl;
  ICharacter *unequipTester = new Character("unequipTester");

  tmp = new Ice();
  unequipTester->equip(tmp);
  unequipTester->use(0, *unequipTester);

  unequipTester->unequip(0); // 메모리 누수 발생 여부 확인
  unequipTester->use(0, *unequipTester);

  unequipTester->unequip(0); // 메모리 누수 발생 여부 확인

  delete unequipTester;

  return 0;
}
