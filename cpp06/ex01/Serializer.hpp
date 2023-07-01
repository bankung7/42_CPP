#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
    char c;
    int seq;
};

class Serializer
{
    
private:
    Serializer();
    Serializer(const Serializer& c);
    Serializer& operator=(const Serializer& c);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif

// static class that has 2 methods

// uintptr_t serialize(Data* ptr);
// It takes a pointer and converts it to the unsigned integer type uintptr_t.

// Data* deserialize(uintptr_t raw);
// it takes an unsigned integer parameter and converts it to a pointer to Data.