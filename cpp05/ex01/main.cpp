#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing Form and Bureaucrat ex01 ===" << std::endl;

	try {
		// Test 1: Create valid bureaucrats and forms
		std::cout << "\n--- Test 1: Valid creation ---" << std::endl;
		Bureaucrat john("John", 50);
		Bureaucrat alice("Alice", 5);
		Form taxForm("Tax Form", 75, 60);  // John can sign (50 < 75)
		Form secretForm("Secret Form", 10, 5);  // Alice can sign (5 < 10)

		std::cout << john << std::endl;
		std::cout << alice << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		// Test 2: Successful signing
		std::cout << "\n--- Test 2: Successful signing ---" << std::endl;
		john.signForm(taxForm);
		alice.signForm(secretForm);

		// Test 3: Failed signing (grade too low)
		std::cout << "\n--- Test 3: Failed signing (grade too low) ---" << std::endl;
		Form vipForm("VIP Form", 1, 1);  // Requires grade 1, both should fail
		john.signForm(vipForm);
		alice.signForm(vipForm);

		// Test 4: Already signed form
		std::cout << "\n--- Test 4: Already signed form ---" << std::endl;
		alice.signForm(taxForm);

	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Test 5: Invalid form creation
		std::cout << "\n--- Test 5: Invalid form creation (grade 0) ---" << std::endl;
		Form invalidForm("Invalid", 0, 50);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Test 6: Invalid form creation (grade too high)
		std::cout << "\n--- Test 6: Invalid form creation (grade > 150) ---" << std::endl;
		Form invalidForm2("Invalid2", 50, 151);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Test 7: Invalid bureaucrat creation
		std::cout << "\n--- Test 7: Invalid bureaucrat creation ---" << std::endl;
		Bureaucrat invalidBureaucrat("Invalid", 0);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Test 8: Form getters
		std::cout << "\n--- Test 8: Form getters ---" << std::endl;
		Form testForm("Test Form", 100, 75);
		std::cout << "Form name: " << testForm.getName() << std::endl;
		std::cout << "Is signed: " << testForm.getIsSigned() << std::endl;
		std::cout << "Grade to sign: " << testForm.getGradeToSign() << std::endl;
		std::cout << "Grade to execute: " << testForm.getGradeToExecute() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
