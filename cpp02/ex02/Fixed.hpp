#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					rawBits;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copyFrom);
		Fixed& operator=(const Fixed &right);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const rawBits);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool 	operator>(const Fixed &right) const;
		bool 	operator<(const Fixed &right) const;
		bool 	operator>=(const Fixed &right) const;
		bool 	operator<=(const Fixed &right) const;
		bool 	operator==(const Fixed &right) const;
		bool 	operator!=(const Fixed &right) const;

		Fixed 	operator+(const Fixed &right) const;
		Fixed 	operator-(const Fixed &right) const;
		Fixed 	operator*(const Fixed &right) const;
		Fixed 	operator/(const Fixed &right) const;
		
		Fixed 	operator++(void);
		Fixed 	operator++(int);
		Fixed 	operator--(void);
		Fixed 	operator--(int);

		static 	Fixed&	min(Fixed &a, Fixed &b);
		static 	const Fixed& min(const Fixed &a, const Fixed &b);
		static 	Fixed&	max(Fixed &a, Fixed &b);
		static 	const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
