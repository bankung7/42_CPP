#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("A", 1);
        std::cout << a << std::endl;
        
        Bureaucrat z("Z", 150);
        std::cout << z << std::endl;

        Bureaucrat b("B", 0);
        Bureaucrat c("B", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    Bureaucrat a("A", 100);
    std::cout << a << std::endl;

    try
    {
        for (int i = 0; i < 99; i++)
            a.gradeIncrement();
        std::cout << a << std::endl;
        a.gradeIncrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;

    Bureaucrat b("B", 150);
    b = a;
    std::cout << b << std::endl;
    try
    {
        for (int i = 0; i < 149; i++)
            b.gradeDecrement();
        std::cout << b << std::endl;
        b.gradeDecrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}