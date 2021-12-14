#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form    form1("yo", 0, 54, 34);
    Form    form2(form1);
    Form    form3("Nu-uh", 0, 12, 9);

    Bureaucrat  bureaucrat1("Hermes", 15);
    std::cout << form1 << std::endl;
    bureaucrat1.signForm(form1);
    std::cout << form3 << std::endl;
    bureaucrat1.signForm(form3);
    return 0;
}