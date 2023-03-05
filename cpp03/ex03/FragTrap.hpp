#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap
{

private:

public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap& c);
    FragTrap& operator=(const FragTrap& c);
    ~FragTrap(void);

    void highFivesGuys(void);

};

#endif
