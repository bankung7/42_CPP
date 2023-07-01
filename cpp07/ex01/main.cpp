#include "iter.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "Enpty Array" << std::endl;
        int arr[0];
        iter(arr, 2, &talk);
    }
    {
        std::cout << "Test for char arr" << std::endl;
        char arr[5] = {'a', 'b', 'c', 'd', 'e'};
        iter(arr, 5, &talk);
    }
    {
        std::cout << "Test for string arr" << std::endl;
        std::string arr[5] = {"1", "2", "3", "4", "5"};
        iter(arr, 5, &talk);
    }
    {
        std::cout << "Test for int arr" << std::endl;
        int arr[5] = {1, 2, 3, 4, 5};
        iter(arr, 5, &talk);
    }
    {
        std::cout << "Test for float arr" << std::endl;
        float arr[5] = {1.01f, 2.02f, 3.03f, 4.04f, 5.05f};
        iter(arr, 5, &talk);
    }
    {
        std::cout << "Test for double arr" << std::endl;
        double arr[5] = {1.02, 2.04, 3.06, 4.08, 5.10};
        iter(arr, 5, &talk);
    }
	return 0;
}