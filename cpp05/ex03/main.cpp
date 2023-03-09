#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    {
        Bureaucrat a("A", 40);
        Bureaucrat b("B", 1);

        Intern someRandomIntern;
        AForm* scf;
        AForm* rrf;
        AForm* ppf;

        try
        {
            scf = someRandomIntern.makeForm("shrubbery creation", "Home");
            rrf = someRandomIntern.makeForm("robotomy request", "Colder");
            ppf = someRandomIntern.makeForm("presidential pardon", "Denver");

            std::cout << std::endl;

            std::cout << *scf << std::endl << std::endl;
            std::cout << *rrf << std::endl << std::endl;
            std::cout << *ppf << std::endl << std::endl;

            a.signForm(*scf);
            a.signForm(*rrf);
            a.signForm(*ppf);
            b.signForm(*ppf);

            std::cout << std::endl;

            a.executeForm(*scf);
            std::cout << std::endl;
            a.executeForm(*rrf);
            std::cout << std::endl;
            b.executeForm(*ppf);

            delete scf;
            delete rrf;
            delete ppf;

            std::cout << std::endl;

            ppf = someRandomIntern.makeForm("resignation", "golf");
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return (0);
}