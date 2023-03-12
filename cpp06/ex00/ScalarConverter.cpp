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
    std::stringstream ss(input);
    ss >> this->_double;

    if (caseChar())
        return ;
    if (caseInt())
        return ;
    if (caseFloat())
        return ;
}

bool ScalarConverter::caseChar(void)
{
    // if not char [ length != 1 ]. from example, 0 is shown as null, then it might be int first
    if (this->_input.length() != 1 || std::isdigit(this->_input[0]))
        return (false);

    this->_char = this->_input[0];
  
    std::cout << "char case" << std::endl;
    cprint(this->_char);
    cprint(static_cast<int>(this->_char));
    cprint(static_cast<float>(this->_char));
    cprint(static_cast<double>(this->_char));
    return (true);
}

bool ScalarConverter::caseInt(void)
{
    // try stringstream way
    // if overflow from int, i decide to let it unbehavior
    std::stringstream iss(this->_input);
    iss >> this->_int;

    if (iss.good() || (this->_int == 0 && this->_input[0] != '0'))
        return (false);

    std::cout << "int case" << std::endl;
    cprint(static_cast<char>(this->_int));
    cprint(this->_int);
    cprint(static_cast<float>(this->_int));
    cprint(static_cast<double>(this->_int));
    return (true);
}

bool ScalarConverter::caseFloat(void)
{
    if (this->_input.back() != 'f')
        return (false);
    std::stringstream fss(this->_input.substr(0, this->_input.length() - 1));
    fss >> this->_float;

    std::cout << this->_float << std::endl;
    // std::cout << this->_float << std::endl;
    // std::cout << fss.str()<< std::endl;

    // std::cout << "float case" << std::endl;
    return (true);
}

void ScalarConverter::cprint(const char& c)
{
    std::cout << "char : ";
    if (this->_double < CHAR_MIN || this->_double > CHAR_MAX)
        std::cout << "impossible";
    else if (std::isprint(c))
        std::cout << "'" << c << "'";
    else
        std::cout << "Non printable";
    std::cout << std::endl;
}

void ScalarConverter::cprint(const int& i)
{
    std::cout << "int : ";
    if (this->_double >= INT_MIN && this->_double <= INT_MAX)
        std::cout << i;
    else
        std::cout << "impossible";
    std::cout << std::endl;
}

void ScalarConverter::cprint(const float& f)
{
    std::cout << "float : ";
    if (this->_double >= -FLT_MAX && this->_double <= FLT_MAX)
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    else
        std::cout << "impossible";
    std::cout << std::endl;
}

void ScalarConverter::cprint(const double& d)
{
    std::cout << "double : ";
    std::cout << d;
    std::cout << std::endl;
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
