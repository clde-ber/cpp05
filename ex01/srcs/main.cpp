#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs)
{
    o << rhs->getName() << ", bureaucrat grade " << rhs->getGrade();
    return o;
}

std::ostream & operator<<(std::ostream & o, Form* const & rhs)
{
    o << "Form sign status : " << rhs->getIfSigned() << ", grade required for signing : " << rhs->getGradeReqSign() \
    << ", grade required for executing : " << rhs->getGradeReqExe();
    return o;
}

int main()
{
    Bureaucrat *test = new Bureaucrat("test", 5);
    try
    {
        if (!(test->getGrade() > 1 && test->getGrade() < 150))
            throw std::exception();
        else
        {
            test->incrementGrade();
            std::cout << test << std::endl;
            test->decrementGrade();
            std::cout << test << std::endl;
        }    
    }
    catch (std::exception & e)
    {
        if (test->getGrade() < 1)
            test->GradeTooHighException();
        else
            test->GradeTooLowException();
    }
    Form* paper = new Form(0, 4, 3);
    try
    {
        if (!(paper->getGradeReqSign() > 1 && paper->getGradeReqSign() < 150 \
        && paper->getGradeReqExe() > 1 && paper->getGradeReqExe() < 150))
            throw std::exception();
        else
            paper->signForm(test);
    }
    catch (std::exception & e)
    {
        if (paper->getGradeReqSign() < 1 or paper->getGradeReqExe() < 1)
            test->GradeTooHighException();
        else
            test->GradeTooLowException();
    }
    delete test;
    delete paper;
    return 0;
}