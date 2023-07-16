<<<<<<< HEAD
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

=======
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <stdlib.h>

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

>>>>>>> 4408d21c1d1db63b9d89543ddc4c3da24e8a15cc
#endif