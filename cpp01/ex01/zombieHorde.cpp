#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    // allocate memory for zombie
    Zombie *zombie = new Zombie[N];

    // set its name
    for (int i = 0; i < N; i++)
        zombie[i].setName(name);
    return (zombie);
}