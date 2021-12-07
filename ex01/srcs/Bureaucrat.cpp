#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
    std::cout << "Constructor by default called";
    std::cout << "-> [Nameless] bureaucrat is created with greade [null]" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Constructor called";
    std::cout << "-> [" << _name << "] " << "bureaucrat is created with grade [" << _grade << "]" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs) : _name(rhs._name), _grade(rhs._grade)
{
    std::cout << "Constructor by copy called";
    std::cout << "-> [" << _name << "] " << "bureaucrat is created with grade [" << _grade << "]" << std::endl;
}

Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "Assignation operator called";
    new (this) Bureaucrat(rhs);
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs)
{
    o << "Bureaucrat name : " << rhs->getName() << " | grade : " << rhs->getGrade() << std::endl;
    return o;
}

std::string const & Bureaucrat::getName() const
{
    return _name;
}

int const & Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::checkValue(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::incrementGrade()
{
    std::cout << this << "Increment : grade [" << _grade << "]->[" << _grade - 1 << "]" << std::endl;
    checkValue(--_grade);
}

void    Bureaucrat::decrementGrade()
{
    std::cout << this << "Decrement : grade [" << _grade << "]->[" << _grade + 1 << "]" << std::endl;
    checkValue(++_grade);
}