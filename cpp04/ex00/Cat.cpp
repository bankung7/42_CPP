#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& c): Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = c;
}

Cat& Cat::operator=(const Cat& c)
{
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &c)
        this->_type = c._type;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << this->_type << " >> Meowww Meawwwww" << std::endl;
}