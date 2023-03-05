#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type): _type(type)
{
    std::cout << "Animal defined constructor called" << std::endl;
}

Animal::Animal(const Animal& c)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = c;
}

Animal& Animal::operator=(const Animal& c)
{
    std::cout << "Animal copy assignment called" << std::endl;
    if (this != &c)
        _type = c._type;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal >> Animmmmmmmmalllllllllll" << std::endl;
}

std::string Animal::getType(void) const
{
    return (_type);
}