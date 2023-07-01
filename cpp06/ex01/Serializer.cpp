#include "Serializer.hpp"

Serializer::Serializer(void)
{

}

Serializer::Serializer(const Serializer& c)
{
    *this = c;
}

Serializer& Serializer::operator=(const Serializer& c)
{
    if (this != &c)
    {
    }
    return (*this);
}

Serializer::~Serializer(void)
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

// the reinterpret_cast is used to convert a pointer of some data type into a pointer of another data type,
// even if the data types before and after conversion are different.

// the reinterpret_cast only guarantees that if we cast a pointer to a different type,
// and then reinterpret_cast it bask to the original type,
// we will get the original value