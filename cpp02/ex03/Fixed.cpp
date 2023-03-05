#include "Fixed.hpp"

const int Fixed::fractBits = 8;

// Default constructor
Fixed::Fixed(void) : value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

// Int
Fixed::Fixed(const int value) : value(value << fractBits)
{
    // std::cout << "Int constructor called" << std::endl;
}
// float
Fixed::Fixed(const float value) : value(roundf(value * (1 << fractBits)))
{
    // std::cout << "Float constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& f)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

// Copy addignment
Fixed& Fixed::operator=(const Fixed& f)
{
    // std::cout << "Copy assignment oeprator called" << std::endl;
    if (this != &f)
        this->setRawBits(f.getRawBits());
    return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
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

// comparision member function < > <= >= == !=
bool Fixed::operator<(const Fixed &f) const
{
    return (this->value < f.value);
}

bool Fixed::operator>(const Fixed &f) const
{
    return (this->value > f.value);
}

bool Fixed::operator<=(const Fixed &f) const
{
    return (this->value <= f.value);
}

bool Fixed::operator>=(const Fixed &f) const
{
    return (this->value >= f.value);
}

bool Fixed::operator==(const Fixed &f) const
{
    return (this->value == f.value);
}

bool Fixed::operator!=(const Fixed &f) const
{
    return (this->value != f.value);
}

// arithemetic + - * /
Fixed Fixed::operator+(const Fixed &f) const
{
    Fixed c;
    c.setRawBits(this->getRawBits() + f.getRawBits());
    return (c);
}

Fixed Fixed::operator-(const Fixed &f) const
{
    Fixed c;
    c.setRawBits(this->getRawBits() - f.getRawBits());
    return (c);
}

Fixed Fixed::operator*(const Fixed &f) const
{
    Fixed c;
    c.setRawBits((this->getRawBits() * f.getRawBits()) >> fractBits);
    return (c);
}

Fixed Fixed::operator/(const Fixed &f) const
{
    Fixed c;
    c.setRawBits((this->getRawBits() << fractBits) / f.getRawBits());
    return (c);
}

// incremental and decremental, pre and post
Fixed Fixed::operator++(void)
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed c(this->toFloat());
    this->value++;
    return (c);
}
Fixed Fixed::operator--(void)
{
    this->value--;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed c(this->toFloat());
    this->value--;
    return (c);
}

// static min and const
Fixed const &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed const &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

// overload operator
std::ostream &operator<<(std::ostream &stream, const Fixed &f)
{
    stream << f.toFloat();
    return (stream);
}
