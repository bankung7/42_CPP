#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& c)
{
    *this = c;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& c)
{
    (void)c;
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

bool ScalarConverter::checkNumber(void)
{
    // just try to convert to int, then check if 0 - 127 then can be char
    // but char only has 1 length, so try check later

    int i = 0;
    if (this->_input[i] == '+' || this->_input[i] == '-')
        i++;
    for (; i < (int)this->_input.length(); i++)
        if (!std::isdigit(this->_input[i]))
            break;
    // if not '.' , then i should not be double or float by input
    if (this->_input[i] == 0)
        return (true);
    if (this->_input[i++] != '.')
        return (false);
    for (; i < (int)this->_input[i]; i++)
        if (!std::isdigit(this->_input[i]))
            break;
    if (this->_input[i] == 0)
        return (true);
    if (this->_input[i] == 'f' && this->_input[i + 1] == 0)
        return (true);
    return (false);
}

void ScalarConverter::convert(const std::string& input)
{
    this->_input = input;
    std::cout << "input : " << _input << " = ";

    this->_isNumber = checkNumber();
    std::cout << this->_isNumber << std::endl;
    if (this->_isNumber)
        return caseNumber();
}

void ScalarConverter::caseNumber(void)
{
    this->_value = std::atof(this->_input.c_str());
    std::cout << "char : " << std::endl;
    std::cout << "int : " << static_cast<int>(this->_value) << std::endl;
    std::cout << "float : " << std::setprecision(2) << static_cast<float>(this->_value) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(this->_value) << std::endl;
}