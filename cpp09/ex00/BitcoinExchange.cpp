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
        // std::cout << ctime(&fdate) << " = " << value << std::endl;

        // not sure why but it sorted
        this->_db.insert(std::pair<time_t, double>(fdate, value));
    }
    dbFile.close();
    std::cout << std::endl;
};

void BitcoinExchange::readInput(std::string input) {

    // check file existance
    std::ifstream ifile;
    ifile.open(input);
    if (!ifile.is_open())
        throw std::runtime_error("Error : input file is not found");

    std::string row;
    std::getline(ifile, row, '\n');
    while (std::getline(ifile, row, '\n')) {
        // check format to skip and give warning
        if (std::count(row.begin(), row.end(), '|') != 1) {
            std::cout << "Error : bad input => " << row << std::endl;
            continue ;
        }

        // split row
        std::stringstream column(row);

        // get date
        std::string dateInput;
        std::getline(column, dateInput, '|');
        if (std::count(dateInput.begin(), dateInput.end(), '-') != 2) {
            std::cout << "[WARNING] : date in wrong format [YYYY-MM-DD] >> " << dateInput << std::endl;
            continue ;
        }
        std::time_t fdate = convertDate(dateInput);
        // if (fdate == 0) {
        //     std::cout << "[WARNING] : date in wrong format [YYYY-MM-DD] >> " << dateInput << std::endl;
        //     continue ;
        // }
        (void)fdate;

        // get value
        std::string valueInput;
        std::getline(column, valueInput, '|');
        double value;
        value = convertValue(valueInput);

        // check
        if (value < 0) {
            std::cout << "Error : not a positive number." << std::endl;
            continue ;
        }
        if (value > std::numeric_limits<int>::max()) {
            std::cout << "Error : too large a number." << std::endl;
            continue ;
        }
        // fixed this 
        // std::map<time_t, double>::iterator it = this->_db.upper_bound(fdate);
        std::map<time_t, double>::iterator it;
        it = this->_db.find(fdate);
        if (it != this->_db.end())
            std::cout << dateInput << " => " << value << " = " << (value * it->second) << std::endl;
        else {
            it = this->_db.upper_bound(fdate);
            if (it != this->_db.begin()) {
                it--;
                std::cout << dateInput << " => " << value << " = " << (value * it->second) << std::endl;
            }
            else {
                std::cout << "Error : no data" << std::endl;
            }
        }
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

    // std::cout << vday << "-" << vmonth << "-" << vyear << std::endl;

    // check input
    // still not check leap year or day in month
    // if ((vyear < 1970 || vyear > 2100) ||
    //     (vmonth < 1 || vmonth > 12) ||
    //     (vday < 1 || vday > 31))
    //     return (0);

    std::tm tm;
    tm.tm_year = vyear - 1900;
    tm.tm_mon = vmonth - 1;
    tm.tm_mday = vday;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = 0;
    std::time_t t = std::mktime(&tm);
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
