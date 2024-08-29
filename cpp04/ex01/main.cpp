#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  /* test subject */
  std::cout << "<< Test Subject >> " << std::endl;
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  delete j;
  delete i;
  std::cout << "--------------------" << std::endl;

  /* test 1 */
  std::cout << "<< TEST 1 >>" << std::endl;
  Animal *a[4];

  for (int i = 0; i < 4; i++) {
    if (i < 2)
      a[i] = new Cat();
    else
      a[i] = new Dog();
    std::cout << std::endl;
  }
  std::cout << "--------------------" << std::endl;

  for (int i = 0; i < 4; i++) {
    delete a[i];
    std::cout << std::endl;
  }
  std::cout << "--------------------" << std::endl;

  /* test 2 */
  {
    std::cout << "<< TEST 2 >>" << std::endl;
    Dog a;
    std::cout << std::endl;
    Dog b;
    b = a;

    Dog c = a;
  }

  return 0;
}