#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0) {}

Fixed::Fixed(const int value) : rawBits(value << bits) {}

Fixed::Fixed(const float value) : rawBits(roundf(value * (1 << bits))) {}

Fixed::Fixed(const Fixed &right)
{
	*this = right;
}

Fixed& Fixed::operator=(const Fixed &right)
{
	if (this != &right)
		rawBits = right.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {}

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
	return ((float)rawBits / (1 << bits));
}

int		Fixed::toInt(void) const
{
	return (rawBits >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}

bool 	Fixed::operator>(const Fixed &right) const
{
	return (rawBits > right.rawBits);
}

bool 	Fixed::operator<(const Fixed &right) const
{
	return (rawBits < right.rawBits);
}

bool 	Fixed::operator>=(const Fixed &right) const
{
	return (rawBits >= right.rawBits);
}

bool 	Fixed::operator<=(const Fixed &right) const
{
	return (rawBits <= right.rawBits);
}

bool 	Fixed::operator==(const Fixed &right) const
{
	return (rawBits == right.rawBits);
}

bool 	Fixed::operator!=(const Fixed &right) const
{
	return (rawBits != right.rawBits);
}

Fixed Fixed::operator+(const Fixed &right) const
{
	return (Fixed(this->toFloat() + right.toFloat()));
}

Fixed Fixed::operator-(const Fixed &right) const
{
	return (Fixed(this->toFloat() - right.toFloat()));
}

Fixed Fixed::operator*(const Fixed &right) const
{
	return (Fixed(this->toFloat() * right.toFloat()));
}

Fixed Fixed::operator/(const Fixed &right) const
{
	return (Fixed(this->toFloat() / right.toFloat()));
}

Fixed Fixed::operator++(void)
{
	rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	rawBits++;
	return (temp);
}

Fixed Fixed::operator--(void)
{
	rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	rawBits--;
	return (temp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
