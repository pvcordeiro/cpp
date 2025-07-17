#include "Array.hpp"

int main(void)
{
	Array<int> a(5);
	for (size_t i = 0; i < a.size(); ++i)
		a[i] = i * 10;
	
	Array<int> b = a;
	b[0] = 42;
	b[4] = 24;

	Array<int> c;

	std::cout << "Array a: ";
	for (size_t i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << "\n";

	std::cout << "Array b: ";
	for (size_t i = 0; i < b.size(); ++i)
		std::cout << b[i] << " ";
	std::cout << "\n";

	std::cout << "Array c: ";
	for (size_t i = 0; i < c.size(); ++i)
		std::cout << c[i] << " ";
	std::cout << "\n";

	try {
		std::cout << a[10] << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
