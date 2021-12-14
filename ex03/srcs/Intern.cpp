#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{

}

Intern::Intern( Intern const & rhs)
{
    (void)rhs;
    new (this) Intern;
}

Intern & Intern::operator=(Intern const & rhs)
{
    (void)rhs;
    new (this) Intern;
    return *this;
}

Intern::~Intern()
{

}

Form* Intern::makeForm(const char* type, std::string target)
{
    int i = 0;
    int x = 0;

    std::string formTypes[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    Form* form[3] = { new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target) };

    for (i = 0; i < 3; i++)
    {
        if (formTypes[i] == type)
        {
            std::cout << "Intern creates new [" << type << "] form!" << std::endl;
            for (x = 0; x < 3; x++)
            {
                if (x != i)
                {
                   delete form[x];
                   form[x] = 0;
                }
            }
            return form[i];
        }
        formTypes[i] = "";
    }
    for (x = 0; x < 3; x++)
    {
        delete form[x];
        form[x] = 0;
    }
    throw UnknownTypeException();
    return NULL;
}
