#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &copyFrom) {(void)copyFrom;}

Serializer &Serializer::operator=(const Serializer &right) {(void)right;return(*this);}

Serializer::~Serializer(void) {}

unsigned long	Serializer::serialize(Data*ptr)
{
	return (reinterpret_cast<unsigned long>(ptr));
}

Data*		Serializer::deserialize(unsigned long raw)
{
	return (reinterpret_cast<Data*>(raw));
}
