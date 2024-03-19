#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void check()
// {
// 	system("leaks animal");
// }

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	std::cout << "-------------------------" << std::endl;

	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() <<  " " << std::endl;
	k->makeSound();
	std::cout << "-------------------------" << std::endl;
	
	delete meta;
	delete j;
	delete i;
	delete k;
	
	// atexit(check);
	return 0;
}