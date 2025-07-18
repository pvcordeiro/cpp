#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class	Span
{
	private:
		std::vector<int> vec;
		unsigned int	max;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &copyFrom);
		Span& operator=(const Span &copyFrom);
		~Span(void);

		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		unsigned int	getMax(void);
};

#endif
