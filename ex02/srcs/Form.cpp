#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _signed(0), _gradeReqSign(75), _gradeReqExe(25)
{

}

AForm::AForm(int is_signed, int gradeReqSign, int gradeReqExe) : _signed(is_signed), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe)
{

}

AForm::AForm( AForm const & rhs) : _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe)
{

}

AForm const & AForm::operator=(AForm const & rhs) const
{
    return rhs;
}

AForm::~AForm()
{

}

std::string const AForm::getName() const
{
    return this->_name;
}

void AForm::setIfSigned(int boolean)
{
    this->_signed = boolean;
}

void AForm::setGradeReqSign(int grade)
{
    this->_gradeReqSign = grade;
}

void AForm::setGradeReqExe(int grade)
{
    this->_gradeReqExe = grade;
}

int AForm::getIfSigned() const
{
    return this->_signed;
}

int AForm::getGradeReqSign() const
{
    return this->_gradeReqSign;
}

int AForm::getGradeReqExe() const
{
    return this->_gradeReqExe;
}

int AForm::beSigned(Bureaucrat* bureaucrat) const
{
    if (bureaucrat->getGrade() == this->_gradeReqSign)
        return 1;
    else
        return 0;
}

void AForm::signForm(Bureaucrat* bureaucrat)
{
    if (bureaucrat->getGrade() <= this->_gradeReqSign)
    {
        std::cout << bureaucrat->getName() << " signs " << this->_name << std::endl;
        this->_signed = 1;
    }
    else
        std::cout << bureaucrat->getName() << " cannot sign because " << bureaucrat->getGrade() << " is not worth " << this->_gradeReqSign << std::endl;
}
