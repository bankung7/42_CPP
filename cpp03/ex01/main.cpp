#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    {
        ScavTrap a("Hirumina");
        a.guardGate();
        int i = 0;
        for (; i < 5; i++)
            a.attack("Monster");
        a.beRepaired(1);
        a.takeDamage(11);
        for (; i < 8; i++)
            a.attack("Monster");
        a.takeDamage(90);
        a.beRepaired(1);
    }
    return (0);
}