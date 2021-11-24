#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat* test1 = new Bureaucrat("test1", 2);
    Bureaucrat* test2 = new Bureaucrat("test2", 5);
    Form* paper1 = new Form("form1", 0, 1, 3);
    try
    {
        paper1->beSigned(test1);
        paper1->signForm(test1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    Form* paper2 = new Form("form2", 0, 72, 5);
    try
    {
        paper2->beSigned(test2);
        paper2->signForm(test2);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete test1;
    delete test2;
    delete paper1;
    delete paper2;
    return 0;
}