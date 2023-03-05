#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

private:

public:
    WrongCat(void);
    WrongCat(const WrongCat& c);
    WrongCat& operator=(const WrongCat& c);
    ~WrongCat(void);

    void makeSound(void) const;

};

#endif
