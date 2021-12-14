#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        RobotomyRequestForm robot("Robot");
        Bureaucrat  bureaucrat1("Hermes", 45);
        ShrubberyCreationForm trees("Trees");
        PresidentialPardonForm president("president"); 
    
        bureaucrat1.executeForm(robot);
        bureaucrat1.signForm(robot);
        bureaucrat1.executeForm(robot);
        bureaucrat1.signForm(trees);
        bureaucrat1.executeForm(trees);
        bureaucrat1.signForm(president);
        for (int i = 0; i < 20; i++)
            bureaucrat1.incrementGrade();
        bureaucrat1.signForm(president);
        bureaucrat1.executeForm(president);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}