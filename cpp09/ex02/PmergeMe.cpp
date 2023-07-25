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

// Vector section
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
    this->_ulist.push_back(number);
};

void PmergeMe::makePair(void) {
    // std::cout << "the size = " << this->_uvector.size() << std::endl;
    int n = this->_uvector.size() - this->_uvector.size() % 2;
    std::vector<int>::iterator it = this->_uvector.begin();
    for (int i = 0; i < n; i += 2, it += 2) {
        // std::cout << *it << " " << *(it + 1) << std::endl;
        std::sort(it, it + 2, std::greater<int>());
        // std::cout << *it << " " << *(it + 1) << std::endl;
        this->_vpair.push_back(std::make_pair(this->_uvector[i], this->_uvector[i + 1]));

    }
    std::sort(this->_vpair.begin(), this->_vpair.end());
};

void PmergeMe::vsort(void) {

    // start
    readVector("Before", this->_uvector);
    makePair();

    std::vector<std::pair<int, int> >::iterator it = this->_vpair.begin();
    for (; it != this->_vpair.end(); it++)
        this->_svector.push_back((it->first));

    it = this->_vpair.begin();
    for (; it != this->_vpair.end(); it++) {
        this->_svector.insert(std::upper_bound(this->_svector.begin(), this->_svector.end(), it->second), it->second);
    }

    // if the input is odd N
    if (this->_uvector.size() % 2 == 1)
        this->_svector.insert(std::upper_bound(this->_svector.begin(), this->_svector.end(), this->_uvector[this->_uvector.size() - 1]), this->_uvector[this->_uvector.size() - 1]);

    // test print
    readVector("After", this->_svector);
};
