#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c): AForm(c.getName(), c.getSignGrade(), c.getExecuteGrade()), _target(c._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& c)
{
    this->_target = c._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getStatus())
        throw ShrubberyCreationForm::FormNotSigned();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
        
    // draw ascii tree here //
}