#include "Intern.hpp"

Intern::Intern(void)
{

}

Intern::Intern(const Intern& c)
{
    *this = c;
}

Intern& Intern::operator=(const Intern& c)
{
    if (this != &c)
    {

    }
    return (*this);
}

Intern::~Intern(void)
{
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* ptr;

    int i = 0;
    while (i < 3 && name != form[i])
        i++;
    
    switch (i)
    {
        case 0:
            ptr = new ShrubberyCreationForm(target);
            break;
        case 1:
            ptr = new RobotomyRequestForm(target);
            break;
        case 2:
            ptr = new PresidentialPardonForm(target);
        default:
            ptr = NULL;
    }
    return (ptr);
}