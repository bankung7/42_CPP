#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{

protected:
    std::string _type;

public:
    WrongAnimal(void);
    WrongAnimal(const std::string& type);
    WrongAnimal(const WrongAnimal& c);
    WrongAnimal& operator=(const WrongAnimal& c);
    ~WrongAnimal(void);

    void makeSound(void) const;

    std::string getType(void) const;

};

#endif
