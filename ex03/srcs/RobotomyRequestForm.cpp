#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy request", 0, 72, 45, "random target"), _target("random target")
{
    std::srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("robotomy request", 0, 72, 45, target), _target(target)
{
    std::srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : Form("robotomy request", 0, 72, 45, rhs._target), _target(rhs._target)
{
    std::srand(time(NULL));
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    std::srand(time(NULL));
    new (this) RobotomyRequestForm(rhs);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeSpecialForm(Bureaucrat const & executor) const
{
    (void)executor;
    if (rand()%2)
    {
        std::string file = "rainSound.mp3";
        std::string command;

        command += "cvlc --play-and-exit ";
        command += file;
        system(command.c_str());
        std::cout << _target << " has been robotomized succesfully" << std::endl;
    }
    else
        std::cout << "failure" << std::endl;
}