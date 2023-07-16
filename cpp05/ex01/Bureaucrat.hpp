#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{

private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(const std::string&, const int&);
    Bureaucrat(const Bureaucrat& c);
    Bureaucrat& operator=(const Bureaucrat& c);
    ~Bureaucrat(void);

    std::string getName(void) const;
    int getGrade(void) const;

    void gradeIncrement(void);
    void gradeDecrement(void);

    class GradeTooHighException: public std::exception
    {
        const char* what(void) const throw();
    };

    class GradeTooLowException: public std::exception
    {
        const char* what(void) const throw();
    };

    void signForm(Form& f);

};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);

#endif

// signForm() in Bureaucrat class, if the form got sign =>
// print something like <bureaucrat> signed <form>
// or <bureaucrat> couldn’t sign <form> because <reason>
