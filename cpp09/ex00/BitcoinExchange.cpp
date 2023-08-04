#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {};


BitcoinExchange::BitcoinExchange(const BitcoinExchange &c): _db(c._db) {
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &c) {
    if (this != &c)
        this->_db = c._db;
    return (*this);
};

BitcoinExchange::~BitcoinExchange(void) {

};

void BitcoinExchange::makeDB(std::string filename) {

    // check file existance
    std::ifstream dbFile;
    dbFile.open(filename.c_str());
    if (!dbFile.is_open())
        throw std::runtime_error("Error : [ data.csv ] => file is not found");

    // read
    std::string row;
    // skip first line
    std::getline(dbFile, row, '\n');
    while (std::getline(dbFile, row, '\n')) {
        // check format to skip and give warning
        if (std::count(row.begin(), row.end(), ',') != 1) {
            std::cout << "[WARNING] : db wrong format >> " << row << std::endl;
            continue ;
        }

        // split row
        std::stringstream column(row);

        // get date
        std::string dateInput;
        std::getline(column, dateInput, ',');
        if (std::count(dateInput.begin(), dateInput.end(), '-') != 2) {
            std::cout << "[WARNING] : date in wrong format [YYYY-MM-DD] >> " << dateInput << std::endl;
            continue ;
        }
        std::time_t fdate = convertDate(dateInput);
        if (fdate == 0) {
            std::cout << "[WARNING] : date in wrong format [YYYY-MM-DD] >> " << dateInput << std::endl;
            continue ;
        }

        // get value
        std::string valueInput;
        std::getline(column, valueInput, ',');
        double value;
        value = convertValue(valueInput);
        if (value < 0 || value > std::numeric_limits<int>::max()) {
            std::cout << "[WARNING] : number over max value >> " << valueInput << std::endl;
            continue ;
        }
        
        // std::cout << ctime(&this->_db.begin()->first) << " = " << value << std::endl;

        // insert into db
        this->_db.insert(std::pair<time_t, double>(fdate, value));
    }

    dbFile.close();

    if (this->_db.size() == 0)
        throw std::runtime_error("Error : datatbase is empty");

    std::cout << "==================================" << std::endl;
};

void BitcoinExchange::readInput(std::string input) {

    // check file existance
    std::ifstream ifile;
    ifile.open(input.c_str());
    if (!ifile.is_open())
        throw std::runtime_error("Error : input file is not found");

    // loop line and skip first line
    std::string row;
    std::getline(ifile, row, '\n');
    while (std::getline(ifile, row, '\n')) {
        // check if not 2 part by |
        if (std::count(row.begin(), row.end(), '|') != 1) {
            std::cout << "Error : bad input => " << row << std::endl;
            continue;
        }
        
        // prep for getline
        std::stringstream ssrow;
        ssrow << row;
        
        // get date
        std::string idate;
        std::getline(ssrow, idate, '|');
        time_t vdate = convertDate(idate);
        if (vdate == -1) {
            std::cout << "Error : bad date format." << std::endl;
            continue ;
        }

        // get value
        std::string ivalue;
        std::getline(ssrow, ivalue, '\n');
        double vvalue = convertValue(ivalue);
        if (vvalue < 0) {
            std::cout << "Error : not a positive number." << std::endl;
            continue ;
        }

        if (vvalue > 1000) {
            std::cout << "Error : too large a number." << std::endl;
            continue ;
        }

        std::map<time_t, double>::iterator it = this->_db.begin();

        if ((++it)->first > vdate) {
            std::cout << "Error : input date is before date in database => " << idate << std::endl;
            continue ;
        }

        double price;
        it = this->_db.lower_bound(vdate);

        if (it->first == vdate)
            price = it->second;
        else 
            price = (--it)->second;

        price *= vvalue;

        if (price > std::numeric_limits<double>::max()) {
            std::cout << "Error : exceed max value." << std::endl;
            continue ;
        }
        // std::cout << std::fixed << std::setprecision(3);
        std::cout << idate << " => " << vvalue << " = "  << price << std::endl;
    }

    ifile.close();
};

time_t BitcoinExchange::convertDate(std::string &input) {
    std::stringstream dinput;
    dinput << input;

    std::string iyear;
    std::string imonth;
    std::string iday;
    std::getline(dinput, iyear, '-');
    std::getline(dinput, imonth, '-');
    std::getline(dinput, iday, '-');

    int vyear = stringToInt(iyear);
    int vmonth = stringToInt(imonth);
    int vday = stringToInt(iday);

    if (vyear < 1900 || vyear > 2050 || vmonth < 1 || vday < 1)
        return (-1);

    // std::cout << vday << "-" << vmonth << "-" << vyear << std::endl;

    std::tm tm;
    tm.tm_year = vyear - 1900;
    tm.tm_mon = vmonth - 1;
    tm.tm_mday = vday;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = 0;
    std::time_t t = std::mktime(&tm);

    // std::cout << "==== " << tm.tm_year + 1900 << " " << tm.tm_mon + 1 << " " << tm.tm_mday << std::endl;
    if (tm.tm_year != vyear - 1900 || tm.tm_mon != vmonth - 1 || tm.tm_mday != vday)
        return (-1);
    return (t);
};

double BitcoinExchange::convertValue(std::string &input) {
    std::stringstream svalue;
    double value;
    svalue << input;
    svalue >> value;
    if (svalue.good() == 1 || svalue.fail() == 1)
        return (-1);
    return (value);
};

int BitcoinExchange::stringToInt(std::string &input) {
    std::stringstream sinput;
    sinput << input;
    int value;
    sinput >> value;
    return (value);
};
