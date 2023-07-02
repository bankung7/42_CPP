#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{

private:
    std::string _name;
    AMateria* _inventory[4];

public:
    Character(const std::string& name);
    Character(const Character& c);
    Character& operator=(const Character& c);
    ~Character(void);

    std::string const &getName(void) const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

};

#endif
