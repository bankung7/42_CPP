#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{

private:
    std::string inName;
    std::string outName;
    std::string toFind;
    std::string toReplace;

public:
    Sed( void );
    ~Sed( void );
    void setFileName( std::string inName );
    int replace( std::string toFind, std::string toReplace );
};

#endif
