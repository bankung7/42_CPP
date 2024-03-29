#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>

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

};

#endif

// Logic Note
// When the operator is found, it take last 2 number in the stack
