#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyFrom) : rawBits(copyFrom.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}
void	Fixed::setRawBits(int const raw)
{
	this->rawBits = rawBits;
}
