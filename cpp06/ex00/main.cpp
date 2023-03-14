#include <iostream>
#include "ScalarConverter.hpp"
#include <sstream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "./convert [argument]" << std::endl;
        return (1);
    }

    ScalarConverter con;
    con.convert(argv[1]);
}
