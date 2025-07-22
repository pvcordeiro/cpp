#include "PmergeMe.hpp"
#include <iomanip>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <sstream>


int main(int argc, char* argv[]) {
	if (argc < 2)
		return (std::cerr << "Error: no numbers to sort" << std::endl, 1);
	PmergeMe::run(argc, argv);
    return 0;
}
