#include "Span.hpp"

int randomNumber () { return (std::rand() % ((2147483646 - 0) + 1)); }

int main()
{
    srand(time(NULL));
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "=======================" << std::endl;
        std::cout << "Test N is 0 and addNumber" << std::endl;
        std::cout << "=======================" << std::endl;
        Span sp = Span(0);
        try {
            sp.addNumber(0);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=======================" << std::endl;
        std::cout << "Test N is 1 and get span" << std::endl;
        std::cout << "=======================" << std::endl;
        Span sp = Span(1);
        sp.addNumber(-1);
        try {
            std::cout << "Try shortest Span => " << sp.shortestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << "Try longest Span => " << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::list<int> list;
        for (int i = 0; i < 10000; i++) {
            list.push_back(randomNumber());
        };
        {
            Span sp = Span(10000);
            std::cout << "=======================" << std::endl;
            std::cout << "Try 10000 number" << std::endl;
            std::cout << "=======================" << std::endl;
            for (int i = 0; i < 10000; i++) {
                sp.addNumber(randomNumber());
            }
            std::cout << "Try shortest Span => " << sp.shortestSpan() << std::endl;
            std::cout << "Try longest Span => " << sp.longestSpan() << std::endl;
        }
        {
            Span sp = Span(10000);
            std::cout << "=======================" << std::endl;
            std::cout << "Try 10000 number in 1 add" << std::endl;
            std::cout << "=======================" << std::endl;
            sp.addNumberInOne(list);
            std::cout << "Try shortest Span => " << sp.shortestSpan() << std::endl;
            std::cout << "Try longest Span => " << sp.longestSpan() << std::endl;
        }
        {
            std::cout << "=======================" << std::endl;
            std::cout << "Try over limit for addNumberInOne" << std::endl;
            std::cout << "=======================" << std::endl;
            Span sp = Span(1);
            sp.addNumber(1);
            try {
                sp.addNumberInOne(list);
            } catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    return (0);
}