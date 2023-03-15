#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <numeric>
#include <cfloat>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>


class ScalarConverter
{

private:
    std::string _input;
    char _char;
    int _int;
    float _float;
    double _double;
    bool _isNan;
    int _isInf;
    bool _isString;

public:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& c);
    ScalarConverter& operator=(const ScalarConverter& c);
    ~ScalarConverter(void);

    void convert(const std::string& input);

    void caseChar(void);
    void caseInt(void);
    void caseFloat(void);
    void caseDouble(void);
    bool checkSpecial(void);

    // polymorphic for print case
    void cprint(const char& c);
    void cprint(const int& i);
    void cprint(const float& f);
    void cprint(const double& d);
};

#endif

// the problem is "the static class" ?, how to deal with this

// detect the type of the literal passed as parameter
// convert it from string to its actual type
// then convert it explicitly to the three other data type
// lastly, display the result as shown

// when overflow or does not make any sense, display impossible message
// include numeric limits and special value header is ok

// char 0 to  255
// int -2147483648 to 2147483647
// float ... to ... with 1 precision and end with f
// double ... to ... with 1 precision

// then char is some part of all three.
// so i decide to convert original into number first
