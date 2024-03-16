#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point& point) : x_(point.getX()), y_(point.getY()) {}

Point& Point::operator=(const Point &point) {
	if (this != &point)
	{
		const_cast<Fixed&>(x_) = point.getX();
		const_cast<Fixed&>(y_) = point.getY();
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const {
	return x_;
}

Fixed Point::getY(void) const {
	return y_;
}