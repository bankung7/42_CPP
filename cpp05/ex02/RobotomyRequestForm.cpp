#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& c): AForm(c.getName(), c.getSignGrade(), c.getExecuteGrade()), _target(c._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& c)
{
    this->_target = c._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}
