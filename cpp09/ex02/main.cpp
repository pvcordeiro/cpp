#include "PmergeMe.hpp"
#include <iomanip>

bool isPositiveInteger(const std::string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    std::stringstream ss(str);
    long val = 0;
    ss >> val;
    return (ss.eof() && !ss.fail() && val > 0);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    std::deque<int> deq;
    std::ostringstream before;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        std::stringstream ss(arg);
        int val = 0;
        ss >> val;
        if (!ss.eof() || ss.fail()) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(val);
        deq.push_back(val);
        before << val << " ";
    }
    std::cout << "Before: " << before.str() << std::endl;

    clock_t startVec = clock();
    PmergeMe::fordJohnsonSortVector(vec);
    clock_t endVec = clock();
    double durVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;

    clock_t startDeq = clock();
    PmergeMe::fordJohnsonSortDeque(deq);
    clock_t endDeq = clock();
    double durDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

    std::ostringstream after;
    for (size_t i = 0; i < vec.size(); ++i) {
        after << vec[i] << " ";
    }
    std::cout << "After: " << after.str() << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << durVec / 1000000.0 << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << durDeq / 1000000.0 << " us" << std::endl;
    return 0;
}
