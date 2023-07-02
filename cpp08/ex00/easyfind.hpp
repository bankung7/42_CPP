#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

// it seem like the iterator, i guess.
template<typename T>
typename T::iterator easyfind(T &cont, int n)
{
    typename T::iterator it;

    it = std::find(cont.begin(), cont.end(), n);

    if (it == cont.end())
        throw (std::out_of_range("Not found"));
        
    return (it);
}
#endif
