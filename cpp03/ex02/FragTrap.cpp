#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Default", 100, 100, 30)
{
    std::cout << "FragTrap " << name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap " << name << " defined constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& c)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = c;
}

FragTrap& FragTrap::operator=(const FragTrap& c)
{
    std::cout << "FragTrap copy assignment called" << std::endl;
    if (this != &c)
    {
        this->name = c.name;
        this->hp = c.hp;
        this->ep = c.ep;
        this->atk = c.atk;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap ask you for a very positive high fives~" << std::endl;
}