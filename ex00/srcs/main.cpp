#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat  Bureaucrat1("Hermes");
    try
    {
        Bureaucrat1.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat1.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << Bureaucrat1 << std::endl;
    
    return 0;
}