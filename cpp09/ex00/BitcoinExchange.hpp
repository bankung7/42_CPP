#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <limits>

class BitcoinExchange {

private:
    std::map<time_t, double> _db;

public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &c);
    BitcoinExchange& operator=(const BitcoinExchange &c);
    ~BitcoinExchange(void);

    void makeDB(std::string filename);
    void readInput(std::string input);

    time_t convertDate(std::string &input);
    double convertValue(std::string &input);
    int stringToInt(std::string &input);

};

#endif
