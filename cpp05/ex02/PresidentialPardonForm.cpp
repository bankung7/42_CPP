#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c): AForm(c.getName(), c.getSignGrade(), c.getExecuteGrade()), _target(c._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& c)
{
    this->_target = c._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}
