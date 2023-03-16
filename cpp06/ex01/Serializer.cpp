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