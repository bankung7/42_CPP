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
    std::list<int> _ulist;
    std::list<int> _slist;
    std::list<std::pair<int, int> > _lpair;

public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &c);
    PmergeMe operator=(const PmergeMe &c);
    ~PmergeMe(void);

    void addNumber(std::string input);
    double getJacobstholIndex(int n);
    
    template <typename T>
    void mergeSort(T &cont, int begin, int end);

    template <typename T>
    void merge(T &pair, int left, int mid, int right);

    template <typename T>
    void readCont(T cont, std::string text);
    
    // vector
    void sortVector(void);
    int insertNumber(int pos, int number);

    // list
    void sortList(void);

};

#endif

// step
// group input to pair
// sort each pair 
// sort the list based on high value of each pair
