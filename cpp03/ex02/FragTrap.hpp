#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragtrap);
		FragTrap& operator=(const FragTrap& fragstrap);
		~FragTrap();

		void highFiveGuys(void);
};

#endif