#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing Form and Bureaucrat ex01 ===" << std::endl;

	try {
		std::cout << "\n--- Test 1: Valid creation ---" << std::endl;
		Bureaucrat john("John", 50);
		Bureaucrat alice("Alice", 5);
		Form taxForm("Tax Form", 75, 60);
		Form secretForm("Secret Form", 10, 5);

		std::cout << john << std::endl;
		std::cout << alice << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		std::cout << "\n--- Test 2: Successful signing ---" << std::endl;
		john.signForm(taxForm);
		alice.signForm(secretForm);

		std::cout << "\n--- Test 3: Failed signing (grade too low) ---" << std::endl;
		Form vipForm("VIP Form", 1, 1);
		john.signForm(vipForm);
		alice.signForm(vipForm);

		std::cout << "\n--- Test 4: Already signed form ---" << std::endl;
		alice.signForm(taxForm);

	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Test 5: Invalid form creation (grade 0) ---" << std::endl;
		Form invalidForm("Invalid", 0, 50);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Test 6: Invalid form creation (grade > 150) ---" << std::endl;
		Form invalidForm2("Invalid2", 50, 151);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Test 7: Invalid bureaucrat creation ---" << std::endl;
		Bureaucrat invalidBureaucrat("Invalid", 0);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Test 8: Form getters ---" << std::endl;
		Form testForm("Test Form", 100, 75);
		std::cout << testForm << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
