#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("none")
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs) : _target(rhs._target)
{

}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) const
{
    return rhs;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute (Bureaucrat const & executor) const
{
    (void)executor;
}