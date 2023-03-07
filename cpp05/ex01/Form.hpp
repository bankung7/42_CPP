#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

private:
    const std::string _name;
    bool _isSign;
    const int _signGrade;
    const int _executeGrade;

public:
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& c);
    Form& operator=(const Form& c);
    ~Form(void);

    class GradeTooHighException: public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        const char* what() const throw();
    };

    class FormSigned: public std::exception
    {
        const char* what() const throw();
    };

    // getter for all member function
    const std::string getName(void) const;
    bool getStatus(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;

    void beSign(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& stream, const Form& f);

#endif

// private attribute => ok
// const name => ok
// bool issign => ok
// const grade require to sign =>ok
// const grade require to execute =>ok

// Form class apply same rule as Bureaucrat => ok
// if grade out of bound
// thrown Form::GradeTooHighException and Form::GradeTooLowException

// getter for all attribute =>
// and overload << to print all form's information =>

// beSign() in Form class which take bureaucrat as paremeter =>
// change sign status when grade is higher or equal to the requirement.
// If grade too low, throw Form::GradeTooLowException
