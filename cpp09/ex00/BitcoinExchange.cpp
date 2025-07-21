#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void) : data() {}

Bitcoin::Bitcoin(const Bitcoin &copyFrom) : data(copyFrom.data) {}

Bitcoin& Bitcoin::operator=(const Bitcoin &right)
{
	if (this == &right)
		return (*this);
	data = right.data;
	return (*this);
}

Bitcoin::~Bitcoin(void) {}

void	Bitcoin::loadCsv(const std::string &csv)
{
	std::ifstream file(csv.c_str());
	if (!file.is_open())
		return (std::cerr << "Error: could not open file." << std::endl, (void)0);
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, rateStr;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			double rate = std::strtod(rateStr.c_str(), NULL);
			data[date] = rate;
		}
	}
}

double	Bitcoin::getExchangeRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = data.find(date);
	if (it != data.end())
		return (it->second);
	it = data.lower_bound(date);
	if (it == data.begin())
		return (-1.0);
	if (it == data.end() || it->first != date)
		--it;
	return (it->second);
}

static std::string trim(const std::string &s)
{
	size_t start = s.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return ("");
	size_t end = s.find_last_not_of(" \t\n\r\f\v");
	return (s.substr(start, end - start + 1));
}

static std::string validateInput(const std::string &line, std::string &date, double &value)
{
	std::istringstream iss(line);
	std::string valueStr;
	char *endptr;

	if (!std::getline(iss, date, '|'))
		return ("Error: bad input => " + line);
	date = trim(date);
	if (!std::getline(iss, valueStr))
		return ("Error: bad input => " + line);
	valueStr = trim(valueStr);
	if (valueStr.empty())
		return ("Error: bad input => " + line);
	value = std::strtod(valueStr.c_str(), &endptr);
	if (*endptr != '\0')
		return ("Error: bad input => " + line);
	if (value < 0)
		return ("Error: not a positive number.");
	if (value > 1000)
		return ("Error: too large a number.");
	return ("");
}

void Bitcoin::parseTxt(const std::string &inputTxt)
{
	std::string date;
	double value;
	std::string line;

	std::ifstream file(inputTxt.c_str());
	if (!file.is_open())
		return (std::cerr << "Error: could not open file." << std::endl, (void)0);
	std::getline(file, line);
	while (std::getline(file, line))
	{

		std::string err = validateInput(line, date, value);
		if (!err.empty())
		{
			std::cout << err << std::endl;
			continue;
		}
		double rate = getExchangeRate(date);
		if (rate < 0)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}
