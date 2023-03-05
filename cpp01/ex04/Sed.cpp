#include "Sed.hpp"

Sed::Sed( void ): inName(""), outName(""), toFind(""), toReplace("") 
{
}

Sed::~Sed( void )
{
}

void Sed::setFileName( std::string inName )
{
    this->inName = inName;
    this->outName = inName + ".replace";
}

int Sed::replace( std::string toFind, std::string toReplace )
{    
    // open infile
    std::fstream inFile;

    inFile.open(inName.c_str(), std::ios::in);
    if (!inFile.is_open())
    {
        std::cout << "error: cannot open the file " << inName << std::endl;
        return (1);
    }

    // open out file
    std::fstream outFile;

    outFile.open(outName.c_str(), std::ios::out | std::ios::trunc );
    if (!outFile.is_open())
    {
        inFile.close();
        std::cout << "error: cannot create the output file" << std::endl;
        return (1);
    }

    // get all text from input to str and close the infile
    std::string text;
    std::getline(inFile, text, '\0');
    inFile.close();

    size_t pos = text.find(toFind);

    // user erase and insert what to replace
    while (pos != std::string::npos && toFind.length() > 0 && toReplace.length() > 0)
    {
        text.erase(pos, toFind.length());
        text.insert(pos, toReplace);
        pos = text.find(toFind, pos + toReplace.length());
    }
    // write to the file
    outFile << text;

    // close out file
    outFile.close();

    // announce
    std::cout << "Replace success" << std::endl;
    return (0);
}