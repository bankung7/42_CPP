#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <vector>
#include <list>
#include <iomanip>

class PmergeMe {

private:
    std::vector<int> _uvector;
    std::vector<int> _svector;
    std::vector<std::pair<int, int> > _vpair;
    std::vector<int>::iterator _svit;

public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &c);
    PmergeMe operator=(const PmergeMe &c);
    ~PmergeMe(void);

    void addNumber(std::string input);
    double getJacobstholIndex(int n);


    // vector
    void sortVector(void);
    void mergeSort(int begin, int end);
    void merge(int left, int mid, int right);
    int insertNumber(int pos, int number);

    // test function
    void readVector(int n);

};

#endif

// step
// group input to pair
// sort each pair 
// sort the list based on high value of each pair
