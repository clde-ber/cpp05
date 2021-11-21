#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("none")
{
    this->setGradeReqSign(25);
    this->setGradeReqExe(5);
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : _target(target)
{
    this->setGradeReqSign(25);
    this->setGradeReqExe(5);
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs) : _target(rhs._target)
{
    this->setGradeReqSign(rhs.getGradeReqSign());
    this->setGradeReqExe(rhs.getGradeReqExe());
}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) const
{
    return rhs;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute (Bureaucrat const & executor) const
{
    try
    {
        if (this->getIfSigned() == 0)
            throw AForm::UnsignedException();
        else if (executor.getGrade() > this->getGradeReqExe() or (executor.getGrade() < 1 and executor.getGrade() > 150))
            throw AForm::GradeTooLowException();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << executor.getName() << " has been forgiven by Zafod Beeblebrox!" << std::endl;
}