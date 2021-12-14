#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat  bureaucrat1("Hermes", 45);
    Intern      intern;
    Intern      intern2(intern);

    try
    {
        Form* trees = intern.makeForm("shrubbery creation", bureaucrat1.getName());
        bureaucrat1.signForm(*trees);
        bureaucrat1.executeForm(*trees);
        delete trees;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form* robot = intern.makeForm("robotomy request", bureaucrat1.getName());
        bureaucrat1.signForm(*robot);
        bureaucrat1.executeForm(*robot);
        delete robot;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form* president = intern.makeForm("presidential pardon", bureaucrat1.getName());
        bureaucrat1.signForm(*president);
        bureaucrat1.executeForm(*president);
        delete president;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form *unknown = intern.makeForm("unknown type", bureaucrat1.getName());
        bureaucrat1.signForm(*unknown);
        bureaucrat1.executeForm(*unknown);
        delete unknown;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}