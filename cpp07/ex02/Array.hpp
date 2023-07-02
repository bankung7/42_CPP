#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{

private:
    T* _arr;
    unsigned int _size;

public:
    // construction with no parameter
    Array(void): _arr(0), _size(0) {};

    // construction with an unsinged int as a parameter
    Array(unsigned int n): _arr(new T[n]), _size(n) {};

    // copy constructor
    Array(const Array& c): _arr(new T[c._size]), _size(c._size) {
        for (int i = 0; i < (int)this->_size; i++)
            this->_arr[i] = c._arr[i];
    }

    // assignment operator
    Array& operator=(const Array& c) {
        if (this != &c)
        {
            delete[] this->_arr;
            *this = c;
        }
        return (*this);
    }

    // subscription operator
    T& operator[](int i) {
        if (i < 0 || i >= (int)this->_size )
            throw OutOfBound();
        return (this->_arr[i]);
    }

    // deconstructor
    ~Array(void) {
        if (this->_size > 0)
            delete[] this->_arr; 
    }

    // function that return number of elements in the array
    unsigned int size(void) const {
        return (this->_size);
    }

    // class exception
    class OutOfBound: public std::exception {
        public:
            char const* what(void) const throw () {
                return ("Out of Bound");
            }
    };

};

#endif