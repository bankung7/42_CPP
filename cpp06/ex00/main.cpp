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

    // this is a great guideline //
    // std::string data = "2147483649";
    // std::stringstream ss(data);
    // float d;
    // ss >> d;
    // std::cout << data << std::endl;
    // std::cout << ss << std::endl;
    // std::cout << d << std::endl;

    // std::cout << static_cast<int>(d) << std::endl;
}
