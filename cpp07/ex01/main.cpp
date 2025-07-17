#include "iter.hpp"

static void printInt(int const &x)
{
	std::cout << x << std::endl;
}

static void changeInt(int &x)
{
	x = 10;
}

static void printDouble(double const &x)
{
	std::cout << x << std::endl;
}

static void changeDouble(double &x)
{
	x = 15.15;
}

static void printString(std::string const &x)
{
	std::cout << x << std::endl;
}

static void changeString(std::string &x)
{
	x = "wow";
}

template <typename T>
void printTemplate(const T &x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	std::cout << "====== const and non-const test ======\n" << std::endl;

	std::cout << "== int ==" << std::endl;
	int arr[5] = {0, 1, 2, 3, 4};

	iter(arr, 5, printInt);
	iter(arr, 5, changeInt);
	iter(arr, 5, printInt);

	std::cout << "\n== double ==" << std::endl;
	double darr[3] = {1.1, 2.2, 3.3};

	iter(darr, 3, printDouble);
	iter(darr, 3, changeDouble);
	iter(darr, 3, printDouble);

	std::cout << "\n== string ==" << std::endl;
	std::string sarr[2] = {"cpp", "sucks"};

	iter(sarr, 2, printString);
	iter(sarr, 2, changeString);
	iter(sarr, 2, printString);

	std::cout << "\n===== template test =====\n" << std::endl;

	std::cout << "== template to int ==" << std::endl;
	int tarr[3] = {3, 2, 1};

	iter(tarr, 3, printTemplate<int>);
	iter(tarr, 3, changeInt);
	iter(tarr, 3, printTemplate<int>);

	std::cout << "\n== template to double ==" << std::endl;
	double tdarr[3] = {3.5, 2.5, 1.5};

	iter(tdarr, 3, printTemplate<double>);
	iter(tdarr, 3, changeDouble);
	iter(tdarr, 3, printTemplate<double>);

	std::cout << "\n== template to string ==" << std::endl;
	std::string tsarr[3] = {"42", "Lisboa", "yeah"};

	iter(tsarr, 3, printTemplate<std::string>);
	iter(tsarr, 3, changeString);
	iter(tsarr, 3, printTemplate<std::string>);

	return (0);
}
