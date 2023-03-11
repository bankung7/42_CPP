#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("A", 140);
        std::cout << a << std::endl << std::endl;

        std::cout << "Intern exist" << std::endl;
        Intern ia;
        AForm* scf = ia.makeForm("shrubbery creation", "Home");
        AForm* rrf = ia.makeForm("robotomy request", "School");
        AForm* ppf = ia.makeForm("presidential pardon", "Player");

        std::cout << std::endl;

        std::cout << *scf << std::endl << std::endl;
        std::cout << *rrf << std::endl << std::endl;
        std::cout << *ppf << std::endl << std::endl;

        try
        {
            std::cout << "Intern try to create non-exist form" << std::endl;
            AForm* bf= ia.makeForm("blank form", "None");
            std::cout << *bf << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        std::cout << std::endl;
        std::cout << "Let's try to sign and execute" << std::endl;
        a.signForm(*scf);
        a.executeForm(*scf);
        
        for (int i = 0; i < 100; i++)
            a.gradeIncrement();
        std::cout << std::endl << a << std::endl;
        a.executeForm(*scf);
        std::cout << std::endl;

        a.signForm(*rrf);
        a.executeForm(*rrf);

        for (int i = 0; i < 25; i++)
            a.gradeIncrement();
        std::cout << std::endl << a << std::endl;
        std::cout << std::endl;
        a.signForm(*ppf);
        a.executeForm(*ppf);

        for (int i = 0; i < 10; i++)
            a.gradeIncrement();
        std::cout << std::endl << a << std::endl;
        a.executeForm(*ppf);

        delete scf;
        delete rrf;
        delete ppf;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}