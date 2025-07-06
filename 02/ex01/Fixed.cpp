#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	raw = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << 
}

Fixed::Fixed(const float num)
{

}

Fixed::Fixed(const Fixed &copyFrom)
{
	std::cout << "Copy constructor called" << std::endl;
	raw = copyFrom.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &copyFrom)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyFrom)
		raw = copyFrom.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (raw);
}
void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

float	Fixed::toFloat(void) const
{

}

int		Fixed::toInt(void) const
{

}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}