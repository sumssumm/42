#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// void check()
// {
// 	system("leaks animal");
// }

int main()
{
	Animal *a[4];
	
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			a[i] = new Cat();
		else 
			a[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 0; i < 4; i++)
		delete a[i];

	std::cout << "--------------------" << std::endl;

	// Brain 
	// atexit(check);
	return 0;
}