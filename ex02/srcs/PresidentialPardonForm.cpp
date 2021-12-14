#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("presidential pardon", 0, 25, 5, "random target"), _target("random target")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("presidential pardon", 0, 25, 5, target), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs) : Form("presidential pardon", 0, 25, 5, rhs._target), _target(rhs._target)
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    new (this) PresidentialPardonForm(rhs);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::executeSpecialForm(Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " has been forgiven by Zafod Beeblebrox!" << std::endl;
}