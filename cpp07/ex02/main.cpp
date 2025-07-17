#include "Array.hpp"

int main(void)
{

	std::cout << "===== int tests =====\n" << std::endl;
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

	std::cout << "\n===== double tests =====\n" << std::endl;
    Array<double> d(4);
    for (size_t i = 0; i < d.size(); ++i)
        d[i] = i * 1.5;

    Array<double> e = d;
    e[1] = 42.42;
    e[3] = -3.14;

    Array<double> f;

    std::cout << "Array d: ";
    for (size_t i = 0; i < d.size(); ++i)
        std::cout << d[i] << " ";
    std::cout << "\n";

    std::cout << "Array e: ";
    for (size_t i = 0; i < e.size(); ++i)
        std::cout << e[i] << " ";
    std::cout << "\n";

    std::cout << "Array f: ";
    for (size_t i = 0; i < f.size(); ++i)
        std::cout << f[i] << " ";
    std::cout << "\n";

    try {
        std::cout << d[10] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	std::cout << "\n===== string tests =====\n" << std::endl;
    Array<std::string> g(3);
    g[0] = "hello";
    g[1] = "world";
    g[2] = "!";

    Array<std::string> h = g;
    h[1] = "C++";

    Array<std::string> i;

    std::cout << "Array g: ";
    for (size_t i = 0; i < g.size(); ++i)
        std::cout << g[i] << " ";
    std::cout << "\n";

    std::cout << "Array h: ";
    for (size_t i = 0; i < h.size(); ++i)
        std::cout << h[i] << " ";
    std::cout << "\n";

    std::cout << "Array i: ";
    for (size_t j = 0; j < i.size(); ++j)
        std::cout << i[j] << " ";
    std::cout << "\n";

    try {
        std::cout << g[5] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	return (0);
}
