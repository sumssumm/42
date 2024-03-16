#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	number_;
		static const int bits_ = 8;

	public:
		Fixed(); //default constructor
		Fixed(const Fixed &fixed); //copy constructor
		Fixed& operator = (const Fixed &fixed); //copy assignment operator
		~Fixed(); //destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif