#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Testing Bureaucrat Class ===" << std::endl;
	
	try {
		std::cout << "\n1. Creating valid bureaucrat (John, grade 50):" << std::endl;
		Bureaucrat john("John", 50);
		std::cout << john;
		
		std::cout << "\n2. Incrementing grade by 10:" << std::endl;
		john.incrementGrade(10);
		std::cout << john;
		
		std::cout << "\n3. Decrementing grade by 20:" << std::endl;
		john.decrementGrade(20);
		std::cout << john;
		
		std::cout << "\n4. Testing copy constructor:" << std::endl;
		Bureaucrat johnCopy(john);
		std::cout << "Original: " << john;
		std::cout << "Copy: " << johnCopy;
		
		std::cout << "\n5. Testing assignment operator:" << std::endl;
		Bureaucrat jane("Jane", 100);
		std::cout << "Before assignment - Jane: " << jane;
		jane = john;
		std::cout << "After assignment - Jane: " << jane;
		
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n6. Testing grade too high exception (creating with grade 0):" << std::endl;
		Bureaucrat invalid("Invalid", 0);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n7. Testing grade too low exception (creating with grade 151):" << std::endl;
		Bureaucrat invalid("Invalid", 151);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n8. Testing increment beyond limit:" << std::endl;
		Bureaucrat topGuy("TopGuy", 2);
		std::cout << "Before increment: " << topGuy;
		topGuy.incrementGrade(5);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n9. Testing decrement beyond limit:" << std::endl;
		Bureaucrat lowGuy("LowGuy", 149);
		std::cout << "Before decrement: " << lowGuy;
		lowGuy.decrementGrade(5);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n10. Testing default constructor:" << std::endl;
	Bureaucrat defaultBureaucrat;
	std::cout << defaultBureaucrat;
	
	std::cout << "\n=== All tests completed ===" << std::endl;
	
	return 0;
}
