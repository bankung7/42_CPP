#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

private:
    std::string _ideas[100];

public:
    Brain(void);
    Brain(const Brain& c);
    Brain& operator=(const Brain& c);
    ~Brain(void);

};

#endif
