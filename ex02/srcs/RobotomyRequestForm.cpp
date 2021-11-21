#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("none")
{
    this->setGradeReqSign(72);
    this->setGradeReqExe(45);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : _target(target)
{
    this->setGradeReqSign(72);
    this->setGradeReqExe(45);
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : _target(rhs._target)
{
    this->setGradeReqSign(rhs.getGradeReqSign());
    this->setGradeReqExe(rhs.getGradeReqExe());
}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) const
{
    return rhs;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute (Bureaucrat const & executor) const
{
    try
    {
        if (this->getIfSigned() == 0)
            throw AForm::UnsignedException();
        else if (executor.getGrade() > this->getGradeReqExe())
            throw AForm::GradeTooLowException();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    const char* file = "rain.wav";
    char toJoin[255];
    memset(toJoin, 0, std::strlen(toJoin));
    char* pre = std::strcat(toJoin, "aplay -d 4 ");
    const char *command = std::strcat(pre, file);
    std::cout << command << std::endl;
    system(command);
}