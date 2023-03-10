#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& c)
{
    (void)c;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& c)
{
    (void)c;
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

void ScalarConverter::convert(const std::string& input)
{
    // input string and detect the type of the literal
    this->_input = input;

    std::cout << "input : " << this->_input << std::endl;

    // convert from string to its actual type
    if (isChar())
        return (printChar());
    if (isInt())
        return (printInt());
    if (isFloat())
        return (printFloat());
    if (isDouble())
        return (printDouble());
}

bool ScalarConverter::isChar(void) const
{

    return (false);
}

bool ScalarConverter::isInt(void) const
{
    int i = 0;
    if (this->_input[i] == '+' || this->_input[i] == '-')
        i++;
    for (; i < (int)this->_input.length(); i++)
        if (std::isdigit(this->_input[i]) == 0)
            return (false);
    return (true);
}

bool ScalarConverter::isFloat(void) const
{
    return (false);
}

bool ScalarConverter::isDouble(void) const
{
    return (false);
}

void ScalarConverter::printChar(void)
{

}

void ScalarConverter::printInt(void)
{
    long n = std::atol(this->_input.c_str());

    std::cout << "int : ";
    if (n > INT_MAX || n < INT_MIN)
        std::cout << "imposible" << std::endl;
    else
        std::cout << static_cast<int>(n) << std::endl;
}

void ScalarConverter::printFloat(void)
{

}

void ScalarConverter::printDouble(void)
{

}