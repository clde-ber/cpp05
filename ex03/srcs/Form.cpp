#include "Bureaucrat.hpp"
#include "Form.hpp"

AForm::AForm(void)
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

void AForm::getName(std::string const name)
{
    this->_name = name;
}

void AForm::setIfSigned(int isSigned)
{
    this->_signed = isSigned;
}

void AForm::setGradeReqSign(int const grade)
{
    this->_gradeReqSign = grade;
}

void AForm::setGradeReqExe(int const grade)
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
    try
    {
        if (bureaucrat->getGrade() > this->_gradeReqSign or bureaucrat->getGrade() < 1 or bureaucrat->getGrade() > 150)
            throw AForm::GradeReqSignException();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    if (bureaucrat->getGrade() <= this->_gradeReqSign)
    {
        std::cout << bureaucrat->getName() << " signs " << this->_name << std::endl;
        this->_signed = 1;
    }
}