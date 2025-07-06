#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : rawBits(value << bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : rawBits(roundf(value * (1 << bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyFrom)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyFrom;
}

Fixed& Fixed::operator=(const Fixed &copyFrom)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyFrom)
		rawBits = copyFrom.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (rawBits);
}
void	Fixed::setRawBits(int const rawBits)
{
	this->rawBits = rawBits;
}

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << bits));
}

int		Fixed::toInt(void) const
{
	return (getRawBits() >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}
