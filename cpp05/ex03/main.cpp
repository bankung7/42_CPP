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
        AForm* rrf;

        try
        {
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            std::cout << *rrf << std::endl;
            a.signForm(*rrf);
            a.executeForm(*rrf);
            delete rrf;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}