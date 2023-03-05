#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("default_clap_name", 100, 50, 30), name("default")
{
    std::cout << "DiamondTrap " << this->name << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", 100, 50, 30), name(name)
{
    std::cout << "DiamondTrap " << name << " defined constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& c)
{
    std::cout << "DiamondTrap copy construct called" << std::endl;
    *this = c;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& c)
{
    std::cout << "DiamondTrap copy assignment called" << std::endl;
    if (this != &c)
    {
        this->name = c.DiamondTrap::name;
        this->hp = c.hp;
        this->ep = c.ep;
        this->atk = c.atk;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap Name : " << this->name << std::endl;
    std::cout << "ClapTrap name    : " << ClapTrap::name << std::endl;
}
