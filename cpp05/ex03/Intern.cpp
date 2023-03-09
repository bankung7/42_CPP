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

    for (int i = 0; i < 3; i++)
    {
        if (name == form[i])
        {
            std::cout << "Intern creates " << form[i] << " form" << std::endl;
            switch (i)
            {
            case 0:
                return (new ShrubberyCreationForm(target));
            case 1:
                return (new RobotomyRequestForm(target));
            case 2:
                return (new PresidentialPardonForm(target));
            default:
                break;
            }
        }
    }
    std::cout << "Intern don't know this " << name << " form" << std::endl;
    return (NULL);


}