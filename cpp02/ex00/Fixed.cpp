#include "Fixed.hpp"

const int Fixed::fractBits = 8;

// Deafault constructor
Fixed::Fixed(void): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

// Copy addignment
Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->setRawBits(f.getRawBits());
    return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

// getRawBits
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

// setRawBits
void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}