#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("A", 0);
        Bureaucrat b("B", 151);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Bureaucrat a("A", 75);
        std::cout << a << std::endl;

        for (int i = 0; i < 74; i++)
            a.gradeIncrement();
        std::cout << a << std::endl;
        a.gradeIncrement();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat a("A", 100);
        std::cout << a << std::endl;

        for (int i = 0; i < 50; i++)
            a.gradeDecrement();
        std::cout << a << std::endl;
        a.gradeDecrement();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}