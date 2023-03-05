#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog& c): Animal("Dog")
{
    std::cout << "Dog copy constructor called" << std::endl;
    _type = c._type;
    _brain = new Brain(*c._brain);
}

Dog& Dog::operator=(const Dog& c)
{
    std::cout << "Dog copy assignment called" << std::endl;
    if (this != &c)
    {
        _type = c._type;
        delete this->_brain;
        _brain = new Brain(*c._brain); // use copy cons then copy assign
    }
    return (*this);
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << _type << " >> Boxxxesss Bowwoooo >>" << std::endl;
}