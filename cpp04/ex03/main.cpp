#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);

        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        // std::cout << "Check copy char" << std::endl;
        // {
        //     Character a("A");

        //     AMateria* ta = src->createMateria("cure");
        //     AMateria* tb = src->createMateria("ice");

        //     a.equip(ta);

        //     Character b(a);
        //     b.equip(tb);

        //     a.use(0, b);
        //     b.use(0, a);

        //     b = a;

        //     a.use(1, b);
        //     b.use(1, a);
        // }

        delete bob;
        delete me;
        delete src;
    }
    return (0);
}
