#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& c)
{
    std::cout << "Brain copy contructor called" << std::endl;
    *this = c;
}

Brain& Brain::operator=(const Brain& c)
{
    std::cout << "Brain copy assignment called" << std::endl;
    if (this != &c)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = c._ideas[i];
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}
