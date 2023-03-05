#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{

protected:
    std::string _type;

public:
    AMateria(std::string const &type);

    AMateria(const AMateria& c);
    AMateria& operator=(const AMateria& c);
    virtual ~AMateria(void);

    // [...]

    std::string const &getType(void) const; // Returns the materia type
    virtual AMateria *clone(void) const = 0; // this will be depend on which ice or cure
    virtual void use(ICharacter &target);
};

#endif
