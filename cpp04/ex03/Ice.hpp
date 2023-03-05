#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{

private:

public:
    Ice(void);
    Ice(const Ice& c);
    Ice& operator=(const Ice& c);
    ~Ice(void);

    AMateria* clone(void) const;
    void use(ICharacter& target);

};

#endif
