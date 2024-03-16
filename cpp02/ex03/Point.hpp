#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x_;
		Fixed const y_;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);
		Point& operator=(const Point& point);
		~Point();
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif