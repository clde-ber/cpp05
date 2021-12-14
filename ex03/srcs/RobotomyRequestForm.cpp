#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", 0, 72, 45, "random target"),_target("random target")
{
    
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("robotomy request", 0, 72, 45, target), _target(target)
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : Form("robotomy request", 0, 72, 45, rhs._target), _target(rhs._target)
{
    srand(time(NULL));
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
    if (rand()%2)
        std::cout << _target << " has been robotomized succesfully" << std::endl;
    else
        std::cout << "failure" << std::endl;
}