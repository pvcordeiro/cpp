# C++ Learning Journey 🚀

This repository contains my journey through C++ programming, exploring fundamental concepts through practical exercises. Each module focuses on specific C++ features and programming paradigms.


## � Table of Contents

- [CPP00 - Namespaces, Classes, Member Functions](#cpp00---namespaces-classes-member-functions-stdio-streams-initialization-lists-static-const)
- [CPP01 - Memory Allocation, Pointers, References](#cpp01---memory-allocation-pointers-to-members-references-switch-statement)
- [CPP02 - Operator Overloading, Canonical Form](#cpp02---ad-hoc-polymorphism-operator-overloading-orthodox-canonical-class-form)
- [CPP03 - Inheritance](#cpp03---inheritance)
- [CPP04 - Polymorphism, Abstract Classes](#cpp04---subtype-polymorphism-abstract-classes-interfaces)
- [CPP05 - Exceptions, Operator Overloading, File Streams](#cpp05---exceptions-operator-overloading-file-streams)
- [CPP06 - Casts, Serialization, Static Members](#cpp06---casts-serialization-static-members)
- [CPP07 - Templates, Iterators, Algorithms](#cpp07---templates-iterators-algorithms)
- [CPP08 - STL, Containers, Algorithms](#cpp08---stl-containers-algorithms)
- [CPP09 - Polymorphic Containers, Inheritance](#cpp09---polymorphic-containers-inheritance)
- [Building and Running](#️-building-and-running)
- [Key Learning Outcomes](#-key-learning-outcomes)
- [Code Quality Standards](#-code-quality-standards)
- [Skills Developed](#-skills-developed)

## �📚 Module Overview

### CPP00 - Namespaces, Classes, Member Functions, stdio streams, Initialization lists, Static, Const

**Key Concepts Learned:**
- Basic C++ syntax and iostream usage
- Class design and encapsulation
- Member functions and constructors
- Static members and methods
- Input/output formatting

#### Exercises:
- **ex00 - Megaphone**: Introduction to C++ iostream, string manipulation, and basic program structure
- **ex01 - Phonebook**: First class implementation with private members, constructors, and user interaction
- **ex02 - Account**: Static members, timestamps, and complex class interactions

---

### CPP01 - Memory Allocation, Pointers to Members, References, Switch Statement

**Key Concepts Learned:**
- Stack vs Heap memory allocation
- Pointers and references in C++
- Dynamic memory management with `new` and `delete`
- Object lifetime and scope
- Reference semantics

#### Exercises:
- **ex00 - BraiiiiiiinnnzzzZ**: Stack vs heap allocation, constructors/destructors
- **ex01 - Zombie Horde**: Dynamic array allocation and object initialization
- **ex02 - HI THIS IS BRAIN**: Understanding pointers vs references
- **ex03 - Unnecessary Violence**: References as class members and object relationships
- **ex04 - Sed is for Losers**: File I/O and string manipulation
- **ex05 - Harl 2.0**: Function pointers and method dispatch
- **ex06 - Harl Filter**: Switch statements and program flow control

---

### CPP02 - Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form

**Key Concepts Learned:**
- Operator overloading principles
- Copy constructor and assignment operator
- Orthodox Canonical Class Form (The Big Three)
- Fixed-point arithmetic
- Implicit vs explicit type conversions

#### Exercises:
- **ex00 - My First Class in Orthodox Canonical Form**: Basic canonical form implementation
- **ex01 - Towards a More Useful Fixed-Point Number Class**: Type conversions and constructors
- **ex02 - Now We're Talking**: Complete operator overloading (arithmetic, comparison, increment/decrement)

---

### CPP03 - Inheritance

**Key Concepts Learned:**
- Class inheritance and the "is-a" relationship
- Protected vs private vs public inheritance
- Virtual destructors and method overriding
- Base class initialization
- Diamond problem basics

#### Exercises:
- **ex00 - Aaaaand... OPEN!**: Basic class design with encapsulation
- **ex01 - Serena, my Love!**: Single inheritance and method overriding
- **ex02 - Repetitive Work**: Multiple inheritance and method resolution

---


### CPP04 - Subtype Polymorphism, Abstract Classes, Interfaces

**Key Concepts Learned:**
- Virtual functions and polymorphism
- Abstract classes and pure virtual functions
- Deep copy vs shallow copy
- Virtual destructors and proper cleanup
- Dynamic memory management with inheritance

#### Exercises:
- **ex00 - Polymorphism**: Basic virtual functions and polymorphic behavior
- **ex01 - I Don't Want to Set the World on Fire**: Deep copy implementation with Brain class
- **ex02 - Abstract Class**: Pure virtual functions and abstract base classes

---

### CPP05 - Exceptions, Operator Overloading, File Streams

**Key Concepts Learned:**
- Exception handling and custom exceptions
- Operator overloading (increment, decrement, stream operators)
- File I/O and stream manipulation
- Inheritance and polymorphism with exceptions
- Form and bureaucrat class interactions

#### Exercises:
- **ex00 - Bureaucrat**: Exception handling and operator overloading
- **ex01 - Form**: Inheritance, exceptions, and validation
- **ex02 - Shrubbery Creation**: File I/O, polymorphism, and exceptions
- **ex03 - Intern**: Dynamic object creation and exception safety

---

### CPP06 - Casts, Serialization, Static Members

**Key Concepts Learned:**
- C++ type casting (static_cast, dynamic_cast, etc.)
- Serialization and deserialization
- Static members and functions
- RTTI (Run-Time Type Information)
- Pseudo-random number generation

#### Exercises:
- **ex00 - Casts**: Type casting and RTTI
- **ex01 - Serialization**: Object serialization and pointer manipulation
- **ex02 - Base Class Identification**: Dynamic casting and polymorphism

---

### CPP07 - Templates, Iterators, Algorithms

**Key Concepts Learned:**
- Function and class templates
- Iterator patterns and STL algorithms
- Template specialization
- Generic programming
- Container manipulation

#### Exercises:
- **ex00 - Template**: Function templates and specialization
- **ex01 - Iter**: Iterator usage and template functions
- **ex02 - Array**: Template classes and array manipulation

---

### CPP08 - STL, Containers, Algorithms

**Key Concepts Learned:**
- Standard Template Library (STL) containers (vector, list, etc.)
- Algorithms (sort, find, etc.)
- Functors and predicates
- Exception safety with containers
- Custom container implementation

#### Exercises:
- **ex00 - Easy Find**: STL algorithms and exception handling
- **ex01 - Span**: Custom container and range algorithms
- **ex02 - MutantStack**: Stack extension and iterator support

---

### CPP09 - Polymorphic Containers, Inheritance

**Key Concepts Learned:**
- Polymorphic containers
- Multiple inheritance and interfaces
- Abstract base classes and virtual functions
- Dynamic memory management in containers
- Advanced object-oriented design

#### Exercises:
- **ex00 - RPN**: Reverse Polish Notation calculator with stack
- **ex01 - Bitcoin Exchange**: File parsing and data structures
- **ex02 - PmergeMe**: Polymorphic containers and sorting algorithms

---

## 🛠️ Building and Running

Each exercise contains its own Makefile. To build and run:

```bash
# Navigate to any exercise directory
cd cpp0X/exXX

# Compile
make

# Run the executable
./program_name
```

## 📝 Key Learning Outcomes

### Memory Management
- Understanding when to use stack vs heap allocation
- Proper resource management with constructors/destructors
- RAII (Resource Acquisition Is Initialization) principles

### Object-Oriented Programming
- Encapsulation through private/protected members
- Inheritance hierarchies and polymorphism
- Virtual and pure virtual functions and abstract classes
- Proper class design following C++ best practices

### C++ Language Features
- Operator overloading for natural syntax
- References vs pointers usage patterns
- Static members for class-wide data
- Orthodox Canonical Class Form for robust classes
- Virtual destructors and polymorphic cleanup

### Best Practices
- Const correctness
- Proper header file organization
- Memory leak prevention
- Deep copy implementation for resource management
- Virtual destructor usage in inheritance hierarchies
- Code organization and modularity

## 🔍 Code Quality Standards

All exercises follow:
- **C++98 standard** compliance
- **Orthodox Canonical Class Form** where applicable
- **Proper memory management** (no leaks)
- **Consistent coding style** with clear naming conventions
- **Comprehensive error handling**

## 🎯 Skills Developed

- **Problem-solving** through incremental complexity
- **Code organization** with headers and implementation files
- **Debugging** memory-related issues
- **Design patterns** in object-oriented programming
- **C++ idioms** and best practices

---

*This repository represents the foundation of my C++ journey, building from basic syntax to advanced object-oriented concepts. Each exercise builds upon previous knowledge while introducing new challenges and concepts.*
