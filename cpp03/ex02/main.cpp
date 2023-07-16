#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    {
        FragTrap a("Sakuramiji");

        a.highFivesGuys();

        int i = 0;

        for (; i < 5; i++)
            a.attack("Monster");
        a.takeDamage(50);
        a.beRepaired(10);

        for (; i < 7; i++)
            a.attack("Monster");

        a.takeDamage(100);
        a.beRepaired(1);
    }
    return (0);
}