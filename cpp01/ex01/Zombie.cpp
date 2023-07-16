#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie has been called" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << " : died" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}