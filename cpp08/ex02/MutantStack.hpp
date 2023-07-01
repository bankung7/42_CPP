#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{

private:

public:
    MutantStack<T>(void) : std::stack<T>() {};
    MutantStack<T>(const MutantStack<T>& c): std::stack<T>(c) {};
    MutantStack<T>& operator=(const MutantStack<T>& c) {
        if (this != &c)
            this = c;
        return (*this);
    };
    ~MutantStack<T>(void) {};

    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return (this->c.begin()); };
    iterator end() { return (this->c.end()); };

    const_iterator cbegin() { return (this->c.cbegin()); };
    const_iterator cend() { return (this->c.cend()); };

    reverse_iterator rbegin() { return (this->c.rbegin()); };
    reverse_iterator rend() { return (this->c.rend()); };

    const_reverse_iterator crbegin() { return (this->c.crbegin()); };
    const_reverse_iterator crend() { return (this->c.crend()); };
};

#endif
