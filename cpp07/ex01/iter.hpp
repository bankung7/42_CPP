#ifndef ITER_H
# define ITER_H

# include <cstdlib>
# include <iostream>

template <typename T>
void iter(T *arr, size_t size, void (*f)(const T &))
{
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
