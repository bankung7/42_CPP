#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;
    }
    {
        int i = 0;
        int n = 4;

        Animal* animal[n]; // create array of animal

        for (; i < n / 2; i++) // half of it is Dog
            animal[i] = new Dog();
        for (; i < n; i++) // another half is Cat
            animal[i] = new Cat();

        std::cout << std::endl;

        for (int i = 0; i < n; i++)
            animal[i]->makeSound();

        std::cout << std::endl;

        for (int i = 0; i < n; i++) // delete 
            delete animal[i];
    }
    // {
    //     Dog dog1;
    //     {
    //         Dog tmp(dog1);
    //     }
    //     {
    //         Dog tmp;
    //         tmp = dog1;
    //     }
    // }
    return (0);
}