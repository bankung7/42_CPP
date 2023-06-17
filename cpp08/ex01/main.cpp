#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

int randomNumber () { return (std::rand() % 1000000000); }

int main()
{
    try {
        std::cout << "=== No number ===" << std::endl;
        Span sp(0);
        sp.longestSpan();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "=== 1 number ===" << std::endl;
        Span sp(1);
        sp.addNumber(1);
        sp.longestSpan();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "=== try add to exceed ===" << std::endl;
        Span sp(1);
        sp.addNumber(1);
        sp.addNumber(1);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "=== try number ===" << std::endl;
        Span sp = Span(6);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(1);
        // sp.addNumber(11);

        // std::vector<int>::iterator it;
        // for (it = sp.vec.begin(); it != sp.vec.end(); it++)
        //     std::cout << *it << std::endl;
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    // try multiple add
    try
    {
        unsigned int n = 10000;
        std::cout << "=== try multilple number in 1 adding ===" << std::endl;
        Span sp = Span(n);
        std::vector<int> vect(n);
        std::generate (vect.begin(), vect.end(), randomNumber);

        // std::vector<int>::iterator it;
        // for (it = vect.begin(); it != vect.end(); it++)
        //     std::cout << *it << std::endl;
        
        std::cout << "start add to vector" << std::endl;
        sp.addMultiNumber(vect);
        // sp.addNumber(1);
        std::cout << "finish add to vector" << std::endl;
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}