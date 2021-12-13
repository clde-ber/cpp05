#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <string>
#include <iostream>
#include <fstream>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
    private:
        std::string const _target;
        std::string _trees;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm( ShrubberyCreationForm const & rhs);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
        virtual ~ShrubberyCreationForm();
        void executeSpecialForm(Bureaucrat const & executor) const;
};

#endif