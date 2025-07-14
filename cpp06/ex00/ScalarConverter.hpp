#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& copyFrom);
		ScalarConverter &operator=(const ScalarConverter& right);
		~ScalarConverter(void);
	public:
		static void convert(const std::string &input);
};

#endif
