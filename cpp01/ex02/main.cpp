#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string Address: " << &string << std::endl;
	std::cout << "stringPTR Address: " << stringPTR << std::endl;
	std::cout << "stringREF Address: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "string Value: " << string << std::endl;
	std::cout << "stringPTR Value: " << *stringPTR << std::endl;
	std::cout << "stringREF Value: " << stringREF << std::endl;

	return (0);
}
