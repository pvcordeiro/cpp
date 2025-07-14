#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& copyFrom);
		ScalarConverter &operator=(const ScalarConverter& right);
		~ScalarConverter(void);

		static void convert(const std::string &input);
};

#endif