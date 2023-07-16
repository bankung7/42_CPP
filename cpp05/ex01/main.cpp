#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form a("Form A", 0, 40);
        Form b("Form B", 10, 0);
        Form c("Form C", 151, 12);
        Form d("Form D", 12, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    Bureaucrat b("B", 100);
    Form fb("Form B", 50, 30);
    Form fc("Form C", 110, 90);
    // Form fc(fb);

    std::cout << b << std::endl << std::endl;
    std::cout << fb << std::endl << std::endl;
    std::cout << fc << std::endl;

    std::cout << std::endl;

    try
    {
        b.signForm(fb);
        b.signForm(fc);
        b.signForm(fc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << fb << std::endl;
    std::cout << std::endl;
    std::cout << fc << std::endl;

    return (0);
}