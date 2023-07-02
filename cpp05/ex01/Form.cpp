#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int executeGrade): _name(name), _isSign(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade <= 0 || executeGrade <= 0)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& c): _name(c._name), _isSign(c._isSign), _signGrade(c._signGrade), _executeGrade(c._executeGrade)
{
}

Form& Form::operator=(const Form& c)
{
    if (this != &c)
        this->_isSign = c._isSign;
    return (*this);
}

Form::~Form(void)
{
}

// Exception
const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("grade too low");
}

const char* Form::FormSigned::what(void) const throw()
{
    return ("form was signed by other");
}

// getter attribute
const std::string Form::getName(void) const
{
    return (_name);
}

bool Form::getStatus(void) const
{
    return (_isSign);
}

int Form::getSignGrade(void) const
{
    return (_signGrade);
}

int Form::getExecuteGrade(void) const
{
    return (_executeGrade);
}

void Form::beSign(const Bureaucrat& b)
{
    if (this->getStatus())
        throw Form::FormSigned();
    if (b.getGrade() > this->getSignGrade())
        throw Form::GradeTooLowException();
    this->_isSign = 1;
}

// overload <<
std::ostream& operator<<(std::ostream& stream, const Form& f)
{
    stream << "Form Name      : " << f.getName() << std::endl;
    stream << "Sign status    : " << f.getStatus() << std::endl;
    stream << "Required Grade : " << f.getSignGrade() << std::endl;
    stream << "Execute Grade  : " << f.getExecuteGrade();
    return (stream);
}
