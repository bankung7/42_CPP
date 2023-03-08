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

        Intern someRandomIntern;
        AForm* scf;
        AForm* rrf;
        AForm* ppf;

        try
        {
            scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
            rrf = someRandomIntern.makeForm("robotomy request", "Colder");
            ppf = someRandomIntern.makeForm("presidential pardon", "Denver");

            std::cout << *scf << std::endl << std::endl;
            std::cout << *rrf << std::endl << std::endl;
            std::cout << *ppf << std::endl << std::endl;

            a.signForm(*scf);
            a.signForm(*rrf);
            a.signForm(*ppf);

            std::cout << std::endl;

            a.executeForm(*scf);
            a.executeForm(*rrf);
            a.executeForm(*ppf);

            delete scf;
            delete rrf;
            delete ppf;

            ppf = someRandomIntern.makeForm("resignation", "golf");
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return (0);
}