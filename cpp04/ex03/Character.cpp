#include "Character.hpp"

Character::Character(const std::string& name): _name(name)
{
    // std::cout << name << " Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(const Character& c)
{
    // std::cout << "Character copy constructor called" << std::endl;
    this->_name = c._name;
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = 0;
        if (c._inventory[i])
            this->_inventory[i] = c._inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& c)
{
    // std::cout << "Character copy assignment called" << std::endl;
    if (this != &c)
    {
        this->_name = c._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            this->_inventory[i] = 0;
            if (c._inventory[i])
                this->_inventory[i] = c._inventory[i]->clone();
        }
    }
    return (*this);
}

Character::~Character(void)
{
    // std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] != 0)
            delete this->_inventory[i];
    }
}

std::string const &Character::getName(void) const
{
    return (this->_name);
}

// it point to the materia and it sould copy to equip or ref to it, which better
void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "nothing to be equip" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == 0)
        {
            // std::cout << this->_name << " equip with " << m->getType() << " at slot => " << i << std::endl;
            this->_inventory[i] = m;
            return ;
        }
    }
    std::cout << this->_name << " cannot equip as inventory full" << std::endl;
}

// imagine that when unequip, the meteria is gone.
void Character::unequip(int idx)
{
    if ((idx >= 0 && idx < 4) && this->_inventory[idx] != 0)
    {
        // std::cout << this->_name << " unequip " << this->_inventory[idx]->getType() << " at slot => " << idx << std::endl;
        delete this->_inventory[idx];
        this->_inventory[idx] = 0;
        return ;
    }
    std::cout << "This slot is empty" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx < 4) && this->_inventory[idx])
        this->_inventory[idx]->use(target);
    else
        std::cout << this->_name << " spell nothing to " << target.getName() << std::endl;
}
