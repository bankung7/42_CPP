#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{

private:
    std::string _data;
    std::string _input;
    std::map<std::string, double> _db;

public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange& c);
    BitcoinExchange& operator=(const BitcoinExchange &c);
    ~BitcoinExchange(void);

    void setData(std::string data);
    void setInput(std::string input);
};

#endif
