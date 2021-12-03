#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 0, 25, 5, "no target")
{
    std::cout << "[presidential pardon form] default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("presidential pardon", 0, 25, 5, target)
{
    std::cout << "[presidential pardon form] constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs) : AForm("presidential pardon", 0, 25, 5, rhs._target)
{
    std::cout << "[presidential pardon form] copy constructor called" << std::endl;
}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) const
{
    std::cout << "[presidential pardon form] assignation operator called" << std::endl;
    return rhs;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[presidential pardon form] destrcutor called" << std::endl;
}

void PresidentialPardonForm::execute (Bureaucrat const & executor) const
{
    std::cout << executor.getName() << " has been forgiven by Zafod Beeblebrox!" << std::endl;
}