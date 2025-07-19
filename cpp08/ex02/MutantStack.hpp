#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template<typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		MutantStack(void) : std::stack<T, Container>(void) {}
		MutantStack(const MutantStack& copyFrom) : std::stack<T, Container>(copyFrom) {}
		MutantStack& operator=(const MutantStack& right)
		{
			std::stack<T, Container>::operator=(right);
			return (*this);
		}
		~MutantStack(void) {}

		iterator begin() { return (this->c.begin()); };
		iterator end() { return(this->c.end()); };
		const_iterator begin() const { return (this->c.begin()); };
		const_iterator end() const { return (this->c.end()); };
};

#endif
