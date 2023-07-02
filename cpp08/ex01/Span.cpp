#include "Span.hpp"

Span::Span(void)
{
};

Span::Span(unsigned int n): _N(n)
{
};

Span::Span(const Span &c)
{
    this->_N = c._N;
    std::vector<int>_vec(c._vec);
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
    return ("Member is too less");
}

void Span::addNumber(int n)
{
    if (this->_vec.size() >= this->_N)
        throw OufOfRange();
    this->_vec.push_back(n);
};

int Span::shortestSpan(void) const
{
    if (this->_vec.size() <= 1)
        throw LessNumber();
    std::vector<int>::const_iterator it = this->_vec.begin();
    int min = INT_MAX;
    for (; it != this->_vec.end(); it++)
    {
        std::vector<int>::const_iterator its = (it + 1);
        for (; its != this->_vec.end(); its++)
        {
            if ((abs(*it - *its)) < min)
            {
                // std::cout << *it << " " << *its << std::endl; 
                min = abs(*it - *its);
            }
            if (*it == *its)
                std::cout << "Duplicate " << *it << " " << *its << std::endl; 
        }
    }
    return (min);
}

int Span::longestSpan(void) const
{
    if (this->_vec.size() <= 1)
        throw LessNumber();
    int max = *max_element(this->_vec.begin(), this->_vec.end());
    int min = *min_element(this->_vec.begin(), this->_vec.end());
    return (max - min);
}

void Span::addMultiNumber(std::vector<int> ivec)
{
    if (this->_vec.size() + ivec.size() > this->_N)
        throw Span::OufOfRange();
    this->_vec.insert(this->_vec.end(), ivec.begin(), ivec.end());
}