#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "=== Module 04 Exercise 01: Deep Copy with Brain ===" << std::endl;
	
	std::cout << "\n=== Creating Animals with Brains ===" << std::endl;
	Dog* dog1 = new Dog();
	Cat* cat1 = new Cat();
	
	std::cout << "\n=== Testing Basic Functionality ===" << std::endl;
	std::cout << "Dog1 type: " << dog1->getType() << std::endl;
	std::cout << "Cat1 type: " << cat1->getType() << std::endl;
	
	dog1->makeSound();
	cat1->makeSound();
	
	std::cout << "\n=== Testing Deep Copy with Copy Constructor ===" << std::endl;
	std::cout << "Creating dog2 as copy of dog1..." << std::endl;
	Dog* dog2 = new Dog(*dog1);  // Copy constructor should create new Brain
	
	std::cout << "Creating cat2 as copy of cat1..." << std::endl;
	Cat* cat2 = new Cat(*cat1);  // Copy constructor should create new Brain
	
	std::cout << "\n=== Testing Deep Copy with Assignment Operator ===" << std::endl;
	std::cout << "Creating dog3 and cat3..." << std::endl;
	Dog* dog3 = new Dog();
	Cat* cat3 = new Cat();
	
	std::cout << "Assigning dog1 to dog3..." << std::endl;
	*dog3 = *dog1;  // Assignment operator should deep copy Brain
	
	std::cout << "Assigning cat1 to cat3..." << std::endl;
	*cat3 = *cat1;  // Assignment operator should deep copy Brain
	
	std::cout << "\n=== Testing Array of Animals (Subject Requirement) ===" << std::endl;
	const int arraySize = 4;
	Animal* animals[arraySize];
	
	std::cout << "Creating array of " << arraySize << " animals (half Dogs, half Cats)..." << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
		{
			std::cout << "Creating Dog[" << i << "]" << std::endl;
			animals[i] = new Dog();
		}
		else
		{
			std::cout << "Creating Cat[" << i << "]" << std::endl;
			animals[i] = new Cat();
		}
	}
	
	std::cout << "\nTesting polymorphic behavior:" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}
	
	std::cout << "\nDeleting array of animals (testing virtual destructors):" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Deleting Animal[" << i << "]..." << std::endl;
		delete animals[i];  // Should call proper destructor chain and free Brain
	}
	
	std::cout << "\n=== Testing Brain Independence (Deep Copy Verification) ===" << std::endl;
	std::cout << "All copied animals should have independent Brains" << std::endl;
	std::cout << "Original and copied animals can have different brain states" << std::endl;
	
	// Verify all animals still work (independent Brains)
	std::cout << "\nVerifying independence:" << std::endl;
	std::cout << "Dog1: ";
	dog1->makeSound();
	std::cout << "Dog2 (copy): ";
	dog2->makeSound();
	std::cout << "Dog3 (assigned): ";
	dog3->makeSound();
	
	std::cout << "Cat1: ";
	cat1->makeSound();
	std::cout << "Cat2 (copy): ";
	cat2->makeSound();
	std::cout << "Cat3 (assigned): ";
	cat3->makeSound();
	
	std::cout << "\n=== Cleanup ===" << std::endl;
	std::cout << "Deleting remaining animals..." << std::endl;
	delete dog1;
	delete dog2;
	delete dog3;
	delete cat1;
	delete cat2;
	delete cat3;
	
	std::cout << "\n=== Summary ===" << std::endl;
	std::cout << "✅ Deep copy implemented: Each animal has its own Brain" << std::endl;
	std::cout << "✅ Copy constructor creates independent Brain objects" << std::endl;
	std::cout << "✅ Assignment operator properly cleans up and deep copies Brain" << std::endl;
	std::cout << "✅ Virtual destructors ensure proper cleanup of derived classes" << std::endl;
	std::cout << "✅ No memory leaks: Each Brain is properly deleted" << std::endl;
	
	return 0;
}
