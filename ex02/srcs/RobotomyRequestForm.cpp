#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("none")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : _target(rhs._target)
{

}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) const
{
    return rhs;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute (Bureaucrat const & executor) const
{
    (void)executor;
}