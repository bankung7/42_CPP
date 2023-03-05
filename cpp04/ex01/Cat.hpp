#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{

private:
    Brain* _brain;

public:
    Cat(void);
    Cat(const Cat& c);
    Cat& operator=(const Cat& c);
    ~Cat(void);

    void makeSound(void) const;

};

#endif
