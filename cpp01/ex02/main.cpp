#include <iostream>

int main(void)
{
    // let's build string variable
    std::string str = "HI THIS IS BRAIN";

    // create a pointer to the string
    std::string *stringPTR = &str;

    // create a reference to the string, this is called a another name of the str
    // it just a new variable which is deffinately a str.
    std::string &stringREF = str;

    std::cout << "let's print the address of them" << std::endl;
    // print address of string variable
    std::cout << "string: " << &str << std::endl;

    // print address of ptr
    std::cout << "stringPTR : " << stringPTR << std::endl;

    // print address of ref
    std::cout << "stringREF : " << &stringREF << std::endl;

    std::cout << "let's print the value of them" << std::endl;
    // value of string
    std::cout << "string : " << str << std::endl;

    // value of ptr
    std::cout << "stringPTR : " << *stringPTR << std::endl;

    // value of ref
    std::cout << "stringREF : " << stringREF << std::endl;

    return (0);
}