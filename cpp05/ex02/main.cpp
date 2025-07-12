#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing Form Creation ===" << std::endl;
    
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");
    
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;
    
    std::cout << "\n=== Testing Bureaucrats ===" << std::endl;
    
    try {
        Bureaucrat lowGrade("Intern", 150);
        Bureaucrat midGrade("Manager", 50);
        Bureaucrat highGrade("CEO", 1);
        
        std::cout << lowGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << highGrade << std::endl;
        
        std::cout << "\n=== Testing Form Signing ===" << std::endl;
        
        std::cout << "\n--- Low grade bureaucrat trying to sign forms ---" << std::endl;
        lowGrade.signForm(shrub);
        lowGrade.signForm(robot);
        lowGrade.signForm(pardon);
        
        std::cout << "\n--- Mid grade bureaucrat trying to sign forms ---" << std::endl;
        midGrade.signForm(shrub);
        midGrade.signForm(robot);
        midGrade.signForm(pardon);
        
        std::cout << "\n=== Testing Form Execution ===" << std::endl;
        
        std::cout << "\n--- Low grade bureaucrat trying to execute forms ---" << std::endl;
        lowGrade.executeForm(shrub);
        lowGrade.executeForm(robot);
        lowGrade.executeForm(pardon);
        
        std::cout << "\n--- Mid grade bureaucrat trying to execute forms ---" << std::endl;
        midGrade.executeForm(shrub);
        midGrade.executeForm(robot);
        midGrade.executeForm(pardon);
        
        std::cout << "\n--- High grade bureaucrat trying to execute forms ---" << std::endl;
        highGrade.executeForm(shrub); 
        highGrade.executeForm(robot); 
        highGrade.executeForm(pardon);
        
        std::cout << "\n=== Testing Unsigned Form Execution ===" << std::endl;
        
        ShrubberyCreationForm unsignedShrub("unsigned");
        std::cout << "\n--- Trying to execute unsigned form ---" << std::endl;
        highGrade.executeForm(unsignedShrub);
        
        std::cout << "\n=== Testing Exception Handling ===" << std::endl;
        
        try {
            Bureaucrat invalidLow("Invalid Low", 151);
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        try {
            Bureaucrat invalidHigh("Invalid High", 0);
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n=== Testing Copy and Assignment ===" << std::endl;
        
        ShrubberyCreationForm shrubCopy(shrub);
        std::cout << "Original: " << shrub << std::endl;
        std::cout << "Copy: " << shrubCopy << std::endl;
        
        RobotomyRequestForm robotAssign;
        robotAssign = robot;
        std::cout << "Original robot: " << robot << std::endl;
        std::cout << "Assigned robot: " << robotAssign << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
