#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

class PhoneBook {
	private:
		Contact contacts[8];
		int		index;

	public:
		PhoneBook(void);

		void	add();
		Contact get_contact(Contact contact, int i);

		~PhoneBook();
};

#endif