#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		for (size_t j = 0; j < str.length(); ++j)
			std::cout << (char)toupper(str[j]);
	}
	std::cout << '\n';
	return (0);
}
