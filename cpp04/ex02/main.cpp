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
        // const Animal meta;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        delete j;
        delete i;
    }
    std::cout << std::endl;
    {
        int n = 4;
        int i = 0;
        Animal* animal[n];
        for (; i < n / 2; i++)
            animal[i] = new Dog();
        for (; i < n; i++)
            animal[i] = new Cat();
        std::cout << std::endl;
        for (int i = 0; i < n; i++)
            animal[i]->makeSound();
        std::cout << std::endl;
        for (int i = 0; i < n; i++)
            delete animal[i];
    }
    // {
    //     Dog basic;
    //     {
    //         Dog tmp = basic;
    //     }
    //     Dog advance;
    //     {
    //         Dog tmp;
    //         tmp = advance;
    //     }
    // }
    return (0);
}