#include "PmergeMe.hpp"
#include <iomanip>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <sstream>

static bool isPositiveInteger(const std::string& str)
{
    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.size(); ++i)
        if (!isdigit(str[i]))
            return (false);
    std::stringstream ss(str);
    long val = 0;
    ss >> val;
    return (ss.eof() && !ss.fail() && val > 0);
}

template <typename Container>
static bool parseArgs(int argc, char **argv, Container& container, std::ostringstream& out)
{
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg))
            return (std::cerr << "Error" << std::endl, false);
        std::stringstream ss(arg);
        int val = 0;
        ss >> val;
        if (!ss.eof() || ss.fail())
            return (std::cerr << "Error" << std::endl, false);
        container.push_back(val);
        out << val << " ";
    }
    return (true);
}

template <typename Container, typename SortFunc>
static double timeSort(Container& container, SortFunc sortFunc)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortFunc(container);
    gettimeofday(&end, NULL);
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

int main(int argc, char* argv[]) {
    if (argc < 2)
        return (std::cerr << "Error" << std::endl, 1);

    std::vector<int> vec;
    std::deque<int> deq;
    std::ostringstream beforeVec;
	std::ostringstream beforeDeq;

    if (!parseArgs(argc, argv, vec, beforeVec))
        return (std::cerr << "Error" << std::endl, 1);
    if (!parseArgs(argc, argv, deq, beforeDeq))
        return (std::cerr << "Error" << std::endl, 1);

    std::cout << "Before: " << beforeVec.str() << std::endl;
    double durVec = timeSort(vec, PmergeMe::fordJohnsonSortVector);
    double durDeq = timeSort(deq, PmergeMe::fordJohnsonSortDeque);

    std::ostringstream after;
    for (size_t i = 0; i < vec.size(); ++i)
        after << vec[i] << " ";
    std::cout << "After: " << after.str() << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << durVec / 1000000.0 << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << durDeq / 1000000.0 << " us" << std::endl;
    return (0);
}
