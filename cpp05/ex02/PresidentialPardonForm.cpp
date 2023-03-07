#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 72, 45), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c): AForm("PresidentialPardonForm", 72, 45), _target(c._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& c)
{
    (void)c;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();
    if (!this->getStatus())
        throw AForm::AFormNotSigned();
    
    std::cout << this->_target << " has been pardoned by Zabphod Beeblebrox" << std::endl;
}