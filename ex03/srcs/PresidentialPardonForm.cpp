#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 0, 25, 5, "no target")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("presidential pardon", 0, 25, 5, target)
{

}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs) : AForm("presidential pardon", 0, 25, 5, rhs._target)
{

}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    return rhs;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}


void PresidentialPardonForm::execute (Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " has been forgiven by Zafod Beeblebrox!" << std::endl;
}