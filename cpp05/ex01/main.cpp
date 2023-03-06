#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form a("Form A", 0, 40);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    Bureaucrat b("B", 100);
    Form fb("Form B", 50, 30);
    Form fc("Form C", 110, 90);

    std::cout << b << std::endl << std::endl;
    std::cout << fb << std::endl << std::endl;
    std::cout << fc << std::endl;

    std::cout << std::endl;

    try
    {
        b.signForm(fb);
        b.signForm(fc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << fb << std::endl;
    std::cout << std::endl;
    std::cout << fc << std::endl;

    return (0);
}