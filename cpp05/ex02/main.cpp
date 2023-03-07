#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Bureaucrat a("A", 146);
    Bureaucrat b("B", 100);
    ShrubberyCreationForm fs("Home");

    std::cout << a << std::endl;
    std::cout << b << std::endl << std::endl;

    std::cout << fs << std::endl << std::endl;

    try
    {
        a.signForm(fs);
        b.signForm(fs);
        a.signForm(fs);
        b.signForm(fs);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}