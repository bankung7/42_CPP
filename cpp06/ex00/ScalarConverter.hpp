#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter {

private:
    int _isstr;
    double _num;
    std::string _str;

public:
    ScalarConverter(void);
    ScalarConverter(std::string str);
    ScalarConverter(const ScalarConverter& c);
    ScalarConverter& operator=(const ScalarConverter& c);
    ~ScalarConverter(void);

    void castChar(void);
    void castInt(void);
    void castFloat(void);
    void caseDouble(void);

    void checkInput(void);

};

#endif