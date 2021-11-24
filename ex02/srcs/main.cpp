#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat* b1 = new Bureaucrat("B1", 50);
    ShrubberyCreationForm* sForm = new ShrubberyCreationForm(b1->getName());
    RobotomyRequestForm* rForm = new RobotomyRequestForm(b1->getName());
    PresidentialPardonForm* pForm = new PresidentialPardonForm(b1->getName());
    try
    {
        sForm->beSigned(b1);
        sForm->signForm(b1);
        sForm->checkIfSigned(sForm->getIfSigned());
        b1->executeForm(*sForm);
        sForm->execute(*b1);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        rForm->beSigned(b1);
        rForm->signForm(b1);
        rForm->checkIfSigned(rForm->getIfSigned());
        b1->executeForm(*rForm);
        rForm->execute(*b1);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        pForm->checkIfSigned(pForm->getIfSigned());
        b1->executeForm(*pForm);
        pForm->execute(*b1);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete b1;
    delete sForm;
    delete rForm;
    delete pForm;
    Bureaucrat* b2 = new Bureaucrat("test2", 3);
    sForm = new ShrubberyCreationForm(b2->getName());
    rForm = new RobotomyRequestForm(b2->getName());
    pForm = new PresidentialPardonForm(b2->getName());
    try
    {
        sForm->checkIfSigned(sForm->getIfSigned());
        b2->executeForm(*sForm);
        sForm->execute(*b2);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        rForm->beSigned(b2);
        rForm->signForm(b2);
        rForm->checkIfSigned(rForm->getIfSigned());
        b2->executeForm(*rForm);
        rForm->execute(*b2);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        pForm->beSigned(b2);
        pForm->signForm(b2);
        pForm->checkIfSigned(pForm->getIfSigned());
        b2->executeForm(*pForm);
        pForm->execute(*b2);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    delete b2;
    delete sForm;
    delete rForm;
    delete pForm;
    return 0;
}