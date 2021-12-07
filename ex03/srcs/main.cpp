#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat* b = new Bureaucrat("B1", 50);
    Intern* i = new Intern();
    Form* sForm = i->makeForm("shrubbery creation", b->getName());
    try
    {
        sForm->beSigned(b);
        sForm->signForm(b);
        sForm->checkIfSigned(sForm->getIfSigned());
        b->executeForm(*sForm);
        sForm->execute(*b);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    Form* rForm = i->makeForm("robotomy request", b->getName());
    try
    {
        rForm->beSigned(b);
        rForm->signForm(b);
        rForm->checkIfSigned(rForm->getIfSigned());
        b->executeForm(*rForm);
        rForm->execute(*b);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    Form* randomForm = i->makeForm("some random form", b->getName());
    try
    {
        randomForm->checkIfSigned(randomForm->getIfSigned());
        b->executeForm(*randomForm);
        randomForm->execute(*b);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete b;
    delete i;
    delete sForm;
    delete rForm;
    delete randomForm;
    return 0;
}