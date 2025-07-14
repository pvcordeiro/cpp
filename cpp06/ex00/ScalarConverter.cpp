#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& copyFrom) {(void)copyFrom;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& right) {(void)right; return (*this);}

ScalarConverter::~ScalarConverter(void) {}

static bool isChar(const std::string::)

static bool baseCase(const std::string &input)
{
	if (input == "nanf" || input == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (false);
	}
	if (input == "+inff" || input == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (false);
	}
	if (input == "-inff" || input == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (false);
	}
}

static void convert(const std::string &input)
{
	
}
