#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {

};

PmergeMe::PmergeMe(const PmergeMe &c) {
    (void)c;
};

PmergeMe PmergeMe::operator=(const PmergeMe &c) {
    if (this != &c)
        *this = c;
    return (*this);
};

PmergeMe::~PmergeMe(void) {

};

void PmergeMe::addNumber(std::string input) {
    std::stringstream ss;
    ss << input;
    double n;
    ss >> n;
    if (ss.good() == 1 || ss.fail() == 1) {
        std::cout << "[WARNING] : not a number => " << input << std::endl;
        return ;
    }
    this->_uvector.push_back(n);
    this->_ulist.push_back(n);
}

double PmergeMe::getJacobstholIndex(int n) {
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (getJacobstholIndex(k, n - 1) + (2 * getJacobstholIndex(k, n - 2)));
};

void PmergeMe::sortVector(void) {

    // pair the input
    std::vector<std::pair<int, int> > pair;
    int k = this->_uvector.size() - (this->_uvector.size() % 2);
    for (int i = 0; i < k; i += 2) {
        pair.push_back(std::pair<int, int>(this->_uvector[i], this->_uvector[i + 1]));
    }

    // try read pair
    std::vector<std::pair<int, int> >::iterator it = pair.begin();

    // sort each pair
    while (it != pair.end()) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
        it++;
    }

    // sort pair
    std::sort(pair.begin(), pair.end());

    std::vector<int> pend;
    // insert high value in mainchain
    it = pair.begin();
    while (it != pair.end()) {
        this->_svector.push_back(it->first);
        pend.push_back(it->second);
        it++;
    }
    // push last if have to pend
    if (this->_uvector.size() % 2 == 1)
        pend.push_back(this->_uvector.back());

    // push first pend, no matter what, to the main chain
    // this->_svector.insert(this->_svector.begin(), pair.begin()->second);

    std::vector<int>::iterator sit = this->_svector.begin();
    std::vector<int>::iterator site = this->_svector.end();
    for (; sit != site; sit++)
        std::cout << *sit << " ";

    // insert the pend to the main chain by Jacobsthol index
    int i = 0;
    double jIndex = getJacobstholIndex(i);
    if (jIndex > pair.size() - 1)
        jIndex = pair.size() - 1;
    
};

// test function
void PmergeMe::readData(int n) {
    if (n == 0) {
        std::vector<int>::iterator it = this->_uvector.begin();
        std::vector<int>::iterator ite = this->_uvector.end();
        for (; it != ite; it++)
            std::cout << *it << " ";
    } else if (n == 1) {
        std::list<int>::iterator it = this->_ulist.begin();
        std::list<int>::iterator ite = this->_ulist.end();
        for (; it != ite; it++)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
};

