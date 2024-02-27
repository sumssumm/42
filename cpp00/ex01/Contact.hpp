#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact(void);
		~Contact(void);
		/* setter */
		void	set_firstname(std::string str);
		void	set_lastname(std::string str);
		void	set_nickname(std::string str);
		void	set_phonenumber(std::string str);
		void	set_secret(std::string str);
		/* getter */
		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phonenumber(void) const;
		std::string	get_secret(void) const;
};

#endif