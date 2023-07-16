#include "easyfind.hpp"
#include <iostream>
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
            std::cout << "try find 5 : " << *easyfind(vec, 5) << std::endl;
            std::cout << "try find 1 : " << *easyfind(vec, 1) << std::endl;
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
            std::cout << "try find 3 : " << *easyfind(lst, 3) << std::endl;
            std::cout << "try find 5 : " << *easyfind(lst, 5) << std::endl;
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
            std::cout << "try find 2 : " << *easyfind(dq, 2) << std::endl;
            std::cout << "try find 69 : " << *easyfind(dq, 69) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}