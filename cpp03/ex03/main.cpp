#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    {
        ClapTrap a("Asakura");
        a.attack("Monster");
        a.beRepaired(10);
        a.takeDamage(20);
    }
    std::cout << std::endl;
    {
        ScavTrap a("Minamino");
        a.guardGate();
        a.attack("Monster");
        a.beRepaired(10);
        a.takeDamage(20);
    }
    std::cout << std::endl;
    {
        FragTrap a("Huruka");
        a.highFivesGuys();
        a.attack("Monster");
        a.beRepaired(10);
        a.takeDamage(20);
    }
    std::cout << std::endl;
    {
        DiamondTrap a("Sakuramiji");
        a.whoAmI();
        a.guardGate();
        a.highFivesGuys();
        int i = 0;
        for (; i < 5; i++)
            a.attack("Monster");
        a.beRepaired(1);
        a.takeDamage(200);
        a.attack("Monster");
    }
    return (0);
}