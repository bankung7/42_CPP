#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{

private:
    Brain* _brain;

public:
    Dog(void);
    Dog(const Dog& c);
    Dog& operator=(const Dog& c);
    ~Dog(void);

    void makeSound(void) const;

};

#endif
