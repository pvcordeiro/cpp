#include "easyfind.hpp"

template <typename T>

int easyfind(T &container, int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw (std::runtime_error("Value not found"));
	return (std::distance(container.begin(), it));
}
