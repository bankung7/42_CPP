#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "./convert [argument]" << std::endl;
        return (1);
    }

    // std::stringstream ss;
    // ss << std::string(argv[1]);
    // double dd;
    // ss >> dd;

    double dd = atof(argv[1]);
    
    // std::cout << dd << " : " << (dd == dd) << std::endl;

    ScalarConverter conver(dd);
}

// static cast is a runtime casting, which convert or cast one data type to another.
// it means it does not check the data type at runtime as if it is valid or not.
