#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int& grade): _name(name), _grade(grade)
{
    if (grade <= 0)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& c)
{
    *this = c;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& c)
{
    if (this != &c)
        this->_grade = c._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::gradeIncrement(void)
{
    if (this->_grade - 1 <= 0)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::gradeDecrement(void)
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("grade too low");
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSign(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.checkExecuteRequirement(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " cannot execute " << form.getName() << " bacuase " << e.what() << std::endl;
    }
    
}

// overload for print
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
    stream << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (stream);
}