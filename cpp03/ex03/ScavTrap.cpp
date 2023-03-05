#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("Default", 100, 50, 20)
{
    std::cout << "ScavTrap " << name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap " << name << " defined constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& c)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = c;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& c)
{
    std::cout << "ScavTrap copy assignment called" << std::endl;
    if (this != &c)
    {
        this->name = c.name;
        this->hp = c.hp;
        this->ep = c.ep;
        this->atk = c.atk;
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hp > 0 && ep > 0)
    {
        ep--;
        std::cout << "ScavTrap " << name << " deal " << atk << " damaged to " << target << "!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << name << " is lack out of something" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now in gate keeper mode" << std::endl;
}