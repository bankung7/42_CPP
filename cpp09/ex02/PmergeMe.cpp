#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {

};

PmergeMe::PmergeMe(const PmergeMe &c) {
    this->_uvector = c._uvector;
    this->_svector = c._svector;
    this->_vpair = c._vpair;
    this->_ulist = c._ulist;
    this->_slist = c._slist;
    this->_lpair = c._lpair;
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
void PmergeMe::readCont(T cont, std::string text) {
    typename T::iterator it = cont.begin();
    typename T::iterator eit = cont.end();

    std::cout << text;
    for (; it != eit; it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::announceTime(std::clock_t start, std::string type) {
    start = std::clock() - start;
    std::cout << "Time to process a range of " << this->_uvector.size();
    std::cout << std::fixed << std::setprecision(6);
    std::cout << " elements with std::" << type << " : " << (start / (CLOCKS_PER_SEC * 1.0)) << " s" << std::endl;

}

// Vector Section
void PmergeMe::mergeSort(std::vector<std::pair<int, int> > &cont, int begin, int end) {
    if (begin >= end)
        return ;
    int mid = begin + (end - begin) / 2;
    mergeSort(cont, begin, mid);
    mergeSort(cont, mid + 1, end);
    merge(cont, begin, mid, end);
}

void PmergeMe::merge(std::vector<std::pair<int, int> > &pair, int left, int mid, int right) {
    int subOne = mid - left + 1;
    int subTwo = right - mid;

    // create container
    std::vector<std::pair<int, int> > vone;
    std::vector<std::pair<int, int> > vtwo;

    vone.insert(vone.begin(), pair.begin() + left, pair.begin() + left + subOne + 1);
    vtwo.insert(vtwo.begin(), pair.begin() + mid + 1, pair.begin() + mid + subOne + 2);

    int indexOne = 0;
    int indexTwo = 0;
    int indexMerge = left;
    while (indexOne < subOne && indexTwo < subTwo) {
        if ((vone.begin() + indexOne)->first <= (vtwo.begin() + indexTwo)->first) {
            pair[indexMerge] = vone[indexOne];
            indexOne++;
        }
        else {
            pair[indexMerge] = vtwo[indexTwo];
            indexTwo++;
        }
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
};

int PmergeMe::insertNumber(std::vector<int> &cont, int pos, int number) {
    std::vector<int>::iterator it = cont.begin();

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

    if (this->_uvector.size() == 0)
        throw std::runtime_error("Error : Empty thing to sort");

    readCont(this->_uvector, "Before : ");

    // set time
    clock_t start = std::clock();

    // if the element is less than 3
    if (this->_uvector.size() <= 3) {
        this->_svector.insert(this->_svector.begin(), this->_uvector.begin(), this->_uvector.end());
        std::sort(this->_svector.begin(), this->_svector.end());
        readCont(this->_svector, "After :  ");
        announceTime(start, "vector");
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
    announceTime(start, "vector");
};

// list
void PmergeMe::sortList(void) {

    // add member to the list
    this->_ulist.insert(this->_ulist.begin(), this->_uvector.begin(), this->_uvector.end());

    // readCont(this->_ulist, "Before : ");

    // start the clock
    std::clock_t start = std::clock();

    // if the element is less than 3
    if (this->_ulist.size() <= 3) {
        this->_slist.insert(this->_slist.begin(), this->_ulist.begin(), this->_ulist.end());
        this->_slist.sort();
        // readCont(this->_slist, "After [LIST] :  ");
        announceTime(start, "list");
        return ;
    }

    // group the element to pair, if odd let the last unpair.
    std::list<int>::iterator it = this->_ulist.begin();
    while (it != this->_ulist.end()) {
        int n = *it;
        if (++it == this->_ulist.end())
            break ;
        this->_lpair.push_back(std::make_pair<int, int>(n, *it));
        it++;
    }

    // compare each pair to determine large of thos elements
    std::list<std::pair<int, int> >::iterator pit = this->_lpair.begin();
    pit = this->_lpair.begin();
    while (pit != this->_lpair.end()) {
        if (pit->first < pit->second)
            std::swap(pit->first, pit->second);
        pit++;
    }

    // recursive sort by merge sort each pair to be in sequence, ascending order
    mergeSortList(this->_lpair);

    // insert the sort high value from each pair into sorted container
    pit = this->_lpair.begin();
    for (; pit != this->_lpair.end(); pit++)
        this->_slist.push_back(pit->first);

    // add first and second to the sorted one
    pit = this->_lpair.begin();
    this->_slist.insert(this->_slist.begin(), (pit++)->second);
    it = this->_slist.begin();
    insertList(this->_slist, it, pit->second);

    // insert the rest using jacobthal sequence as index
    int remaining = this->_lpair.size() - 2;
    double current = 3;
    double jNumber = 0;
    double before = 0;
    while (remaining > 0) {
        jNumber = getJacobstholIndex(current);
        if (jNumber > this->_lpair.size() - 1)
            jNumber = this->_lpair.size() - 1;
        double now = jNumber;
        while (jNumber > before + 1 && remaining > 0) {
            insertList(this->_slist, it, getListValue(this->_lpair, jNumber));
            jNumber--;
            remaining--;
        }
        current++;
        before = now - 1;
    }

    // if the size is odd, add the last one
    if (this->_ulist.size() % 2 == 1)
        insertList(this->_slist, it, this->_ulist.back());

    // readCont(this->_slist, "After [LIST] :  ");

    // time
    announceTime(start, "list");
};

int PmergeMe::getListValue(std::list<std::pair<int, int> > list, double pos) {
    std::list<std::pair<int, int> >::iterator it = list.begin();
    while (pos-- > 0)
        it++;
    return (it->second);
};

void PmergeMe::mergeSortList(std::list<std::pair<int, int> > &list) {
    if (list.size() <= 1)
        return ;

    int mid = list.size() / 2;

    std::list<std::pair<int, int> > a;
    std::list<std::pair<int, int> > b;
    std::list<std::pair<int, int> >::iterator block = list.begin();
    
    int i = 0;
    while (i++ < mid) {
        block++;
    }
    a.insert(a.begin(), list.begin(), block);
    b.insert(b.begin(), block, list.end());

    mergeSortList(a);
    mergeSortList(b);

    a.merge(b);
    list.clear();
    list.insert(list.begin(), a.begin(), a.end());

}

void PmergeMe::insertList(std::list<int> &cont, std::list<int>::iterator &it, int number) {

    while (1) {
        if (number <= cont.front()) {
            cont.push_front(number);
            it = cont.begin();
            return ;
        }
        if (number >= cont.back()) {
            cont.push_back(number);
            it = cont.end();
            return ;
        }
        // case equal
        if (number == *it) {
            cont.insert(it, number);
            return ;
        }
        // case less than
        if (number < *it) 
            it--;
        // case more than
        else if (number > *it) {
            if (++it == cont.end()) {
                cont.push_back(number);
                it = cont.end();
                return ;
            }
            --it;
            if (number < *(++it)) {
                cont.insert(it--, number);
                return ;
            }
        }
    }
    return ;
};
