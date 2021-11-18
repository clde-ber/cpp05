#include "Bureaucrat.hpp"

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs)
{
    o << rhs->getName() << ", bureaucrat grade " << rhs->getGrade();
    return o;
}

int main()
{
    Bureaucrat* test = new Bureaucrat("test", 151);
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
    delete test;
    test = new Bureaucrat("test", 0);
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
    delete test;
    test = new Bureaucrat("test", 5);
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
    delete test;
    return 0;
}