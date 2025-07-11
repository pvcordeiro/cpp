#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed random number generator for robotomy
    
    std::cout << "=== Presidential Pardon Form Test ===" << std::endl;
    
    try {
        // Create a PresidentialPardonForm
        PresidentialPardonForm pardonForm("Alice");
        std::cout << "Created: " << pardonForm << std::endl;
        
        // Create bureaucrats with different grades
        Bureaucrat highRankBureaucrat("Boss", 1);
        Bureaucrat midRankBureaucrat("Manager", 40);
        Bureaucrat lowRankBureaucrat("Intern", 150);
        
        std::cout << "\nBureaucrats created:" << std::endl;
        std::cout << highRankBureaucrat << std::endl;
        std::cout << midRankBureaucrat << std::endl;
        std::cout << lowRankBureaucrat << std::endl;
        
        std::cout << "\n--- Testing Presidential Pardon Form Signing ---" << std::endl;
        
        // Try to sign with low rank bureaucrat (should fail - needs grade 25 or better)
        std::cout << "Trying to sign with low rank bureaucrat:" << std::endl;
        lowRankBureaucrat.signForm(pardonForm);
        
        // Try to sign with mid rank bureaucrat (should succeed - grade 40 < 25, so this should fail)
        std::cout << "\nTrying to sign with mid rank bureaucrat:" << std::endl;
        midRankBureaucrat.signForm(pardonForm);
        
        // Sign with high rank bureaucrat
        std::cout << "\nSigning with high rank bureaucrat:" << std::endl;
        highRankBureaucrat.signForm(pardonForm);
        
        std::cout << "\n--- Testing Presidential Pardon Form Execution ---" << std::endl;
        
        // Try to execute with mid rank bureaucrat (should fail - needs grade 5 or better)
        std::cout << "Trying to execute with mid rank bureaucrat:" << std::endl;
        midRankBureaucrat.executeForm(pardonForm);
        
        // Try to execute with high rank bureaucrat (should succeed - grade 1 > 5)
        std::cout << "\nTrying to execute with high rank bureaucrat:" << std::endl;
        highRankBureaucrat.executeForm(pardonForm);
        
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Robotomy Request Form Test ===" << std::endl;
    
    try {
        // Create a RobotomyRequestForm
        RobotomyRequestForm robotomyForm("Bob");
        std::cout << "Created: " << robotomyForm << std::endl;
        
        // Create bureaucrats suitable for robotomy form (sign: 72, execute: 45)
        Bureaucrat robotomyBureaucrat("Surgeon", 50);
        Bureaucrat robotomySignBureaucrat("Doctor", 70);
        
        std::cout << "\nBureaucrats for robotomy:" << std::endl;
        std::cout << robotomyBureaucrat << std::endl;
        std::cout << robotomySignBureaucrat << std::endl;
        
        std::cout << "\n--- Testing Robotomy Form Signing ---" << std::endl;
        
        // Try to sign with bureaucrat (grade 70 should be able to sign - needs 72 or better)
        std::cout << "Trying to sign with Doctor (grade 70):" << std::endl;
        robotomySignBureaucrat.signForm(robotomyForm);
        
        std::cout << "\n--- Testing Robotomy Form Execution ---" << std::endl;
        
        // Try to execute with Surgeon (grade 50 should fail - needs 45 or better)
        std::cout << "Trying to execute with Surgeon (grade 50):" << std::endl;
        robotomyBureaucrat.executeForm(robotomyForm);
        
        // Try to execute with high rank bureaucrat (should succeed)
        std::cout << "\nTrying to execute with Boss (grade 1):" << std::endl;
        Bureaucrat highRankBureaucrat2("Boss", 1);
        highRankBureaucrat2.executeForm(robotomyForm);
        
        std::cout << "\n--- Testing Multiple Robotomy Attempts ---" << std::endl;
        std::cout << "Attempting robotomy multiple times to see random results:" << std::endl;
        
        for (int i = 0; i < 5; i++) {
            std::cout << "Attempt " << (i + 1) << ": ";
            highRankBureaucrat2.executeForm(robotomyForm);
        }
        
        std::cout << "\n--- Testing with unsigned robotomy form ---" << std::endl;
        
        // Create another form and try to execute without signing
        RobotomyRequestForm unsignedRobotomy("Charlie");
        std::cout << "Trying to execute unsigned robotomy form:" << std::endl;
        highRankBureaucrat2.executeForm(unsignedRobotomy);
        
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test Complete ===" << std::endl;
    return 0;
}
