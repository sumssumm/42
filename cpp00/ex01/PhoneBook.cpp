#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	cnt_contact = 0;
}

PhoneBook::~PhoneBook() {}

std::string	get_input(std::string str)
{
	std::string	input;

	while (1)
	{
		std::cout << str;
		if (!std::getline(std::cin, input) || std::cin.eof())
		{	
			clearerr(stdin);
			std::cin.clear();
			std::cout << "Try agian!" << std::endl;
		}
		else if (input.empty())
			std::cout << "Try agian!" << std::endl;
		else if (input.find_first_of(" \t\n\v\f\r") == 0 || \
				input.find_first_of("\t\n\v\f\r") != std::string::npos)
			std::cout << "Try agian!" << std::endl;
		else
			return input;
	}
}

void	PhoneBook::add_contact(void)
{
	std::string	input;

	input = get_input("First Name: ");
	contacts[index % 8].set_firstname(input);
	input = get_input("Last Name: ");
	contacts[index % 8].set_lastname(input);
	input = get_input("Nick Name: ");
	contacts[index % 8].set_nickname(input);
	input = get_input("Phone Number: ");
	contacts[index % 8].set_phonenumber(input);
	input = get_input("Darkest Secret: ");
	contacts[index % 8].set_secret(input);
	index++;
	if (cnt_contact < 8)
		cnt_contact++;
}

void	print_contact(std::string str)
{
	if (str.size() > 10)
		str = str.substr(0, 9) + '.';
	std::cout << '|' << std::setw(10) << str;
}

int	check_number(int cnt_contact)
{
	int			number;
	std::string input;

	std::cout << "Enter the number: ";
	if (!std::getline(std::cin, input) || std::cin.eof())
	{
		clearerr(stdin);
		std::cin.clear();
		std::cout << "Empty!" << std::endl;
		return -1;
	}
	std::istringstream iss(input);
	if (iss >> number)
	{
		std::string	tmp;
		if (iss >> tmp)
			std::cout << "Need only number!" << std::endl;
		else if (number < 1 || number > cnt_contact)
			std::cout << "Wrong number!" << std::endl;
		else
			return number - 1;
	}
	else
		std::cout << "Need a number!" << std::endl;
	return -1;
}

void	PhoneBook::print_detail(void)
{
	int	i;

	i = check_number(cnt_contact);
	if (i >= 0 && i < cnt_contact)
	{
		std::cout << "First Name : " << contacts[i].get_firstname() << std::endl;
		std::cout << "Last Name : " << contacts[i].get_lastname() << std::endl;
		std::cout << "Nickname: " << contacts[i].get_nickname() << std::endl;
		std::cout << "Phone Number: " << contacts[i].get_phonenumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[i].get_secret() << std::endl;
	}
	else
		return ;
}

void	PhoneBook::search_contact(void)
{
	if (index == 0)
	{
		std::cout << "Add a contact!" << std::endl;
		return ;
	}
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < cnt_contact; i++)
	{
		std::cout << '|' << "         " << i + 1;
		print_contact(contacts[i].get_firstname());
		print_contact(contacts[i].get_firstname());
		print_contact(contacts[i].get_firstname());
		std::cout << '|' << std::endl;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	// std::cout << "Enter the number: ";
	print_detail();
}