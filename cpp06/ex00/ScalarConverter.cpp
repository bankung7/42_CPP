#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(double input): _num(input)
{
    std::cout << "char: "; castChar();
    std::cout << "int: "; castInt();
    std::cout << "float: "; castFloat();
    std::cout << "double: "; caseDouble();
}

ScalarConverter::ScalarConverter(const ScalarConverter &c)
{
    this->_num = c._num;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &c)
{
    if (this != &c)
        *this = c;
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

void ScalarConverter::castChar(void)
{
    if ((this->_num != this->_num) || this->_num < 0 || this->_num > 127)
        std::cout << "imposible";
    else if (this->_num < 33 || this->_num > 126)
        std::cout << "Non displayable";
    else
        std::cout << static_cast<char>(this->_num);
    std::cout << std::endl;
}

void ScalarConverter::castInt(void)
{
    if ((this->_num != this->_num) || this->_num < INT_MIN || this->_num > INT_MAX)
        std::cout << "imposible";
    else
        std::cout << static_cast<int>(this->_num);
    std::cout << std::endl;
}

void ScalarConverter::castFloat(void)
{
    if (this->_num != this->_num)
        std::cout << "nan";
    else
        std::cout << static_cast<float>(this->_num);
    if (this->_num == static_cast<int>(this->_num))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::caseDouble(void)
{
    std::cout << this->_num;
    if (this->_num == static_cast<int>(this->_num))
        std::cout << ".0";
    std::cout << std::endl;
}