#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: could not open file." << std::endl, 1);
	Bitcoin btc;
	btc.loadCsv("data.csv");
	btc.parseTxt(argv[1]);
	return (0);
}
