#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); //will output the cat sound!
        j->makeSound(); // will output the dog sound
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    // {
    //     const WrongAnimal* meta = new WrongAnimal();
    //     const WrongAnimal* i = new WrongCat();
    //     const WrongCat* cat = new WrongCat();

    //     std::cout << i->getType() << " " << std::endl;

    //     i->makeSound(); //will output the cat sound!
    //     meta->makeSound();
    //     cat->makeSound();

    //     delete meta;
    //     delete i;
    //     delete cat;
    // }
    return (0);
}