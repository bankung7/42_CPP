#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(std::string str): _isstr(0), _str(str)
{
    checkInput();
    this->_num = atof(this->_str.c_str());

    std::cout << "char: "; castChar();
    std::cout << "int: "; castInt();
    std::cout << "float: "; castFloat();
    std::cout << "double: "; caseDouble();
}

ScalarConverter::ScalarConverter(const ScalarConverter &c)
{
    this->_isstr = c._isstr;
    this->_num = c._num;
    this->_str = c._str;
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
    if ((this->_num != this->_num) || this->_isstr == 1
        || this->_num < 0 || this->_num > 127 )
        std::cout << "imposible";
    else if (this->_num < 32 || this->_num > 126)
        std::cout << "Non displayable";
    else
        std::cout << static_cast<char>(this->_num);
    std::cout << std::endl;
}

void ScalarConverter::castInt(void)
{
    if ((this->_num != this->_num) || this->_isstr == 1
        || this->_num < std::numeric_limits<int>::min()
        || this->_num > std::numeric_limits<int>::max())
        std::cout << "imposible";
    else
        std::cout << static_cast<int>(this->_num);
    std::cout << std::endl;
}

void ScalarConverter::castFloat(void)
{
    if (this->_isstr == 1 && this->_num == this->_num
        && this->_num != std::numeric_limits<float>::infinity()
        && -this->_num != std::numeric_limits<float>::infinity())
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
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
    if (this->_isstr == 1 && this->_num == this->_num
        && this->_num != std::numeric_limits<double>::infinity()
        && -this->_num != std::numeric_limits<double>::infinity())
    {
        std::cout << "impossible" << std::endl;
        return ;
    }

    std::cout << this->_num;
    if (this->_num == static_cast<int>(this->_num))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::checkInput(void)
{
    int i = 0;
    int decimal = 0;
    while (this->_str[i])
    {
        if (i == 0 && (this->_str[i] == '+' || this->_str[i] == '-'))
            i++;
        else if (decimal == 0 && this->_str[i] == '.')
            decimal = 1;
        else if (isdigit(this->_str[i]) == 0)
        {
            if (this->_str[i + 1] == 0 && this->_str[i] == 'f')
            {
                this->_str[i] = 0;
                i++;
                continue ;
            }
            this->_isstr = 1;
            return ;
        }
        i++;
    }
}