#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    {
        ClapTrap a("Tsukishima");

        int i = 0;
        a.beRepaired(1);
        for (; i < 5; i++)
            a.attack("Monster");
        a.takeDamage(12);
        a.beRepaired(1);
    }
    return (0);
}