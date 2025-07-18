#include "Span.hpp"

Span::Span(void) : vec(), max(0) {}

Span::Span(unsigned int N) : vec(), max(N) {}

Span::Span(const Span &copyFrom) : vec(copyFrom.vec), max(copyFrom.max) {}

Span& Span::operator=(const Span &right)
{
	if (this == &right)
		return (*this);
	vec = right.vec;
	max = right.max;
	return (*this);
}

Span::~Span(void) {}

void	Span::addNumber(int n)
{
	if (vec.size() >= max)
		throw (std::runtime_error("Storage Full"));
	vec.push_back(n);
}

int		Span::shortestSpan(void)
{
	if (vec.size() < 2)
		throw (std::runtime_error("Too few member in vector"));
	std::vector<int> sorted(vec);
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> diffs(sorted.size() - 1);
	std::transform(sorted.begin() + 1, sorted.end(), sorted.begin(), diffs.begin(), std::minus<int>());
	return (*std::min_element(diffs.begin(), diffs.end()));
}

int		Span::longestSpan(void)
{
	if (vec.size() < 2)
		throw (std::runtime_error("Too few member in vector"));
	return ((*std::max_element(vec.begin(), vec.end())) - (*std::min_element(vec.begin(), vec.end())));
}

void	Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) 
{
	if (vec.size() + (std::distance(begin, end) > max))
		throw (std::runtime_error("Storage Full"));
	vec.insert(vec.end(), begin, end);
}


unsigned int	Span::getMax(void)
{
	return (max);
}
