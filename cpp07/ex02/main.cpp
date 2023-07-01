#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    {
        std::cout << "Empty Array" << std::endl;
        Array<int> num;
    }
    {
        std::cout << "Try to any array size" << std::endl;
        Array<int> num(5);

    }

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        // std::cout << numbers[i] << " : " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    {
        std::cout << "what is the size : " << numbers.size() << std::endl;
    }
    delete [] mirror;//
    return 0;
}