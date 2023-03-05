#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    // std::cout << "New type " << type << " has been added" << std::endl;
}

Weapon::~Weapon(void)
{
    // std::cout << "Weapon has been destroyed" << std::endl;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}