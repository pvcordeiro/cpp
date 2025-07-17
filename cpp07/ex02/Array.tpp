#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : data(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), length(n) {}

template <typename T>
Array<T>::Array(const Array &copyFrom) : data(NULL), length(copyFrom.length)
{
	if (length)
		data = new T[length];
	for (size_t i = 0; i < length; ++i)
		data[i] = copyFrom.data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &right)
{
	if (this == &right)
		return (*this);
	delete[] data;
	length = right.length;
	data = length ? new T[length] : NULL;
	for (size_t i = 0; i < length; ++i)
		data[i] = right.data[i];
	return (*this);
}

template <typename T>
Array<T>::~Array(void) { delete[] data; }

template <typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= length)
		throw (std::out_of_range("Index out of bounds"));
	return (data[i]);
}

template <typename T>
const T &Array<T>::operator[](size_t i) const
{
	if (i >= length)
		throw (std::out_of_range("Index out of bounds"));
	return (data[i]);
}

template <typename T>
size_t Array<T>::size(void) const { return (length); }
