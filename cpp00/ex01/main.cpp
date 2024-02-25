#include "PhoneBook.hpp"

int main(void)
{
	std::string	str;

	while (1)
	{
		std::cout << "COMMAND (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, str) || std::cin.eof())
		{
			std::cout << "Try again!" << std::endl;
			break;
		}
		if (str == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			return 0;
		}
		else if (str == "ADD")
		{
			std::cout << "add" << std::endl;
			continue ;
		}
		else if (str == "SEARCH")
		{
			std::cout << "search" << std::endl;
			continue ;
		}
		else
			std::cout << "Try again" << std::endl;
	}
	return 0;
}