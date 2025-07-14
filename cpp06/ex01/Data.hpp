#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	public:
		int			value;
		Data(void);
		Data(const Data &copyFrom);
		Data &operator=(const Data &right);
		~Data(void);
};

#endif
