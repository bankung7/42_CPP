#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
    // std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& c)
{
    // std::cout << "AMateria copy constructor called" << std::endl;
    *this = c;
}

AMateria& AMateria::operator=(const AMateria& c)
{
    // std::cout << "AMateria copy assignment called" << std::endl;
    if (this != &c) 
    {}
    return (*this);
}

AMateria::~AMateria(void)
{
    // std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType(void) const
{
    return (_type);
}

// AMateria* AMateria::clone(void) const
// {
//     return (0);
// }

// use function
void AMateria::use(ICharacter& target)
{
    (void)target;
}