#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstdlib>

template <typename T>
void iter(T *arr, size_t size, void (*f)(T&))
{
    if (!arr || size <= 0 || !f)
        return ;
    for (int i = 0; i < (int)size; i++)
        f(arr[i]);
}

template <typename T>
void iter(T *arr, size_t size, void (*f)(const T&))
{
    if (!arr || size <= 0 || !f)
        return ;
    for (int i = 0; i < (int)size; i++)
        f(arr[i]);
}

#endif
