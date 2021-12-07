#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm  : public Form
{
    private:
        std::string const _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm( PresidentialPardonForm const & rhs);
        PresidentialPardonForm const & operator=(PresidentialPardonForm const & rhs);
        ~PresidentialPardonForm();
        void execute (Bureaucrat const & executor) const;
};

#endif