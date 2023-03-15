#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(void): _char(0), _int(0), _float(0), _double(0), _isNan(0), _isInf(0),_isString(0)
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
    
    // test double
    std::stringstream dss(this->_input);
    dss >> this->_double;

    // special case
    checkSpecial();

    // std::cout << "inf : " << this->_isInf << std::endl;
    // std::cout << "nan : " << this->_isNan << std::endl;

    if (!dss.fail() && !dss.good() && this->_input.find('.') != std::string::npos)
        return (caseDouble());
    
    // test float
    std::string str(input);
    str.pop_back();
    std::stringstream fss(str);
    double ftest;
    fss >> ftest;

    if (!fss.fail() && !fss.good() && this->_input.back() == 'f' && this->_input.find('.') != std::string::npos)
        return (caseFloat());

    // test int
    if (!dss.fail() && !dss.good())
        return (caseInt());
    
    // test char
    if (this->_input.length() == 1)
        return (caseChar());
    
    this->_isString = 1;
    // std::cout << "this no case" << std::endl;
    cprint(static_cast<char>(this->_double)); std::cout << std::endl;
    cprint(static_cast<int>(this->_double)); std::cout << std::endl;
    cprint(static_cast<float>(this->_double)); std::cout << std::endl;
    cprint(static_cast<double>(this->_double)); std::cout << std::endl;
    return ;
}

bool ScalarConverter::checkSpecial(void)
{
    if (this->_double == std::numeric_limits<double>::infinity())
        return (this->_isInf = 1);
    if (this->_double == -std::numeric_limits<double>::infinity())
        return (this->_isInf = -1);
    
    if (this->_input.back() == 'f')
    {
        std::string str(this->_input);
        str.pop_back();
        std::stringstream ss(str);
        float t;
        ss >> t;

        if (!ss.fail() && !ss.good() && (t != t))
            return (this->_isNan = 1);
        if (!ss.fail() && !ss.good() && (t == std::numeric_limits<float>::infinity()))
            return (this->_isInf = 1);
        if (!ss.fail() && !ss.good() && (t == -std::numeric_limits<float>::infinity()))
            return (this->_isInf = -1);
        std::cout << "out " <<std::endl;
    }

    if (this->_double != this->_double)
        return (this->_isNan = 1);

    return (false);
}

void ScalarConverter::caseChar(void)
{
    // std::cout << "case char" << std::endl;

    this->_char = this->_input[0];

    cprint(this->_char); std::cout << std::endl;
    std::cout << "int : " << static_cast<int>(this->_char) << std::endl;
    std::cout << "float : " << static_cast<float>(this->_char) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(this->_char) << ".0" << std::endl;
}

void ScalarConverter::caseInt(void)
{
    // std::cout << "case int" << std::endl;

    std::stringstream ss(this->_input);
    ss >> this->_int;

    cprint(static_cast<char>(this->_int)); std::cout << std::endl;
    cprint(this->_int); std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    cprint(static_cast<float>(this->_int)); std::cout << std::endl;
    cprint(static_cast<double>(this->_int)); std::cout << std::endl;
}

void ScalarConverter::caseFloat(void)
{
    // std::cout << "float case" << std::endl;

    std::string str(this->_input);
    str.pop_back();
    std::stringstream ss(str);
    ss >> this->_float;

    cprint(static_cast<char>(this->_float)); std::cout << std::endl;
    cprint(static_cast<int>(this->_float)); std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    cprint(this->_float); std::cout << std::endl;
    cprint(static_cast<double>(this->_float)); std::cout << std::endl;
}

void ScalarConverter::caseDouble(void)
{
    // std::cout << "double case" << std::endl;

    cprint(static_cast<char>(this->_double)); std::cout << std::endl;
    cprint(static_cast<int>(this->_double)); std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    cprint(static_cast<float>(this->_double)); std::cout << std::endl;
    cprint(this->_double); std::cout << std::endl;
}

void ScalarConverter::cprint(const char& c)
{
    std::cout << "char : ";
    // if (this->_double < CHAR_MIN || this->_double > CHAR_MAX)
    if (this->_double < std::numeric_limits<char>::min()
        || this->_double > std::numeric_limits<char>::max()
        || this->_isInf != 0 || this->_isNan || this->_isString)
        std::cout << "impossible";
    else if (std::isprint(c))
        std::cout << "'" << c << "'";
    else
        std::cout << "Non displayable";
}

void ScalarConverter::cprint(const int& i)
{
    std::cout << "int : ";
    if (this->_double < std::numeric_limits<int>::min()
        || this->_double > std::numeric_limits<int>::max()
        || this->_isInf != 0 || this->_isNan || this->_isString)
        std::cout << "impossible";
    else
        std::cout << i;
}

void ScalarConverter::cprint(const float& f)
{
    std::cout << "float : ";
    if (this->_isInf != 0)
        std::cout << std::showpos << this->_isInf * std::numeric_limits<float>::infinity() << "f";
    else if (this->_isNan)
        std::cout << std::numeric_limits<float>::quiet_NaN() << "f";
    else if (this->_double < -std::numeric_limits<float>::max()
        || this->_double > std::numeric_limits<float>::max()
        || this->_isString)
        std::cout << "impossible";
    else
        std::cout << f << "f";
}

void ScalarConverter::cprint(const double& d)
{
    std::cout << "double : ";
    if (this->_isNan)
        std::cout << std::numeric_limits<double>::quiet_NaN();
    else if (this->_isInf != 0)
        std::cout << std::showpos << this->_isInf * std::numeric_limits<double>::infinity();
    else if (this->_isString)
        std::cout << "impossible";
    else
        std::cout << d;
}
