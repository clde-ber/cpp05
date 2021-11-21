#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
    Bureaucrat *gradeTooLow = new Bureaucrat("too low", 51);
    test->incrementGrade();
    std::cout << test << std::endl;
    test->decrementGrade();
    std::cout << test << std::endl;
    ShrubberyCreationForm* sForm = new ShrubberyCreationForm(test->getName());
    RobotomyRequestForm* rForm = new RobotomyRequestForm(test->getName());
    PresidentialPardonForm* pForm = new PresidentialPardonForm(test->getName());
    sForm->ShrubberyCreationForm::execute(*gradeTooHigh);
    rForm->RobotomyRequestForm::execute(*gradeTooHigh);
    pForm->PresidentialPardonForm::execute(*gradeTooHigh);
    sForm->ShrubberyCreationForm::execute(*gradeTooLow);
    rForm->RobotomyRequestForm::execute(*gradeTooLow);
    pForm->PresidentialPardonForm::execute(*gradeTooLow);
    sForm->signForm(test);
    rForm->signForm(test);
    pForm->signForm(test);
    sForm->signForm(gradeTooHigh);
    rForm->signForm(gradeTooHigh);
    pForm->signForm(gradeTooHigh);
    sForm->signForm(gradeTooLow);
    rForm->signForm(gradeTooLow);
    pForm->signForm(gradeTooLow);
    sForm->ShrubberyCreationForm::execute(*test);
    rForm->RobotomyRequestForm::execute(*test);
    pForm->PresidentialPardonForm::execute(*test);
    sForm->ShrubberyCreationForm::execute(*gradeTooHigh);
    rForm->RobotomyRequestForm::execute(*gradeTooHigh);
    pForm->PresidentialPardonForm::execute(*gradeTooHigh);
    sForm->ShrubberyCreationForm::execute(*gradeTooLow);
    rForm->RobotomyRequestForm::execute(*gradeTooLow);
    pForm->PresidentialPardonForm::execute(*gradeTooLow);
    delete test;
    delete gradeTooHigh;
    delete gradeTooLow;
    delete sForm;
    delete rForm;
    delete pForm;
    return 0;
}