#ifndef AAFORM_HPP
#define AAFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

private:
    const std::string _name;
    bool _isSign;
    const int _signGrade;
    const int _executeGrade;

public:
    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& c);
    AForm& operator=(const AForm& c);
    virtual ~AForm(void);

    class GradeTooHighException: public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        const char* what() const throw();
    };

    class FormNotSigned: public std::exception
    {
        const char* what() const throw();
    };

    // getter for all member function
    const std::string getName(void) const;
    bool getStatus(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;

    void beSign(const Bureaucrat& b);

    virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& stream, const AForm& f);

#endif

// make the form to be abstract
// rename to AForm
// all attributes are still private and in base class
// add the execute(Bureaucrat const & executor) const member function to
// the base form and implement a function to execute the form’s action of the concrete
// classes. You have to check that the form is signed and that the grade of the bureaucrat
// attempting to execute the form is high enough. Otherwise, throw an appropriate exception.