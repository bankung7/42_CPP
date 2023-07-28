#include "Span.hpp"

int randomNumber () { return (std::rand() % ((2147483646 - 0) + 1)); }

int main()
{
    srand(time(NULL));
    {
        Span sp = Span(5);

        try
        {
            std::cout << "=====> try with no member" << std::endl;
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        sp.addNumber(6);

        try
        {
            std::cout << "=====> try with one 1 member" << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        
        sp.addNumber(-3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.readSpan();

        std::cout << "======> Basic try" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        try
        {
            std::cout << "======> try add over range" << std::endl;
            sp.addNumber(1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Span sp = Span(10000);

        std::cout << "=====> create 10000 members" << std::endl;
        for (int i = 0; i < 10000; i++)
            sp.addNumber(randomNumber());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        try
        {
            std::cout << "=====> try add in 1 call" << std::endl;
            std::cout << "Creating 10000 number" << std::endl;
            std::list<int> intVec;
            for (int i = 0; i < 10000; i++)
                intVec.insert(intVec.begin(), randomNumber());
            std::cout << "preparing add" << std::endl;
            Span sp = Span(10000);
            sp.addNumberInOne(intVec);
            std::cout << "=====> complete adding try short and long span" << std::endl;
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return (0);
}