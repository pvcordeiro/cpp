#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

class Bitcoin
{
	private:
		std::map<std::string, double> data;
	public:
		Bitcoin(void);
		Bitcoin(const Bitcoin &copyFrom);
		Bitcoin& operator=(const Bitcoin &right);
		~Bitcoin(void);

		void	loadCsv(const std::string &filename);
		double	getExchangeRate(const std::string &date) const;
		void	parseTxt(const std::string &filename);
};

#endif
