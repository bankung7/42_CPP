#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("default"), hp(10), ep(10), atk(0)
{
    std::cout << "ClapTrap " << name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), ep(10), atk(0)
{
    std::cout << "ClapTrap " << name << " defined constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp = 10, int ep = 10, int atk = 0): name(name), hp(hp), ep(ep), atk(atk)
{
    std::cout << "ClapTrap " << name << " defined constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c): name(c.name), hp(c.hp), ep(c.ep), atk(c.atk)
{
    std::cout << "ClapTrap copy construct called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
    std::cout << "ClapTrap copy assignment called" << std::endl;
    if (this != &c)
    {
        name = c.name;
        hp = c.hp;
        ep = c.ep;
        atk = c.atk;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

// Member function
void ClapTrap::attack(const std::string& target)
{
    if (hp > 0 && ep > 0)
    {
        ep--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << atk << " points of damage!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " has run out of hp or ep" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp > 0 && ep > 0)
    {
        hp -= amount;
        std::cout << "ClapTrap " << name << " get damaged by " << amount << " point [" << hp << "]" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " has run out of hp or ep" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp > 0 && ep > 0)
    {
        ep--;
        hp += amount;
        std::cout << "ClapTrap " << name << " repaired itself by " << amount << " point [" << hp << "]" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " has run out of hp or ep" << std::endl;
}
