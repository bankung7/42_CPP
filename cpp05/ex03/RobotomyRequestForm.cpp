#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& c): AForm("RobotomyRequestForm", 72, 45), _target(c._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& c)
{
    (void)c;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->checkExecuteRequirement(executor);

    std::cout << "tskkk stskk skk tskk tagg tukk" << std::endl;

    srand(time(NULL));
    int randNum = rand() % 2;

    if (randNum == 0)
        std::cout << "The " << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The " << this->_target << " has been failed" << std::endl;
}
