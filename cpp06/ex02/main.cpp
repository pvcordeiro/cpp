#include "functions.hpp"

int main(void)
{
    std::cout << "=== Testing Runtime Type Identification ===" << std::endl;
    srand(time(NULL));
    std::cout << "\n=== Testing generate() and identify() functions ===" << std::endl;
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;
        Base* ptr = generate();
        std::cout << "Identifying via pointer: ";
        identify(ptr);
        std::cout << "Identifying via reference: ";
        identify(*ptr);
        delete ptr;
    }
    
    std::cout << "\n=== Testing with known types ===" << std::endl;
	
    std::cout << "\n--- Testing with A ---" << std::endl;
    Base* a = new A();
    std::cout << "Pointer identification: ";
    identify(a);
    std::cout << "Reference identification: ";
    identify(*a);
    delete a;
    
    std::cout << "\n--- Testing with B ---" << std::endl;
    Base* b = new B();
    std::cout << "Pointer identification: ";
    identify(b);
    std::cout << "Reference identification: ";
    identify(*b);
    delete b;
    
    std::cout << "\n--- Testing with C ---" << std::endl;
    Base* c = new C();
    std::cout << "Pointer identification: ";
    identify(c);
    std::cout << "Reference identification: ";
    identify(*c);
    delete c;
    
    std::cout << "\n=== Testing edge cases ===" << std::endl;
    
    std::cout << "\n--- Testing with NULL pointer ---" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "NULL pointer identification: ";
    identify(nullPtr);
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}
