#include <iostream>
#include "MutantStack.hpp"
#include <stack>
#include <vector>


int main()
{
    MutantStack<int> mstack;

    mstack.push(0);
    mstack.push(999);
    
    std::cout << "the top of stack : " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Current size : " << mstack.size() << std::endl;
    std::cout << "the top of stack : " << mstack.top() << std::endl;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "==== Try with real stack ====" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Current stack size : " << mstack.size() << std::endl;
    while (s.size() > 0)
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    std::cout << "Current stack size : " << mstack.size() << std::endl;

    std::cout << "==== Try copy by iterator to array ====" << std::endl;
    std::vector<int> vec;
    std::cout << "Vector size : " << vec.size() << std::endl;
    it = mstack.begin();
    while (it != ite)
    {
        vec.push_back(*it);
        it++;
    }
    std::cout << "Vector size : " << vec.size() << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
    return (0);
}