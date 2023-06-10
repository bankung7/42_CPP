#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{

private:
    unsigned int N;
    Span(void);

public:

    std::vector<int> vec;
    class OverRangeException: public std::exception {
        public:
            const char* what(void) const throw() {
                return ("Range is over limit");
            };
    };

    Span(unsigned int N);
    Span(const Span &c);
    Span& operator=(const Span &c);
    ~Span(void);

    void addNumber(int);
    int shortestSpan(void);
    int longestSpan(void);

};

#endif
