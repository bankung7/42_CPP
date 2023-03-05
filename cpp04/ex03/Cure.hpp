#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{

private:

public:
    Cure(void);
    Cure(const Cure& c);
    Cure& operator=(const Cure& c);
    ~Cure(void);

    AMateria* clone(void) const;
    void use(ICharacter& target);

};

#endif
