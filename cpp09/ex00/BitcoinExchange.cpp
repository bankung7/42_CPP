#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& c)
{
    this->_data = c._data;
    this->_input = c._input;
    this->_db = c._db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &c)
{
    if (this != &c)
        *this = c;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::setData(std::string data)
{
    std::fstream infile;
    infile.open(data.c_str(), std::ios::in);
    if (!infile.is_open())
        throw std::invalid_argument("Error: Something wrong with Data File");

    std::cout << "Creating database from " << data << " file" << std::endl;

    std::string line;

    // skip header line
    getline(infile, line);

    while (getline(infile, line))
    {
        // get first arg

        // get second arg

        // check if last arg fail
    }

    std::cout << "Database is completed" << std::endl;
    infile.close();
}

void BitcoinExchange::setInput(std::string input)
{
    (void)input;
}
