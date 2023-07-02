#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

    int getRawBits(void) const;
    void setRawBits(int const raw);

};

#endif
