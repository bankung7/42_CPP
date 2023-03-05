#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{

private:
    AMateria* _materia[4];

public:
    MateriaSource(void);
    MateriaSource(const MateriaSource& c);
    MateriaSource& operator=(const MateriaSource& c);
    ~MateriaSource(void);

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);

};

#endif
