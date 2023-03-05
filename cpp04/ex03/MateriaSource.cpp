#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    // std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& c)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_materia[i] = 0;
        if (c._materia[i])
            this->_materia[i] = c._materia[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& c)
{
    // std::cout << "MateriaSource copy assignment called" << std::endl;
    if (this != &c)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materia[i])
                delete this->_materia[i];
            this->_materia[i] = 0;
            if (c._materia[i])
                this->_materia[i] = c._materia[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    // std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != 0)
            delete this->_materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->_materia[i] == 0 && m)
        {
            // std::cout << "learn [" << i << "]=>" << m->getType() << std::endl;
            this->_materia[i] = m;
            return ;
        }
    }
    std::cout << "The inventory is full of materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] && this->_materia[i]->getType() == type)
        {
            // std::cout << "create new => " << type << std::endl;
            return (this->_materia[i]->clone());
        }
    }
    std::cout << "Nothing to create here" << std::endl;
    return (NULL);
}