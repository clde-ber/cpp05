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
    Bureaucrat1.incrementGrade();
    std::cout << Bureaucrat1 << std::endl;
    
    return 0;
}