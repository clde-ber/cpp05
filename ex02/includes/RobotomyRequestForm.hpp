#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string const _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm( RobotomyRequestForm const & rhs);
        RobotomyRequestForm const & operator=(RobotomyRequestForm const & rhs);
        ~RobotomyRequestForm();
        void execute (Bureaucrat const & executor) const;
};

#endif