#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _signed(0), _gradeReqSign(75), _gradeReqExe(25)
{

}

Form::Form(int is_signed, int gradeReqSign, int gradeReqExe) : _signed(is_signed), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe)
{

}

Form::Form( Form const & rhs) : _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe)
{

}

Form const & Form::operator=(Form const & rhs) const
{
    return rhs;
}

Form::~Form()
{

}

int Form::getIfSigned() const
{
    return this->_signed;
}

int Form::getGradeReqSign() const
{
    return this->_gradeReqSign;
}

int Form::getGradeReqExe() const
{
    return this->_gradeReqExe;
}

void Form::GradeTooHighException()
{
    if (this->getGradeReqSign() > 150)
        std::cout << "Too high grade required to sign!" << std::endl;
    else
        std::cout << "Too high grade required to execute!" << std::endl;
}

void Form::GradeTooLowException()
{
    if (this->getGradeReqSign() < 1)
        std::cout << "Too low grade required to sign!" << std::endl;
    else
        std::cout << "Too low grade required to execute!" << std::endl;
}

int Form::beSigned(Bureaucrat* & bureaucrat) const
{
    if (bureaucrat->getGrade() == this->_gradeReqSign)
        return 1;
    else
        return 0;
}

void Form::signForm(Bureaucrat* & bureaucrat)
{
    if (this->beSigned(bureaucrat))
        std::cout << bureaucrat->getName() << " signs " << this->_name << std::endl;
    else
        std::cout << bureaucrat->getName() << " cannot sign because " << bureaucrat->getGrade() << " is not worth " << this->_gradeReqSign << std::endl;
}