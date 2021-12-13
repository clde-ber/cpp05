#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", 0, 72, 45, "no target")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("robotomy request", 0, 72, 45, target)
{

}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : Form("robotomy request", 0, 72, 45, rhs._target)
{

}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    new (this) RobotomyRequestForm(rhs);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::executeSpecialForm(Bureaucrat const & executor) const
{
    (void)executor;
    const char* file = "rainSound.mp3";
    char toJoin[255];
    memset(toJoin, 0, std::strlen(toJoin));
    char* pre = std::strcat(toJoin, "cvlc --play-and-exit ");
    const char *command = std::strcat(pre, file);
    std::cout << command << std::endl;
    system(command);
}