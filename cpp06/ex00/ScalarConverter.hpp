#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {

private:
    double _num;

public:
    ScalarConverter(void);
    ScalarConverter(double input);
    ScalarConverter(const ScalarConverter& c);
    ScalarConverter& operator=(const ScalarConverter& c);
    ~ScalarConverter(void);

    void castChar(void);
    void castInt(void);
    void castFloat(void);
    void caseDouble(void);

};

#endif