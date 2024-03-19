#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	private:
		std::string ideas_[100];
	public:
		Brain();
		Brain(std::string idea);
		Brain(const Brain &brain);
		Brain& operator=(const Brain &brain);
		~Brain();

		std::string getBrain(int n) const;
		void setBrain(std::string idea, int n);
};

#endif