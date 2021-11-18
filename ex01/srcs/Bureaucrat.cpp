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

void Bureaucrat::GradeTooHighException()
{
    std::cout << "Grade too high!" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
    std::cout << "Grade too low!" << std::endl;
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
    this->_grade--;
}

void    Bureaucrat::decrementGrade()
{
    this->_grade++;
}