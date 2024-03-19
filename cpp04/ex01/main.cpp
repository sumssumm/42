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
	Animal *a[4];
	Cat cat;
	std::cout << std::endl;

	Dog dog;
	std::cout << "--------------------" << std::endl;
	
	for (int i = 0; i < 4; i++) {
		if (i < 2) 
			a[i] = new Cat(cat);
		else 
			a[i] = new Dog(dog);
		std::cout << std::endl;
	}
	std::cout << "--------------------" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete a[i];
		std::cout << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	std::cout << std::endl;
	// atexit(check);
	return 0;
}