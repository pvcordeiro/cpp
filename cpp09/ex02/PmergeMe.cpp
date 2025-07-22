#include "PmergeMe.hpp"

template <typename Container>
static void sorting(Container& input)
{
	if (input.size() <= 1)
		return ;
	Container mins;
	Container maxs;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
		{
			mins.push_back(input[i]);
			maxs.push_back(input[i + 1]);
		}
		else
		{
			mins.push_back(input[i + 1]);
			maxs.push_back(input[i]);
		}
	}
	if (input.size() % 2 == 1)
		maxs.push_back(input.back());

	sorting(maxs);

	for (size_t i = 0; i < mins.size(); ++i)
	{
		typename Container::iterator pos = std::lower_bound(maxs.begin(), maxs.end(), mins[i]);
		maxs.insert(pos, mins[i]);
	}
	std::copy(maxs.begin(), maxs.end(), input.begin());
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& input)
{
	sorting(input);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& input)
{
	sorting(input);
}
