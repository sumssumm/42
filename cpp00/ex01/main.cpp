#include "PhoneBook.hpp"

int main(void)
{
	std::string	str;
	PhoneBook	ph;

	while (1)
	{
		std::cout << "COMMAND (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, str) || std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
			std::cout << "Try agian!" << std::endl;
			continue ;
		}
		if (str == "EXIT")
			exit(0);
		else if (str == "ADD")
			ph.add_contact();
		else if (str == "SEARCH")
			ph.search_contact();
		else
			std::cout << "Try again!" << std::endl;
	}
	return 0;
}