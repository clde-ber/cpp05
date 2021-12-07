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

Intern const & Intern::operator=(Intern const & rhs)
{
    new (this) Intern(rhs);
    return *this;
}

Intern::~Intern()
{

}

Form* Intern::makeForm(const char* type, std::string target)
{
    std::string formTypes[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    Form* form[3] = { new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target) };

    for (int i = 0; i < 3; i++)
    {
        if (formTypes[i].compare(type))
        {
            std::cout << "Intern creates new [" << type << "] form!" << std::endl;
            for (int x = 0; x < 3; x++)
            {
                if (x != i)
                    delete form[x];
            }
            return form[i];
        }
    }
    return NULL;
}
