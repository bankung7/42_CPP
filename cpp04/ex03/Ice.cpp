#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& c): AMateria(c._type)
{
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& c)
{
    // std::cout << "Ice copy assignment called" << std::endl;
    if (this != &c)
        _type = c._type;
    return (*this);
}

Ice::~Ice(void)
{
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone(void) const
{
    return (new Ice);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}