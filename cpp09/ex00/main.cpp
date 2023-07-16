#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc [file.txt]" << std::endl;
        return (1);
    }

    try
    {
        BitcoinExchange btc;
        btc.setData("data.csv");
        btc.setInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
};