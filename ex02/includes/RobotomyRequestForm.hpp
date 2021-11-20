#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm//(Grades requis : signature 72, execution 45)
{
    private:
        std::string const _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm( RobotomyRequestForm const & rhs);
        RobotomyRequestForm const & operator=(RobotomyRequestForm const & rhs) const;
        ~RobotomyRequestForm();
        void execute (Bureaucrat const & executor) const;
};

#endif