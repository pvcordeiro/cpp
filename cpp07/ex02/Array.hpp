#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T* 		data;
		size_t	length;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &copyFrom);
		Array &operator=(const Array &right);
		~Array(void);

		T &operator[](size_t i);
		const T &operator[](size_t i) const;

		size_t	size(void) const;
};

#include "Array.tpp"

#endif
