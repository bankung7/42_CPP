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

template <typename T>
void PmergeMe::mergeSort(T &cont, int begin, int end) {
    if (begin >= end)
        return ;
    int mid = begin + (end - begin) / 2;
    mergeSort(cont, begin, mid);
    mergeSort(cont, mid + 1, end);
    merge(cont, begin, mid, end);
}

template <typename T>
void PmergeMe::merge(T &pair, int left, int mid, int right) {
    int subOne = mid - left + 1;
    int subTwo = right - mid;

    // create container
    T vone;
    T vtwo;

    vone.insert(vone.begin(), pair.begin() + left, pair.begin() + left + subOne + 1);
    vtwo.insert(vtwo.begin(), pair.begin() + mid + 1, pair.begin() + mid + subOne + 2);

    int indexOne = 0;
    int indexTwo = 0;
    int indexMerge = left;
    while (indexOne < subOne && indexTwo < subTwo) {
        // std::cout << "Compare " << (vone.begin() + indexOne)->first << " with " << (vtwo.begin() + indexTwo)->first << std::endl;
        if ((vone.begin() + indexOne)->first <= (vtwo.begin() + indexTwo)->first) {
            pair[indexMerge] = vone[indexOne];
            indexOne++;
        }
        else {
            pair[indexMerge] = vtwo[indexTwo];
            indexTwo++;
        }
        // std::cout << "So it would be " << (this->_vpair.begin() + indexMerge)->first << std::endl;
        indexMerge++;
    }

    while (indexOne < subOne) {
        pair[indexMerge] = vone[indexOne];
        indexOne++;
        indexMerge++;
    }

    while (indexTwo < subTwo) {
        pair[indexMerge] = vtwo[indexTwo];
        indexTwo++;
        indexMerge++;
    }

    // std::vector<std::pair<int, int> >::iterator it = this->_vpair.begin();
    // for (int i = left; i <= right; i++) {
    //     std::cout << (it + i)->first << std::endl;
    // }
    // std::cout << "============================" << std::endl;
};

template <typename T>
void PmergeMe::readCont(T cont, std::string text) {
    typename T::iterator it = cont.begin();
    typename T::iterator eit = cont.end();

    std::cout << text;
    for (; it != eit; it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Vector Section
template <typename T>
int PmergeMe::insertNumber(T &cont, int pos, int number) {
    typename T::iterator it = cont.begin();

    while (1) {
        if (number <= cont.front()) {
            cont.insert(it, number);
            return (0);
        }
        if (number >= cont.back()) {
            cont.push_back(number);
            return (cont.size() - 1);
        }
        if (number < *(it + pos)) 
            pos--;
        else if (number > *(it + pos)) {
            if ((it + pos + 1) == cont.end()) {
                cont.push_back(number);
                return (pos);
            }
            if (number < *(it + pos + 1)) {
                cont.insert((it + pos + 1), number);
                return (pos);
            }
            pos++;
        }
        else {
            cont.insert((it + pos), number);
            break ;
        }
    }
    return (pos);
};

void PmergeMe::sortVector(void) {

    readCont(this->_uvector, "Before : ");

    // set time
    std::clock_t start = std::clock();

    // if the element is less than 3
    if (this->_uvector.size() <= 3) {
        this->_svector.insert(this->_svector.begin(), this->_uvector.begin(), this->_uvector.end());
        std::sort(this->_svector.begin(), this->_svector.end());
        readCont(this->_svector, "After :  ");
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
    mergeSort(this->_vpair, 0, this->_vpair.size() - 1);

    // insert the sort high value from each pair into sorted container
    pit = this->_vpair.begin();
    for (; pit != this->_vpair.end(); pit++)
        this->_svector.push_back(pit->first);

    // add first and second to the sorted one
    int cpos = 0;
    this->_svector.insert(this->_svector.begin(), this->_vpair.begin()->second);
    cpos = insertNumber(this->_svector, cpos, (this->_vpair.begin() + 1)->second);

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
            cpos = insertNumber(this->_svector, cpos, (this->_vpair.begin() + jNumber)->second);
            jNumber--;
            remaining--;
        }
        current++;
        before = now - 1;
    }

    // if the size is odd, add the last one
    if (this->_uvector.size() % 2 == 1)
        insertNumber(this->_svector, cpos, this->_uvector.back());

    readCont(this->_svector, "After :  ");

    // time
    start = std::clock() - start;
    std::cout << "Time to process a range of " << this->_uvector.size();
    std::cout << std::fixed << std::setprecision(6);
    std::cout << " elements with std::vector : " << (start / (CLOCKS_PER_SEC * 1.0)) << " us" << std::endl;
};

// List section
void PmergeMe::sortDeque(void) {

    // add member to the list
    this->_udeque.insert(this->_udeque.begin(), this->_uvector.begin(), this->_uvector.end());

    // start the clock
    std::clock_t start = std::clock();

    // if the element is less than 3
    if (this->_udeque.size() <= 3) {
        this->_sdeque.insert(this->_sdeque.begin(), this->_udeque.begin(), this->_udeque.end());
        std::sort(this->_sdeque.begin(), this->_sdeque.end());
        readCont(this->_sdeque, "After :  ");
        return ;
    }

    // group the element to pair, if odd let the last unpair.
    std::deque<int>::iterator it = this->_udeque.begin();
    while (it != this->_udeque.end()) {
        int n = *it;
        if (++it == this->_udeque.end())
            break ;
        this->_dpair.push_back(std::make_pair<int, int>(n, *it));
        it++;
    }

    // compare each pair to determine large of thos elements
    std::deque<std::pair<int, int> >::iterator pit = this->_dpair.begin();
    pit = this->_dpair.begin();
    while (pit != this->_dpair.end()) {
        if (pit->first < pit->second)
            std::swap(pit->first, pit->second);
        pit++;
    }

    // recursive sort by merge sort each pair to be in sequence, ascending order
    mergeSort(this->_dpair, 0, this->_dpair.size() - 1);

    // insert the sort high value from each pair into sorted container
    pit = this->_dpair.begin();
    for (; pit != this->_dpair.end(); pit++)
        this->_sdeque.push_back(pit->first);

    // add first and second to the sorted one
    int cpos = 0;
    this->_sdeque.insert(this->_sdeque.begin(), this->_dpair.begin()->second);
    cpos = insertNumber(this->_sdeque, cpos, (this->_dpair.begin() + 1)->second);

    // insert the rest using jacobthal sequence as index
    int remaining = this->_dpair.size() - 2;
    double current = 3;
    double jNumber = 0;
    double before = 0;
    while (remaining > 0) {
        jNumber = getJacobstholIndex(current);
        if (jNumber > this->_dpair.size() - 1)
            jNumber = this->_dpair.size() - 1;
        double now = jNumber;
        while (jNumber > before + 1 && remaining > 0) {
            cpos = insertNumber(this->_sdeque, cpos, (this->_dpair.begin() + jNumber)->second);
            jNumber--;
            remaining--;
        }
        current++;
        before = now - 1;
    }

    // if the size is odd, add the last one
    if (this->_udeque.size() % 2 == 1)
        insertNumber(this->_sdeque, cpos, this->_udeque.back());

    // readCont(this->_sdeque, "After :  ");

    // time
    start = std::clock() - start;
    std::cout << "Time to process a range of " << this->_udeque.size();
    std::cout << std::fixed << std::setprecision(6);
    std::cout << " elements with std::deque :  " << (start / (CLOCKS_PER_SEC * 1.0)) << " us" << std::endl;
};