#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int executeGrade): _name(name), _isSign(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade <= 0 || executeGrade <= 0)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& c): _name(c._name), _isSign(c._isSign), _signGrade(c._signGrade), _executeGrade(c._executeGrade)
{
}

AForm& AForm::operator=(const AForm& c)
{
    if (this != &c)
        this->_isSign = c._isSign;
    return (*this);
}

AForm::~AForm(void)
{
}

// Exception
const char* AForm::GradeTooHighException::what(void) const throw()
{
    return ("grade too high");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return ("grade too low");
}

const char* AForm::AFormSigned::what(void) const throw()
{
    return ("form was signed by other");
}

const char* AForm::AFormNotSigned::what(void) const throw()
{
    return ("form is still not signed");
}

const char* AForm::InvalidForm::what(void) const throw()
{
    return ("Invalid Form");
}

// getter attribute
const std::string AForm::getName(void) const
{
    return (_name);
}

bool AForm::getStatus(void) const
{
    return (_isSign);
}

int AForm::getSignGrade(void) const
{
    return (_signGrade);
}

int AForm::getExecuteGrade(void) const
{
    return (_executeGrade);
}

void AForm::beSign(const Bureaucrat& b)
{
    if (b.getGrade() > this->getSignGrade())
        throw AForm::GradeTooLowException();
    if (this->getStatus())
        throw AForm::AFormSigned();
    this->_isSign = 1;
}

void AForm::checkExecuteRequirement(const Bureaucrat& b) const
{
    if (b.getGrade() > this->getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();
    if (!this->getStatus())
        throw AForm::AFormNotSigned();
}

// overload <<
std::ostream& operator<<(std::ostream& stream, const AForm& f)
{
    stream << "Form Name      : " << f.getName() << std::endl;
    stream << "Sign status    : " << f.getStatus() << std::endl;
    stream << "Required Grade : " << f.getSignGrade() << std::endl;
    stream << "Execute Grade  : " << f.getExecuteGrade();
    return (stream);
}
