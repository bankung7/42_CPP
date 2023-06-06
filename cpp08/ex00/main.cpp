#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    {
        // vector
        std::cout << "vector" << std::endl;
        std::vector<int> vec(5);
        std::fill(vec.begin(), vec.end(), 5);
        try
        {
            std::cout << *easyfind(vec, 1) << std::endl;
            std::cout << *easyfind(vec, 69) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        // array
        std::cout << "array" << std::endl;
        std::array<int, 5> arr = {1, 2, 3, 4, 5};
        try
        {
            std::cout << *easyfind(arr, 2) << std::endl;
            std::cout << *easyfind(arr, 69) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        // list
        std::cout << "list" << std::endl;
        std::list<int> lst;
        for (int i = 0; i < 5; i++)
            lst.push_back(i);
        try
        {
            std::cout << *easyfind(lst, 3) << std::endl;
            std::cout << *easyfind(lst, 69) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        // deque
        std::cout << "deque" << std::endl;
        std::deque<int> dq;
        for (int i = 0; i < 5; i++)
            dq.push_back(i);
        try
        {
            std::cout << *easyfind(dq, 4) << std::endl;
            std::cout << *easyfind(dq, 69) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}