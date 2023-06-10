#include "Span.hpp"

Span::Span(void){};

Span::Span(unsigned int N) : N(N) {};

Span::Span(const Span &c) {
    this->N = c.N;
    std::vector<int> vec(c.vec.begin(), c.vec.end());
};

Span &Span::operator=(const Span &c){
    if (this != &c)
    {
        this->N = c.N;
        std::vector<int> vec(c.vec.begin(), c.vec.end());
    }
    return (*this);
};

Span::~Span(void){};

void Span::addNumber(int n){
    if (this->vec.size() >= this->N)
        throw (OverRangeException());
    // this->vec.push_back(n);
    if (vec.size() == 0)
    {
        vec.push_back(n);
        return ;
    }
    std::vector<int>::iterator it;
    it = vec.end();
    vec.insert(it, n);
};

int Span::shortestSpan(void){
    return (0);
};

int Span::longestSpan(void){
    return (0);
};