#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc [file.txt]" << std::endl;
        return (1);
    }

    // calling
    BitcoinExchange bt;

    try {
        bt.makeDB(std::string("data.csv"));
        bt.readInput(std::string(argv[1]));
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
};