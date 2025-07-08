#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing Proper Polymorphism (Animal with virtual functions) ===" << std::endl;
	
	// Creating animals through base class pointers
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "Animal type: " << animal->getType() << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	
	std::cout << "\nTesting makeSound() - should call correct derived class method:" << std::endl;
	std::cout << "Animal sound: ";
	animal->makeSound();
	std::cout << "Dog sound: ";
	dog->makeSound();
	std::cout << "Cat sound: ";
	cat->makeSound();
	
	// Clean up
	delete animal;
	delete dog;
	delete cat;
	
	std::cout << "\n=== Testing Improper Polymorphism (WrongAnimal without virtual functions) ===" << std::endl;
	
	// Creating wrong animals through base class pointers
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	
	std::cout << "\nTesting makeSound() - should call base class method (wrong behavior):" << std::endl;
	std::cout << "WrongAnimal sound: ";
	wrongAnimal->makeSound();
	std::cout << "WrongCat sound (through base pointer): ";
	wrongCat->makeSound(); // This will call WrongAnimal's makeSound, not WrongCat's!
	
	// Test direct WrongCat instance to show the difference
	WrongCat directWrongCat;
	std::cout << "WrongCat sound (direct instance): ";
	directWrongCat.makeSound(); // This will call WrongCat's makeSound
	
	// Clean up
	delete wrongAnimal;
	delete wrongCat;
	
	std::cout << "\n=== Testing Copy Constructor and Assignment Operator ===" << std::endl;
	
	Dog originalDog;
	Dog copiedDog(originalDog);  // Copy constructor
	Dog assignedDog;
	assignedDog = originalDog;   // Assignment operator
	
	std::cout << "Original dog: ";
	originalDog.makeSound();
	std::cout << "Copied dog: ";
	copiedDog.makeSound();
	std::cout << "Assigned dog: ";
	assignedDog.makeSound();
	
	std::cout << "\n=== Summary ===" << std::endl;
	std::cout << "- Animal class uses virtual functions for proper polymorphism" << std::endl;
	std::cout << "- WrongAnimal class doesn't use virtual functions, causing incorrect behavior" << std::endl;
	std::cout << "- When using base class pointers, virtual functions ensure correct derived method calls" << std::endl;
	
	return 0;
}
