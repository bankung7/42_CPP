#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{

private:
    Fixed const x;
    Fixed const y;

public:
    Point(void);
    Point(const float, const float);
    Point(const Point&);
    Point& operator=(const Point&);
    ~Point(void);

    // get x and y
    Fixed getX(void) const;
    Fixed getY(void) const;

};

#endif