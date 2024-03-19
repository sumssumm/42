#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class Character : public ICharacter
{
	private:
		AMateria *inventory_[4];
		std::string name_;

	public:
		// Constructors
		Character();
		Character(std::string name);
		Character(const Character &copy);
		
		// Destructor
		~Character();
		
		// Operators
		Character & operator=(const Character &assign);

		std::string const & getName() const = 0;
		void equip(AMateria* m);
		void unequip(int idx)0;
		void use(int idx, ICharacter& target);
		AMateria getInventory(int idx) const;
};

#endif