#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>

template <typename T, typename container = std::deque<T> >
class MutantStack: public std::stack<T, container>
{

private:

public:
    typedef typename std::stack<T, container>::container_type::iterator                 iterator;
    typedef typename std::stack<T, container>::container_type::const_iterator           const_iterator;
    typedef typename std::stack<T, container>::container_type::reverse_iterator         reverse_iterator;
    typedef typename std::stack<T, container>::container_type::const_reverse_iterator   const_reverse_iterator;

    MutantStack<T, container>(void): std::stack<T, container>() {};
    MutantStack<T, container>(const MutantStack<T, container> &c): std::deque<T, container>(c) {};
    MutantStack<T, container>& operator=(const MutantStack<T, container> &c) {
        if (this != &c)
            this->c = c.c;
        return (*this);
    };
    ~MutantStack<T, container>(void) {};

    MutantStack<T, container>::iterator begin(void) { return (this->c.begin()); };
    MutantStack<T, container>::iterator end(void) { return (this->c.end()); };
    MutantStack<T, container>::const_iterator cbegin(void) { return (this->c.begin()); };
    MutantStack<T, container>::const_iterator cend(void) { return (this->c.end()); };
   
};

#endif
