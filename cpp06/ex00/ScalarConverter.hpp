#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <cfloat>

class ScalarConverter
{

private:
    std::string _input;

public:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& c);
    ScalarConverter& operator=(const ScalarConverter& c);
    ~ScalarConverter(void);

    void convert(const std::string&);

    bool isChar(void) const;
    bool isInt(void) const;
    bool isFloat(void) const;
    bool isDouble(void) const;

    void printChar(void);
    void printInt(void);
    void printFloat(void);
    void printDouble(void);

};

#endif

// You have to first detect the type of the literal passed as parameter,
// convert it from string to its actual type, 
// then convert it explicitly to the three other data types.
// Lastly, display the results as shown below.