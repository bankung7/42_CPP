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
    
    std::ofstream outfile;
    outfile.open(this->_target + "__shrubbery");
    if (!outfile.is_open())
        return ;
 
    // draw ascii tree here //
    int h = 10;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h - i; j++)
            outfile << " ";
        for (int k = 0; k < i * 2; k++)
        {
            if (k % 2 == 0)
                outfile << "#";
            else
                outfile << "*";
        }
        outfile << std::endl;
    }
    for (int i = 0; i < h / 3; i++)
    {
        for (int j = 0; j < h - 1; j++)
            outfile << " ";
        outfile << "##" << std::endl;
    }

    outfile.close();
}