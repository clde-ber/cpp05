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
    test->incrementGrade();
    std::cout << test << std::endl;
    test->decrementGrade();
    std::cout << test << std::endl;
    ShrubberyCreationForm* sForm = new ShrubberyCreationForm(test->getName());
    RobotomyRequestForm* rForm = new RobotomyRequestForm(test->getName());
    PresidentialPardonForm* pForm = new PresidentialPardonForm(test->getName());
    sForm->signForm(test);
    sForm->ShrubberyCreationForm::execute(*test);
    rForm->RobotomyRequestForm::execute(*test);
    pForm->PresidentialPardonForm::execute(*test);
    delete test;
    return 0;
}