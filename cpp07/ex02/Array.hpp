#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>

template <typename T>
class Array
{

private:
    T* _arr;
    unsigned int _size;

public:
    class OutOfBoundException: public std::exception {
        public:
            const char* what(void) const throw() {
                return ("Index is out of bound");
            };
    };

    Array(void): _arr(0), _size(0) {};
    Array(unsigned int n): _arr(new T[n]), _size(n) {};
    Array(const Array& c): _arr(new T[c._size]), _size(c._size) {
        for (int i = 0; i < (int)this->_size; i++)
            this->_arr[i] = c._arr[i];
    };
    Array& operator=(const Array& c) {
        if (this == &c)
            return (*this);
        if (this->_size != c._size)
        {
            delete[] this->_arr;
            this->_arr = new T[c._size];
            this->_size = c._size;
        }
        for (int i = 0; i < (int)this->_size; i++)
            this->_arr[i] = c._arr[i];
        return (*this);
    };
    // subscript operator
    T& operator[](unsigned int n) {
        if (n >= _size)
            throw (OutOfBoundException());
        return (_arr[n]);
    }
    ~Array(void) {
        if (this->_size != 0)
            delete[] _arr;  
    };

    unsigned int size(void) const { return (_size); };
};

#endif
