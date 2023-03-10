#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid or Incomplete argument." << std::endl;
        return (1);
    }

    ScalarConverter con;
    con.convert(argv[1]);

    return (0);
}