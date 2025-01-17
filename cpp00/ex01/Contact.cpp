#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

void	Contact::set_firstname(std::string str)
{
	first_name = str;
}

void	Contact::set_lastname(std::string str)
{
	last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	nick_name = str;
}

void	Contact::set_phonenumber(std::string str)
{
	phone_number = str;
}

void	Contact::set_secret(std::string str)
{
	darkest_secret = str;
}

std::string	Contact::get_firstname(void) const
{
	return first_name;
}

std::string	Contact::get_lastname(void) const
{
	return last_name;
}

std::string	Contact::get_nickname(void) const
{
	return nick_name;
}

std::string	Contact::get_phonenumber(void) const
{
	return phone_number;
}

std::string	Contact::get_secret(void) const
{
	return darkest_secret;
}
