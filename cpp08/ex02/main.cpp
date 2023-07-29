#include <iostream>
#include "MutantStack.hpp"
#include <stack>
#include <list>

int main()
{
    // test from subject
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top stack value : " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "top stack value : " << mstack.top() << std::endl;
    std::cout << "stack size " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // real stack
    std::stack<int> s(mstack);
    // while (s.size() > 0)
    // {
    //     std::cout << s.top() << " ";
    //     s.pop();
    // }
    // std::cout << std::endl;
    
    // try move to list
    std::cout << "Move to list with iterator" << std::endl;
    std::list<int> list;
    list.insert(list.begin(), mstack.begin(), mstack.end());
    std::list<int>::iterator lit = list.begin();
    while (lit != list.end()) {
        std::cout << *lit << " ";
        lit++;
    }
    std::cout << std::endl;

    return (0);
}