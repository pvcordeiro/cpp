#include "Data.hpp"

Data::Data(void) : value(0) {}

Data::Data(const Data &copyFrom) : value(copyFrom.value) {}

Data &Data::operator=(const Data &right)
{
	this->value = right.value;
	return (*this);
}

Data::~Data(void) {}
