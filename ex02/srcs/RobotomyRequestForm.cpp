#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 0, 72, 45, "no target")
{
    std::cout << "[robotomy request form] default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("robotomy request", 0, 72, 45, target)
{
    std::cout << "[robotomy request form] constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : AForm("robotomy request", 0, 72, 45, rhs._target)
{
    std::cout << "[robotomy request form] copy constructor called" << std::endl;
}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) const
{
    std::cout << "[robotomy request form] assignation operator called" << std::endl;
    return rhs;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[robotomy request form] destrcutor called" << std::endl;
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