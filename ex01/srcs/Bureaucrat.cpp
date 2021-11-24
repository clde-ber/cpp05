#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
    std::cout << "Constructor by default called";
    std::cout << "-> [Nameless] bureaucrat is created with greade [null]" << std::endl << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Constructor called";
    std::cout << "-> [" << this->_name << "] " << "bureaucrat is created with grade [" << this->_grade << "]" << std::endl << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs) : _name(rhs._name), _grade(rhs._grade)
{
    std::cout << "Constructor by copy called";
    std::cout << "-> [" << this->_name << "] " << "bureaucrat is created with grade [" << this->_grade << "]" << std::endl << std::endl;
}

Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & rhs) const
{
    std::cout << "Assignation operator called";
    std::cout << "-> Object substitution : Bureaucrat name is now [" << this->_name << "] " << "and grade is now [" << this->_grade << "]" << std::endl << std::endl;
    return rhs;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called." << std::endl << std::endl;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs)
{
    o << "Bureaucrat name : " << rhs->getName() << " | grade : " << rhs->getGrade() << std::endl;
    return o;
}

std::string const Bureaucrat::getName() const
{
    return this->_name;
}

int  Bureaucrat::getGrade() const
{
    return this->_grade;
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
    std::cout << this << "Increment : grade [" << this->_grade << "]->[" << this->_grade - 1 << "]" << std::endl;
    checkValue(--this->_grade);
}

void    Bureaucrat::decrementGrade()
{
    std::cout << this << "Decrement : grade [" << this->_grade << "]->[" << this->_grade + 1 << "]" << std::endl;
    checkValue(++this->_grade);
}