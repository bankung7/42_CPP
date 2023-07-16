#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
    std::cout << "WrongAnimal defined constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& c)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = c;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& c)
{
    std::cout << "WrongAnimal copy assignment called" << std::endl;
    if (this != &c)
        type = c.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal >> Wronimalllll" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}