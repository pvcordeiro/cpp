#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>


class PmergeMe
{
	public:
		static void fordJohnsonSortVector(std::vector<int>& input);
		static void fordJohnsonSortDeque(std::deque<int>& input);
		virtual	void abstract(void) = 0;
};

#endif 
