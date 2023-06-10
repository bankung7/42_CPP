#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

#include <iostream>

class Span
{

private:
    unsigned int N;

public:
    std::vector<int>vec;

    Span(void);
    Span(unsigned int N);
    Span(const Span &c);
    Span& operator=(const Span &c);
    ~Span(void);

    class OufOfRange: public std::exception{
        const char* what(void) const throw();
    };

    class LessNumber: public std::exception{
        const char* what(void) const throw();
    };

    void addNumber(int);
    int shortestSpan(void) const;
    int longestSpan(void) const;

};

#endif
