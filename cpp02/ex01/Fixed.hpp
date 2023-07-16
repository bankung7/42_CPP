#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

private:
    int value;
    static const int fractBits;

public:
    Fixed(void);
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    ~Fixed(void);

    // int and float constructor
    Fixed(const int value);
    Fixed(const float value);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    // to float and to int
    float toFloat(void) const;
    int toInt(void) const;

};

// overload operator
std::ostream& operator<<(std::ostream& stream, const Fixed& f);

#endif
