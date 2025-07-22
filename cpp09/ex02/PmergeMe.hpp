#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
public:
	static void run(int argc, char** argv);
	virtual	void abstract(void) = 0;
};

#endif 
