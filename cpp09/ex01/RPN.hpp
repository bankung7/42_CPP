#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstring>

class RPN
{

private:
    std::stack<int> _stack;

public:
    RPN(void);
    RPN(std::string str);
    RPN(const RPN& c);
    RPN& operator=(const RPN& c);
    ~RPN(void);

    void input(char c);
    void operations(char c);

    class OperationError : public std::exception {
        const char* what(void) const throw();
    };

};

#endif

// Logic Note
// When the operator is found, it take last 2 number in the stack
