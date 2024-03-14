#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string	type_;

	public:
		Weapon(std::string type);
		~Weapon();
		const	std::string &getType(void) const;
		void	setType(std::string type);
};

#endif