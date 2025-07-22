#include "PmergeMe.hpp"

template <typename Container>
static void mySort(Container &input)
{
	int left = 0;
	int right = input.size();
	if (right - left <= 1)
		return ;
	int mid = left + (right - left) / 2;
	Container leftHalf(input.begin() + left, input.begin() + mid);
	Container rightHalf(input.begin() + mid, input.begin() + right);
	mySort(leftHalf);
	mySort(rightHalf);
	std::merge(leftHalf.begin(), leftHalf.end(), rightHalf.begin(), rightHalf.end(), input.begin());
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& input)
{
    mySort(input);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& input)
{
    mySort(input);
}
