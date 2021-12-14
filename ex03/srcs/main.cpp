#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat  bureaucrat1("Hermes", 45);
    Intern      intern;
    Intern      intern2(intern);
    Form* trees = 0;
    Form* robot = 0;
    Form* president = 0;
    Form *unknown = 0;

    try
    {
        trees = intern.makeForm("shrubbery creation", bureaucrat1.getName());
        bureaucrat1.signForm(*trees);
        bureaucrat1.executeForm(*trees);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (trees)
        delete trees;
    try
    {
        robot = intern.makeForm("robotomy request", bureaucrat1.getName());
        bureaucrat1.signForm(*robot);
        bureaucrat1.executeForm(*robot);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (robot)
        delete robot;
    try
    {
        president = intern.makeForm("presidential pardon", bureaucrat1.getName());
        bureaucrat1.signForm(*president);
        bureaucrat1.executeForm(*president);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (president)
        delete president;
    try
    {
        unknown = intern.makeForm("unknown type", bureaucrat1.getName());
        bureaucrat1.signForm(*unknown);
        bureaucrat1.executeForm(*unknown);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (unknown)
        delete unknown;
    return 0;
}