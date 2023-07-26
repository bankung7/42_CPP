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

// test function
void PmergeMe::readVector(std::string text, std::vector<int> vector) {
    std::cout << text << ": ";
    std::vector<int>::iterator it = vector.begin();
    for (; it != vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
};

void PmergeMe::readPair(void) {
    std::vector<std::pair<int, int> >::iterator it = this->_vpair.begin();
    for (; it != this->_vpair.end(); it++)
        std::cout << "[ " << it->first << " : " << it->second << " ]" << std::endl;
};

void PmergeMe::addNumber(std::string input) {
    std::stringstream ss;
    ss << input;
    double number;
    ss >> number;
    if (ss.good() || ss.fail())
        throw std::runtime_error("Error: Not a number has been input");
    if (number < 0)
        throw std::runtime_error("Error: Negative number has passed in");
    if (number > std::numeric_limits<int>::max())
        throw std::runtime_error("Error: Over integer value");
    this->_uvector.push_back(number);
};

// Vector section
void PmergeMe::vsort(void) {

    // start
    readVector("Before", this->_uvector);

    // time start
    std::clock_t start = std::clock();

    // make pair
    int n = this->_uvector.size() - this->_uvector.size() % 2;
    for (int i = 0; i < n; i += 2)
        this->_vpair.push_back(std::make_pair(this->_uvector[i], this->_uvector[i + 1]));

    // sort each pair
    std::vector<std::pair<int, int> >::iterator it = this->_vpair.begin();
    for (; it != this->_vpair.end(); it++) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }

    // sort pair vector
    std::sort(this->_vpair.begin(), this->_vpair.end());
    // readPair();

    // move the high value to new sorted vector
    it = this->_vpair.begin();
    for (; it != this->_vpair.end(); it++)
        this->_svector.push_back(it->first);

    // insert the low value into sorted vector
    it = this->_vpair.begin();
    for (; it != this->_vpair.end(); it++)
        this->_svector.insert(std::upper_bound(this->_svector.begin(), this->_svector.end(), it->second), it->second);

    // if odd left, insert now
    int size = this->_uvector.size();
    if (size % 2 == 1)
        this->_svector.insert(std::upper_bound(this->_svector.begin(), this->_svector.end(), this->_uvector[size - 1]), this->_uvector[size - 1]);

    start = std::clock() - start;

    // // test print
    readVector("After", this->_svector);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Time to process a range of " << size << " elements with std::vector : ";
    std::cout << (start / static_cast<double>CLOCKS_PER_SEC) * 1000.0 << " ms" << std::endl;
};

// list
void PmergeMe::lsort(void) {

    std::clock_t start = std::clock();

    // make pair
    int n = this->_uvector.size() - this->_uvector.size() % 2;
    for (int i = 0; i < n; i += 2)
        this->_lpair.push_back(std::make_pair(this->_uvector[i], this->_uvector[i + 1]));

    // sort each pair
    std::list<std::pair<int, int> >::iterator it = this->_lpair.begin();
    for (; it != this->_lpair.end(); it++) {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }

    // sort pair vector
    this->_lpair.sort();

    // move the high value to new sorted vector
    it = this->_lpair.begin();
    for (; it != this->_lpair.end(); it++)
        this->_slist.push_back(it->first);

    // insert the low value into sorted vector
    it = this->_lpair.begin();
    for (; it != this->_lpair.end(); it++)
        this->_slist.insert(std::upper_bound(this->_slist.begin(), this->_slist.end(), it->second), it->second);


    // if odd left, insert now
    int size = this->_uvector.size();
    if (size % 2 == 1)
        this->_slist.insert(std::upper_bound(this->_slist.begin(), this->_slist.end(), this->_uvector[size - 1]), this->_uvector[size - 1]);

    start = std::clock() - start;

    std::cout << "Time to process a range of " << size << " elements with std::list   : ";
    std::cout << (start / static_cast<double>CLOCKS_PER_SEC) * 1000.0 << " ms" << std::endl;

    // test print
    // std::list<int>::iterator lit = this->_slist.begin();
    // std::cout << "After: ";
    // for (; lit != this->_slist.end(); lit++)
    //     std::cout << *lit << " ";
    // std::cout << std::endl;
};
