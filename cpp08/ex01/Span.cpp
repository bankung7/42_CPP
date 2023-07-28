#include "Span.hpp"

Span::Span(void): _N(0) {};

Span::Span(unsigned int n): _N(n) {};

Span::Span(Span const &c) {
    this->_N = c._N;
    this->_list = c._list;
};

Span &Span::operator=(Span const &c) {
    if (this != &c)
        *this = c;
    return (*this);
};

Span::~Span(void) {};

void Span::addNumber(int n) {
    if (this->_list.size() >= this->_N)
        throw std::runtime_error("Error : over limit");
    this->_list.push_back(n);
    this->_list.sort();
};

int Span::shortestSpan(void) {
    if (this->_list.size() <= 1)
        throw std::runtime_error("Error : too less number in the span");
    int min = std::numeric_limits<int>::max();
    std::list<int>::iterator it = this->_list.begin();
    while (it != this->_list.end()) {
        int cal = *(it++);
        if (it == this->_list.end())
            break;
        cal = *it - cal;
        if (cal < min)
            min = cal;
    }
    return (min);
};

int Span::longestSpan(void) {
    if (this->_list.size() <= 1)
        throw std::runtime_error("Error : too less number in the span");
    return (this->_list.back() - this->_list.front());
};

void Span::addNumberInOne(std::list<int> lst) {
    if (lst.size() + this->_list.size() > this->_N)
        throw std::runtime_error("Error : over limit");
    this->_list.insert(this->_list.end(), lst.begin(), lst.end());
    this->_list.sort();
};

void Span::readSpan(void) {
    std::list<int>::iterator it = this->_list.begin();
    while (it != this->_list.end()) {
        std::cout << *it << std::endl;
        it++;
    }
};