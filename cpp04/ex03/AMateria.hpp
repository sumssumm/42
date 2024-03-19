#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type_;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		AMateria& operator=(const AMateria &assign);
		~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif