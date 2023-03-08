#ifndef AFORM_HPP
#define AFORM_HPP

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
    virtual ~AForm(void); // make it virtual

    class GradeTooHighException: public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        const char* what() const throw();
    };

    class AFormSigned: public std::exception
    {
        const char* what() const throw();
    };

    class AFormNotSigned: public std::exception
    {
        const char* what() const throw();
    };

    class InvalidForm: public std::exception
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

// change the name to AForm
// All attribute remain private and in the base class
// add the execute(Bureaucrat const & executor) const member function to the base form
// You have to check that the form is signed and that the grade of the bureaucrat
// attempting to execute the form is high enough. Otherwise, throw an appropriate exception.