#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <limits>
#include <utility>

class PmergeMe {

private:
    std::vector<int> _uvector;
    std::vector<int> _svector;
    std::vector<std::pair<int, int> > _vpair;

    std::list<int> _ulist;
    std::list<int> _slist;
    std::list<std::pair<int, int> > _vlist;

public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &c);
    PmergeMe operator=(const PmergeMe &c);
    ~PmergeMe(void);

    // test functions
    void readPair(void);

    // vector
    void readVector(std::string text, std::vector<int> vector);
    void addNumber(std::string input);
    void makePair(void);
    void vsort(void);
};

#endif

// step
// 1. create pair of number <int, int>
// 2. sort each pair ascendingly <low, high>
// 3. recursive sort the pair by high value in each pair
// 4. put the low value of each pair by insertion sort