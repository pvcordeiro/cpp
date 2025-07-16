#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& copyFrom) {(void)copyFrom;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& right) {(void)right; return (*this);}

ScalarConverter::~ScalarConverter(void) {}

static bool printBaseCase(const std::string& floatVal, const std::string& doubleVal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatVal << std::endl;
	std::cout << "double: " << doubleVal << std::endl;
	return (true);
}

static bool baseCase(const std::string &input)
{
	return (input == "nanf" || input == "nan") ? printBaseCase("nanf", "nan") :
           (input == "+inff" || input == "+inf") ? printBaseCase("+inff", "+inf") :
           (input == "-inff" || input == "-inf") ? printBaseCase("-inff", "-inf") :
           false;
}

static std::string convertToChar(double value)
{
	if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
		return ("impossible");
	else if (value < 32 || value == 127)
		return "Non printable";
	else
		return ("'" + std::string(1, static_cast<char>(value)) + "'");
}

static std::string convertToInt(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		return ("impossible");
	else
	{
		std::ostringstream oss;
		oss << static_cast<int>(value);
		return (oss.str());
	}
}

static bool printAll(double value, bool isInteger = false)
{
	std::cout << "char: " << convertToChar(value) << std::endl;
	std::cout << "int: " << convertToInt(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value);
	if (isInteger && !std::isnan(value) && !std::isinf(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << value;
	if (isInteger && !std::isnan(value) && !std::isinf(value))
		std::cout << ".0";
	std::cout << std::endl;
	return (true);
}

static bool isChar(const std::string &input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		char c = input[0];
		return (printAll(static_cast<double>(c), true));
	}
	return (false);
}

static bool isInt(const std::string &input)
{
	if (input.find('.') != std::string::npos || input.find('f') != std::string::npos)
		return (false);
	long check = atol(input.c_str());
	if (check < INT_MIN || check > INT_MAX)
		return (false);
	int value = static_cast<int>(check);
	return (printAll(static_cast<double>(value), true));
}

static bool	isFloatOrDouble(const std::string &input)
{
	bool	isFloat = (input[input.length() - 1] == 'f' && input.find('.') != std::string::npos);
	bool	isDouble = (input.find('.') != std::string::npos && input[input.length() - 1] != 'f');
	if (!isFloat && !isDouble)
		return (false);
	std::string checkedString = isFloat ? input.substr(0, input.length() - 1) : input;
	double value = atof(checkedString.c_str());
	return (printAll(value, (value == static_cast<int>(value))));
}

void ScalarConverter::convert(const std::string &input)
{
	if (baseCase(input) || isChar(input) || isInt(input) || isFloatOrDouble(input))
		return ;
	std::cout << "Error: Invalid input" << std::endl;
}
