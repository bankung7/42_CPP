#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(void): _char(0), _int(0), _float(0), _double(0), _isInf(0)
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

    if (!dss.fail() && !dss.good() && this->_input.find('.') != std::string::npos)
        return (caseDouble());
    
    // test float
    std::string str(input);
    str.pop_back();
    std::stringstream fss(str);
    fss >> this->_double;

    if (!fss.fail() && !fss.good() && this->_input.back() == 'f' && this->_input.find('.') != std::string::npos)
        return (caseFloat());

    // test int
    if (!dss.fail() && !dss.good())
        return (caseInt());
    
    // test char
    if (this->_input.length() == 1)
        return (caseChar());

    std::cout << "No case" << std::endl;
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : impossible" << std::endl;
    std::cout << "double : impossible" << std::endl;
    return ;
}

bool ScalarConverter::checkSpecial(void)
{
    std::cout << (this->_double == std::numeric_limits<double>::infinity()) << std::endl;
    std::cout << (this->_double == -std::numeric_limits<double>::infinity()) << std::endl;
    std::cout << "value : " << this->_double << std::endl;

    if (this->_double == std::numeric_limits<double>::infinity() ||
        this->_double == -std::numeric_limits<double>::infinity())
        return (this->_isInf = 1);

    return (false);
}

void ScalarConverter::caseChar(void)
{
    std::cout << "case char" << std::endl;

    this->_char = this->_input[0];

    cprint(this->_char); std::cout << std::endl;
    std::cout << "int : " << static_cast<int>(this->_char) << std::endl;
    std::cout << "float : " << static_cast<float>(this->_char) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(this->_char) << ".0" << std::endl;
}

void ScalarConverter::caseInt(void)
{
    std::cout << "case int" << std::endl;

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
    std::cout << "float case" << std::endl;

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
    std::cout << "double case" << std::endl;

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
        || this->_isInf)
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
        || this->_isInf)
        std::cout << "impossible";
    else
        std::cout << i;
}

void ScalarConverter::cprint(const float& f)
{
    std::cout << "float : ";
    if (this->_double < -std::numeric_limits<float>::max()
        || this->_double > std::numeric_limits<float>::max())
        std::cout << "impossible";
    else
        std::cout << f << "f";
}

void ScalarConverter::cprint(const double& d)
{
    std::cout << "double : ";
    std::cout << d;
}
