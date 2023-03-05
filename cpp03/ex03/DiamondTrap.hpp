#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

private:
    std::string name;

public:
    DiamondTrap(void);
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& c);
    DiamondTrap& operator=(const DiamondTrap& c);
    ~DiamondTrap(void);

    using ScavTrap::attack;

    void whoAmI(void);

};

#endif
