#include "Span.hpp"

Span::Span(void)
{
};

Span::Span(unsigned int n): N(n)
{
};

Span::Span(const Span &c)
{
    this->N = c.N;
    std::vector<int>vec(c.vec);
};

Span& Span::operator=(const Span &c)
{
    if (this != &c)
        *this = c;
    return (*this);
};

Span::~Span(void)
{};

const char* Span::OufOfRange::what(void) const throw()
{
    return ("Out of Range");
}

const char* Span::LessNumber::what(void) const throw()
{
    return ("Less Number");
}

void Span::addNumber(int n)
{
    if (vec.size() >= N)
        throw OufOfRange();
    vec.push_back(n);
};

int Span::shortestSpan(void) const
{
    if (vec.size() <= 1)
        throw LessNumber();
    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    return (max - min);
}

int Span::longestSpan(void) const
{
    if (vec.size() <= 1)
        throw LessNumber();
    return (0);
}