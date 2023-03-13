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

void ScalarConverter::convert(const std::string& input)
{
    this->_input = input;
    // std::stringstream ss(input);
    // ss >> this->_double;

    // std::cout << "strstream : " << ss.str() << std::endl;
    // std::cout << "value : " << this->_double << std::endl;
    // std::cout << "fail : " << ss.fail() << std::endl;

    if (caseDouble())
        return ;
    if (caseFloat())
        return ;
    if (caseInt())
        return ;
    if (caseChar())
        return ;
}

bool ScalarConverter::caseChar(void)
{
    // if (this->_input.length() != 1 || std::isdigit(this->_input[0]))
    //     return (false);
    
    // std::cout << "char case => " << this->_input[0] << std::endl;
    return (true);
}

bool ScalarConverter::caseInt(void)
{
 
    return (true);
}

bool ScalarConverter::caseFloat(void)
{

    return (true);
}

bool ScalarConverter::caseDouble(void)
{
    std::stringstream ss(this->_input);
    ss >> this->_double;

    std::cout << this->_double << std::endl;

    std::cout << "good : " << ss.good() << std::endl;
    std::cout << "fail : " << ss.fail() << std::endl;

    if (ss.fail() || ss.good())
    {
        std::cout << "not double" << std::endl;
        return (false);
    }

    std::cout << "double case" << std::endl;
    return (true);
}

// bool ScalarConverter::checkNumber(void)
// {
//     int i = 0;
//     if (this->_input[i] == '+' || this->_input[i] == '-')
//         i++;
//     for (; i < (int)this->_input.length(); i++)
//         if (!std::isdigit(this->_input[i]))
//             break;
//     if (this->_input[i] == 0)
//         return (caseInt());
//     if (this->_input.length() == 1)
//         return (caseChar());
//     if (this->_input[i++] != '.')
//         return (false);
//     for (; i < (int)this->_input[i]; i++)
//         if (!std::isdigit(this->_input[i]))
//             break;
//     if (this->_input[i] == 0)
//         return (caseDouble());
//     if (this->_input[i] == 'f' && this->_input[i + 1] == 0)
//         return (caseFloat());
//     return (false);
// }

// void ScalarConverter::convert(const std::string& input)
// {
//     std::stringstream sstream(input);
//     sstream >> this->_value;

//     std::cout << "value : " << this->_input << std::endl;

// }

// bool ScalarConverter::caseChar(void)
// {
//     std::cout << "===== Char case =====" << std::endl;
//     char c = static_cast<char>(this->_input[0]);
//     this->_value = this->_input[0];
//     std::cout << "char : "; cprint(c);
//     std::cout << "int : "; cprint(static_cast<int>(c));
//     std::cout << "float : "; cprint(static_cast<float>(c));
//     std::cout << "double : "; cprint(static_cast<double>(c));
//     return (true);
// }

// bool ScalarConverter::caseInt(void)
// {
//     // if it overflow or underflow from int when conversion.
//     // it should cast as over, or cast from the input.
//     std::cout << "===== Int case =====" << std::endl;
//     int i = std::atoi(this->_input.c_str());
//     std::cout << "char : "; cprint(static_cast<char>(this->_value));
//     std::cout << "int : "; cprint(i);
//     std::cout << "float : "; cprint(static_cast<float>(this->_value));
//     std::cout << "double : "; cprint(static_cast<double>(this->_value));

//     // std::cout << "char : "; cprint(static_cast<char>(i));
//     // std::cout << "int : "; cprint(i);
//     // std::cout << "float : "; cprint(static_cast<float>(i));
//     // std::cout << "double : "; cprint(static_cast<double>(i));
//     return (true);
// }

// bool ScalarConverter::caseFloat(void)
// {
//     // as float is 4 byte, it may loss some precision.
//     std::cout << "===== Float case =====" << std::endl;
//     std::cout << "char : "; cprint(static_cast<char>(this->_value));
//     std::cout << "int : "; cprint(static_cast<int>(this->_value));
//     std::cout << "float : "; cprint(static_cast<float>(this->_value));
//     std::cout << "double : "; cprint(static_cast<double>(this->_value));
//     return (true);
// }

// bool ScalarConverter::caseDouble(void)
// {
//     std::cout << "===== Double case =====" << std::endl;
//     std::cout << "char : "; cprint(static_cast<char>(this->_value));
//     std::cout << "int : "; cprint(static_cast<int>(this->_value));
//     std::cout << "float : "; cprint(static_cast<float>(this->_value));
//     std::cout << "double : "; cprint(this->_value);
//     return (true);
// }

// bool ScalarConverter::caseSpecial(void)
// {
//     return (true);
// }

// // polymorphic for cprint
// void ScalarConverter::cprint(const char& c)
// {
//     if (this->_value < CHAR_MIN || this->_value > CHAR_MAX)
//         std::cout << "impossible" << std::endl;
//     else if (std::isprint(c))
//         std::cout << "'" << c << "'" << std::endl;
//     else
//         std::cout << "Non printable" << std::endl;
// }

// void ScalarConverter::cprint(const int& i)
// {
//     if (this->_value < INT_MIN || this->_value > INT_MAX)
//         std::cout << "impossible" << std::endl;
//     else
//         std::cout << i << std::endl;
// }

// void ScalarConverter::cprint(const float& f)
// {
//     if (f == 0)
//         std::cout << "0.0f" << std::endl;
//     else if (this->_value < FLT_MIN || this->_value > FLT_MAX)
//         std::cout << "impossible" << std::endl;
//     else
//         std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
// }

// void ScalarConverter::cprint(const double& d)
// {
//     if ((this->_value < 0 && this->_input[0] != '-') || (this->_value > 0 && this->_input[0] == '-'))
//         std::cout << "impossible" << std::endl;
//     else if (d == 0)
//         std::cout << "0.0" << std::endl;
//     else
//         std::cout << std::fixed << std::setprecision(1) << d << std::endl;
// }
