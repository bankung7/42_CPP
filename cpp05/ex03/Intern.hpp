#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

public:
    Intern(void);
    Intern(const Intern& c);
    Intern& operator=(const Intern& c);
    ~Intern(void);

    AForm* makeForm(const std::string& name, const std::string& target);

};

#endif

// However, the intern has one important capacity: the makeForm() function. 
// It takes two strings. The first one is the name of a form 
// and the second one is the target of the form. 
// It return a pointer to a Form object (whose name is the one passed as parameter)
// whose target will be initialized to the second parameter.