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
    if (n < 0 || n > std::numeric_limits<int>::max()) {
        std::cout << "[WARNING] : out of range [0 - max int]=> " << input << std::endl;
        return ;
    }
    this->_uvector.push_back(n);
}

double PmergeMe::getJacobstholIndex(int n) {
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (getJacobstholIndex(n - 1) + (2 * getJacobstholIndex(n - 2)));
}

int PmergeMe::insertNumber(int pos, int number) {
    std::vector<int>::iterator it = this->_svector.begin();

    while (1) {
        if (number <= this->_svector.front()) {
            this->_svector.insert(it, number);
            return (0);
        }
        if (number >= this->_svector.back()) {
            this->_svector.push_back(number);
            return (this->_svector.size() - 1);
        }
        if (number < *(it + pos)) 
            pos--;
        else if (number > *(it + pos)) {
            if ((it + pos + 1) == this->_svector.end()) {
                this->_svector.push_back(number);
                return (pos);
            }
            if (number < *(it + pos + 1)) {
                this->_svector.insert((it + pos + 1), number);
                return (pos);
            }
            pos++;
        }
        else {
            this->_svector.insert((it + pos), number);
            break ;
        }
    }
    return (pos);
};

void PmergeMe::sortVector(void) {

    // set time
    std::clock_t start = std::clock();

    // if the element is less than 3
    if (this->_uvector.size() <= 3) {
        this->_svector.insert(this->_svector.begin(), this->_uvector.begin(), this->_uvector.end());
        std::sort(this->_svector.begin(), this->_svector.end());
        readVector(1);
        return ;
    }

    // group the element to pair, if odd let the last unpair.
    std::vector<int>::iterator it = this->_uvector.begin();
    while (it != this->_uvector.end()) {
        int n = *it;
        if (++it == this->_uvector.end())
            break ;
        this->_vpair.push_back(std::make_pair<int, int>(n, *it));
        it++;
    }

    // compare each pair to determine large of thos elements
    std::vector<std::pair<int, int> >::iterator pit = this->_vpair.begin();
    pit = this->_vpair.begin();
    while (pit != this->_vpair.end()) {
        if (pit->first < pit->second)
            std::swap(pit->first, pit->second);
        pit++;
    }

    // recursive sort by merge sort each pair to be in sequence, ascending order
    mergeSort(0, this->_vpair.size() - 1);

    // insert the sort high value from each pair into sorted container
    pit = this->_vpair.begin();
    for (; pit != this->_vpair.end(); pit++)
        this->_svector.push_back(pit->first);

    // add first and second to the sorted one
    int cpos = 0;
    this->_svector.insert(this->_svector.begin(), this->_vpair.begin()->second);
    cpos = insertNumber(cpos, (this->_vpair.begin() + 1)->second);

    // insert the rest using jacobthal sequence as index
    int remaining = this->_vpair.size() - 2;
    double current = 3;
    double jNumber = 0;
    double before = 0;
    while (remaining > 0) {
        jNumber = getJacobstholIndex(current);
        if (jNumber > this->_vpair.size() - 1)
            jNumber = this->_vpair.size() - 1;
        double now = jNumber;
        while (jNumber > before + 1 && remaining > 0) {
            cpos = insertNumber(cpos, (this->_vpair.begin() + jNumber)->second);
            jNumber--;
            remaining--;
        }
        current++;
        before = now - 1;
    }

    // if the size is odd, add the last one
    if (this->_uvector.size() % 2 == 1)
        insertNumber(cpos, this->_uvector.back());

    readVector(1);

    // time
    start = std::clock() - start;
    std::cout << "Time to process a range of " << this->_uvector.size();
    std::cout << std::fixed << std::setprecision(6);
    std::cout << " elements with std::vector : " << (start / (CLOCKS_PER_SEC * 1.0)) << " us" << std::endl;
};

void PmergeMe::mergeSort(int begin, int end) {
    if (begin >= end)
        return ;
    int mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

void PmergeMe::merge(int left, int mid, int right) {
    int subOne = mid - left + 1;
    int subTwo = right - mid;

    // create container
    std::vector<std::pair<int, int> > vone;
    std::vector<std::pair<int, int> > vtwo;

    // for (int i = 0; i < subOne; i++) {
    //     vone.push_back(this->_vpair[left + i]);
    // }
    vone.insert(vone.begin(), this->_vpair.begin() + left, this->_vpair.begin() + left + subOne + 1);
    // for (int i = 0; i < subTwo; i++) {
    //     vtwo.push_back(this->_vpair[mid + 1 + i]);
    // }
    vtwo.insert(vtwo.begin(), this->_vpair.begin() + mid + 1, this->_vpair.begin() + mid + subOne + 2);

    int indexOne = 0;
    int indexTwo = 0;
    int indexMerge = left;
    while (indexOne < subOne && indexTwo < subTwo) {
        // std::cout << "Compare " << (vone.begin() + indexOne)->first << " with " << (vtwo.begin() + indexTwo)->first << std::endl;
        if ((vone.begin() + indexOne)->first <= (vtwo.begin() + indexTwo)->first) {
            this->_vpair[indexMerge] = vone[indexOne];
            indexOne++;
        }
        else {
            this->_vpair[indexMerge] = vtwo[indexTwo];
            indexTwo++;
        }
        // std::cout << "So it would be " << (this->_vpair.begin() + indexMerge)->first << std::endl;
        indexMerge++;
    }

    while (indexOne < subOne) {
        this->_vpair[indexMerge] = vone[indexOne];
        indexOne++;
        indexMerge++;
    }

    while (indexTwo < subTwo) {
        this->_vpair[indexMerge] = vtwo[indexTwo];
        indexTwo++;
        indexMerge++;
    }

    // std::vector<std::pair<int, int> >::iterator it = this->_vpair.begin();
    // for (int i = left; i <= right; i++) {
    //     std::cout << (it + i)->first << std::endl;
    // }
    // std::cout << "============================" << std::endl;
};

void PmergeMe::readVector(int n) {
    std::vector<int>::iterator it;
    std::vector<int>::iterator eit;

    if (n == 0) {
        it = this->_uvector.begin();
        eit = this->_uvector.end();
        std::cout << "Before: ";
    } else {
        it = this->_svector.begin();
        eit = this->_svector.end();
        std::cout << "After:  ";
    }

    for (; it != eit; it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}