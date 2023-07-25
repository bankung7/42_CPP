#include "PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc == 1) {
        std::cout << "Error : no argument was passed in here" << std::endl;
        return (1);
    }
    
    PmergeMe pm;
    try
    {
        for (int i = 1; i < argc; i++) {
            pm.addNumber(std::string(argv[i]));
        }

        // vector
        pm.vsort();
        
        // display
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);;
}