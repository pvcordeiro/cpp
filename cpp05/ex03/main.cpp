#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing Intern Class ===" << std::endl;
    
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 50);
        
        std::cout << "\n=== Testing Form Creation via Intern ===" << std::endl;
        
        std::cout << "\n1. Creating Shrubbery Creation Form:" << std::endl;
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (shrub) {
            std::cout << *shrub << std::endl;
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
            delete shrub;
        }
        
        std::cout << "\n2. Creating Robotomy Request Form:" << std::endl;
        AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
        if (robot) {
            std::cout << *robot << std::endl;
            boss.signForm(*robot);
            boss.executeForm(*robot);
            boss.executeForm(*robot);
            boss.executeForm(*robot);
            delete robot;
        }
        
        std::cout << "\n3. Creating Presidential Pardon Form:" << std::endl;
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (pardon) {
            std::cout << *pardon << std::endl;
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }
        
        std::cout << "\n=== Testing Invalid Form Names ===" << std::endl;
        
        std::cout << "\n4. Trying to create invalid form:" << std::endl;
        AForm* invalid1 = someRandomIntern.makeForm("invalid form", "target");
        if (!invalid1) {
            std::cout << "Correctly returned NULL for invalid form" << std::endl;
        }
        
        std::cout << "\n5. Trying to create form with wrong case:" << std::endl;
        AForm* invalid2 = someRandomIntern.makeForm("Shrubbery Creation", "target");
        if (!invalid2) {
            std::cout << "Correctly returned NULL for case-sensitive form name" << std::endl;
        }
        
        std::cout << "\n6. Trying to create form with extra spaces:" << std::endl;
        AForm* invalid3 = someRandomIntern.makeForm("shrubbery creation ", "target");
        if (!invalid3) {
            std::cout << "Correctly returned NULL for form name with trailing space" << std::endl;
        }
        
        std::cout << "\n=== Testing Intern Canonical Orthodox Form ===" << std::endl;
        
        std::cout << "\n7. Testing copy constructor:" << std::endl;
        Intern intern1;
        Intern intern2(intern1);
        AForm* form1 = intern1.makeForm("robotomy request", "Robot1");
        AForm* form2 = intern2.makeForm("robotomy request", "Robot2");
        
        if (form1 && form2) {
            std::cout << "Both interns work independently" << std::endl;
            delete form1;
            delete form2;
        }
        
        std::cout << "\n8. Testing assignment operator:" << std::endl;
        Intern intern3;
        intern3 = intern1;
        AForm* form3 = intern3.makeForm("presidential pardon", "Someone");
        if (form3) {
            std::cout << "Assignment operator works correctly" << std::endl;
            delete form3;
        }
        
        std::cout << "\n=== Testing Different Bureaucrat Grades ===" << std::endl;
        
        std::cout << "\n9. Testing with mid-grade bureaucrat:" << std::endl;
        AForm* testForm = someRandomIntern.makeForm("presidential pardon", "Test Subject");
        if (testForm) {
            std::cout << *testForm << std::endl;
            manager.signForm(*testForm);
            manager.executeForm(*testForm);
            delete testForm;
        }
        
        std::cout << "\n=== Testing Multiple Forms Creation ===" << std::endl;
        
        std::cout << "\n10. Creating multiple forms rapidly:" << std::endl;
        AForm* forms[3];
        forms[0] = someRandomIntern.makeForm("shrubbery creation", "park");
        forms[1] = someRandomIntern.makeForm("robotomy request", "C-3PO");
        forms[2] = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        
        for (int i = 0; i < 3; i++) {
            if (forms[i]) {
                std::cout << "Form " << i + 1 << ": " << forms[i]->getName() << std::endl;
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                delete forms[i];
            }
        }
        
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
