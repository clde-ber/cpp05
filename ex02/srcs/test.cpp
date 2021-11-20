#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("none")
{
    _trees = " _\\ |/ /     &  3       #)   #)  (# \\/\\|//    &    3       #) (#  (#   _\\/ |//_    &  3          (# #)       \\|/       \"\"            [-]         |        \"\"            [-]         |        \"\"            [-]         |        \"\"            [-]    ";
 }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : _target(target)
{
    _trees = " _\\ |/ /     &  3       #)   #)  (# \\/\\|//    &    3       #) (#  (#   _\\/ |//_    &  3          (# #)       \\|/       \"\"            [-]         |        \"\"            [-]         |        \"\"            [-]         |        \"\"            [-]    ";
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs) : _target(rhs._target)
{
    _trees = rhs._trees;
}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) const
{
    return rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
    if (this->getIfSigned() && executor.getGrade() <= this->getGradeReqExe())
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 35; j++)
            {
                std::cout << this->_trees[(int)(j + i * 35)];
            }
            std::cout << std::endl;
        }
    }
    else
    {
        if (this->getIfSigned() == 0)
            throw AForm::UnsignedException();
        else if (executor.getGrade() > this->getGradeReqExe())
            throw AForm::GradeTooLowException();
    }
}