#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <cstdlib>
# include <sstream>

class PhoneBook {
	private:
		Contact contacts[8];
		int		index;
		int		cnt_contact;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void);
		void	print_detail(void);
};

#endif