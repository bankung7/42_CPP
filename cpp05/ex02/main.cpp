#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Bureaucrat a("A", 146);
    Bureaucrat b("B", 130);
    std::cout << a << std::endl << std::endl;
    std::cout << b << std::endl << std::endl;

    try
    {
       ShrubberyCreationForm sf("Home");
       ShrubberyCreationForm ss("School");
       std::cout << sf << std::endl << std::endl;
       a.signForm(sf);
       a.executeForm(sf);
       b.executeForm(ss);

       std::cout << std::endl;
       std::cout << sf << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    return (0);
}