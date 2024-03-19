#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	number_;
		static const int bits_;

	public:
		Fixed(); //default constructor
		Fixed(const Fixed &fixed); //copy constructor
		Fixed& operator=(const Fixed &fixed); //copy assignment operator
		~Fixed(); //destructor
		
		Fixed(const int number);
		Fixed(const float number);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif

