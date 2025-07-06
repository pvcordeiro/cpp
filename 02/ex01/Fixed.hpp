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
		Fixed& operator=(const Fixed &copyFrom);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const rawBits);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
