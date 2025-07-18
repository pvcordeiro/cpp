#include "Span.hpp"
#include <ctime>

int main() {
	std::cout << "===== test with addNumber =====\n" << std::endl;
    Span sp1(10000);
    try {
        for (int i = 0; i < 10000; ++i)
            sp1.addNumber(i);
        std::cout << "shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp1.longestSpan() << std::endl;
        
		sp1.addNumber(1);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	std::cout << "\n===== test with addRange =====\n" << std::endl;
    Span sp2(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; ++i)
        v.push_back(rand());
    try {
        sp2.addRange(v.begin(), v.end());
        std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp2.longestSpan() << std::endl;

		sp2.addRange(v.begin(), v.end());
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	std::cout << "\n===== test with too few numbers =====" << std::endl;
    Span sp3(5);
    try {
        sp3.addNumber(42);
        std::cout << "calling shortest span:\n" << sp3.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
