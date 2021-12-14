#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form    form1("yo", 0, 54, 34);
        Form    form2(form1);
        // Form    form3("Nu-uh", 0,-12, -19);

        Bureaucrat  bureaucrat1("Hermes", 15);
        std::cout << form1 << std::endl;
        bureaucrat1.signForm(form2);
        std::cout << form1 << std::endl;
        bureaucrat1.signForm(form2);
        // std::cout << form3 << std::endl;
        // bureaucrat1.signForm(form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}