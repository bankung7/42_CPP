#include "Fixed.hpp"

const int Fixed::fractBits = 8;

// Default constructor
Fixed::Fixed(void) : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value) : value(value << fractBits)
{
    std::cout << "Int constructor called" << std::endl;
}
// float constructor
Fixed::Fixed(const float value) : value(roundf(value * (1 << fractBits)))
{
    std::cout << "Float constructor called" << std::endl;
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
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

// setRawBits
void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

// toFloat
float Fixed::toFloat(void) const
{
    return (value / (float)(1 << fractBits));
}

// toInt
int Fixed::toInt(void) const
{
    return (value >> fractBits);
}

// toInt

// overload operator
std::ostream& operator<<(std::ostream& stream, const Fixed& f)
{
    stream << f.toFloat();
    return (stream);
}