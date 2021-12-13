#include "Bureaucrat.hpp"

int main()
{
    // Bureaucrat* test = new Bureaucrat();
    // Bureaucrat* tmp = new Bureaucrat("substitute", 75);
    // *test = *tmp;
    // Bureaucrat* tmp2 = new Bureaucrat(*tmp);
    // *tmp2 = *tmp;
    // delete test;
    // delete tmp2;
    // delete tmp;
    // Bureaucrat* test1 = new Bureaucrat("test1", 151);
    // try
    // {
    //     test1->decrementGrade();
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // delete test1;
    // Bureaucrat* test2 = new Bureaucrat("test2", 0);
    // try
    // {
    //     test2->incrementGrade();    
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // delete test2;
    // Bureaucrat* test3 = new Bureaucrat("test3", 5);
    // try
    // {
    //     test3->incrementGrade();
    //     test3->incrementGrade();
    //     test3->incrementGrade();
    //     test3->incrementGrade();
    //     test3->incrementGrade(); 
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // delete test3;
    Bureaucrat  Bureaucrat1("Hermes");
    try
    {
        Bureaucrat1.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout <<e.what() << std::endl;
    }
    Bureaucrat1.incrementGrade();
    std::cout << Bureaucrat1 << std::endl;
    
    return 0;
}