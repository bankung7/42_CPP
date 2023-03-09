#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);

#endif

// must have constant name

// a grade that range from 1 to 150
// the highest grade is 1, on the other hand 150 is lowest

// when try to instantiate invalid grade throw error 
// Bureaucrat::GradeTooHighException or Bureaucrat::GradeTooLowException

// provide getName() and getGrade() attribute
// implement 2 function, increament and decrement grade
// when grade increase mean 3 -> 2
// if out or range, throw same exception as the constructor

// using try catch block

// implement overlod << to print something like example.
