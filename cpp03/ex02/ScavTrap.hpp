#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap
{

private:

public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& c);
    ScavTrap& operator=(const ScavTrap& c);
    ~ScavTrap(void);

    void attack(const std::string& target);
    void guardGate(void);

};

#endif
