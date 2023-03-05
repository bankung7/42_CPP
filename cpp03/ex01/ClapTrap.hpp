#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

protected:
    std::string name;
    int hp;
    int ep;
    int atk;

public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(std::string name, int hp, int ep, int atk);
    ClapTrap(const ClapTrap& c);
    ClapTrap& operator=(const ClapTrap& c);
    ~ClapTrap(void);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif
