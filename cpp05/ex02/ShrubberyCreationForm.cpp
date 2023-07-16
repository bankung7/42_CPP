#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c): AForm("ShrubberyCreationForm", 145, 137), _target(c._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& c)
{
    (void)c;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();
    if (!this->getStatus())
        throw AForm::AFormNotSigned();
    
    std::ofstream outfile;

    outfile.open(std::string(this->_target + "_shrubbery").c_str());
    if (!outfile.is_open())
        return ;

    int h = 14;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h - i; j++)
            outfile << " ";
        for (int k = 0; k < i * 2; k++)
            outfile << "#";
        outfile << std::endl;
    }
    for (int i = 0; i < h / 2; i++)
    {
        for (int j = 0; j < h - 1; j++)
            outfile << " ";
        outfile << "###" << std::endl;
    }
    for (int i = 0; i < h * 2; i++)
        outfile << "/";
    outfile << std::endl;

    outfile.close();
}