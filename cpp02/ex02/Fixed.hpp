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

    // comparision member function < > <= >= == !=
    bool operator<(const Fixed& f) const;
    bool operator>(const Fixed& f) const;
    bool operator<=(const Fixed& f) const;
    bool operator>=(const Fixed& f) const;
    bool operator==(const Fixed& f) const;
    bool operator!=(const Fixed& f) const;

    // arithemetic + - * /
    Fixed operator+(const Fixed& f) const;
    Fixed operator-(const Fixed& f) const;
    Fixed operator*(const Fixed& f) const;
    Fixed operator/(const Fixed& f) const;

    // incremental and decremental, pre and post
    Fixed operator++(void);
    Fixed operator++(int);
    Fixed operator--(void);
    Fixed operator--(int);

    // static min and const
    static const Fixed& min(Fixed& a, Fixed& b); 
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // static max and const
    
};

// overload operator
std::ostream& operator<<(std::ostream& stream, const Fixed& f);

#endif
