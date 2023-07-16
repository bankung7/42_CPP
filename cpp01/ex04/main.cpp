#include <iostream>
#include "Sed.hpp"

int main(int argc, char **argv)
{
    //check if argument is not 4
    if (argc != 4)
        std::cout << "error: bad arguments" << std::endl;
    else
    {
        Sed sobj;
        sobj.setFileName(argv[1]);
        sobj.replace(argv[2], argv[3]);
    }
    return (0);
}