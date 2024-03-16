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
		/* Canonical Form constructor */
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		
		/* constant constructor*/
		Fixed(const int number);
		Fixed(const float number);

		/* convert fixed_point value to other value*/
		float	toFloat(void) const;
		int		toInt(void) const;

		/* comparison operators */
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		/* arithmetic operators */
		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;

		/* increment/decrement operators */
		Fixed&	operator++(void);
		const Fixed	operator++(int);
		Fixed&	operator--(void);
		const Fixed	operator--(int);

		/* min & max */
		static Fixed&		min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed&	min(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed&		max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed&	max(Fixed const &fixed1, Fixed const &fixed2);

		/* getter & setter */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif

