#include "HumanB.hpp"

// this is called initialization list
HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    // std::cout << name << " has been created with nothing " << std::endl;
}

HumanB::~HumanB(void)
{
}

// because its weapon type is pointer, we have to use -> instead of .
void HumanB::attack(void)
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}