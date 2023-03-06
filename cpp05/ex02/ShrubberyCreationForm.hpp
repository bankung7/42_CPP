#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{

private:
    std::string _target;

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& c);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& c);
    ~ShrubberyCreationForm(void);

    void execute(Bureaucrat const & executor) const;

};

#endif

// create concreat class ShrubberyCreationForm
// Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, 
// and writes ASCII trees inside i
// All of them take only one parameter in their constructor: the target of the form. 
// For example, "home" if you want to plant shrubbery at home.