#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(0, 0);
    Point b(0, 30);
    Point c(30, 0);

    // test //
    std::cout << "edge : " << bsp(a, b, c, Point(0, 15)) << std::endl;
    std::cout << "vertex : " << bsp(a, b, c, Point(0, 30)) << std::endl;
    std::cout << "somewhere in : " << bsp(a, b, c, Point(10 , 5)) << std::endl;
    std::cout << "somewhere in : " << bsp(a, b, c, Point(1 , 2)) << std::endl;
    std::cout << "somewhere out : " << bsp(a, b, c, Point(35 , 15)) << std::endl;
    std::cout << "somewhere out : " << bsp(a, b, c, Point(-1000 , 5)) << std::endl;

    return 0;
}