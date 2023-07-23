#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {};


BitcoinExchange::BitcoinExchange(const BitcoinExchange &c) {
    (void)c;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &c) {
    (void)c;
    return (*this);
};

BitcoinExchange::~BitcoinExchange(void) {

};

void BitcoinExchange::makeDB(std::string filename) {

    // check file existance
    std::ifstream dbFile;
    dbFile.open(filename);
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

        std::cout << fdate << " = " << value << std::endl;

    }

    // split and put in structure

    // return
};

void BitcoinExchange::readInput(std::string input) {
    std::cout << input << std::endl;
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

    // check input
    // still not check leap year or day in month
    if ((vyear < 1970 || vyear > 2100) ||
        (vmonth < 1 || vmonth > 12) ||
        (vday < 1 || vday > 31))
        return (0);

    std::tm tm;
    tm.tm_year = vyear - 1900;
    tm.tm_mon = vmonth - 1;
    tm.tm_mday = vday;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_isdst = 0;
    std::time_t t = std::mktime(&tm);
    // std::cout << vyear << " " << vmonth << " " << vday << std::endl;
    // std::cout << ctime(&t) << std::endl;
    return (t);
};

double BitcoinExchange::convertValue(std::string &input) {
    std::stringstream svalue;
    double value;
    svalue << input;
    svalue >> value;
    return (value);
};

int BitcoinExchange::stringToInt(std::string &input) {
    std::stringstream sinput;
    sinput << input;
    int value;
    sinput >> value;
    return (value);
};
