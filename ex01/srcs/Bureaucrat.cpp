#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(150)
{
    std::cout << "Constructor by default called" << std::endl;
    checkValue(_grade);
    std::cout << "-> [" << _name << "] bureaucrat is created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150)
{
    std::cout << "Constructor called" << std::endl;
    checkValue(_grade);
    std::cout << "-> [" << _name << "] bureaucrat is created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Constructor called" << std::endl;
    checkValue(_grade);
    std::cout << "-> [" << _name << "] " << "bureaucrat is created with grade [" << _grade << "]" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs)
{
    std::cout << "Constructor by copy called" << std::endl;
    *this = rhs;
    std::cout << "-> [" << _name << "] " << "bureaucrat is created with grade [" << _grade << "]" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    _grade = rhs._grade;
    checkValue(_grade);
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << "Bureaucrat name : " << rhs.getName() << " | grade : " << rhs.getGrade();
    return o;
}

std::string const & Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::checkValue(int grade) const
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::incrementGrade()
{
    std::cout << "Increment : grade [" << _grade << "]->[" << _grade - 1 << "]" << std::endl;
    checkValue(_grade - 1);
    _grade--;
}

void    Bureaucrat::decrementGrade()
{
    std::cout << "Decrement : grade [" << _grade << "]->[" << _grade + 1 << "]" << std::endl;
    checkValue(_grade + 1);
    _grade++;
}

void Bureaucrat::signForm(Form & form)
{
    try
    {
        form.beSigned(*this);
        std::cout <<  _name << " signs " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}