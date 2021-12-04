#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 0, 72, 45, "no target")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("robotomy request", 0, 72, 45, target)
{

}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : AForm("robotomy request", 0, 72, 45, rhs._target)
{

}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    return rhs;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}


void RobotomyRequestForm::execute (Bureaucrat const & executor) const
{
    (void)executor;
    const char* file = "rain.wav";
    char toJoin[255];
    memset(toJoin, 0, std::strlen(toJoin));
    char* pre = std::strcat(toJoin, "aplay -d 4 ");
    const char *command = std::strcat(pre, file);
    std::cout << command << std::endl;
    system(command);
}