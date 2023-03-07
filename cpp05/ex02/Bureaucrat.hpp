#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

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

    void signForm(AForm& f);

    void executeForm(Form const & form);

};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);

#endif

// add executeForm(Form const & form)