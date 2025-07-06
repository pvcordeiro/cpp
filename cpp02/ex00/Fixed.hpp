#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					rawBits;
		static const int	bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &right);
		Fixed& operator=(const Fixed &right);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
