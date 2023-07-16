#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{

protected:
    std::string _type;

public:
    Animal(void);
    Animal(const std::string& type);
    Animal(const Animal& c);
    Animal& operator=(const Animal& c);
    virtual ~Animal(void);

    virtual void makeSound(void) const;

    std::string getType(void) const;

};

#endif
