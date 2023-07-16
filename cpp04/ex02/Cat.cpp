#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat& c): Animal("Cat")
{
    std::cout << "Cat copy constructor called" << std::endl;
    _type = c._type;
    _brain = new Brain(*c._brain);
}

Cat& Cat::operator=(const Cat& c)
{
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &c)
    {
        _type = c._type;
        delete this->_brain;
        _brain = new Brain(*c._brain); // use copy cons then copy assign
    }
    return (*this);
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << _type << " >> Meowwww Meawwww >>" << std::endl;
}