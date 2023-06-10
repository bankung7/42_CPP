#include "Span.hpp"
#include <iostream>

int main()
{
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.addNumber(11);

        std::vector<int>::iterator it;
        for (it = sp.vec.begin(); it != sp.vec.end(); it++)
            std::cout << *it << std::endl;
        // std::cout << sp.shortestSpan() << std::endl;
        // std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}