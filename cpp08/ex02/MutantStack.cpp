#include "MutantStack.hpp"
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other) {
	std::stack<T, Container>::operator=(other);
	return *this;
}
template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

MutantStack::Container::iterator begin() { return this->c.begin(); }
MutantStack::Container::iterator end() { return this->c.end(); }
MutantStack::Container::const_iterator begin() const { return this->c.begin(); }
MutantStack::Container::const_iterator end() const { return this->c.end(); }