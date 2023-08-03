#include "PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "Error : no argument was passed in here" << std::endl;
        return (1);
    }
    
    PmergeMe pm;
    try
    {
        // add number
        for (int i = 1; i < argc; i++)
            pm.addNumber(argv[i]);

        // display
        pm.sortVector();
        pm.sortList();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);;
}