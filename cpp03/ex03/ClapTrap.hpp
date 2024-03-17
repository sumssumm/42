#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string		name_;
		unsigned int	hit_point_;
		unsigned int	energy_point_;
		unsigned int	attack_damage_;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap& operator=(const ClapTrap &claptrap);
		~ClapTrap();

		void attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif