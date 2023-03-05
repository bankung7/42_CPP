#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& c): Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = c;
}

Dog& Dog::operator=(const Dog& c)
{
    std::cout << "Dog copy assignment called" << std::endl;
    if (this != &c)
        this->_type = c._type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << this->_type << " >> Boxxxesss Bowwoooo" << std::endl;
}