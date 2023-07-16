#include "HumanA.hpp"

// this is called initialization list
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
    // std::cout << name << " has been created with " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}