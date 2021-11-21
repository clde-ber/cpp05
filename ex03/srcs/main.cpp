#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs)
{
    o << rhs->getName() << ", bureaucrat grade " << rhs->getGrade();
    return o;
}

std::ostream & operator<<(std::ostream & o, AForm* const & rhs)
{
    o << "Form sign status : " << rhs->getIfSigned() << ", grade required for signing : " << rhs->getGradeReqSign() \
    << ", grade required for executing : " << rhs->getGradeReqExe();
    return o;
}

int main()
{
    Bureaucrat *test = new Bureaucrat("test", 5);
    Bureaucrat *gradeTooHigh = new Bureaucrat("too high", 0);
    Bureaucrat *gradeTooLow = new Bureaucrat("too low", 85);
    Intern *intern = new Intern();
    AForm *internF;

    test->incrementGrade();
    std::cout << test << std::endl;
    test->decrementGrade();
    std::cout << test << std::endl;
    ShrubberyCreationForm* sForm = new ShrubberyCreationForm(test->getName());
    RobotomyRequestForm* rForm = new RobotomyRequestForm(test->getName());
    PresidentialPardonForm* pForm = new PresidentialPardonForm(test->getName());
    std::cout << "*************grade too high*************" << std::endl;
    sForm->ShrubberyCreationForm::execute(*gradeTooHigh);
    rForm->RobotomyRequestForm::execute(*gradeTooHigh);
    pForm->PresidentialPardonForm::execute(*gradeTooHigh);
    std::cout << "*************grade too low*************" << std::endl;
    sForm->ShrubberyCreationForm::execute(*gradeTooLow);
    rForm->RobotomyRequestForm::execute(*gradeTooLow);
    pForm->PresidentialPardonForm::execute(*gradeTooLow);
    std::cout << "*************test*************" << std::endl;
    sForm->signForm(test);
    rForm->signForm(test);
    pForm->signForm(test);
    std::cout << "*************grade too high*************" << std::endl;
    sForm->signForm(gradeTooHigh);
    rForm->signForm(gradeTooHigh);
    pForm->signForm(gradeTooHigh);
    std::cout << "*************grade too low*************" << std::endl;
    sForm->signForm(gradeTooLow);
    rForm->signForm(gradeTooLow);
    pForm->signForm(gradeTooLow);
    std::cout << "*************test*************" << std::endl;
    sForm->ShrubberyCreationForm::execute(*test);
    rForm->RobotomyRequestForm::execute(*test);
    pForm->PresidentialPardonForm::execute(*test);
    std::cout << "*************grade too high*************" << std::endl;
    sForm->ShrubberyCreationForm::execute(*gradeTooHigh);
    rForm->RobotomyRequestForm::execute(*gradeTooHigh);
    pForm->PresidentialPardonForm::execute(*gradeTooHigh);
    std::cout << "*************grade too low*************" << std::endl;
    sForm->ShrubberyCreationForm::execute(*gradeTooLow);
    rForm->RobotomyRequestForm::execute(*gradeTooLow);
    pForm->PresidentialPardonForm::execute(*gradeTooLow);
    internF = intern->makeForm("robotomy request", "Bender");
    std::cout << "*************test*************" << std::endl;
    internF->signForm(test);
    std::cout << "*************grade too high*************" << std::endl;
    internF->signForm(gradeTooHigh);
    std::cout << "*************grade too low*************" << std::endl;
    internF->signForm(gradeTooLow);
    std::cout << "*************test*************" << std::endl;
    internF->execute(*test);
    std::cout << "*************grade too high*************" << std::endl;
    internF->execute(*gradeTooHigh);
    std::cout << "*************grade too low*************" << std::endl;
    internF->execute(*gradeTooLow);
    delete test;
    delete gradeTooHigh;
    delete gradeTooLow;
    delete sForm;
    delete rForm;
    delete pForm;
    delete intern;
    delete internF;
    return 0;
}