#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// It randomly instanciates A, B or C and returns the instance as a Base pointer. 
// Feel free to use anything you like for the random choice implementation
Base* generate(void)
{
    srand(time(0));
    int num = rand() % 3;
    if (num == 0)
        return (new A);
    if (num == 1)
        return (new B);
    return (new C);
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "this is A pointer" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "this is B pointer" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "this is C pointer" << std::endl;
    else
        std::cout << "Don't know" << std::endl;
}


// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// Using a pointer inside this function is forbidden.
void identify(Base& p)
{
    try{
        A& a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "this is A pointer" << std::endl;
        return ;
    } catch (...) {};

    try{
        B& b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "this is B pointer" << std::endl;
        return ;
    } catch (...) {};

    try{
        C& c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "this is C pointer" << std::endl;
        return ;
    } catch (...) {};
}

int main(void)
{
    Base* ptr = generate();

    std::cout << "actual type" << std::endl;
    identify(ptr);

    std::cout << std::endl;
    std::cout << "actual type by reference" << std::endl;
    identify(*ptr);

    delete ptr;

    return (0);
}

// dynamic cast is a runtime cast which used to perform conversion of one type variable to another
// only on the class pointers and references.
// it checks the valid casting of the variable at the run time, and if the casting fail, it return null