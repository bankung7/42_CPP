#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& c): WrongAnimal()
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = c;
}

WrongCat& WrongCat::operator=(const WrongCat& c)
{
    std::cout << "WrongCat copy assignment called" << std::endl;
    if (this != &c)
        _type = c._type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat >> WronnnnggggMeawwwww" << std::endl;
}