#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    // call from stack by randomChump
    randomChump("Stack");

    // let call from heap
    Zombie *zombie = newZombie("Heap");
    zombie->announce();
    delete zombie;
    return (0);
}