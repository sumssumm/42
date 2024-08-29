#include <unistd.h>

#include <iostream>
#include <vector>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void testMateriaUsage(ICharacter* user, ICharacter* target) {
  user->use(0, *target);
  user->use(1, *target);
  user->use(2, *target);
  user->use(3, *target);
}

int main() {
  // 1. 기본 테스트
  std::cout << getpid() << std::endl;
  std::cout << "== 기본 테스트 ==" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  testMateriaUsage(me, bob);

  delete bob;
  delete me;
  delete src;

  // 3. 중복된 Materia 관리
  std::cout << "\n== 중복된 Materia 관리 ==" << std::endl;
  MateriaSource* source = new MateriaSource();
  source->learnMateria(new Ice());
  source->learnMateria(new Ice());
  source->learnMateria(new Cure());
  source->learnMateria(new Cure());

  ICharacter* tester = new Character("tester");

  for (int i = 0; i < 4; ++i) {
    tmp = source->createMateria(i < 2 ? "ice" : "cure");
    tester->equip(tmp);
  }

  testMateriaUsage(tester, tester);

  delete tester;
  delete source;

  // 4. 최대 인벤토리 용량 초과 테스트
  std::cout << "\n== 최대 인벤토리 용량 초과 테스트 ==" << std::endl;
  ICharacter* maxInventory = new Character("maxInventory");

  for (int i = 0; i < 5; ++i) {  // 다섯 번 시도, 하지만 네 번만 성공
    tmp = new Ice();
    maxInventory->equip(tmp);
  }

  testMateriaUsage(maxInventory, maxInventory);

  delete maxInventory;

  // 5. unequip 테스트 (메모리 누수 방지)
  std::cout << "\n== unequip 테스트 (메모리 누수 방지) ==" << std::endl;
  ICharacter* unequipTester = new Character("unequipTester");

  tmp = new Ice();
  unequipTester->equip(tmp);
  unequipTester->unequip(0);  // 메모리 누수 발생 여부 확인

  delete unequipTester;  // 메모리 누수 여부를 검사

  return 0;
}
