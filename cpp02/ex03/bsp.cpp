#include "Point.hpp"

Fixed calArea(Point const p1, Point const p2, Point const p3)
{
    return ((p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY())) / Fixed(2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // find the area of each triangle
    Fixed l(calArea(a, b, c));
    Fixed x(calArea(point, a, b));
    Fixed y(calArea(point, b, c));
    Fixed z(calArea(point, c, a));

    if (l < 0)
        l = l * Fixed(-1);
    if (x < 0)
        x = x * Fixed(-1);
    if (y < 0)
        y = y * Fixed(-1);
    if (z < 0)
        z = z * Fixed(-1);
        
    // if some area equal to 0, this mean it align on the same line
    bool edge = ((x == 0) || (y == 0) || (z == 0));
    if (edge)
        return (false);

    // So, if every areas are greater than 0 or positive
    // it mean the point is inside the triangle
    return (l == (x + y + z));
}