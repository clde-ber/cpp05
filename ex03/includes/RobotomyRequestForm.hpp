#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
    private:
        std::string const _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm( RobotomyRequestForm const & rhs);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        virtual ~RobotomyRequestForm();
        void executeSpecialForm(Bureaucrat const & executor) const;
};

#endif