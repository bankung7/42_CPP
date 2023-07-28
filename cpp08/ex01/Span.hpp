#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <list>
#include <limits>

class Span {

private:
    unsigned int _N;
    std::list<int> _list;

public:
    Span(void);
    Span(unsigned int n);
    Span(Span const &c);
    Span &operator=(Span const &c);
    ~Span(void);

    void addNumber(int n);
    int shortestSpan(void);
    int longestSpan(void);

    void addNumberInOne(std::list<int> lst);
    void readSpan(void);
};

#endif
