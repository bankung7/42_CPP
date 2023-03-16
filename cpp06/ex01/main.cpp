#include <iostream>
#include "Serializer.hpp"


int main(void)
{
    Data* dptr = new Data;
    dptr->c = 'A';
    dptr->seq = 69;

    uintptr_t iptr = 0;
    Data* d2ptr = 0;

    std::cout << "dptr : " << dptr << " => " << dptr->c << " => " << dptr->seq << std::endl;
    std::cout << "iptr : " << iptr << std::endl;
    std::cout << "d2ptr : " << d2ptr << std::endl;

    std::cout << std::endl;

    iptr = Serializer::serialize(dptr);
    std::cout << "iptr : " << iptr << std::endl;

    d2ptr = Serializer::deserialize(iptr);
    std::cout << "dptr : " << d2ptr << " => " << d2ptr->c << " => " << d2ptr->seq << std::endl;

    delete dptr;
    
    return (0);
}