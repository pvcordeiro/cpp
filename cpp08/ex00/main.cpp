#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::cout << "===== vector test =====\n" << std::endl;
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        int idx = easyfind(v, 20);
        std::cout << "Found 20 in vector at index: " << idx << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int idx = easyfind(v, 99);
        std::cout << "Found 99 in vector at index: " << idx << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n===== list test =====\n" << std::endl;
    std::list<int> l;
    l.push_back(100);
    l.push_back(200);
    l.push_back(300);

    try {
        int idx = easyfind(l, 200);
        std::cout << "Found 200 in list at index: " << idx << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int idx = easyfind(l, 999);
        std::cout << "Found 999 in list at index: " << idx << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
