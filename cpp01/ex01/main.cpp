#include "Zombie.hpp"

// define N
int N = 5;

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
    // let build it by call function
    Zombie *zombie = zombieHorde(N, "Zombie");

    // just try to let its announce
    for (int i = 0; i < N; i++)
        zombie[i].announce();

    // don't forget to free it by delete
    delete[] zombie;
    return (0);
}