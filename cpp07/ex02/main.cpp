#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    {
        std::cout << "==================================" << std::endl;
        std::cout << "Creating Empty Array" << std::endl;
        std::cout << "==================================" << std::endl;
        Array<int> num;
        std::cout << std::endl;
    }
    {
        std::cout << "==================================" << std::endl;
        std::cout << "Try creating any array size" << std::endl;
        std::cout << "==================================" << std::endl;
        Array<int> num(5);
        num[0] = 1;
        std::cout << std::endl;
    }

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "==================================" << std::endl;
    std::cout << "try copy number into our array" << std::endl;
    std::cout << "==================================" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << std::endl;

    //SCOPE
    {
        std::cout << "==================================" << std::endl;
        std::cout << "try copy cons and assignment" << std::endl;
        std::cout << "==================================" << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    std::cout << std::endl;

    std::cout << "==================================" << std::endl;
    std::cout << "try checking that is same value in arrays" << std::endl;
    std::cout << "==================================" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        // std::cout << numbers[i] << " : " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << std::endl;

    std::cout << "==================================" << std::endl;
    std::cout << "try negative index" << std::endl;
    std::cout << "==================================" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << "==================================" << std::endl;
    std::cout << "try over index" << std::endl;
    std::cout << "==================================" << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << "==================================" << std::endl;
    std::cout << "try put new value in it" << std::endl;
    std::cout << "==================================" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << std::endl;

    std::cout << "==================================" << std::endl;
    std::cout << "what is the size : " << numbers.size() << std::endl;
    std::cout << "==================================" << std::endl;

    delete [] mirror;
    
    return 0;
}