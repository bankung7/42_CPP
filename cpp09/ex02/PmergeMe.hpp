#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <list>

class PmergeMe {

private:
    std::vector<int> _uvector;
    std::vector<int> _svector;
    std::list<int> _ulist;

public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &c);
    PmergeMe operator=(const PmergeMe &c);
    ~PmergeMe(void);

    void addNumber(std::string input);
    double getJacobstholIndex(int n);

    // vector
    void sortVector(void);


    // test function
    void readData(int n);

};

#endif

// step
// group input to pair
// sort each pair 
// sort the list based on high value of each pair
