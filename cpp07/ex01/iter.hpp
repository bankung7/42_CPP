#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>
# include <iostream>
# include <sstream>

template <typename T>
void iter(T *arr, size_t size, void (*f)(const T &))
{
    if (size <= 0)
        return ;
    for (int i = 0; i < (int)size; i++)
        f(arr[i]);
}

// test function
template <typename T>
void talk(T &thing)
{
    std::cout << thing << std::endl;
}

#endif
