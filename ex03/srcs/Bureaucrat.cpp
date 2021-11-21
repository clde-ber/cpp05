#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{

}

Bureaucrat::Bureaucrat( std::string const name, int grade) : _name(name), _grade(grade)
{

}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs) : _name(rhs._name), _grade(rhs._grade)
{

}

Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & rhs) const
{
    return rhs;
}

Bureaucrat::~Bureaucrat()
{

}

std::string const Bureaucrat::getName() const
{
    return this->_name;
}

int  Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::incrementGrade()
{
    try
    {
        if (this->_grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        if (this->_grade - 1 > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    this->_grade--;
    
}

void    Bureaucrat::decrementGrade()
{
    this->_grade++;
}

void Bureaucrat::executeForm (AForm const & form)
{
    if (form.getIfSigned() && this->_grade <= form.getGradeReqExe())
        std::cout << this->_name << " executs " << form.getName() << std::endl;
    else
    {
        if (form.getIfSigned() == 0)
            throw Bureaucrat::UnsignedException();
        else if (this->_grade > form.getGradeReqExe())
            throw Bureaucrat::GradeTooLowException();
    }
}