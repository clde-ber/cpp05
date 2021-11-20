#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("none")
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
    this->setGradeReqSign(145);
    this->setGradeReqExe(137);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : _target(target)
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
    this->setGradeReqSign(145);
    this->setGradeReqExe(137);
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs) : _target(rhs._target)
{
    _trees = rhs._trees;
    this->setGradeReqSign(rhs.getGradeReqSign());
    this->setGradeReqExe(rhs.getGradeReqExe());
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
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 33; j++)
            {
                std::cout << this->_trees[(int)(j + i * 33)];
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