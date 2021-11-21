#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{

}

Intern::Intern( Intern const & rhs)
{
    *this = rhs;
}

Intern const & Intern::operator=(Intern const & rhs) const
{
    return rhs;
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const char* type, std::string name)
{
    try
    {
        if (std::strcmp(type, "shrubbery creation") and std::strcmp(type, "robotomy request") and std::strcmp(type, "presidential pardon"))
            throw Intern::UnknownTypeException();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Intern creates new " << type << " form!" << std::endl;
    if (std::strcmp(type, "shrubbery creation"))
        return new ShrubberyCreationForm(name);
    else if (std::strcmp(type, "robotomy request"))
        return new RobotomyRequestForm(name);
    else
        return new PresidentialPardonForm(name);
}
