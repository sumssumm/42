#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// void check()
// {
// 	system("leaks -q animal");
// }

int main()
{
	// Animal a;
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	// atexit(check);
	return 0;
}