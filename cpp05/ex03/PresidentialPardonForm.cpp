#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c): AForm("PresidentialPardonForm", 25, 5), _target(c._target)
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
    this->checkExecuteRequirement(executor);
    
    std::cout << this->_target << " has been pardoned by Zabphod Beeblebrox" << std::endl;
}
