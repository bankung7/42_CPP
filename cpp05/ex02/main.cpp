#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("A", 146);
        Bureaucrat b("B", 70);
        Bureaucrat c("C", 20);
        ShrubberyCreationForm fs("Home");
        RobotomyRequestForm fr("Town");
        PresidentialPardonForm fp("Prayuth");

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl << std::endl;

        std::cout << fs << std::endl << std::endl;
        std::cout << fr << std::endl << std::endl;
        std::cout << fp << std::endl << std::endl;

        try
        {
            a.signForm(fs);
            b.signForm(fs);
            a.executeForm(fs);
            b.executeForm(fs);
            std::cout << std::endl;
            c.signForm(fr);
            c.executeForm(fr);
            std::cout << std::endl;
            c.signForm(fp);
            c.executeForm(fp);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}