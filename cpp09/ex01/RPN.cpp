#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(std::string str)
{
    if (str.size() < 3)
        throw std::runtime_error("Operations Error");

    std::string::iterator it = str.begin();
    std::string ops = "+-/*";
    for (; it != str.end(); it++)
    {
        if (*it == ' ')
            continue ;
        // std::cout << *it << std::endl;
        if (ops.find(*it) != std::string::npos)
        {
            // std::cout << "found operator" << std::endl;
            operations(*it);
            continue ;
        }
        if (std::isdigit(*it))
        {
            // std::cout << "Number" << std::endl;
            input(*it);
            continue ;
        }
        throw std::runtime_error("Operations Error");
        return ;
    }
    if (this->_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << this->_stack.top() << std::endl;
}

RPN::RPN(const RPN& c)
{
    this->_stack = c._stack;
}

RPN& RPN::operator=(const RPN &c)
{
    if (this != &c)
        *this = c;
    return (*this);
}

RPN::~RPN(void)
{
}

void RPN::input(char c)
{
    std::string n;
    n.push_back(c);
    this->_stack.push(std::atoi(n.c_str()));
    // std::cout << this->_stack.top() << std::endl;
}

// try readjust by last to value next time.
void RPN::operations(char c)
{
    if (this->_stack.size() < 2)
        throw std::runtime_error("Error");
    int v1 = this->_stack.top();
    this->_stack.pop();
    if (c == '+')
        this->_stack.top() += v1;
    else if (c == '-')
        this->_stack.top() -= v1;
    else if (c == '*')
        this->_stack.top() *= v1;
    else if (c == '/') {
        if (v1 == 0)
            throw std::runtime_error("Error : Div by 0");
        this->_stack.top() /= v1;
    }
    // std::cout << "=== > " << this->_stack.top() << std::endl;
}

// find the way to throw error