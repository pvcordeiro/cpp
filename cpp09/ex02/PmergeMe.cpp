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

template <typename Container>
static double sortAndTime(Container& input)
{
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	sorting(input);
	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

static bool isPositiveInteger(const std::string& str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.size(); ++i)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

static bool parseAndValidateArgs(int argc, char** argv, std::vector<int>& values, std::ostringstream& before)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		if (!isPositiveInteger(arg))
			return (false);
		int val = atoi(arg.c_str());
		if (val <= 0)
			return (false);
		values.push_back(val);
		before << val << " ";
	}
	return (true);
}

void PmergeMe::run(int argc, char** argv)
{
	std::vector<int> values;
	std::ostringstream before;
	if (!parseAndValidateArgs(argc, argv, values, before))
		return (std::cerr << "Error: invalid args" << std::endl, (void)0);

	std::cout << "Before: " << before.str() << std::endl;

	std::vector<int> vec(values.begin(), values.end());
	double durVec = sortAndTime(vec);

	std::deque<int> deq(values.begin(), values.end());
	double durDeq = sortAndTime(deq);

	std::ostringstream after;
	for (size_t i = 0; i < vec.size(); ++i)
		after << vec[i] << " ";
	std::cout << "After: " << after.str() << std::endl;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << durVec / 1000000.0 << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << durDeq / 1000000.0 << " us" << std::endl;
}
