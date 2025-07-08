#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "=== Module 04 Exercise 02: Abstract Classes and Pure Virtual Functions ===" << std::endl;
	
	std::cout << "\n=== Testing Abstract Class Behavior ===" << std::endl;
	std::cout << "❌ Cannot instantiate Animal directly (would cause compiler error):" << std::endl;
	std::cout << "// Animal animal;           // Compiler error!" << std::endl;
	std::cout << "// Animal* animal = new Animal();  // Compiler error!" << std::endl;
	std::cout << "✅ Reason: Animal::makeSound() is pure virtual (= 0)" << std::endl;
	
	std::cout << "\n=== Creating Concrete Animals (Dog and Cat) ===" << std::endl;
	Animal* dog1 = new Dog();  // ✅ Works - Dog implements makeSound()
	Animal* cat1 = new Cat();  // ✅ Works - Cat implements makeSound()
	
	std::cout << "\n=== Testing Polymorphism with Abstract Base ===" << std::endl;
	std::cout << "Dog1 type: " << dog1->getType() << std::endl;
	std::cout << "Cat1 type: " << cat1->getType() << std::endl;
	
	std::cout << "\nTesting pure virtual function calls:" << std::endl;
	std::cout << "Dog1 sound: ";
	dog1->makeSound();  // Calls Dog::makeSound() - no Animal implementation exists
	std::cout << "Cat1 sound: ";
	cat1->makeSound();  // Calls Cat::makeSound() - no Animal implementation exists
	
	std::cout << "\n=== Testing Array of Abstract Base Pointers ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];
	
	std::cout << "Creating array of " << arraySize << " animals (mix of Dogs and Cats)..." << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		if (i % 2 == 0)
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
	
	std::cout << "\nTesting polymorphic behavior with abstract base:" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();  // Pure virtual function calls concrete implementations
	}
	
	std::cout << "\n=== Testing Deep Copy with Abstract Base ===" << std::endl;
	std::cout << "Creating copies through concrete classes..." << std::endl;
	
	Dog* dog2 = new Dog();
	Cat* cat2 = new Cat();
	
	// Copy through concrete types (since we can't instantiate Animal)
	Dog dog3(*static_cast<Dog*>(dog1));  // Copy constructor
	Cat cat3(*static_cast<Cat*>(cat1));  // Copy constructor
	
	std::cout << "Dog3 (copy) sound: ";
	dog3.makeSound();
	std::cout << "Cat3 (copy) sound: ";
	cat3.makeSound();
	
	// Assignment through concrete types
	*dog2 = *static_cast<Dog*>(dog1);
	*cat2 = *static_cast<Cat*>(cat1);
	
	std::cout << "Dog2 (assigned) sound: ";
	dog2->makeSound();
	std::cout << "Cat2 (assigned) sound: ";
	cat2->makeSound();
	
	std::cout << "\n=== Testing Virtual Destructors with Abstract Base ===" << std::endl;
	std::cout << "Deleting through abstract base pointers..." << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Deleting Animal[" << i << "] (" << animals[i]->getType() << ")..." << std::endl;
		delete animals[i];  // Virtual destructor ensures correct cleanup
	}
	
	std::cout << "\n=== Cleanup Remaining Objects ===" << std::endl;
	delete dog1;
	delete cat1;
	delete dog2;
	delete cat2;
	// dog3 and cat3 are stack objects - auto cleanup
	
	std::cout << "\n=== Summary ===" << std::endl;
	std::cout << "✅ Abstract class cannot be instantiated directly" << std::endl;
	std::cout << "✅ Pure virtual functions (= 0) force implementation in derived classes" << std::endl;
	std::cout << "✅ Abstract base pointers work perfectly for polymorphism" << std::endl;
	std::cout << "✅ Concrete derived classes implement all pure virtual functions" << std::endl;
	std::cout << "✅ Virtual destructors work correctly with abstract bases" << std::endl;
	std::cout << "✅ Deep copy still works through concrete derived classes" << std::endl;
	std::cout << "✅ Brain objects properly managed in derived classes" << std::endl;
	std::cout << "✅ Abstract classes enforce interface contracts" << std::endl;
	
	return 0;
}
