#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
    // std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& c): AMateria(c._type)
{
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& c)
{
    // std::cout << "Cure copy assignment called" << std::endl;
    if (this != &c)
        _type = c._type;
    return (*this);
}

Cure::~Cure(void)
{
    // std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone(void) const
{
    return (new Cure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}