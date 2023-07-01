#include <iostream>
#include "Serializer.hpp"

int main(void)
{
    Data* dptr = new Data;
    dptr->c = 'A';
    dptr->seq = 69;

    uintptr_t iptr = 0;
    Data* d2ptr = 0;

    std::cout << "Original Data" << std::endl;
    std::cout << "dptr : " << dptr << " => " << dptr->c << " => " << dptr->seq << std::endl;
    std::cout << "iptr : " << iptr << std::endl;
    std::cout << "d2ptr : " << d2ptr << std::endl;

    std::cout << std::endl;

    iptr = Serializer::serialize(dptr);
    std::cout << "Make it Serialize" << std::endl;
    std::cout << "iptr : " << iptr << std::endl << std::endl;

    d2ptr = Serializer::deserialize(iptr);
    std::cout << "Convert it back to Data" << std::endl;
    std::cout << "dptr : " << d2ptr << " => " << d2ptr->c << " => " << d2ptr->seq << std::endl;

    delete dptr;

    return (0);
}

// reinterpret cast is used to cast a pointer to any other type of pointer.
// it does not check whether the pointer or the data pointed to by the pointer is the same or not.
// it can cast a pointer to an integer or vice versa.
